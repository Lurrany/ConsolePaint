#include "../FiguraGeometricaCirculo.h"
#include "../Utilerias.h"
#include <math.h>
#include <iostream>

using namespace std;

void FiguraGeometricaCirculo::ImprimirCirculo(const Circulo& Cir){
    int x, y;
    x = Cir.CoordenadaX;
    y = Cir.CoordenadaY;
    //mover cursor al lugar de impresión
    Utilerias Uti;


    const int width= Cir.Radio;
    const int length=Cir.Radio*1;
    //Establecer x a la mitad del circulo
    x -= width;
    //Establecer y a la mitad del circulo :D
    y -= (width/2);

    //Mover a coodenadas
    Uti.MoverACoordenada(x, y, true);
    //recorer el ancho del circulo
    for (int y1=width;y1 >= -width;y1-=2){
        //Variable para guardar el valor de la linea :D
        std::string linea;
        for (int x1=-length;x1 <= length;x1++)  {
            //Si la posición coresponde al radio del criculo imprimir caracter
            if ((int)sqrt(pow(x1, 2)+pow(y1, 2))==Cir.Radio)
                linea += Cir.Caracter;
            else
                //Si no corresponde colocar un espacio :D
                linea += " ";

         }
         //Escribir en pantalla la linea
         Uti.EscribirEnPantalla(linea,false);
         //aumentar y, por el cambio en el moviemitno de coordenadas y ya no se usa :(
         y++;
         //Mover al inicio de x de la coordenada a graficar.
         Uti.MoverACoordenada(x,0, false);
         //Aumentar en y
         Uti.MoverCursor(0, 1);
     }
}
