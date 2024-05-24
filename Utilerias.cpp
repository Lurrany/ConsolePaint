#include "Utilerias.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "FiguraGeometricaCuadrado.h"
#include "FiguraGeometricaRectangulo.h"
#include "FiguraGeometricaTriangulo.h"
#include "FiguraGeometricaCirculo.h"
#include "FiguraGeometricaLinea.h"
#include "Entidades.h"
#include <list>

using namespace std;
int _coordenadaXGuardada, _coordenadaYGuardada;
Cuadrado _ultimoCuadrado;
Circulo _ultimoCirculo;
Rectangulo _ultimoRectangulo;
Triangulo _ultimoTriangulo;
//variables de coordenadas.
int _coordenadaX = 0;
int _coordenadaY = 0;
//Variables para guardar el tamaño de la pantalla
int _columnas;
int _filas;
//Caracter para escribir e iniciarlo en *
char _caracterDibujo = '*';
//Color de los caracteres:
int _colorCaracteres = 15; //iniciar el color principal en blanco :D
const int _colorTextoBlanco = 15;
//Lista de objetos con las coordenada en pantalla
std::list<PosicionPantalla> _posicionesEnPantalla;

//procedimiento para cambiar el color
void Utilerias::CambiarColor(int Color){
    //Obtener el output de la consola
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //colocar el buffer
    FlushConsoleInputBuffer(hConsole);
    //asignar el color :D
    SetConsoleTextAttribute(hConsole, Color);
}
void Utilerias::EscribirEnPantalla(std::string Mensaje, bool Borrar){
    int x = ObtenerCoordenadaX();
    int y = ObtenerCoordenadaY();
    //cambiar color del texto de la consola antes de graficar
    if(_colorCaracteres != 0){ // verificar que se escogiera un color
            CambiarColor(_colorCaracteres);
    }
    for(auto letra:Mensaje){
            //pasar al otro lado de la pantalla al llegar al borde :D
            if(x >= ObtenerColumnas()){
                x = 0;
            }
            //objeto con la posicion y el caracter.
            PosicionPantalla pos;
            pos.CoordenadaX = x;
            pos.CoordenadaY = y;
            pos.Caracter = letra;
            pos.Color = _colorCaracteres;
            if(letra != ' ')
                _posicionesEnPantalla.push_back(pos);
            else if(letra == ' ' && Borrar)
                _posicionesEnPantalla.push_back(pos);
        x++;
    }
    cout << Mensaje;
    MoverACoordenada(x, y, true);

    //Revertir el cambio de color :D
    CambiarColor(_colorTextoBlanco);
}
void Utilerias::ReescribirEnPantalla(){
    //Recorrer todos los caracteres que estan en la lista de caracteres graficados :D
    for(auto CaracterPantalla:_posicionesEnPantalla){
        //Mover a la coordenada que indique el caracter
        MoverACoordenada(CaracterPantalla.CoordenadaX, CaracterPantalla.CoordenadaY, true);
        //cambiar el color del caracter antes de escribirlo en la pantalla
        CambiarColor(CaracterPantalla.Color);
        cout << CaracterPantalla.Caracter;
    }
    //al terminar cambiar el color al color blanco.
    CambiarColor(_colorTextoBlanco);
}
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
    cin.ignore();
    //retornar el valor ingresado
    return ValorIngresadoPorUsuario;
}
//Metodo para imprimir el menú
int Utilerias::MenuPrincipal(){
    int Opcion;
    GuardarCoordenadasActuales();
    cout << ":::::::::::::::::" << endl;
    MoverCursor(0,1);
    cout << ":: Paint 1.0.0 ::" << endl;
    MoverCursor(0,1);
    cout << ":::::::::::::::::" << endl;
    MoverCursor(0,1);
    cout << "::1 Graficar   ::" << endl;
    MoverCursor(0,1);
    cout << "::2 Guardar    ::" << endl;
    MoverCursor(0,1);
    cout << "::3 Abrir      ::" << endl;
    MoverCursor(0,1);
    cout << ":::::::::::::::::" << endl;
    MoverCursor(0,1);
    cout << ">";
    cin >> Opcion;
    cin.ignore();
    switch(Opcion){
    case 1:
        Opcion = MostrarSubMenuFiguras();
        break;
    }
    return Opcion;
}
int Utilerias::MostrarSubMenuFiguras(){
    int Opcion;
    MoverCursor(10,1);
    cout << ":::::::::::::::::" << endl;
    MoverCursor(0,1);
    cout << "::   Figuras   ::" << endl;
    MoverCursor(0,1);
    cout << ":::::::::::::::::" << endl;
    MoverCursor(0,1);
    cout << "::1 Triangulo  ::" << endl;
    MoverCursor(0,1);
    cout << "::2 Cuadrado   ::" << endl;
    MoverCursor(0,1);
    cout << "::3 Rectangulo ::" << endl;
    MoverCursor(0,1);
    cout << "::4 Circulo    ::" << endl;
    MoverCursor(0,1);
    cout << ":::::::::::::::::" << endl;
    MoverCursor(0,1);
    cout << ">";
    cin >> Opcion;
    cin.ignore();
    switch(Opcion){
    case 1:
        MostrarSubMenuTriangulo();
        break;
    case 2:
        MostrarSubMenuCuadro();
        break;
    case 3:
        MostrarSubMenuRectangulo();
        break;
    case 4:
        MostrarSubMenuCirculo();
        break;
    }
    return Opcion;
}
void Utilerias::MostrarSubMenuCuadro(){
    GuardarCoordenadasActuales();
    //objeto cuadrado
    Cuadrado NuevoCuadrado;
    //Asignar Valores al objeto :D
    NuevoCuadrado.CoordenadaX = _coordenadaXGuardada;
    NuevoCuadrado.CoordenadaY = _coordenadaYGuardada;
    NuevoCuadrado.MostrarRelleno = false;
    NuevoCuadrado.Caracter = _caracterDibujo;
    MoverCursor(0,1);
    cout << "Ancho del cuadro: ";
    cin >> NuevoCuadrado.Ancho;
    cin.ignore();

    FiguraGeometricaCuadrado Cuadrado;
    Cuadrado.ImprimirCuadrado(NuevoCuadrado);
}
void Utilerias::MostrarSubMenuRectangulo(){
    GuardarCoordenadasActuales();
    //Objeto Rectangulo
    Rectangulo NuevoRect;
    //asignar valores al objeto
    NuevoRect.CoordenadaX = _coordenadaXGuardada;
    NuevoRect.CoordenadaY = _coordenadaYGuardada;
    NuevoRect.MostrarRelleno = false;
    NuevoRect.Caracter = _caracterDibujo;

    MoverCursor(0,1);
    cout << "Ancho del rectangulo: ";
    cin >> NuevoRect.Ancho;
    cin.ignore();
    MoverCursor(0,1);
    cout << "Alto del rectangulo: ";
    cin >> NuevoRect.Alto;
    cin.ignore();

    FiguraGeometricaRectangulo Rectangulo;
    Rectangulo.ImprimirRectangulo(NuevoRect);

}
void Utilerias::MostrarSubMenuTriangulo(){
    GuardarCoordenadasActuales();
    //Objeto triangulo
    Triangulo NuevoTri;
    //Asignar los valores
    NuevoTri.CoordenadaX = _coordenadaXGuardada;
    NuevoTri.CoordenadaY = _coordenadaYGuardada;
    NuevoTri.MostrarRelleno = false;
    NuevoTri.Caracter = _caracterDibujo;

    //Solicitar la información al usuario
    MoverCursor(0,1);
    cout << "Base del triangulo: ";
    cin >> NuevoTri.Base;
    cin.ignore();

    FigurageometricaTriangulo Tri;
    Tri.ImprimirTriangulo(NuevoTri);
}
void Utilerias::MostrarSubMenuCirculo(){
    GuardarCoordenadasActuales();
    //Objeto circulo
    Circulo NuevoCirculo;
    //asignar valores
    NuevoCirculo.CoordenadaX = _coordenadaXGuardada;
    NuevoCirculo.CoordenadaY = _coordenadaYGuardada;
    NuevoCirculo.MostrarRelleno = false;
    NuevoCirculo.Caracter = _caracterDibujo;

    //Solicitar la información al usuario
    MoverCursor(0, 1);
    cout << "Ingrese el radio del circulo: ";
    cin >> NuevoCirculo.Radio;
    cin.ignore();

    FiguraGeometricaCirculo Cir;
    Cir.ImprimirCirculo(NuevoCirculo);
}
void Utilerias::MostrarSubMenuRombo(){
    //Guardar coordenadas para dibujar el rombo
    GuardarCoordenadasActuales();
    //Objeto rombo
    Rombo NuevoRombo;

}
void Utilerias::MostrarSubMenuLinea(){
    //Guardar coordenadas para dibujar el rombo
    //Ya no recuerdo para que se guardaban las coordenadas :(
    GuardarCoordenadasActuales();
    //Objeto linea
    Linea Lin;
    //Solicitar la información al usuario
    cout << "Indique la longitud de la linea: ";
    cin >> Lin.Longitud;
    cin.ignore();

    int Direccion;
    cout << "Indique la direccion 1 = vertical | 2 = horizontal " << endl;
    cout << " 3 = inclidado a la derecha | 4 = inclinado a la izquierda: ";
    cin >> Direccion;
    cin.ignore();

    switch(Direccion){
        case 1:
            Lin.Vertical = true;
            Lin.Horizontal = false;
            Lin.InclinacionDerecha = false;
            Lin.InclinacionIzquierda = false;
            break;
        case 2:
            Lin.Vertical = false;
            Lin.Horizontal = true;
            Lin.InclinacionDerecha = false;
            Lin.InclinacionIzquierda = false;
            break;
        case 3:
            Lin.Vertical = false;
            Lin.Horizontal = false;
            Lin.InclinacionDerecha = true;
            Lin.InclinacionIzquierda = false;
            break;
        case 4:
            Lin.Vertical = false;
            Lin.Horizontal = false;
            Lin.InclinacionDerecha = false;
            Lin.InclinacionIzquierda = true;
            break;
    }
    Lin.Caracter = _caracterDibujo;
    Lin.CoordenadaX = _coordenadaXGuardada;
    Lin.CoordenadaY = _coordenadaYGuardada;

    //Objeto para graficar la linea
    FiguraGeometricaLinea NuevaLinea;
    NuevaLinea.ImprimirLinea(Lin);

}
void Utilerias::MostrarControles(){
    cout << "F1: Triangulo | F2: Cuadrado | F3: Rectangulo | F4: Circulo | F5: Linea | F6: Rombo | F7: Hexagono | F8: Nuevo Caracter" << endl;
    cout << "F9: Limpiar Pantalla | F10: Color de Caracter | F12: Grabar Pantalla | Ctrl+A: Abrir archivo |Esc: Salir | paint 1.5.0";
}

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
    //verificar que el cursor no salga de la pantalla :D
    //verificar coordenada x
    if(_coordenadaX >= ObtenerColumnas()){
        _coordenadaX = 0;
        //_coordenadaY ;
    }
    else if(_coordenadaX < 0){
        _coordenadaX = ObtenerColumnas();
        //_coordenadaY--;
    }
    //verificar coordenada y
    if(_coordenadaY >= ObtenerFilas()){
        _coordenadaY = 0;
        //_coordenadaX ++;
    }
    else if(_coordenadaY < 0){
        //_coordenadaX--;
        _coordenadaY = ObtenerFilas()-1;
    }
    COORD CoordenadaNueva;
    CoordenadaNueva.X = _coordenadaX;
    CoordenadaNueva.Y = _coordenadaY;

    //asignar la nueva coordenada.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CoordenadaNueva);
}
void Utilerias::MoverACoordenada(int PosicionX, int PosicionY, bool PermitirCero){
    //Asignar nuevos valores a las variables de coordenada para guardar la posicio.
    if(PosicionX != 0)
        _coordenadaX = PosicionX;
    if(PosicionY != 0)
        _coordenadaY = PosicionY;
    if(PermitirCero){
        _coordenadaX = PosicionX;
        _coordenadaY = PosicionY;
    }
    //verificar que el cursor no salga de la pantalla :D
    //verificar coordenada x
    if(_coordenadaX >= ObtenerColumnas()){
        _coordenadaX = 0;
        //_coordenadaY ;
    }
    else if(_coordenadaX < 0){
        _coordenadaX = ObtenerColumnas();
        //_coordenadaY--;
    }
    //verificar coordenada y
    if(_coordenadaY >= ObtenerFilas()){
        _coordenadaY = 0;
        //_coordenadaX ++;
    }
    else if(_coordenadaY < 0){
        //_coordenadaX--;
        _coordenadaY = ObtenerFilas()-1;
    }
    COORD CoordenadaNueva;
    CoordenadaNueva.X = _coordenadaX;
    CoordenadaNueva.Y = _coordenadaY;

    //asignar la nueva coordenada.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CoordenadaNueva);
}
//obtener el tamaño de la pantalla actual
void Utilerias::ObtenerTamanoDePantalla(){
    //buffer de la pantalla
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //obtener la informacion de la pantalla
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    //asignar las columnas de la pantalla
    _columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //asignar las filas de la pantalla
    _filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
//Obtener columnas
int Utilerias::ObtenerColumnas(){
    ObtenerTamanoDePantalla();
    return _columnas;
}
//Obtener filas
int Utilerias::ObtenerFilas(){
    ObtenerTamanoDePantalla();
    return _filas;
}
//Guardar coordenadas actuales en las variables.
void Utilerias::GuardarCoordenadasActuales(){
    _coordenadaXGuardada = ObtenerCoordenadaX();
    _coordenadaYGuardada = ObtenerCoordenadaY();
}
//Simular tecla
void Utilerias::SimularTecla(WORD Tecla){
     //simular F11 para pantalla completa
    INPUT Entrada;
    //Evento del teclado
    Entrada.type = INPUT_KEYBOARD;
    Entrada.ki.wScan = 0;
    Entrada.ki.time = 0;
    Entrada.ki.dwExtraInfo = 0;

    //Ingreso de la tecla F11
    Entrada.ki.wVk = Tecla;
    Entrada.ki.dwFlags = 0;
    //Enviar la tencla a ser presionada.
    SendInput(1, &Entrada, sizeof(INPUT));
}

//Obtener el caracter de dibujo actual.
char Utilerias::ObtenerCaracterDibujo(){
    cout << "EL caracter para graficar actual es: " << _caracterDibujo;
    return _caracterDibujo;
}
//Asignar un nuevo caracter para dibujar
void Utilerias::AsignarCaracterDibujo(){
    cout << "Ingrese el nuevo caracter para graficar: ";
    cin >>_caracterDibujo;
}

//Cambiar el color
void Utilerias::CambiarColor(){
    int Opcion;
    cout << "Seleccione un color para el texto(1=Rojo, 2=Azul, 3=Verde, 4=Personalizado): ";
    cin >> Opcion;
    cin.ignore();

    switch(Opcion){
        case 1:
            _colorCaracteres = FOREGROUND_RED;
            break;
        case 2:
            _colorCaracteres = FOREGROUND_BLUE;
            break;
        case 3:
            _colorCaracteres = FOREGROUND_GREEN;
            break;
        case 4:
            cout << "Ingrese el codigo de color: ";
            cin >> _caracterDibujo;
            cin.ignore();
            break;
    }
}

//Esto ya no lo use, la idea era tener un registro de cada una de las ultimas figuras graficadas, no fue necesario al final :D
Cuadrado Utilerias::ObtenerUltimoCuadrado(){
    return _ultimoCuadrado;
}
Circulo Utilerias::ObtenerUltimoCirculo(){
    return _ultimoCirculo;
}
Triangulo Utilerias::ObtenerUltimoTriangulo(){
    return _ultimoTriangulo;
}
Rectangulo Utilerias::ObtenerUltimoRectangulo(){
    return _ultimoRectangulo;
}
