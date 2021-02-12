/*************************************************
 * En una sucursal bancaria, los datos asociados a una cuenta bancaria son: número de cuenta y saldo.
* Cada cliente de la sucursal dispone de 2 cuentas, siendo los datos del cliente: dni, nombre y sus 2 cuentas.

*Escribir un programa en C que pida por pantalla los datos para 3 clientes y a continuación escriba para cada cliente:
- Sus datos (dni y nombre) junto con su saldo total si este es positivo.
- Y sus datos (dni y nombre) junto a un mensaje que indique que el cliente no tiene permiso de extracción en el caso de saldo total negativo.

* Además, para cada cliente se debe mostrar los datos de las cuentas en las que tiene saldo negativo.

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
Cuenta cuentas[2];
float saldototal;
} T;

T datos[3];
int i, j;

int main(void) {

for(i=0;i<=2;i++){			
       printf("Introduzca el nombre del cliente %d:", i);
       scanf("%s", datos[i].nombre);
       printf("Su DNI:");
       scanf("%s", datos[i].dni);
for(j=0;j<=1;j++){
       printf("Introduzca el número de su cuenta %d:", j);
       scanf("%d", &datos[i].cuentas[j].ndecuenta);
       printf("Introduzca el saldo de su cuenta %d:", j);
       scanf("%f", &datos[i].cuentas[j].saldo);
       }
       datos[i].saldototal = datos[i].cuentas[0].saldo + datos[i].cuentas[1].saldo;
       if(datos[i].saldototal>=0){
       printf("Usted, con nombre %s y DNI: %s, tiene un saldo total de %f euros.\n\n", datos[i].nombre, datos[i].dni, datos[i].saldototal);
       }else{
       printf("Usted, con nombre %s y con DNI: %s, no tiene permiso de extracción.", datos[i].nombre, datos[i].dni);
       if ((datos[i].cuentas[0].saldo<0)&&(datos[i].cuentas[1].saldo>=0)){
       printf(" Esto se debe a que posee un saldo negativo de %f euros en su primera cuenta, cuyo número es %d.\n\n", datos[i].cuentas[0].saldo, datos[i].cuentas[0].ndecuenta);
}else if ((datos[i].cuentas[1].saldo<0)&&(datos[i].cuentas[0].saldo>=0)){
       printf(" Esto se debe a que posee un saldo negativo de %f euros en su segunda cuenta, cuyo número es %d.\n\n", datos[i].cuentas[1].saldo, datos[i].cuentas[1].ndecuenta);
}else{
printf(" Esto se debe a que posee un saldo negativo en ambas cuentas:En su primera cuenta, cuyo número es %d, tiene un saldo negativo de %f euros; y en su segunda cuenta, cuyo número es %d, tiene otro saldo negativo de %f euros.\n\n", datos[i].cuentas[0].ndecuenta, datos[i].cuentas[0].saldo, datos[i].cuentas[1].ndecuenta, datos[i].cuentas[1].saldo);
}
}
}
}
