#ifndef calculos_h
#define calculos_h

float areaTriangulo(float base, float altura);
float perimetroTrianguloEquilatero(float lado);
float perimetroTrianguloIsosceles(float lado,float base);
float perimetroTrianguloEscaleno(float lado1,float lado2, float lado3);
float areaParalelogramo(float base, float altura);
float perimetroParalelogramo(float lado1,float lado2);
float areaCuadrado(float lado);
float perimetroCuadrado(float lado);
float areaRectangulo(float lado1,float lado2);
float perimetroRectangulo(float lado1,float lado2);
float areaRombo(float diagMayor, float diagMenor);
float perimetroRombo(float lado);
float areaTrapecio(float basMayor,float basMenor,float altura);
float perimetroTrapecio(float lado1, float lado2, float lado3, float lado4);
float areaCirculo(float radio);
float perimetroCirculo(float radio);
float areaPoligono(float apotema,float nLados, float lado );
float perimetroPoligono(float nLados,float lado);


float superficieCubo(float lado);
float volumenCubo(float lado);
float superficieCuboide(float largo, float base, float altura);
float volumenCuboide(float largo,float base,float altura);
float superficieCilindro(float radio,float altura);
float volumenCilindro(float radio,float altura);
float superficieEsfera(float radio);
float volumenEsfera(float radio);
float superficieCono(float radio, float lInclinacion);
float volumenCono(float radio,float altura);








float areaCirculo(float radio);

#endif