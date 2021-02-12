/*************************************************
 * Implementar un programa que solicite dos números por teclado y muestre por pantalla el resultado de sumar y  el de restar dichos números.
 * Autor: Adrián Glez Galván
 * Fecha: 31.Octubre.2019
*************************************************/

#include <stdio.h>

int num1;
int num2;
int resultado1;
int resultado2;

int main(void) {
       printf("Introduzca el primer número: ");
       scanf("%d", &num1);
       printf("Introduzca el segundo número: ");
       scanf("%d", &num2);
resultado1 = num1 + num2;
resultado2 = num1 - num2;
printf("La suma de los números es : %d\n", resultado1);
       printf("La resta de los números es : %d\n", resultado2);
 
}

