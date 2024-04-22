#include <iostream>
#include <windows.h>
#include "Utilerias.h"
#include "FiguraGeometricaCirculo.h"
#include "FiguraGeometricaCuadrado.h"
#include <Entidades.h>
#include <list>

std::list<Rectangulo> Rectangulos;
using namespace std;

int main()
{
    //Pruebas con listas
    /*
    Rectangulo Rect2;
    Rect2.Alto = 3;
    Rect2.Ancho = 4;
    Rect2.Caracter = 'F';
    Rect2.CoordenadaX = 100;
    Rect2.CoordenadaY = 100;
    Rectangulos.push_back(Rect2);

    for(auto Rec:Rectangulos){
        cout << Rec.Alto << endl;
        cout << Rec.Ancho << endl;
        cout << Rec.Caracter << endl;
    }
    */

    //Clase de utilerias
    Utilerias Uti;
    //Simular tecla f11 para poner en pantalla completa :D
    Uti.SimularTecla(VK_F11);
    Uti.ObtenerColumnas();

    //Declarar matriz de pantalla luego de maximizar
    int Pantalla[Uti.ObtenerFilas()][Uti.ObtenerCoordenadaX()];

    Uti.MostrarControles();
    Uti.MoverACoordenada(10, 10);
    FiguraGeometricaCuadrado Cuadrado;
    //std::string textoIngresado = Uti.LeerValorTexto("Ingrese un texto",100);
    //Uti.MostrarMensaje(textoIngresado, false);
    ShowCursor(true);
    bool repetir = true;
    while(repetir){
        if((GetKeyState(VK_LEFT) & 0x8000) || (GetKeyState('A') & 0x8000)){
            Uti.MoverCursor(-1,0);
        }
        if((GetKeyState(VK_RIGHT) & 0x8000) || (GetKeyState('D') & 0x8000)){
            Uti.MoverCursor(1,0);
        }
        if((GetKeyState(VK_UP) & 0x8000) || (GetKeyState('W') & 0x8000)){
            Uti.MoverCursor(0, -1);
        }
        if((GetKeyState(VK_DOWN) & 0x8000) || (GetKeyState('S') & 0x8000)){
            Uti.MoverCursor(0, 1);
        }
        if(GetKeyState(VK_F12) & 0X8000){
            Uti.MenuPrincipal();
        }

        DWORD time;
        time = 65;
        Sleep(time);
    }
    return 0;
}
