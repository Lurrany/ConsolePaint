#include <iostream>
#include <windows.h>
#include "Utilerias.h"
#include <Entidades.h>
#include <list>
#include "FiguraGeometricaCirculo.h""
#include "FiguraGeometricaCuadrado.h"
#include "FiguraGeometricaRectangulo.h"
#include "FiguraGeometricaTriangulo.h"
#include "FiguraGeometricaRombo.h"
#include "FiguraGeometricaHexagono.h"


using namespace std;

void ActualizarPantalla();

int main()
{
    //la clase utilerias hace todo el trabajo :D
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
        //Elimiar caracteres que se colocan al presionar algun F
        Uti.SimularTecla(VK_BACK);
        Uti.SimularTecla(VK_BACK);
        Uti.SimularTecla(VK_BACK);
        //Movimiento
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
        //Opciones del menu
        //Triangulo
        if(GetKeyState(VK_F1) & 0x8000){
            Uti.MostrarSubMenuTriangulo();
            //Actualizar luego que se grafique
            ActualizarPantalla();
        }
        //Cuadrado
        else if(GetKeyState(VK_F2) & 0x8000){
            Uti.MostrarSubMenuCuadro();
            //Actualizar luego que se grafique
            ActualizarPantalla();
        }
        //Rectangulo
        else if(GetKeyState(VK_F3) & 0x8000){
            Uti.MostrarSubMenuRectangulo();
            //Actualizar luego que se grafique
            ActualizarPantalla();
        }
        //Circulo
        else if(GetKeyState(VK_F4) & 0x8000){
            Uti.MostrarSubMenuCirculo();
            //Actualizar luego que se grafique
            ActualizarPantalla();
        }
        //Linea
        else if(GetKeyState(VK_F5) & 0x8000){
            Uti.MostrarSubMenuLinea();
            ActualizarPantalla();
        }
        //Rombo
        else if(GetKeyState(VK_F6) & 0x8000){
            Uti.MostrarSubMenuRombo();
            ActualizarPantalla();
        }
        //Hexagono
        else if(GetKeyState(VK_F7) & 0x8000){
            Uti.MostrarSubMenuHexagono();
            ActualizarPantalla();
        }
        else if(GetKeyState(VK_F8) & 0x8000){
            //Cambiar caracter para graficar
            Uti.AsignarCaracterDibujo();
            ActualizarPantalla();
        }
        else if(GetKeyState(VK_F9) & 0x8000){
            //Limpiar pantalla
            Uti.LimpiarPantalla();
            Uti.EliminarRegistrosDePantalla();
            //Imprimir controles de nuevo
            Uti.MostrarControles();
        }
        else if(GetKeyState(VK_F10) & 0x8000){
            //Llamar al procedimiento para cambiar el color :D
            Uti.CambiarColor();
            //Borrar todo en pantalla y dibujar todo de nuevo.
            ActualizarPantalla();
        }
        else if(GetKeyState(VK_F12) & 0X8000){
            //llamar al proceso para ingresar la información del archivo
            Uti.MostrarSubMenuGuardarArchivo();
            //Actualizar luego que se grafique
            ActualizarPantalla();
        }
        else if(GetKeyState(VK_ESCAPE) & 0x8000){
            //Salir
            repetir = false;
        }
        /*if(GetKeyState(VK_SPACE) & 0x8000){
            //Borrar caracter en pantalla
            Uti.EscribirEnPantalla(" ", true);
        }*/
        if(GetKeyState('P') & 0x8000){

            HANDLE  hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            //colocar el buffer
            FlushConsoleInputBuffer(hConsole);
            //asignar el color :D
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        }

        DWORD time;
        time = 65;
        Sleep(time);
    }
    return 0;
}

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

    cin.clear();
}
