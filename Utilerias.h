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
    //metodo para ajustar tamaño de ventana.
    void AjustarTamanoVentana(int ancho, int alto);
    //mentodo para limpiar la pantalla
    void LimpiarPantalla();
    //metodo para imprimir el menu principal
    int MenuPrincipal();
    //Mostrar sub menu de figuras
    int MostrarSubMenuFiguras();
    //Metodo para ingreso de información
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
    //procedimiento para cambiar el color del texto
    void CambiarColor();
    //Eliminar registros de la pantalla
    void EliminarRegistrosDePantalla();

    //Submenus
    void MostrarSubMenuCuadro();
    //Submenu de información del rectangulo.
    void MostrarSubMenuRectangulo();
    //Submenu triangulo
    void MostrarSubMenuTriangulo();
    //Submenu circulo
    void MostrarSubMenuCirculo();
    //Submenu rombo
    void MostrarSubMenuRombo();
    //Sub menu de linea
    void MostrarSubMenuLinea();
    //Sub menu hexagono
    void MostrarSubMenuHexagono();
    //Solicitar la información al usuario para guardar el archivo de texto
    void MostrarSubMenuGuardarArchivo();
    //abrir archivo
    void MostrarSubMenuImportarArchivo();

    //Gestión del caracter para dibujo
    //Obtener el caracter
    char ObtenerCaracterDibujo();
    //Asignar caracter
    void AsignarCaracterDibujo();
    //Retornar ultimas figuras graficadas
    Cuadrado ObtenerUltimoCuadrado();
    Circulo ObtenerUltimoCirculo();
    Triangulo ObtenerUltimoTriangulo();
    Rectangulo ObtenerUltimoRectangulo();

private:
    //Obtener tamaño de pantalla;
    void ObtenerTamanoDePantalla();
    //Submenu de infromación del cuadro

    //Guardar coordenadas
    void GuardarCoordenadasActuales();
    //Procedimiento para cambiar el color
    void CambiarColor(int Color);

};
#endif // UTILERIAS_H
