#include <iostream>
#include <windows.h>
#include <Utilerias.h>
#include <FiguraGeometricaCirculo.h>
#include <FiguraGeometricaCuadrado.h>
using namespace std;


int main()
{
    //Clase de utilerias
    Utilerias Uti;
    Uti.MenuPrincipal();
    Uti.MoverCursor(0, 0);
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
            Cuadrado.ImprimirCuadrado(_x, _y, 20, false, '*');
        }
        if(GetKeyState(VK_ESCAPE) & 0x8000){
            repetir = false;
        }
        DWORD time;
        time = 50;
        Sleep(time);
    }
    return 0;
}


