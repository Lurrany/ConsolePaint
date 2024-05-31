#ifndef ENTIDADES_H
#define ENTIDADES_H

//Estructura para el cuadro
struct Cuadrado{
    int CoordenadaX;
    int CoordenadaY;
    int Ancho;
    bool MostrarRelleno;
    char Caracter;
    bool Arriba;
    bool Abajo;
    bool Izquierda;
    bool Derecha;
};
//Estructura para el rectangulo
struct Rectangulo{
    int CoordenadaX;
    int CoordenadaY;
    int Ancho;
    int Alto;
    bool MostrarRelleno;
    char Caracter;
    bool Arriba;
    bool Abajo;
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
    bool Arriba;
    bool Abajo;
    bool Izquierda;
    bool Derecha;
};
struct Linea{
    int CoordenadaX;
    int CoordenadaY;
    int Longitud;
    char Caracter;
    bool Horizontal;
    bool Vertical;
    bool InclinacionDerecha;
    bool InclinacionIzquierda;
};
struct Rombo{
    int CoordenadaX;
    int CoordenadaY;
    int Base;
    bool MostrarRelleno;
    char Caracter;
    bool Arriba;
    bool Abajo;
};
struct Hexagono{
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
    int Color;
};
#endif // ENTIDADES_H
