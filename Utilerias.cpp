#include "Utilerias.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
//Metodo para imprimir un mensaje.
void Utilerias::MostrarMensaje(std::string Mensaje, bool SaltoLinea){
    cout << Mensaje << endl;
}
//metodo para ajustar el tamaño de la pantalla.
void Utilerias::AjustarTamanoVentana(int ancho, int alto){
    HWND hwnd = GetConsoleWindow();
    SetWindowPos(hwnd, HWND_TOP, 0,0, ancho, alto, SWP_NOMOVE);
}
//Metodo para limpiar pantalla
void Utilerias::LimpiarPantalla(){
    system("cls");
}
//Leer texto
std::string Utilerias::LeerValorTexto(std::string Mensaje, int TamanoTexto){
    //Mostrar mensaje al usuario
    MostrarMensaje(Mensaje);
    //declarar variable para guardar el resultado.
    char TextoIngresadoPorUsuario[TamanoTexto] = "";
    //leer valor ingresado
    cin.getline(TextoIngresadoPorUsuario, TamanoTexto);
    //retornar el valor ingresado
    return TextoIngresadoPorUsuario;
}
int Utilerias::LeerValorNumerico(std::string Mensaje){
    //Mostrar mensaje al usuario
    MostrarMensaje(Mensaje);
    //declarar variable para guardar el resultado.
    int ValorIngresadoPorUsuario;
    //leer valor ingresado
    cin >> ValorIngresadoPorUsuario;
    //retornar el valor ingresado
    return ValorIngresadoPorUsuario;
}
//Metodo para imprimir el menú
int Utilerias::MenuPrincipal(){
    cout << "___________________" << endl;
    cout << "|"  << "Menu, paint 1.0.0" << "|" << endl;
    cout << "___________________" << endl;

    //leer opcion ingresada
    return 0;
}
void Utilerias::MostrarControles(){
    cout << "CONTROLES: ARRIBA: W, UP; ABAJO: S, DOWN; IZQUIERDA: A, LEFT; DERECHA: D, DOWN" << endl;
}
//variables de coordenadas.
int _coordenadaX = 0;
int _coordenadaY = 3;
//obtener coordenada x
int Utilerias::ObtenerCoordenadaX(){
    return _coordenadaX;
}
//obtener coordenada y
int Utilerias::ObtenerCoordenadaY(){
    return _coordenadaY;
}
//metodo para mover el cursor
void Utilerias::MoverCursor(int PosicionX, int PosicionY){
    //Asignar nuevos valores a las variables de coordenada para guardar la posicio.
    _coordenadaX += PosicionX;
    _coordenadaY += PosicionY;
       //verificar cursor que el cursor x no este en negativo.
    if(_coordenadaX < 0)
        _coordenadaX = 0;
    if(_coordenadaY < 3)
        _coordenadaY = 3;

    COORD CoordenadaNueva;
    CoordenadaNueva.X = _coordenadaX;
    CoordenadaNueva.Y = _coordenadaY;

    //asignar la nueva coordenada.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CoordenadaNueva);
}
void Utilerias::MoverACoordenada(int PosicionX, int PosicionY){
    COORD CoordenadaNueva;
    CoordenadaNueva.X = PosicionX;
    CoordenadaNueva.Y = PosicionY;

    //asignar la nueva coordenada.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CoordenadaNueva);
}
