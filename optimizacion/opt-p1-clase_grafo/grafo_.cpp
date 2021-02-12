 /*
 *  GRAFO.CPP - Implementación de la clase GRAFOS
 *
 *
 *  Autor : Antonio Sedeno Noda, Sergio Alonso
 *  Fecha : 2013-2020
 *  Trabajo realizado por: Adrián González Galván del Grupo 2 de Tarde
 */

#include "grafo.h"

GRAFO::~GRAFO()
{
LS.clear(); //Limpiamos ambas listas
LP.clear();
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura)
{
LS.clear(); //Limpiamos antes de todo la lista de sucesores/adyacencia

ifstream textfile; //copiamos los pasos del constructor:
textfile.open(nombrefichero);

if(textfile.is_open()){ //Si el fichero se abrió correctamente:
textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;

LS.resize(n);

unsigned i, j;
unsigned z=1;

if(Es_dirigido()){ //Si es dirigido

do{
  textfile >> i >> j; //añadimos el arco i-j a la lista de sucesores
  ElementoLista dummy;
  dummy.j= j-1;
  LS[i-1].push_back(dummy);
  z++; 
}while(z<=m);
LP.clear(); //Limpiamos también la lista de predecesores si es que es un grafo dirigido
  
}else{ //Si es NO dirigido
do{
  textfile >> i >> j; //leo un arco
if(i!=j){ //compruebo que no sea un bucle
  ElementoLista dummy;
  dummy.j= j-1;
  LS[i-1].push_back(dummy); //añadimos la arista i-j a la lista de adyacencia
  dummy.j= i-1;
  LS[j-1].push_back(dummy); //debemos añadir también la j-i
}else{ //En caso de que sea un bucle:
  ElementoLista dummy;
  dummy.j = i-1;
  LS[i-1].push_back(dummy);
  }
  z++; 
}while(z<=m);
} //else (cierre)
ListaPredecesores(); //creamos la nueva lista de predecesores
cout << "Fichero cargado correctamente" << endl;
}else{ //si hubo algún problema a la hora de abrir el fichero:
errorapertura=1;
cout<< "Error en la apertura del fichero: revisa nombre y formato"<< endl;
} 


}

void GRAFO::Info_Grafo()
{
    if (dirigido == 1)
    {
        cout << "Grafo dirigido ";
    }
    else
    {
        cout << "Grafo no dirigido ";
    };
    cout << " | nodos " << n << " | ";
    if (dirigido == 1)
    {
        cout << " arcos ";
    }
    else
    {
        cout << "aristas ";
    };
    cout << m << " " << endl;
}

unsigned GRAFO::Es_dirigido()
{
	return dirigido;
}

void Mostrar_Lista(vector<LA_nodo> L) //Objetivo: Mostrar listas LS y LP del tipo vector<LA_nodo> 
{
 for(int i=0; i<L.size(); i++){
 cout << "[" << i+1 << "] : ";
  for(int z=0; z<L[i].size(); z++){
   cout << L[i][z].j+1 << " | ";
} //for z
cout << endl;
} //for i
};

void GRAFO :: Mostrar_Listas (int l)
{

 if(l==(+1)){ //l==+1 --> Lista de sucesores
cout << "Nodos de la lista de sucesores" << endl;
Mostrar_Lista(LS);
}
 if(l==(-1)){ //l==-1 --> Lista de predecesores
cout << "Nodos de la lista de predecesores" << endl;
Mostrar_Lista(LP);
}
 if(l==0){ //l==0 --> Lista de adyacencia
cout << "Nodos de la lista de adyacencia" << endl;
Mostrar_Lista(LS);
}

};

void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
	visitado[i] = true;
    cout << i+1 << ", ";
	for (unsigned j=0;j<LS[i].size();j++)
             if (visitado[LS[i][j].j] == false)
                 dfs(LS[i][j].j, visitado);
}

void GRAFO::ComponentesConexas()
{
unsigned componentesconexas = 0; //declaración de variables
vector<bool> marca(LS.size());

 for(int i=0; i<LS.size(); i++) //inicialización
  marca[i]=false;
int j=0;

 while(j<LS.size()){ //bucle principal
  if(marca[j]==false){ //condición para saber si hemos visitado cada nodo
componentesconexas++;
cout<< "Componente Conexa número " << componentesconexas << " { ";
dfs(j, marca); //dfs desde el nodo 1 (en nuestro caso, el nodo '0')
cout << "}" << endl;
}//if
j++;
}//while

}

void GRAFO::ListaPredecesores()  
{
ElementoLista dummy;
if(Es_dirigido()){ //Nos aseguramos de que sea dirigido
LP.resize(n);//Lo redimensionamos
for(unsigned i=0; i<LS.size(); i++){
 dummy.j=i; //le damos valor al dummy a meter
 for(unsigned z=0; z<LS[i].size(); z++){
  LP[(LS[i][z].j)].push_back(dummy); //para cada elemento de la lista de sucesores, colocamos su correspondiente en la de predecesores
}
}
}//es dirigido

}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) //constructor
{
ifstream textfile;
textfile.open(nombrefichero);

if(textfile.is_open()){ //Si el fichero se abrió correctamente:
textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;

LS.resize(n);

unsigned i, j;
unsigned z=1;

if(Es_dirigido()){ //Si es dirigido

do{
  textfile >> i >> j; //añadimos el arco i-j a la lista de sucesores
  ElementoLista dummy;
  dummy.j= j-1;
  LS[i-1].push_back(dummy);
  z++; 
}while(z<=m);

  
}else{ //Si es NO dirigido
do{
  textfile >> i >> j; //leo un arco
if(i!=j){ //compruebo que no sea un bucle
  ElementoLista dummy;
  dummy.j= j-1;
  LS[i-1].push_back(dummy); //añadimos la arista i-j a la lista de adyacencia
  dummy.j= i-1;
  LS[j-1].push_back(dummy); //debemos añadir también la j-i
}else{ //En caso de que sea un bucle:
  ElementoLista dummy;
  dummy.j = i-1;
  LS[i-1].push_back(dummy);
  }
  z++; 
}while(z<=m);
} //else (cierre)
ListaPredecesores();

}else{ //si hubo algún problema a la hora de abrir el fichero:
errorapertura=1;
} 

} //constructor (cierre)




