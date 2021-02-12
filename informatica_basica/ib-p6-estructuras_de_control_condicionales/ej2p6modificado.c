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

int main(void) {

printf("Introduzca el nombre del primer cliente:\n");
       scanf("%s", datos[0].nombre);
       printf("Introduzca el DNI del primer cliente:\n");
       scanf("%s", datos[0].dni);
       printf("Introduzca el número de su primera cuenta:\n");
       scanf("%d", &datos[0].cuentas[0].ndecuenta);
       printf("Introduzca el saldo de su primera cuenta:\n");
       scanf("%f", &datos[0].cuentas[0].saldo);
       printf("Introduzca el número de su segunda cuenta:\n");
       scanf("%d", &datos[0].cuentas[1].ndecuenta);
       printf("Introduzca el saldo de su segunda cuenta:\n");
       scanf("%f", &datos[0].cuentas[1].saldo);
       datos[0].saldototal = datos[0].cuentas[0].saldo + datos[0].cuentas[1].saldo;
       if(datos[0].saldototal>=0){
       printf("Usted, con nombre %s y DNI: %s, tiene un saldo total de %f euros\n\n", datos[0].nombre, datos[0].dni, datos[0].saldototal);
       }else{
       printf("Usted, con nombre %s y con DNI: %s, no tiene permiso de extracción\n\n", datos[0].nombre, datos[0].dni);
       if ((datos[0].cuentas[0].saldo<0)&&(datos[0].cuentas[1].saldo>=0)){
       printf("Esto se debe a que posee un saldo negativo de %f euros en su primera cuenta, cuyo número es %d.\n\n", datos[0].cuentas[0].saldo, datos[0].cuentas[0].ndecuenta);
}else if ((datos[0].cuentas[1].saldo<0)&&(datos[0].cuentas[0].saldo>=0)){
       printf("Esto se debe a que posee un saldo negativo de %f euros en su segunda cuenta, cuyo número es %d.\n\n", datos[0].cuentas[1].saldo, datos[0].cuentas[1].ndecuenta);
}else{
printf("Esto se debe a que posee un saldo negativo en ambas cuentas:En su primera cuenta, cuyo número es %d, tiene un saldo negativo de %f euros; y en su segunda cuenta, cuyo número es %d, tiene otro saldo negativo de %f euros.\n\n", datos[0].cuentas[0].ndecuenta, datos[0].cuentas[0].saldo, datos[0].cuentas[1].ndecuenta, datos[0].cuentas[1].saldo);
}
}
if((datos[0].cuentas[0].saldo<0)&&(datos[0].cuentas[1].saldo>(datos[0].cuentas[0].saldo*(-1)))){
datos[0].cuentas[0].saldo= datos[0].cuentas[0].saldo+datos[0].cuentas[1].saldo;
datos[0].cuentas[1].saldo=0;
printf("Hemos pasado el dinero de su cuenta 2 a la cuenta 1 con tal de que no poseas saldo negativo en ninguna de ellas. Su saldo en la cuenta 1 es ahora de %f euros y su saldo en la cuenta 2 es ahora de %f euros.\n", datos[0].cuentas[0].saldo, datos[0].cuentas[1].saldo);
}

       
printf("Introduzca el nombre del segundo cliente:\n");
       scanf("%s", datos[1].nombre);
       printf("Introduzca el DNI del segundo cliente:\n");
       scanf("%s", datos[1].dni);
       printf("Introduzca el número de su primera cuenta:\n");
       scanf("%d", &datos[1].cuentas[0].ndecuenta);
       printf("Introduzca el saldo de su primera cuenta:\n");
       scanf("%f", &datos[1].cuentas[0].saldo);
       printf("Introduzca el número de su segunda cuenta:\n");
       scanf("%d", &datos[1].cuentas[1].ndecuenta);
       printf("Introduzca el saldo de su segunda cuenta:\n");
       scanf("%f", &datos[1].cuentas[1].saldo);
       datos[1].saldototal = datos[1].cuentas[0].saldo + datos[1].cuentas[1].saldo;
       if(datos[1].saldototal>=0){
       printf("Usted, con nombre %s y DNI: %s, tiene un saldo total de %f euros\n\n", datos[1].nombre, datos[1].dni, datos[1].saldototal);
       }else{
       printf("Usted, con nombre %s y con DNI: %s, no tiene permiso de extracción\n\n", datos[1].nombre, datos[1].dni);
       if ((datos[1].cuentas[0].saldo<0)&&(datos[1].cuentas[1].saldo>=0)){
       printf("Esto se debe a que posee un saldo negativo de %f euros en su primera cuenta, cuyo número es %d.\n\n", datos[1].cuentas[0].saldo, datos[1].cuentas[0].ndecuenta);
}else if ((datos[1].cuentas[1].saldo<0)&&(datos[1].cuentas[0].saldo>=0)){
       printf("Esto se debe a que posee un saldo negativo de %f euros en su segunda cuenta, cuyo número es %d.\n\n", datos[1].cuentas[1].saldo, datos[1].cuentas[1].ndecuenta);
}else{
printf("Esto se debe a que posee un saldo negativo en ambas cuentas:En su primera cuenta, cuyo número es %d, tiene un saldo negativo de %f euros; y en su segunda cuenta, cuyo número es %d, tiene otro saldo negativo de %f euros.\n\n", datos[1].cuentas[0].ndecuenta, datos[1].cuentas[0].saldo, datos[1].cuentas[1].ndecuenta, datos[1].cuentas[1].saldo);
}
}

printf("Introduzca el nombre del tercer cliente:\n");
       scanf("%s", datos[2].nombre);
       printf("Introduzca el DNI del tercer cliente:\n");
       scanf("%s", datos[2].dni);
       printf("Introduzca el número de su primera cuenta:\n");
       scanf("%d", &datos[2].cuentas[0].ndecuenta);
       printf("Introduzca el saldo de su primera cuenta:\n");
       scanf("%f", &datos[2].cuentas[0].saldo);
       printf("Introduzca el número de su segunda cuenta:\n");
       scanf("%d", &datos[2].cuentas[1].ndecuenta);
       printf("Introduzca el saldo de su segunda cuenta:\n");
       scanf("%f", &datos[2].cuentas[1].saldo);
       datos[2].saldototal = datos[2].cuentas[0].saldo + datos[2].cuentas[1].saldo;
       if(datos[2].saldototal>=0){
       printf("Usted, con nombre %s y DNI: %s, tiene un saldo total de %f euros\n\n", datos[2].nombre, datos[2].dni, datos[2].saldototal);
       }else{
       printf("Usted, con nombre %s y con DNI: %s, no tiene permiso de extracción\n\n", datos[2].nombre, datos[2].dni);
       if ((datos[2].cuentas[0].saldo<0)&&(datos[2].cuentas[1].saldo>=0)){
       printf("Esto se debe a que posee un saldo negativo de %f euros en su primera cuenta, cuyo número es %d.\n\n", datos[2].cuentas[0].saldo, datos[2].cuentas[0].ndecuenta);
}else if ((datos[2].cuentas[1].saldo<0)&&(datos[2].cuentas[0].saldo>=0)){
       printf("Esto se debe a que posee un saldo negativo de %f euros en su segunda cuenta, cuyo número es %d.\n\n", datos[2].cuentas[1].saldo, datos[2].cuentas[1].ndecuenta);
}else{
printf("Esto se debe a que posee un saldo negativo en ambas cuentas:En su primera cuenta, cuyo número es %d, tiene un saldo negativo de %f euros; y en su segunda cuenta, cuyo número es %d, tiene otro saldo negativo de %f euros.\n\n", datos[2].cuentas[0].ndecuenta, datos[2].cuentas[0].saldo, datos[2].cuentas[1].ndecuenta, datos[2].cuentas[1].saldo);
}
}

}

