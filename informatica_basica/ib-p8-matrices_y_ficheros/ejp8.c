/************************************************************************

* Escribir un programa que lee dos matrices A y B de tamaño 3x3 desde un fichero. A continuación debe mostrarlas en pantalla. Además debe realizar los siguientes cálculos:

a) La suma de A y B y almacenarla en el fichero Resultados.txt

b) La suma de cada una de las filas de la matriz A y almacenarla en el fichero
Resultados.txt

c) El valor mínimo de la diagonal principal de la matriz B y almacenarlo en el
fichero Resultados.txt

d)Mostrar por pantalla la media de sumar todos los números impares de la matriz A.

************************************************************************/

#include <stdio.h>

char nombre[20];
FILE *fn1;
FILE *fn2;

int z, i, j, A[3][3], B[3][3], C[3][3], valorminimo, n;
float suma;


int main (void){
printf("\nIntroduce el nombre del fichero donde se guardan las matrices 3x3: ");
scanf("%s", nombre);
fn1 = fopen(nombre, "r");	
if(fn1!=NULL){


printf("Para la matriz A tenemos que:\n\n");
for(i=0;i<=2;i++){
for(j=0;j<=2;j++){                                                                          
fscanf(fn1, "%d", &A[i][j]);	
printf("La posición (%d,%d)=%d\n", i, j, A[i][j]);
                                                                      
}
printf("\n");
}
printf("\n");
}
printf("Para la matriz B tenemos que:\n\n");
for(i=0;i<=2;i++){
for(j=0;j<=2;j++){                                                                          
fscanf(fn1, "%d", &B[i][j]);	
printf("La posición (%d,%d)=%d\n", i, j, B[i][j]);
                                                                      
}
printf("\n");
}
printf("\n");

fn2= fopen("resultados.txt", "w");
if(fn2!=NULL){
fprintf(fn2,"La suma de las 2 matrices da:\n\n");
for(i=0;i<=2;i++){
for(j=0;j<=2;j++){ 
C[i][j]=A[i][j]+B[i][j];
fprintf(fn2,"%d", C[i][j]);
}
fprintf(fn2,"\n");
}
fprintf(fn2,"\n\n");
}
fprintf(fn2,"La suma de cada uno de los elementos de cada fila de la matriz A da:\n\n");
for(i=0;i<=2;i++){
fprintf(fn2,"%d", A[i][0]+A[i][1]+A[i][2]);
fprintf(fn2,"\n");
}

fprintf(fn2,"\n\n");
fprintf(fn2,"El valor mínimo de la diagonal principal de la matriz B es:\n\n");
valorminimo=B[0][0];
if(valorminimo>B[1][1]){
valorminimo=B[1][1];
}else if(valorminimo>B[2][2]){
valorminimo=B[2][2];
}else{
}
fprintf(fn2,"%d",valorminimo);


for(i=0;i<=2;i++){
for(j=0;j<=2;j++){
if((A[i][j]%2)!=0){
suma = suma+A[i][j];
n++;
}
}
}

printf("\nLa media de los números impares de la matriz A es %f.\n\n", suma/n);

fclose(fn1);
fclose(fn2);



}





