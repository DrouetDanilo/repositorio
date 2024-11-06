#include "datos.h"
#include "calculos.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define LOG_FILE "bitacora.txt"
#define CREDENTIALS_FILE "credenciales.txt"


void log_access(const char* username, const char* action) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error al abrir el archivo de bitácora");
        return;
    }

    // Obtener la fecha actual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(log_file, "%04d/%02d/%02d: %s - %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, username, action);
    fclose(log_file);
}

// Función para validar las credenciales
int validate_credentials(const char* username, const char* password) {
    FILE *credentials_file = fopen(CREDENTIALS_FILE, "r");
    if (credentials_file == NULL) {
        perror("Error al abrir el archivo de credenciales");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), credentials_file)) {
        // Eliminar el salto de línea al final de la línea
        line[strcspn(line, "\n")] = 0;

        // Dividir la línea en usuario y contraseña usando strtok
        char *file_username = strtok(line, "-");
        char *file_password = strtok(NULL, "-");

        // Verificar que ambas partes existen
        if (file_username != NULL && file_password != NULL) {
            // Depuración: mostrar los valores leídos
            printf("Usuario leído: %s, Contraseña leída: %s\n", file_username, file_password);
            printf("Usuario ingresado: %s, Contraseña ingresada: %s\n", username, password);

            // Verificar si las credenciales coinciden
            if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
                fclose(credentials_file);
                return 1; // Autenticación exitosa
            }
        }
    }

    fclose(credentials_file);
    return 0; // Autenticación fallida
}

int main() {
    int opcion;
    int continuar = 1;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Ingrese su usuario: ");
    scanf("%s", username);
    printf("Ingrese su clave: ");
    scanf("%s", password);

    // Validar credenciales
    if (validate_credentials(username, password) == 1) {
        log_access(username, "Ingreso exitoso al sistema");
        printf("Bienvenido, %s!\n", username);
    } else {
        log_access(username, "Ingreso fallido usuario/clave erróneo");
        printf("Ingreso fallido. Usuario o clave incorrectos.\n");
    }

    while (continuar) {
        mostrar_menu(); // Asumiendo que esta función ya está definida en otro lugar
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        if (opcion == 0) {
            printf("Fin del programa.\n");
            break;
        }

        solicitar_datos_figura(opcion); // Asumiendo que esta función también está definida

        printf("¿Desea analizar otra figura geométrica? (1 = Sí, 0 = No): ");
        scanf("%d", &continuar);
    }

    return 0;
}

