/*
 *  GRAFO.h - definicion de la clase GRAFO
 *
 *  Autor : Antonio Sedeno Noda, Sergio Alonso
 *  Curso 2012-2017
 */

#ifndef _GRAPH_H
#define _GRAPH_H


#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

//Solo funciona en ciertos entornos
//#define gotoxy(x,y)  printf("\33[%d;%dH",y,x)
//#define clrscr()     gotoxy(1,1); printf("\33[2J")

const unsigned UERROR = 65000;
const int maxint = 1000000;

// definicion de un elemento de la lista de adyacencia

typedef struct
{
	unsigned j; // nodo
	int      c; // atributo para expresar el peso, la longitud, el coste, la inversión, etc...
} ElementoLista;

// definicion del tipo de una lista de adyacencia de un nodo

typedef vector<ElementoLista> LA_nodo;

 /* El algoritmo de Kruskal no usa la adyacencia pesada para su ejecución, sino que precisa de una lista ordenada de aristas: la creamos*/
typedef struct {
        unsigned extremo1, extremo2;
        int peso;
    } AristaPesada;

class GRAFO
 {
	unsigned            dirigido;  //0 si el grafo es no dirigido y 1 si es dirigido
	unsigned            n;         /* numero de NODOS */
	unsigned            m;         /* numero de ARCOS */
	vector<LA_nodo>     LS;        /* Lista de adyacencia de los sucesores: es una matriz dode cada fila posiblemente es posiblemente de distinto tamao*/
	vector<LA_nodo>     LP;        /* Lista de adyacencia de los predecesores: es una matriz dode cada fila posiblemente es posiblemente de distinto tamao*/
        void MostrarCamino(unsigned, unsigned, vector<unsigned>); /*función privada para mostrar caminos a la que accedera el algoritmo de Dijkstra*/
 public:
     GRAFO(char nombrefichero[], int &errorapertura);
     void actualizar (char nombrefichero[], int &errorapertura);
     unsigned Es_dirigido(); // devuelve 0 si el grafo es no dirigido y 1 si es dirigido
     void Info_Grafo();
     void Mostrar_Listas(int l);
     void ListaPredecesores();
     void ComponentesConexas();
     void dfs(unsigned i, vector<bool> &visitado);
     void Dijkstra();
     void Kruskal();
     ~GRAFO();
};


#endif
