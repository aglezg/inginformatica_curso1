/*****************************************************
 *
 * Segundo ejemplo de programa escrito en C:
 * Calcula el doble de un número que se pide por teclado
 *
 * Autora: Adrian Glez Galvan alu0101321219
 * Fecha: 17.Octubre.2019  
 *
**********************************************************/

#include <stdio.h>

int numero; 	/* Variable que contendrá el número a doblar */

/* Función 'main': función principal del programa. En este punto
 * comienza la ejecución. */
int main(void) {
   printf("Introduzca el número que quiera doblar: ");
   scanf("%d", &numero);
   
   numero = numero * 2;

   printf("El doble del número es : %d\n", numero);
} 


