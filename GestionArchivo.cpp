#include "GestionArchivo.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include "Entidades.h"
#include <stdio.h>
#include <errno.h>
#include <fstream>
#include "Utilerias.h"

using namespace std;

void GestionArchivo::CrearArchivo(string NombreArchivo){
    //Agregar la extensión al archivo
    NombreArchivo += ".txt";
    //Declarar el archivo de salida :D
    FILE *outfile;
    //abrir y crear el archivo
	outfile = fopen (NombreArchivo.c_str(), "w");
	//verificar si fue posible crear el archivo
	if (outfile == NULL)
	{
	    //error al crear el archivo
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	// indicar si se creo al archivo o no
	if(fwrite != 0)
		cout << "Se genero el archivo de texto para guardar los datos: " << NombreArchivo << "\n";
	else
		cout << "No fue posible generar el archivo.";
    //Cerrar el archivo
	fclose(outfile);

}
void GestionArchivo::EscribirEnArchivo(string NombreArchivo, string Texto){
    //declarar archivo de tipo ofstream
    ofstream Archivo;
    //abrir archivo,
    Archivo.open(NombreArchivo);
    //escribir el texto en el archivo abierto
    Archivo << Texto.c_str();
    //cerrar archivo
    Archivo.close();
}
void GestionArchivo::Exportar(string NombreArchivo, list<PosicionPantalla> CaracterEnPantalla, int ColumnaPantalla, int FilaPantalla){
    //Declarar archivo
    ofstream Archivo;
    //abrir o crear el archivo
    Archivo.open(NombreArchivo);
    //declarar la matriz con las posiciones de pantalla e iniciarlas en vacio
    string Pantalla[FilaPantalla][ColumnaPantalla];
    for(int Fila = 0; Fila < FilaPantalla; Fila++){
        for(int Columna = 0; Columna < ColumnaPantalla; Columna++){
            Pantalla[Fila][Columna] = " ";
        }
    }
    //recorrer las posiciones en pantalla guardadas y escribir en la matriz con el caracter usado para la figura.
    for(auto CaracterPantalla:CaracterEnPantalla){
        Pantalla[CaracterPantalla.CoordenadaY][CaracterPantalla.CoordenadaX] = CaracterPantalla.Caracter;
    }
    //recorrer la matriz y escribir en pantalla :D
    for(int Fila = 0; Fila < FilaPantalla; Fila++){
        for(int Columna = 0; Columna < ColumnaPantalla; Columna++){
            Archivo << Pantalla[Fila][Columna];
        }
        Archivo << "\n";
    }
    //cerrar el archivo
    Archivo.close();
    //indicar al usuario que se guardo el archivo
    cout << "Se exporto el archivo en Exportados\\" << NombreArchivo << endl;
    //apusar para que el usuario pueda ver el mensaje
    system("pause");
}
list<PosicionPantalla> GestionArchivo::LeerArchivo(string NombreArchivo, int FilaActual, int ColumnaActual, int ColorActual, int CaracterDibujoActual){
    //Clase utilerias
    Utilerias Uti;
    //matriz de pantalla
    string Pantalla[FilaActual][ColumnaActual];
    //crear y abrir el archivo
    ifstream Archivo;
    Archivo.open(NombreArchivo);
    //Lista con las nuevas posiciones :D
    list<PosicionPantalla> NuevaPosicion;
    //verificar que se abre el archivo indicado :D
    if(!Archivo.good()){
        Uti.MostrarMensaje("El archivo: " + NombreArchivo + ", no existe.");
    }
    else{
        //variable para el valor de la linea
         string Lin;
         int FilaRecorrida;
        //while de lectura de linea
         while(getline(Archivo, Lin)){
            //for de recorrido de linea para agregarlo a la lista de posiciones
            for(int c = 0; c < Lin.length(); c++){
                if(Lin[c] != ' '){
                    PosicionPantalla pos;
                    pos.Caracter = CaracterDibujoActual;
                    pos.Color = ColorActual;
                    pos.CoordenadaX = c;
                    pos.CoordenadaY = FilaRecorrida;
                    NuevaPosicion.push_back(pos);
                }
            }
            FilaRecorrida++;
        }
        Uti.MostrarMensaje("El archivo: " + NombreArchivo + ", fue importado.");
    }
    Archivo.close();
    return NuevaPosicion;
}
