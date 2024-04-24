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
//listas con las figuras graficadas.
std::list<Rectangulo> _rectangulos;
std::list<Cuadrado> _cuadros;
std::list<Circulo> _circulos;
std::list<Triangulo> _triangulos;

bool Redibujando = false;
void Redibujar(){
    if(!Redibujando){
        Redibujando = true;
        //Redibular rectangulos
        for(auto Re:_rectangulos){
            //llamar a graficar
            FiguraGeometricaRectangulo FigRectangulo;
            FigRectangulo.ImprimirRectangulo(Re);

        }
        //Redibular cuadros
        for(auto Cu:_cuadros){
            //llamar a graficar
            FiguraGeometricaCuadrado FigCuadrado;
            FigCuadrado.ImprimirCuadrado(Cu);
        }
        //Redibular circulos
        for(auto Ci:_circulos){
            //llamar a graficar
            FiguraGeometricaCirculo FigCirculo;
            //FigCirculo.ImprimirCirculo(Ci);

        }
        //Redibular triangulos
        for(auto Re:_triangulos){
            //llamar a graficar
        }
        Redibujando = false;
    }

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
    Uti.MoverACoordenada(10, 10);
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
            //1 = triangulo
            //2 = cuadrado
            //3 = rectangulo
            //4 = circulo
            int Op = Uti.MenuPrincipal();

            cout << Op;
            switch(Op){
            case 1:
                //Triangulo
                Triangulo TriGraficado;
                TriGraficado = Uti.ObtenerUltimoTriangulo();
                break;
            case 2:
                //Cuadrado
                Cuadrado CuadradoGraficado;
                CuadradoGraficado = Uti.ObtenerUltimoCuadrado();
                break;
            case 3:
                //Rectangulo
                Rectangulo RectanguloGraficado;
                RectanguloGraficado = Uti.ObtenerUltimoRectangulo();
                _rectangulos.push_back(RectanguloGraficado);
                //Redibujar
                Redibujar();
                break;
            case 4:
                //Circulo
                Circulo CirculoGraficado;
                CirculoGraficado = Uti.ObtenerUltimoCirculo();
                break;
            }

        }
        if(GetKeyState(VK_ESCAPE) & 0x8000){
            repetir = false;
        }
        if(GetKeyState(VK_SPACE) & 0x8000){
            cout << " ";
        }
        if(GetKeyState('P') & 0x8000){

        }

        DWORD time;
        time = 65;
        Sleep(time);
    }
    return 0;
}
