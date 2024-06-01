#include <iostream>
#include "../Utilerias.h"
#include "../Entidades.h"
#include "FiguraGeometricaTriangulo.h"
#include "../FiguraGeometricaLinea.h"

using namespace std;

void FigurageometricaTriangulo::ImprimirTriangulo(const Triangulo& Tri){
    //Clase utilerias
    Utilerias Uti;

    FiguraGeometricaLinea FiguraLinea;
    int PuntoUnoX, PuntoUnoY, PuntoDosX, PuntoDosY, PuntoTresX, PuntoTresY;

    if(Tri.Arriba == true){
        PuntoUnoX = Tri.CoordenadaX;
        PuntoUnoY = Tri.CoordenadaY;

        PuntoDosX = Tri.CoordenadaX ;
        PuntoDosY = Tri.CoordenadaY + Tri.Base;

        PuntoTresX = PuntoDosX + Tri.Base;
        PuntoTresY = Tri.CoordenadaY + Tri.Base;

        FiguraLinea.ImprimirLinea(PuntoDosX, PuntoDosY, PuntoUnoX, PuntoUnoY, Tri.Caracter, Tri.Base);
        FiguraLinea.ImprimirLinea(PuntoDosX, PuntoDosY, PuntoTresX, PuntoTresY, Tri.Caracter, Tri.Base);
        FiguraLinea.ImprimirLinea(PuntoUnoX + Tri.Base, PuntoUnoY, PuntoTresX, PuntoTresY, Tri.Caracter, Tri.Base+1);
    }
    else if(Tri.Abajo == true){
        PuntoUnoX = Tri.CoordenadaX;
        PuntoUnoY = Tri.CoordenadaY;

        PuntoDosX = Tri.CoordenadaX + Tri.Base;
        PuntoDosY = (Tri.CoordenadaY);

        PuntoTresX = Tri.CoordenadaX + Tri.Base;
        PuntoTresY = (Tri.CoordenadaY + Tri.Base);

        FiguraLinea.ImprimirLinea(PuntoUnoX, PuntoUnoY, PuntoDosX, PuntoDosY, Tri.Caracter, Tri.Base+1);
        FiguraLinea.ImprimirLinea(PuntoUnoX, PuntoUnoY, PuntoTresX-Tri.Base, PuntoTresY, Tri.Caracter, Tri.Base);
        FiguraLinea.ImprimirLinea(PuntoTresX , PuntoTresY, PuntoDosX, PuntoDosY, Tri.Caracter, Tri.Base);


    }
    else if(Tri.Derecha == true){
        PuntoUnoX = Tri.CoordenadaX;
        PuntoUnoY = Tri.CoordenadaY;

        PuntoDosX = Tri.CoordenadaX-1;
        PuntoDosY = Tri.CoordenadaY + Tri.Base *2;

        PuntoTresX = Tri.CoordenadaX + Tri.Base;
        PuntoTresY = Tri.CoordenadaY + (Tri.Base *0.9);

        FiguraLinea.ImprimirLinea(PuntoUnoX, PuntoUnoY, PuntoDosX, PuntoDosY, Tri.Caracter, Tri.Base*2);
        FiguraLinea.ImprimirLinea(PuntoUnoX, PuntoUnoY, PuntoTresX, PuntoTresY, Tri.Caracter, Tri.Base);
        FiguraLinea.ImprimirLinea(PuntoDosX +1, PuntoDosY, PuntoTresX, PuntoTresY, Tri.Caracter, Tri.Base+1);

    }
    else if(Tri.Izquierda == true){
        PuntoUnoX = Tri.CoordenadaX + Tri.Base;
        PuntoUnoY = Tri.CoordenadaY;

        PuntoDosX = Tri.CoordenadaX ;
        PuntoDosY = Tri.CoordenadaY + (Tri.Base) ;

        PuntoTresX = Tri.CoordenadaX - Tri.Base;
        PuntoTresY = (Tri.CoordenadaY + (Tri.Base *0.9));

        FiguraLinea.ImprimirLinea(PuntoUnoX, PuntoUnoY, PuntoDosX, PuntoDosY, Tri.Caracter, Tri.Base *2);
        FiguraLinea.ImprimirLinea(PuntoTresX, PuntoTresY, PuntoUnoX, PuntoUnoY, Tri.Caracter, Tri.Base+1);
        FiguraLinea.ImprimirLinea(PuntoTresX, PuntoTresY, PuntoDosX, PuntoDosY, Tri.Caracter, Tri.Base);
    }
    //Codigo antiguo para graficar triangulo
    //FiguraLinea.ImprimirLinea(PuntoDosX, PuntoDosY, PuntoTresX, PuntoTresY, Tri.Caracter, Tri.Base);
    /*FiguraLinea.ImprimirLinea(Tri.CoordenadaX, Tri.CoordenadaY, Tri.CoordenadaX - (Tri.Base/2), Tri.Base, Tri.Caracter, Tri.Base);
    FiguraLinea.ImprimirLinea(Tri.CoordenadaX, Tri.CoordenadaY, Tri.Base/2, Tri.Base, Tri.Caracter, Tri.Base);*/
    /*
    //coordenadas
    int x;
    int y;
    x = Tri.CoordenadaX;
    y = Tri.CoordenadaY;

    //colocar el lugar a graficar a la mitad del triangulo
    x -= (Tri.Base);
    //mover a la cordenada a graficar, poniendo en true la opcion de permitir coordenadas 0
    Uti.MoverACoordenada(x,y, true);
    //recorer la altura del triangulo
    for (int c = 1, i = 0; c <= Tri.Base; c++, i = 0) {
        string Linea;
        //Agregar espacios hasta llegar a la posición donde se debe trazar el triangulo
        for (int Espacio = 1; Espacio <= Tri.Base - c; Espacio++) {
            //Asignar el caracter
            Linea += " ";
        }
        //Linea del caracter para verificar el borde
        int CaracterPuesto = 0;
        //mientras el caracter no este en una posición fuera del perimetro donde graficar el triangulo repetir para colocar el carcter
        while (i != 2 * c - 1) {
            //verificar que el caracter puesto sea del inicio del ttriangulo o este dentro del perimetro. para solo trazar el borde
            if(CaracterPuesto == 0 || (CaracterPuesto +1) == (2 * c - 1)){
                Linea += Tri.Caracter;
            }
            //verificar si es la parte de abajo del triangulo y trazarlo
            else if(c== Tri.Base){
                Linea+=Tri.Caracter;
            }
            //si mostrar el relleno, se trazara todo.
            else{
                if(Tri.MostrarRelleno)
                    Linea += Tri.Caracter;
                else
                    Linea += " ";

            }
            //aumentar varialbbes de posición
            CaracterPuesto++;
            i++;
        }
        //Mover el cursor, y no se usa ahora.
        Uti.EscribirEnPantalla(Linea, false);
        y++;
        Uti.MoverACoordenada(x,0, false);
        Uti.MoverCursor(0, 1);

    }
    */
}
