#include <iostream>
#include "../Utilerias.h"
#include "../FiguraGeometricaCuadrado.h"
#include "../Entidades.h"

using namespace std;

void FiguraGeometricaCuadrado::ImprimirCuadrado(const Cuadrado& Cuadro){
    //Uso de la clase utilerias.
    Utilerias Uti;
    int x = Cuadro.CoordenadaX;
    int y = Cuadro.CoordenadaY;
    //mover el cursor a la coordenada indicada.
    Uti.MoverACoordenada(Cuadro.CoordenadaX, Cuadro.CoordenadaY);
    char Pantalla[Cuadro.Ancho][Cuadro.Ancho];
    //array con la información la linea del cuadro
    for(int c = 0; c < Cuadro.Ancho; c++){
        //variable para guardar el resultado.
        std::string Linea;
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

            //Asignar el resultado a la variable de linea
            Linea += Pantalla[c][i];
        }
        //escribir en pantalla la información de la linea e ingresarlo en la lista que guarda el estado de la pantalla :D
        Uti.EscribirEnPantalla(Linea);
        y++;
        Uti.MoverACoordenada(x, y);
    }

}
