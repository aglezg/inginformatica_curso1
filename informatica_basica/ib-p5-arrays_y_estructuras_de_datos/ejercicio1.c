/*************************************************
 * Se dispone de la siguiente información sobre material fungible:
código, nombre y precio. Dado que el precio no se ha actualizado en varios años,hay que aplicar un incremento de 15% a cada uno de los precios del material almacenado en la base de datos.
* Se pide implementar un programa en C que haciendo uso de los tipos de datos compuestos solicite al usuario la información para 3 materiales y, a continuación muestre los datos de dichos materiales con los precios actualizados.
 * Autor: Adrián Glez Galván
 * Fecha: 7.Noviembre.2019
*************************************************/

#include <stdio.h>

typedef struct{
char nombre[100];
int codigo;
float precio;
float incremento;
} T;

T datos[3];

int main(void) {

printf("Introduzca el nombre del primer material:\n");
       scanf("%s", datos[0].nombre);
       printf("Introduzca el código del primer material:\n");
       scanf("%d", &datos[0].codigo);
       printf("Introduzca el precio del primer material:\n");
       scanf("%f", &datos[0].precio);
       datos[0].incremento = 15.0 * (datos[0].precio)/100.0; 
       datos[0].precio = datos[0].precio + datos[0].incremento;
       
printf("Introduzca el nombre del segundo material:\n");
       scanf("%s", datos[1].nombre);
       printf("Introduzca el código del segundo material:\n");
       scanf("%d", &datos[1].codigo);
       printf("Introduzca el precio del segundo material:\n");
       scanf("%f", &datos[1].precio);
       datos[1].incremento = 15.0 * (datos[1].precio)/100.0; 
       datos[1].precio = datos[1].precio + datos[1].incremento;
       
printf("Introduzca el nombre del tercer material:\n");
       scanf("%s", datos[2].nombre);
       printf("Introduzca el código del tercer material:\n");
       scanf("%d", &datos[2].codigo);
       printf("Introduzca el precio del tercer material:\n");
       scanf("%f", &datos[2].precio);
       datos[2].incremento = 15.0 * (datos[2].precio)/100.0; 
       datos[2].precio = datos[2].precio + datos[2].incremento;

       printf("El primer material llamado %s tiene un precio de %f. Su código es %d.\n", datos[0].nombre, datos[0].precio, datos[0].codigo); 
       printf("El segundo material llamado %s tiene un precio de %f. Su código es %d.\n", datos[1].nombre, datos[1].precio, datos[1].codigo);
       printf("El tercer material llamado %s tiene un precio de %f. Su código es %d.\n", datos[2].nombre, datos[2].precio, datos[2].codigo);

}



