/*
 *  GRAFO.h - definicion de la clase GRAFO
 *
 *  Autor : Adrián González Galván del Grupo 2 de Tarde.
 *  Curso 2019-2020
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
	int      c; // atributo para expresar el peso, la longitud, el coste, la inversion, etc..., esto es, lo que me implica que ese arco o arista forme parte de la solucion
} ElementoLista;

// definicion del tipo de una lista de adyacencia de un nodo

typedef vector<ElementoLista> LA_nodo;


class GRAFO
 {
	unsigned            n;         /* numero de NODOS */
	unsigned            m;         /* numero de ARCOS */
	unsigned   			dirigido;  /* 0 si el grafo es no dirigido y 1 si es dirigido */
	vector<LA_nodo>     LS;        /* Lista de adyacencia de los sucesores: es una matriz dode cada fila posiblemente es posiblemente de distinto tamaño*/
	vector<LA_nodo>     LP;        /* Lista de adyacencia de los predecesores: es una matriz dode cada fila posiblemente es posiblemente de distinto tamaño*/
 public:
     GRAFO(char nombrefichero[], int &errorapertura); // HECHO
     void actualizar (char nombrefichero[], int &errorapertura); //HECHO
     unsigned Es_dirigido();   /*devuelve 0 si el grafo es no dirigido y 1 si es dirigido*/ //HECHO
     void Info_Grafo(); //HECHO
     void Mostrar_Listas(int l); //HECHO
     void ListaPredecesores(); //HECHO
     void ComponentesConexas(); //HECHO
     void dfs(unsigned i, vector<bool> &visitado); //HECHO
     void Kruskal();
     ~GRAFO(); //HECHO
};

 /* El algoritmo de Kruskal no usa la adyacencia pesada para su ejecución, sino que precisa de una lista ordenada de aristas: la creamos*/
typedef struct {
        unsigned extremo1, extremo2;
        int peso;
    } AristaPesada;

#endif
