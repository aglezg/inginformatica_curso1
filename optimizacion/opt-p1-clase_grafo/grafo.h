/*
 *  GRAFO.h - definicion de la clase GRAFO
 *
 *  Autor : Antonio Sedeno Noda, Sergio Alonso
 *  Curso 2019-2020
 *  Trabajo realizado por: Adrián González Galván del Grupo 2 de Tarde
 */

#ifndef _GRAPH_H
#define _GRAPH_H


#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
const unsigned UERROR = 65000; 
const int maxint = 1000000;

// definicion de un elemento de la lista de adyacencia

typedef struct
{
	unsigned j; // nodo
	int      c; // atributo para expresar el peso, la longitud, el coste, la inversion, etc...
} ElementoLista;

// definicion del tipo de una lista de adyacencia de un nodo

typedef vector<ElementoLista> LA_nodo; //vector de ElementoLista --> solo nos sirve para un nodo en concreto


class GRAFO
 {
	unsigned             n;         /* numero de NODOS */
	unsigned             m;         /* numero de ARCOS */
	unsigned      dirigido;  /* 0 si el grafo es no dirigido y 1 si es dirigido */
	vector<LA_nodo>     LS;        /* Lista de adyacencia de los sucesores: es una matriz dode cada fila posiblemente es de distinto tamaño*/
	vector<LA_nodo>     LP;        /* Lista de adyacencia de los predecesores: es una matriz dode cada fila posiblemente es de distinto tamaño*/
 public:
     GRAFO(char nombrefichero[], int &errorapertura); //constructor (hecho)
     void actualizar(char nombrefichero[], int &errorapertura); //actualizador (hecho)
     unsigned Es_dirigido();   /*devuelve 0 si el grafo es no dirigido y 1 si es dirigido*/
     void Info_Grafo(); /*muestra por pantalla la información de un grafo*/
     void Mostrar_Listas(int l); //(hecho)
     void ListaPredecesores(); //(hecho)
     void ComponentesConexas(); //(hecho)
     void dfs(unsigned i, vector<bool> &visitado);
     ~GRAFO(); //destructor (hecho)

};

#endif	
