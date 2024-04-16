#ifndef UTILERIAS_H
#define UTILERIAS_H
#include <string>
#include "TamanoPantalla.h"

class Utilerias{
//Metodos/propiedades publicas.
public:
    //Metodo para mostrar mensaje
    void MostrarMensaje(std::string Mensaje, bool SaltoLinea = true);
    //metodo para ajustar tama�o de ventana.
    void AjustarTamanoVentana(int ancho, int alto);
    //mentodo para limpiar la pantalla
    void LimpiarPantalla();
    //metodo para imprimir el menu principal
    int MenuPrincipal();
    //Mostrar sub menu de figuras
    int MostrarSubMenuFiguras();
    //Metodo para ingreso de informaci�n
    std::string LeerValorTexto(std::string Mensaje, int TamanoTexto);
    //Leer valores numericos
    int LeerValorNumerico(std::string Mensaje);
    //mover cursor
    void MoverCursor(int PosicionX, int PosicionY);
    //establecer nueva posicion en pantalla
    void MoverACoordenada(int PosicionX, int PosicionY);
    //leyenda con los controles
    void MostrarControles();
    //Obtener coordenada x
    int ObtenerCoordenadaX();
    //obtener coordenada y
    int ObtenerCoordenadaY();
    //obtener columnas
    int ObtenerColumnas();
    //obtener filas
    int ObtenerFilas();
private:
    //Obtener tama�o de pantalla;
    void ObtenerTamanoDePantalla();
};
#endif // UTILERIAS_H
