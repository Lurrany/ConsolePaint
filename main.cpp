#include <iostream>
#include <windows.h>
#include "Utilerias.h"
#include "FiguraGeometricaCirculo.h"
#include "FiguraGeometricaCuadrado.h"
using namespace std;


int main()
{
    //Clase de utilerias
    Utilerias Uti;
    Uti.ObtenerCoordenadaX();
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
        if(GetKeyState('P') & 0X8000){
            int _x = Uti.ObtenerCoordenadaX();
            int _y = Uti.ObtenerCoordenadaY();
            //Cuadrado.ImprimirCuadrado(_x, _y, 20, false, '*');
            cout << _x << " " << _y;
        }
        if(GetKeyState(VK_ESCAPE) & 0x8000){
            repetir = false;
        }
        if(GetKeyState('U') & 0X8000){
            int columnas, filas;
            columnas = Uti.ObtenerColumnas();
            filas = Uti.ObtenerFilas();
            cout << "X: " << columnas << " Y: " << filas;
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
