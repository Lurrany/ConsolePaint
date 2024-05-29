#ifndef GESTIONARCHIVO_H
#define GESTIONARCHIVO_H

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include "Entidades.h"

using namespace std;

class GestionArchivo
{
    public:
        void EscribirEnArchivo(string NombreArchivo, string Texto);
        void Exportar(string NombreArchivo, list<PosicionPantalla> CaracterEnPantalla, int ColumnaPantalla, int FilaPantalla);
        void CrearArchivo(string NombreArchivo);

    protected:

    private:
};

#endif // GESTIONARCHIVO_H
