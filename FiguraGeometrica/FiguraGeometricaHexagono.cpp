#include "FiguraGeometricaHexagono.h"
#include "../FiguraGeometricaLinea.h"
#include <iostream>
#include "../Entidades.h"

using namespace std;

void FiguraGeometricaHexagono::ImprimirHexagono(const Hexagono& Hexa){
    //Objeto de linea
    FiguraGeometricaLinea lin;
    //graficar las lineas
    //parte de arriba
    lin.ImprimirLinea(Hexa.CoordenadaX, Hexa.CoordenadaY, Hexa.CoordenadaX + Hexa.Base, Hexa.CoordenadaY, Hexa.Caracter, Hexa.Base);
    //Laterales izquierdos
    lin.ImprimirLinea(Hexa.CoordenadaX - (Hexa.Base*2), Hexa.CoordenadaY + Hexa.Base, Hexa.CoordenadaX, Hexa.CoordenadaY, Hexa.Caracter, Hexa.Base);
    lin.ImprimirLinea(Hexa.CoordenadaX - (Hexa.Base*2), Hexa.CoordenadaY + Hexa.Base, Hexa.CoordenadaX, Hexa.CoordenadaY + (Hexa.Base * 2), Hexa.Caracter, Hexa.Base);

    //Laterales derechos
    lin.ImprimirLinea(Hexa.CoordenadaX + (Hexa.Base * 2) -2, Hexa.CoordenadaY, Hexa.CoordenadaX + (Hexa.Base * 2), Hexa.CoordenadaY + Hexa.Base, Hexa.Caracter, Hexa.Base+1);
    lin.ImprimirLinea(Hexa.CoordenadaX + (Hexa.Base*2) -2, Hexa.CoordenadaY + (Hexa.Base * 2), Hexa.CoordenadaX + (Hexa.Base * 2), Hexa.CoordenadaY + Hexa.Base, Hexa.Caracter, Hexa.Base+1);

    //parte de abajo
    lin.ImprimirLinea(Hexa.CoordenadaX, Hexa.CoordenadaY + (Hexa.Base*2), Hexa.CoordenadaX + Hexa.Base, Hexa.CoordenadaY + (Hexa.Base * 2), Hexa.Caracter, Hexa.Base);
}
