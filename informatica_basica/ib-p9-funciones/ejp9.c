/******************************************************************************

Se necesitan, al menos, las siguientes funciones básicas:

a) Leer una matriz desde un fichero
b) Mostrar una matriz en pantalla
c) Calcular la transpuesta de una matriz
d) Obtener el valor máximo en una fila que indique el usuario para una matriz
concreta
e) Calcular la media aritmética de los elementos de la diagonal secundaria de una
matriz
f) Calcular el producto de dos matrices
g) Menú con las opciones anteriores

Escribir un programa en lenguaje C, que haciendo uso de las llamadas a
las funciones básicas, mencionadas anteriormente, muestre al usuario un menú en
pantalla para realizar las siguientes tareas con las matrices A y B de tamaño 3x3.

1.Mostrar en pantalla las matrices A y B.                                     (Hecho)
2.Mostrar la matriz transpuesta de A y de B.                                  (Hecho)
3.Máximo en una fila de A y máximo en la misma fila para B.                   (Hecho)
4.Medias aritméticas de los elementos de la diagonal secundaria de A y de B.  (Hecho)
5.Mostrar los productos AxB y BxA.                                            (Hecho)
6.Salir del programa.                                                         (Hecho)

Modificación: Saber que fila de la matriz A tiene la mayor media.


*Autor del programa: Adrián González Galván
*Grupo: 2, horario de tarde.
*Fecha: 19/12/2019

***********************************************************************************/

#include <stdio.h>
int opcion;
void menu (void);
void leer_matrices(int a[3][3], int b[3][3]);
void leer_matriz(int a[3][3], char nombre_fichero[30]);
int A[3][3], B[3][3], resultante[3][3];
void mostrar_matriz(int a[3][3], char nombre_matriz[20]);
void traspuesta(int a[3][3]);
int maximo_fila(int fil, int a[3][3]);
int fila;
float media_diagonal_secundaria(int a[3][3], int n);
void producto(int a[3][3], int b[3][3]);

int main (void) {
do{
menu();
}while(opcion!=7);
return 0;
}



/* Función menú *********************************************************************/

void menu (void) {
int x, sumafila[3];
int divisor;
float media[3];

printf ("1.- Mostrar las matrices A y B.\n");
printf ("2.- Mostrar las matrices traspuestas de A y de B.\n");
printf("3.- Mostrar el maxímo de una fila de la matriz A y máxímo en la misma fila de la matriz B\n");
printf("4.- Mostrar las medias aritméticas de los elementos de la diagonal secundaria de las matrices A y B\n");
printf("5.- Mostrar los productos de AxB y de BxA\n");
printf("6.- Hallar que fila de la matriz A tiene la mayor media\n");
printf("7.- Salir\n\n");
printf("Introduzca opcion:");
scanf("%d", &opcion);
printf("\n");
switch(opcion){

case 1:
leer_matriz(A, "MatrizA.txt");
mostrar_matriz(A, "A");
leer_matriz(B, "MatrizB.txt");
mostrar_matriz(B, "B");
break;

case 2:

leer_matriz(A, "MatrizA.txt");
traspuesta(A);
mostrar_matriz(A, "A");

leer_matriz(B, "MatrizB.txt");
traspuesta(B);
mostrar_matriz(B, "B");
break;

case 3:
printf("Introduzca la fila donde quiera calcular el máximo:");
scanf("%d", &fila);

leer_matriz(A, "MatrizA.txt");
printf("\nEl máximo para la matriz A es %d.\n\n", maximo_fila(fila, A));

leer_matriz(B, "MatrizB.txt");
printf("El máximo para la matriz B es %d.\n\n", maximo_fila(fila, B));
break;

case 4:

leer_matriz(A, "MatrizA.txt");
printf("La media de la diagonal secundaria para la matriz A es %f.\n\n",media_diagonal_secundaria(A, 3));

leer_matriz(B, "MatrizB.txt");
printf("La media de la diagonal secundaria para la matriz B es %f.\n\n",media_diagonal_secundaria(B, 3));

break;

case 5:

leer_matriz(A, "MatrizA.txt");
leer_matriz(B, "MatrizB.txt");
producto(A, B);
mostrar_matriz(A, "AxB");

leer_matriz(A, "MatrizA.txt");
leer_matriz(B, "MatrizB.txt");
producto(B, A);
mostrar_matriz(B, "BxA");

break;

case 6:
leer_matriz(A, "MatrizA.txt");

divisor=0;	
sumafila[0]=0;
sumafila[1]=0;
sumafila[2]=0;

for(x=0;x<=2;x++){
sumafila[0] = sumafila[0]+ A[0][x];
divisor++;
}
for(x=0;x<=2;x++){
sumafila[1] = sumafila[1]+ A[1][x];
}
for(x=0;x<=2;x++){
sumafila[2] = sumafila[2] + A[2][x];
}
for(x=0;x<=2;x++){
media[x]=sumafila[x]/divisor;
}
if(((media[0])>=(media[1]))&&((media[0])>=(media[2]))){
printf("La primera fila con una media de %f es la que posee mayor valor de media.\n\n",media[0]);
}
if(((media[1])>=(media[0]))&&((media[1])>=(media[2]))){
printf("La segunda fila con una media de %f es la mayor.\n\n", media[1]);
}
if(((media[2])>=(media[0]))&&((media[2])>=(media[1]))){
printf("La tercera fila con una media de %f es la mayor.\n\n", media[2]);
}

break;


case 7:
break;



default:
printf("La opción que ingresó es incorrecta\n\n");
break;

}
}

/* Función para leer una matriz 3x3 ***************************************************/


void leer_matriz(int a[3][3], char nombre_fichero[30]){
FILE *fn1;
int i, j;
fn1=fopen(nombre_fichero, "r");
if(fn1!=NULL){

for(i=0;i<=2;i++){
  for(j=0;j<=2;j++){                                                                          
  fscanf(fn1, "%d", &a[i][j]);	
}
}
}
fclose(fn1);
}

/* Función para mostrar una matriz 3x3************************************************/

void mostrar_matriz(int a[3][3], char nombre_matriz[20]){
int i, j;
printf("Para la matriz %s tenemos que:\n\n", nombre_matriz); 
for(i=0;i<=2;i++){
  for(j=0;j<=2;j++){                                                                         	
  printf("La posición (%d,%d)=%d\n", i, j, a[i][j]);                                                                 
}
printf("\n");
}
printf("\n");
}


/* Función para calcular la traspuesta de una matriz 3x3*********************************************/

void traspuesta(int a[3][3]){

int i, j, traspuesta[3][3];

for(i=0;i<=2;i++){
  for(j=0;j<=2;j++){                                                                          	
  traspuesta[j][i]=a[i][j];                                                               
}
}
for(i=0;i<=2;i++){
  for(j=0;j<=2;j++){                                                                          	
  a[i][j]=traspuesta[i][j];
}
}

}

/* Función para obtener el valor máximo en una fila que indique el usuario para una matriz concreta ****/

int maximo_fila(int fil, int a[3][3]){
int maximo;

maximo= a[fil][0];

if(maximo<a[fil][1]){
maximo = a[fil][1];
}

if(maximo<a[fil][2]){
maximo = a[fil][2];
}

return maximo;
}

/* Función para calcular la media aritmética de los elementos de la diagonal secundaria de una matriz****/


float media_diagonal_secundaria(int a[3][3], int n){ // n = tamaño de nuestra matriz --> nxn, siendo n=1,n=2...

int i, j;
int suma=0;
float media;

for(i=0;i<=2;i++){
  for(j=0;j<=2;j++){ 

if((i+j)==(n-1)){
suma=suma + a[i][j];
}

}
}

media= suma/n;
return media;
}

/* Función para calcular el producto de 2 matrices*******************************************************/

void producto(int a[3][3], int b[3][3]){ 

int i, j;
int c[3][3];

for(i=0;i<=2;i++){
  for(j=0;j<=2;j++){
c[i][j]= (a[i][0]*b[0][j]) + (a[i][1]*b[1][j]) + (a[i][2]*b[2][j]);
}
}
for(i=0;i<=2;i++){
  for(j=0;j<=2;j++){
a[i][j]= c[i][j];
}
}
}








