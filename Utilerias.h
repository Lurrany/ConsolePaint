#ifndef UTILERIAS_H
#define UTILERIAS_H
#include <string>
#include "TamanoPantalla.h"
#include <windows.h>
#include "Entidades.h"

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
    void MoverACoordenada(int PosicionX, int PosicionY, bool ACeroCero);
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
    //simular presionar tecla
    void SimularTecla(WORD Tecla);
    //escribir en pantalla
    void EscribirEnPantalla(std::string Mensaje, bool Borrar);
    //reescribir pantalla
    void ReescribirEnPantalla();
    //Retornar ultimas figuras graficadas
    Cuadrado ObtenerUltimoCuadrado();
    Circulo ObtenerUltimoCirculo();
    Triangulo ObtenerUltimoTriangulo();
    Rectangulo ObtenerUltimoRectangulo();

private:
    //Obtener tama�o de pantalla;
    void ObtenerTamanoDePantalla();
    //Submenu de infromaci�n del cuadro
    void MostrarSubMenuCuadro();
    //Submenu de informaci�n del rectangulo.
    void MostrarSubMenuRectangulo();
    //Submenu triangulo
    void MostrarSubMenuTriangulo();
    void MostrarSubMenuCirculo();
    //Guardar coordenadas
    void GuardarCoordenadasActuales();

};
#endif // UTILERIAS_H
