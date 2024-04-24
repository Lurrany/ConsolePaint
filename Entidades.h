#ifndef ENTIDADES_H
#define ENTIDADES_H

//Estructura para el cuadro
struct Cuadrado{
    int CoordenadaX;
    int CoordenadaY;
    int Ancho;
    bool MostrarRelleno;
    char Caracter;
};
//Estructura para el rectangulo
struct Rectangulo{
    int CoordenadaX;
    int CoordenadaY;
    int Ancho;
    int Alto;
    bool MostrarRelleno;
    char Caracter;
};
//Estructura para el circulo
struct Circulo{
    int CoordenadaX;
    int CoordenadaY;
    float Radio;
    bool MostrarRelleno;
    char Caracter;
};
struct Triangulo{
    int CoordenadaX;
    int CoordenadaY;
    int Base;
    bool MostrarRelleno;
    char Caracter;
};
struct PosicionPantalla{
    int CoordenadaX;
    int CoordenadaY;
    char Caracter;
};
#endif // ENTIDADES_H
