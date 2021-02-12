/*************************************************
 * Escribir un programa que solicite el radio de una circunferencia y muestre en pantalla la longitud de la circunferencia y el área del círculo para ese radio.
 * Autor: Adrián Glez Galván
 * Fecha: 31.Octubre.2019
*************************************************/

#include <stdio.h>

float radio;
float longitud_circunferencia;
float area_circunferencia;

int main(void) {
       printf("Introduzca el radio de la circunferencia: ");
       scanf("%f", &radio);
longitud_circunferencia = 2.0*3.14159*radio;
area_circunferencia = 3.14159*radio*radio;
       printf("La longitud de la circunferencia es : %f\n", longitud_circunferencia);
       printf("El área de la circunferencia es : %f\n", area_circunferencia);
 
}

