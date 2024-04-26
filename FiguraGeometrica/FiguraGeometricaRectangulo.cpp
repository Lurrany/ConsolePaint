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
    Uti.MoverACoordenada(Rect.CoordenadaX, Rect.CoordenadaY, false);
    //Declarar como matriz el rectangulo
    char Pantalla[Rect.Alto][Rect.Ancho];
    //array con la infomración del rectangulo
    for(int c = 0; c < Rect.Alto; c++){
            //Linea de resultado
        std::string Linea;
        for(int i = 0; i < Rect.Ancho; i++){
            //Verificar si es el principio o final del rectangulo para poner el borde
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
        //imprimir linea y mover cursor
        Uti.EscribirEnPantalla(Linea, false);
        y++;
        Uti.MoverACoordenada(x, 0, false);
        Uti.MoverCursor(0,1);
    }
}
