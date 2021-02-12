/***************************************************
*Pedir 2 numeros por teclados: Poner 1 por pantalla si el primero es mayor que el segundo, en caso contrario mostrar un 0
*Autor: Adrián Glez Galván
*Fecha: 31 de octubre de 2019
****************************************************/

#include <stdio.h>

int n1;
int n2;
int resultado;

int main(void){
printf("Introduzca el primer número que quiera comparar:\n");
scanf("%d", &n1);
printf("Introduzca el segundo número que quiera comparar:\n");
scanf("%d", &n2);
resultado = (n1 > n2);
printf("El resultado de la comparación es %d\n", resultado);
}
