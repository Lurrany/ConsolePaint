#include <iostream>
#include "../Utilerias.h"
#include "../FiguraGeometricaCuadrado.h"
#include "FiguraGeometricaRectangulo.h"

using namespace std;

void FiguraGeometricaRectangulo::ImprimirRectangulo(const Rectangulo& Rect){
    //Uso de la clase utilerias.
    Utilerias Uti;
    int x = Rect.CoordenadaX;
    int y = Rect.CoordenadaY;
    //mover el cursor a la coordenada indicada.
    Uti.MoverACoordenada(Rect.CoordenadaX, Rect.CoordenadaY);
    char Pantalla[Rect.Alto][Rect.Ancho];
    //array con la infomración del rectangulo

    for(int c = 0; c < Rect.Alto; c++){
        std::string Linea;
        for(int i = 0; i < Rect.Ancho; i++){
                if((c == 0) || (c == (Rect.Alto-1)) || (i == 0) || (i == (Rect.Ancho-1))){
                    Pantalla[c][i] = Rect.Caracter;
                }
                else{
                    if(Rect.MostrarRelleno){
                        Pantalla[c][i] = Rect.Caracter;
                    }
                    else{
                        Pantalla[c][i] = ' ';
                    }
                }

            Linea += Pantalla[c][i];
        }
        Uti.EscribirEnPantalla(Linea);
        y++;
        Uti.MoverACoordenada(x, y);
        //Uti.MoverCursor(0,1);
    }
}
