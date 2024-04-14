#ifndef UTILERIAS_H
#define UTILERIAS_H
#include <string>
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
    //Metodo para ingreso de información
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
};
#endif // UTILERIAS_H
