#include "FiguraGeometricaLinea.h"
#include "../Entidades.h"
#include "../Utilerias.h"

using namespace std;

void FiguraGeometricaLinea::ImprimirLinea(const Linea& Lin){
    //clase utilerias
    Utilerias Uti;
    //Coordenadas iniciales
    int X = Lin.CoordenadaX;
    int Y = Lin.CoordenadaY;
    //Moverse a la coordenada necesaria en la pantalla.
    Uti.MoverACoordenada(X,Y, true);

    //Preparar si es inclinación izquierda
    if(Lin.InclinacionIzquierda){
        Uti.MoverACoordenada(X, Y + Lin.Longitud, true);
    }
    for(int c = 0; c < Lin.Longitud; c++){
        //variable de linea de texto a imprimir
        string Li;
        Li += Lin.Caracter;
        //imprimir el primer caracter
        Uti.EscribirEnPantalla(Li, false);

        //mover hacia a la nueva dirección
        if(Lin.Horizontal == true){
            Uti.MoverCursor(1,0);
        }
        else if(Lin.Vertical == true){
            Uti.MoverCursor(-1,1);
        }
        else if(Lin.InclinacionDerecha == true){
            Uti.MoverCursor(1, 1);
        }
        else if(Lin.InclinacionIzquierda == true){
            Uti.MoverCursor(1, -1);
        }
    }
}

void FiguraGeometricaLinea::ImprimirLinea(int Ix, int Iy, int Fx, int Fy, char Caracter, int Longitud){
     //clase utilerias
    Utilerias Uti;
    //Coordenadas iniciales

    //Moverse a la coordenada necesaria en la pantalla.
    Uti.MoverACoordenada(Ix,Iy, true);


    for(int c = 0; c < Longitud; c++){
        //variable de linea de texto a imprimir
        string Li;
        Li += Caracter;
        //imprimir el primer caracter
        Uti.EscribirEnPantalla(Li, false);

        //mover hacia a la nueva dirección
        if(Ix < Fx){
            Uti.MoverCursor(1,0);
        }
        if(Iy < Fy){
            Uti.MoverCursor(0, 1);
        }
        if(Ix > Fx){
            Uti.MoverCursor(-1, 0);
        }
        if(Iy > Fy){
            Uti.MoverCursor(0, -1);
        }
    }
}
