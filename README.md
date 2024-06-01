# Paint de Consola
## Proyecto universitario por Alex Alejandro De León Ajmac 7690-22-6607.

![N|Solid](https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/800px-ISO_C%2B%2B_Logo.svg.png)

![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)

Este proyecto tiene como finalidad construir un programa de paint en consola utilizando c++ como lenguaje principal.
## Funciones

- Dibujo de figuras: triángulo, círculo, cuadro, rectángulo, rombo, línea, hexágono.
- Orientación para las figuras.
- Exportación de lo graficado a un archivo de texto.
- Importación de graficas en archivos de 

# Manual de usuario

## Graficar
Los accesos para graficar se muestran al momento de iniciar el programa, los accesos estan asignados de la siguiente manera:
- F1: triángulo
```sh
[Numero] Base del triangulo:
[Numero] Orientacion: [^ = 1] [v = 2] [<- = 3] [-> = 4]:
```
- F2: cuadrado
```sh
[Numero] Ancho del cuadro:
```
- F3: Rectangulo
```sh
[Numero] Ancho del rectangulo:
[Numero] Alto del rectangulo:
```
- F4: Circulo
```sh
[Numero] Ingrese el radio del circulo:
```
- F5: Linea
```sh
[Numero] Indique la longitud de la linea:
[Numero] Direccion [| = 1] [- = 2] [\ = 3] [/ = 4]:
```
- F6: Rombo
```sh
[Numero] Ingrese la longitud de los lados:
[Numero] Orientacion [^ = 1] [v = 2]:
```
- F7: Hexagono
```sh
[Numero] Ingrese la longitud de los lados:
```
## Archivos
La ruta predeterminada para la gestión de los archivos es ..Exportados\

- Ctrl + A: Abrir archivo
```sh
[Texto] Ingrese el nombre del archivo a abrir:
```
- F12: Guardar archivo
```sh
[Texto] Ingrese el nombre para el archivo:
```
## Otras funciones

- F8: Cambiar caracter para graficar
```sh
[char] Ingrese el nuevo caracter para graficar:
```
- F9: Limpiar pantalla
- F10: Cambiar color para graficar
```sh
Seleccione un color para el texto(1=Rojo, 2=Azul, 3=Verde, 4=Personalizado):
```
- Esc: Salir

# Manual técnico
El dibujado de las figuras funciona teniendo una lista list<> de una estructura, donde se guarda cada caracter escrito en la pantalla, una vez que se grafica una figura, se eliminan todos los caracteres en la pantalla y se escriben nuevamente a partir de la lista donde se guardan con su respectiva coordenada, caracter y color.

## Main
La clase main no contiene mayor código, unicamente contiene la validación de las teclas presionadas, así como un procedimiento para actualizar la pantalla.
## Utilerias
La clase Utilerias es la clase con más código, esta clase contiene el código correspondiente a:
- Mover coordenadas
- Guadar caracteres graficados
- Cambio de color de caracter
- Cambio de caracteer para graficar
- Escribir en pantalla
- Leer ingreso de texto y número del usuario
- Imprimir controles
- Solicitar la información para graficar las figuras geometricas
- Solicitar la información para guardar y abrir archivos
- Obtener tamaño de la pantalla

## Figuras Geometricas

En la carpeta Sources>FiguraGeometrica se encuentran todas las clases de figuras geometricas, estas reciben como parametro una estructura que representa la figura geometrica con sus respectivas propiedades y cuenta con un procedimiento que imprime en pantalla la figura geometrica en base a las propiedades recibidas mediante la estructura.

## Gestión de archivos

En la carpeta Sources se encuentra la clase GestionArchivo, esta clase contiene los procedimientos para:
- Crear archivo
- Escribir en archivo
- Exportar
- Leer archivo

Siendo importante la lectura de archivo, ya que es una función que retorna una nueva lista de posiciones de pantalla para que sean graficadas.
