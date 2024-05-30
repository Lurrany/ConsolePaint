#ifndef GESTIONARCHIVO_H
#define GESTIONARCHIVO_H

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include "Entidades.h"
#include "Utilerias.h"

using namespace std;

class GestionArchivo
{
    public:
        //Processo para escribir en el archivo
        void EscribirEnArchivo(string NombreArchivo, string Texto);
        //proceso para exportar a un archivo
        void Exportar(string NombreArchivo, list<PosicionPantalla> CaracterEnPantalla, int ColumnaPantalla, int FilaPantalla);
        //proceso para crear el archivo
        void CrearArchivo(string NombreArchivo);
        //Proceso para leer un archivo :D
        list<PosicionPantalla> LeerArchivo(string NombreArchivo, int FilaActual, int ColumnaActual, int ColorActual, int CaracterDibujoActual);

    protected:

    private:
};

#endif // GESTIONARCHIVO_H
