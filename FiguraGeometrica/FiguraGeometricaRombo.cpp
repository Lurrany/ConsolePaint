#include "FiguraGeometricaRombo.h"
#include "../FiguraGeometricaLinea.h"
#include "../Entidades.h"
#include <iostream>

using namespace std;

void FiguraGeometricaRombo::ImprimirRombo(const Rombo& Rom){
    //objeto de lineas
   FiguraGeometricaLinea lin;
   int CoordenadaY = Rom.CoordenadaY;
   //Graficar hacia arriba
   if(Rom.Arriba){
         CoordenadaY = Rom.CoordenadaY - (Rom.Base*2);

   }
       //llamar al objeto de linea para graficar las lineas del rombo :D
       lin.ImprimirLinea(Rom.CoordenadaX, CoordenadaY+2, Rom.CoordenadaX + Rom.Base, CoordenadaY + Rom.Base, Rom.Caracter, Rom.Base);
       lin.ImprimirLinea(Rom.CoordenadaX - (Rom.Base * 2), CoordenadaY + Rom.Base, Rom.CoordenadaX, CoordenadaY, Rom.Caracter, Rom.Base);

       lin.ImprimirLinea(Rom.CoordenadaX - (Rom.Base * 2), CoordenadaY + Rom.Base, Rom.CoordenadaX + (Rom.Base*2), CoordenadaY + (Rom.Base*2), Rom.Caracter, Rom.Base);

       lin.ImprimirLinea(Rom.CoordenadaX, CoordenadaY + (Rom.Base * 2), Rom.CoordenadaX + (Rom.Base), CoordenadaY + (Rom.Base), Rom.Caracter, Rom.Base );
}
