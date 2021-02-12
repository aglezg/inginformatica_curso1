/*************************************************
 * Se dispone de la siguiente información sobre material fungible:
código, nombre y precio.

* Dado que el precio de los materiales almacenados en la base de datos no se ha actualizado en varios años, hay que aplicar:
- Un incremento de 35% a aquellos materiales cuyo precio sea inferior a 30 €.
- Un incremento de 20% a aquellos con precios comprendidos entre 30 € y 80 € ([30, 80)).
- Un incremento de un 12% para los de precios entre 80 € y 200 € ([80, 200)).
- Y finalmente los materiales de precio superior o igual a 200 € quedarán con el mismo precio.
 
* Se pide implementar un programa en C que haciendo uso de las sentencias de control condicionales solicite al usuario la información para 3 materiales y, a continuación muestre los datos de dichos materiales con los precios actualizados.
 * Autor: Adrián Glez Galván
 * Fecha: 14.Noviembre.2019
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
       if(datos[0].precio<30){
       datos[0].incremento=0.35*datos[0].precio;
       datos[0].precio=datos[0].incremento+datos[0].precio;
       }else if ((datos[0].precio>=30)&&(datos[0].precio<80)){
       datos[0].incremento=0.2*datos[0].precio;
       datos[0].precio=datos[0].incremento+datos[0].precio;
       }else if ((datos[0].precio>=80)&&(datos[0].precio<200)){
       datos[0].incremento=0.12*datos[0].precio;
       datos[0].precio=datos[0].incremento+datos[0].precio;
       }else{
       datos[0].incremento=0*datos[0].precio;
       datos[0].precio=datos[0].incremento+datos[0].precio;
       }
       
printf("Introduzca el nombre del segundo material:\n");
       scanf("%s", datos[1].nombre);
       printf("Introduzca el código del segundo material:\n");
       scanf("%d", &datos[1].codigo);
       printf("Introduzca el precio del segundo material:\n");
       scanf("%f", &datos[1].precio);
        if(datos[1].precio<30){
       datos[1].incremento=0.35*datos[1].precio;
       datos[1].precio=datos[1].incremento+datos[1].precio;
       }else if ((datos[1].precio>=30)&&(datos[1].precio<80)){
       datos[1].incremento=0.2*datos[1].precio;
       datos[1].precio=datos[1].incremento+datos[1].precio;
       }else if ((datos[1].precio>=80)&&(datos[1].precio<200)){
       datos[1].incremento=0.12*datos[1].precio;
       datos[1].precio=datos[1].incremento+datos[1].precio;
       }else{
       datos[1].incremento=0*datos[1].precio;
       datos[1].precio=datos[1].incremento+datos[1].precio;
       }
       
printf("Introduzca el nombre del tercer material:\n");
       scanf("%s", datos[2].nombre);
       printf("Introduzca el código del tercer material:\n");
       scanf("%d", &datos[2].codigo);
       printf("Introduzca el precio del tercer material:\n");
       scanf("%f", &datos[2].precio);
        if(datos[2].precio<30){
       datos[2].incremento=0.35*datos[2].precio;
       datos[2].precio=datos[2].incremento+datos[2].precio;
       }else if ((datos[2].precio>=30)&&(datos[2].precio<80)){
       datos[2].incremento=0.2*datos[2].precio;
       datos[2].precio=datos[2].incremento+datos[2].precio;
       }else if ((datos[2].precio>=80)&&(datos[2].precio<200)){
       datos[2].incremento=0.12*datos[2].precio;
       datos[2].precio=datos[2].incremento+datos[2].precio;
       }else{
       datos[2].incremento=0*datos[2].precio;
       datos[2].precio=datos[2].incremento+datos[2].precio;
       }

       printf("El primer material llamado %s tiene un precio de %f. Su código es %d.\n", datos[0].nombre, datos[0].precio, datos[0].codigo); 
       printf("El segundo material llamado %s tiene un precio de %f. Su código es %d.\n", datos[1].nombre, datos[1].precio, datos[1].codigo);
       printf("El tercer material llamado %s tiene un precio de %f. Su código es %d.\n", datos[2].nombre, datos[2].precio, datos[2].codigo);

}
