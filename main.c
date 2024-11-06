#include "datos.h"
#include "calculos.h"
#include <stdio.h>
//Realice los cálculos de área y perímetro para las siguientes figuras geométricas: Triángulos, 
//Rparalelogramo, cuadrado, rectángulo, rombo, trapecio, círculo y polígono regular. 
int main(){
    int opcion;
    int continuar = 1;


    while (continuar) {
        mostrar_menu();
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        if (opcion == 0) {
            printf("Fin del programa.\n");
            break;
        }

        solicitar_datos_figura(opcion);

        printf("¿Desea analizar otra figura geométrica? (1 = Sí, 0 = No): ");
        scanf("%d", &continuar);
    }
    return 0;
}
