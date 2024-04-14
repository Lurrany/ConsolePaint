#include <iostream>
#include <Utilerias.h>
#include <FiguraGeometricaCuadrado.h>

using namespace std;

void FiguraGeometricaCuadrado::ImprimirCuadrado(int x, int y, int Ancho, bool Relleno, char Caracter){
    Utilerias Uti;
    Uti.MoverACoordenada(x, y);
    int EquivalenciaAltura = (Ancho*0.6);
    char Pantalla[EquivalenciaAltura][Ancho];
    for(int c = 0; c < EquivalenciaAltura; c++){
        for(int i = 0; i < Ancho; i++){
                if((c == 0) || (c == (EquivalenciaAltura-1)) || (i == 0) || (i == (Ancho-1))){
                    Pantalla[c][i] = Caracter;
                }
                else{
                    if(Relleno){
                        Pantalla[c][i] = Caracter;
                    }
                    else{
                        Pantalla[c][i] = ' ';
                    }
                }

            cout << Pantalla[c][i];
        }
        Uti.MoverCursor(0,1);
    }
}
