#include <iostream>
#include "../Utilerias.h"
#include "../FiguraGeometricaCuadrado.h"
#include "../Entidades.h"

using namespace std;

void FiguraGeometricaCuadrado::ImprimirCuadrado(const Cuadrado& Cuadro){
    //Uso de la clase utilerias.
    Utilerias Uti;
    //mover el cursor a la coordenada indicada.
    Uti.MoverACoordenada(Cuadro.CoordenadaX, Cuadro.CoordenadaY);
    char Pantalla[Cuadro.Ancho][Cuadro.Ancho];
    for(int c = 0; c < Cuadro.Ancho; c++){
        for(int i = 0; i < Cuadro.Ancho; i++){
                if((c == 0) || (c == (Cuadro.Ancho-1)) || (i == 0) || (i == (Cuadro.Ancho-1))){
                    Pantalla[c][i] = Cuadro.Caracter;
                }
                else{
                    if(Cuadro.MostrarRelleno){
                        Pantalla[c][i] = Cuadro.Caracter;
                    }
                    else{
                        Pantalla[c][i] = ' ';
                    }
                }

            cout << Pantalla[c][i];
        }
        Uti.MoverCursor(0,1);
    }
}
