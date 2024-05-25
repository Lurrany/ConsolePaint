#include "FiguraGeometricaRombo.h"
#include "../FiguraGeometricaLinea.h"
#include "../Entidades.h"
#include <iostream>

using namespace std;

void FiguraGeometricaRombo::ImprimirRombo(const Rombo& Rom){
    //objeto de lineas
   FiguraGeometricaLinea lin;

   //llamar al objeto de linea para graficar las lineas del rombo :D
   lin.ImprimirLinea(Rom.CoordenadaX, Rom.CoordenadaY+2, Rom.CoordenadaX + Rom.Base, Rom.CoordenadaY + Rom.Base, Rom.Caracter, Rom.Base);
   lin.ImprimirLinea(Rom.CoordenadaX - (Rom.Base * 2), Rom.CoordenadaY + Rom.Base, Rom.CoordenadaX, Rom.CoordenadaY, Rom.Caracter, Rom.Base);

   lin.ImprimirLinea(Rom.CoordenadaX - (Rom.Base * 2), Rom.CoordenadaY + Rom.Base, Rom.CoordenadaX + (Rom.Base*2), Rom.CoordenadaY + (Rom.Base*2), Rom.Caracter, Rom.Base);

   lin.ImprimirLinea(Rom.CoordenadaX, Rom.CoordenadaY + (Rom.Base * 2), Rom.CoordenadaX + (Rom.Base), Rom.CoordenadaY + (Rom.Base), Rom.Caracter, Rom.Base );
}
