/*************************************************
 * En una sucursal bancaria, los datos asociados a una cuenta bancaria son: número de cuenta y saldo. Cada cliente de la sucursal dispone de 2 cuentas, siendo los datos del cliente: dni, nombre y sus 2 cuentas.
* Escribir un programa es C que pida por pantalla los datos para 3 clientes y a continuación escriba para cada cliente sus datos junto con su saldo total.
 * Autor: Adrián Glez Galván
 * Fecha: 7.Noviembre.2019
*************************************************/

#include <stdio.h>

typedef struct{
int ndecuenta;
float saldo;
} Cuenta;

typedef struct{
char nombre[100];
char dni[100];
Cuenta cuentadoble[2];
float saldototal;
} T;

T datos[3];

int main(void) {

printf("Introduzca el nombre del primer cliente:\n");
       scanf("%s", datos[0].nombre);
       printf("Introduzca el DNI del primer cliente:\n");
       scanf("%s", datos[0].dni);
       printf("Introduzca el número de su primera cuenta:\n");
       scanf("%d", &datos[0].cuentadoble[0].ndecuenta);
       printf("Introduzca el saldo de su primera cuenta:\n");
       scanf("%f", &datos[0].cuentadoble[0].saldo);
       printf("Introduzca el número de su segunda cuenta:\n");
       scanf("%d", &datos[0].cuentadoble[1].ndecuenta);
       printf("Introduzca el saldo de su segunda cuenta:\n");
       scanf("%f", &datos[0].cuentadoble[1].saldo);
       datos[0].saldototal = datos[0].cuentadoble[0].saldo + datos[0].cuentadoble[1].saldo;

printf("Introduzca el nombre del segundo cliente:\n");
       scanf("%s", datos[1].nombre);
       printf("Introduzca el DNI del segundo cliente:\n");
       scanf("%s", datos[1].dni);
       printf("Introduzca el número de su primera cuenta:\n");
       scanf("%d", &datos[1].cuentadoble[0].ndecuenta);
       printf("Introduzca el saldo de su primera cuenta:\n");
       scanf("%f", &datos[1].cuentadoble[0].saldo);
       printf("Introduzca el número de su segunda cuenta:\n");
       scanf("%d", &datos[1].cuentadoble[1].ndecuenta);
       printf("Introduzca el saldo de su segunda cuenta:\n");
       scanf("%f", &datos[1].cuentadoble[1].saldo);
       datos[1].saldototal = datos[1].cuentadoble[0].saldo + datos[1].cuentadoble[1].saldo;

printf("Introduzca el nombre del tercer cliente:\n");
       scanf("%s", datos[2].nombre);
       printf("Introduzca el DNI del tercer cliente:\n");
       scanf("%s", datos[2].dni);
       printf("Introduzca el número de su primera cuenta:\n");
       scanf("%d", &datos[2].cuentadoble[0].ndecuenta);
       printf("Introduzca el saldo de su primera cuenta:\n");
       scanf("%f", &datos[2].cuentadoble[0].saldo);
       printf("Introduzca el número de su segunda cuenta:\n");
       scanf("%d", &datos[2].cuentadoble[1].ndecuenta);
       printf("Introduzca el saldo de su segunda cuenta:\n\n");
       scanf("%f", &datos[2].cuentadoble[1].saldo);
       datos[2].saldototal = datos[2].cuentadoble[0].saldo + datos[2].cuentadoble[1].saldo;


printf("El cliente %s, con DNI: %s tiene un saldo en su primera cuenta con número %d de %f euros y un saldo en su segunda con número %d de %f euros. En resumen, posee un saldo total de %f euros.\n\n", datos[0].nombre, datos[0].dni, datos[0].cuentadoble[0].ndecuenta, datos[0].cuentadoble[0].saldo, datos[0].cuentadoble[1].ndecuenta, datos[0].cuentadoble[1].saldo, datos[0].saldototal); 

printf("El cliente %s, con DNI: %s tiene un saldo en su primera cuenta con número %d de %f euros y un saldo en su segunda con número %d de %f euros. En resumen, posee un saldo total de %f euros.\n\n", datos[1].nombre, datos[1].dni, datos[1].cuentadoble[0].ndecuenta, datos[1].cuentadoble[0].saldo, datos[1].cuentadoble[1].ndecuenta, datos[1].cuentadoble[1].saldo, datos[1].saldototal); 

printf("El cliente %s, con DNI: %s tiene un saldo en su primera cuenta con número %d de %f euros y un saldo en su segunda con número %d de %f euros. En resumen, posee un saldo total de %f euros.\n\n", datos[2].nombre, datos[2].dni, datos[2].cuentadoble[0].ndecuenta, datos[2].cuentadoble[0].saldo, datos[2].cuentadoble[1].ndecuenta, datos[2].cuentadoble[1].saldo, datos[2].saldototal); 


}
