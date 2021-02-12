/*************************************************
 * Se dispone de la siguiente información sobre material fungible:
código, nombre y precio.

* Dado que el precio de los materiales almacenados en la base de datos no se ha actualizado en varios años, hay que aplicar:
- Un incremento de 35% a aquellos materiales cuyo precio sea inferior a 30 €.
- Un incremento de 20% a aquellos con precios comprendidos entre 30 € y 80 € ([30, 80)).
- Un incremento de un 12% para los de precios entre 80 € y 200 € ([80, 200)).
- Y finalmente los materiales de precio superior o igual a 200 € quedarán con el mismo precio.
 
* Se pide implementar un programa en C que haciendo uso de las estructuras de control iterativas solicite al usuario la información para 3 materiales y, a continuación muestre los datos de dichos materiales con los precios actualizados.

*Modificación: Mostrar por pantalla la media de esos precios.

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

int i;


int main(void) {

for(i=0;i<=2;i++){
       printf("Introduzca el nombre del material %d: ", i);
       scanf("%s", datos[i].nombre);
       printf("Introduzca el código del material %d :", i);
       scanf("%d", &datos[i].codigo);
       printf("Introduzca el precio del material %d :", i);
       scanf("%f", &datos[i].precio);
       if(datos[i].precio<30.0){
       datos[i].incremento=0.35*datos[i].precio;
       datos[i].precio=datos[i].incremento+datos[i].precio;
       }else if ((datos[i].precio>=30.0)&&(datos[i].precio<80.0)){
       datos[i].incremento=0.2*datos[i].precio;
       datos[i].precio=datos[i].incremento+datos[i].precio;
       }else if ((datos[i].precio>=80.0)&&(datos[i].precio<200.0)){
       datos[i].incremento=0.12*datos[i].precio;
       datos[i].precio=datos[i].incremento+datos[i].precio;
       }else{
       datos[i].incremento=0.0;
       datos[i].precio=datos[i].incremento+datos[i].precio; 
       }
       printf("El material %d llamado %s tiene un precio de %f euros. Su código es %d.\n\n", i, datos[i].nombre, datos[i].precio, datos[i].codigo);
       
}
 
}
