#include <iostream>
#include <windows.h>
#include "Utilerias.h"
#include <Entidades.h>
#include <list>
#include "FiguraGeometricaCirculo.h""
#include "FiguraGeometricaCuadrado.h"
#include "FiguraGeometricaRectangulo.h"
#include "FiguraGeometricaTriangulo.h"


using namespace std;

void ActualizarPantalla(){
    //Objeto de utilerias
    Utilerias Uti;
    //Eliminar con cls toda la pantalla
    Uti.LimpiarPantalla();
    //Mover a 0, 0 para imprimir controles
    Uti.MoverACoordenada(0,0, true);
    //Imprimir controles :D
    Uti.MostrarControles();
    //Reescribir la información guardada en la pantalla
    Uti.ReescribirEnPantalla();
}
int main()
{
    //Clase de utilerias
    Utilerias Uti;
    //Simular tecla f11 para poner en pantalla completa :D
    Uti.SimularTecla(VK_F11);

    //Declarar matriz de pantalla luego de maximizar
    int Pantalla[Uti.ObtenerFilas()][Uti.ObtenerCoordenadaX()];
    Uti.MostrarControles();
    Uti.MoverACoordenada(10, 10, false);
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
            //Limpiar buffer
            cin.clear();
            //Mostrar el menu para que el usuario ingrese la información.
            Uti.MenuPrincipal();
            //Actualizar luego que se grafique
            ActualizarPantalla();
        }
        if(GetKeyState(VK_ESCAPE) & 0x8000){
            //Salir
            repetir = false;
        }
        if(GetKeyState(VK_SPACE) & 0x8000){
            //Borrar caracter en pantalla
            Uti.EscribirEnPantalla(" ", true);
        }
        if(GetKeyState('P') & 0x8000){
            //Boton de pruebas
            Uti.EscribirEnPantalla("Prueba #1", false);
        }
        if(GetKeyState(VK_F5) & 0x8000){
            //Actualizar pantalla
            ActualizarPantalla();
        }
        //Evitar que se guarden las teclas presionadas en buffer :|
        Uti.SimularTecla(VK_BACK);
        DWORD time;
        time = 65;
        Sleep(time);
    }
    return 0;
}
