 /*
 *  GRAFO.CPP - Implementación de la clase GRAFOS
 *
 *  Autor : Adrián González Galván del Grupo 2 de Tarde.
 *  Fecha : 2013-2020
 */

#include "grafo.h"

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) //constructor__________
{
ifstream textfile;
textfile.open(nombrefichero);

if(textfile.is_open()){ //Si el fichero se abrió correctamente:
textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;

LS.resize(n);

unsigned i, j; //arista i-j
int c; //coste

if(Es_dirigido()){ //Si es dirigido

for(unsigned int k=0; k < m; k++){
  textfile >> i >> j >> c; //añadimos el arco i-j a la lista de sucesores y su coste
  ElementoLista dummy;
  dummy.j= j-1;
  dummy.c= c; 
  LS[i-1].push_back(dummy);

}
  
}else{ //Si es NO dirigido

for(unsigned int k=0; k < m; k++){

  textfile >> i >> j >> c; //leo un arco y su coste

if(i!=j){ //compruebo que no sea un bucle
  ElementoLista dummy;
  dummy.j= j-1;
  dummy.c = c;
  LS[i-1].push_back(dummy); //añadimos la arista i-j a la lista de adyacencia
  dummy.j= i-1;
  LS[j-1].push_back(dummy); //debemos añadir también la j-i

}else{ //En caso de que sea un bucle:
  ElementoLista dummy;
  dummy.j = i-1;
  dummy.c = c;
  LS[i-1].push_back(dummy);
  }

} //for (cierre)

} //else Si es NO dirigido (cierre)

ListaPredecesores(); //solo se creará si el grafo es dirigido

}else{ //si hubo algún problema a la hora de abrir el fichero:
errorapertura=1;
} 

}

GRAFO::~GRAFO() //destructor__________
{
LS.clear(); //Limpiamos ambas listas
LP.clear();
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura) //actualizador__________
{
LS.clear(); //Limpiamos antes de todo la lista de sucesores/adyacencia

ifstream textfile; //copiamos los passos del constructor
textfile.open(nombrefichero);

if(textfile.is_open()){ //Si el fichero se abrió correctamente:
textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;

LS.resize(n);

unsigned i, j;
int c;

if(Es_dirigido()){ //Si es dirigido

for(unsigned int k=0; k < m; k++){
  textfile >> i >> j >> c; 
  ElementoLista dummy;
  dummy.j= j-1;
  dummy.c = c;
  LS[i-1].push_back(dummy);
}
LP.clear(); //Limpiamos también la lista de predecesores si es que es un grafo dirigido
  
}else{ //Si es NO dirigido

for(unsigned int k=0; k < m; k++){

  textfile >> i >> j >> c; //leo un arco y su coste 'c'

if(i!=j){ //compruebo que no sea un bucle
  ElementoLista dummy;
  dummy.j= j-1;
  dummy.c= c;
  LS[i-1].push_back(dummy); //añadimos la arista i-j a la lista de adyacencia
  dummy.j= i-1;
  LS[j-1].push_back(dummy); //debemos añadir también la j-i

}else{ //En caso de que sea un bucle:
  ElementoLista dummy;
  dummy.j = i-1;
  dummy.c = c;
  LS[i-1].push_back(dummy);
  }

} //for (cierre)

} //else Si es NO dirigido (cierre)

ListaPredecesores(); //solo se creará si el grafo es dirigido
cout << "Fichero cargado correctamente" << endl;

}else{ //si hubo algún problema a la hora de abrir el fichero:
errorapertura=1;
cout<< "Error en la apertura del fichero: revisa nombre y formato"<< endl;
} 

}


unsigned GRAFO::Es_dirigido()//__________
{
  return dirigido;
}

void GRAFO::Info_Grafo()//__________
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

void Mostrar_Lista(vector<LA_nodo> L)//__________
{
 for(int i=0; i<L.size(); i++){
 cout << "[" << i+1 << "] - ";
  if(L[i].size() == 0)
   cout << "null";
  for(int z=0; z<L[i].size(); z++){
   cout << L[i][z].j+1 << " : " << L[i][z].c << " | "; //añadimos también la impresión del coste de la arista/arco
} //for z
cout << endl;
} //for i

}


void GRAFO :: Mostrar_Listas (int l)//__________
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

void GRAFO::dfs(unsigned i, vector<bool> &visitado)//__________
{
	visitado[i] = true;
    cout << i+1 << " | ";
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

cout << "Nodos de las componentes conexas:" << endl;

 while(j<LS.size()){ //bucle principal
  if(marca[j]==false){ //condición para saber si hemos visitado cada nodo
componentesconexas++;
cout<< "Componente Conexa numero " << componentesconexas << " : ";
dfs(j, marca); //dfs desde el nodo 1 (en nuestro caso, el nodo '0')
cout << endl;
}//if
j++;
}//while

if(componentesconexas > 1) //si tiene más de 1 componente conexa, mostramos que el grafo NO es conexo
 cout << "El grafo es NO conexo." << endl;

}

void GRAFO::Kruskal()//__________
{

    vector <AristaPesada> Aristas; //vector de "AristaPesada", estructura con "unsigned extremo1,extremo2" y "int peso"

    /*Usaremos la busqueda del menor en cada momento, pues es el mejor para Kruskal que no exige tener todas las aristas ordenadas*/
    /*Cargamos todas las aristas de la lista de adyacencia*/

    Aristas.resize(m);

    unsigned k = 0;
    for (unsigned i = 0; i<n; i++){
        for (unsigned j=0; j<LS[i].size();j++){
            if (i < LS[i][j].j) {
                Aristas[k].extremo1 = i;
                Aristas[k].extremo2 = LS[i][j].j;
                Aristas[k++].peso = LS[i][j].c;
                }
        }
    };
    /*Inicializamos el indice a la cabeza del vector*/
    unsigned head = 0;
    AristaPesada AristaDummy; //Para los intercambios en la ordenacion parcial

    /*Inicializamos el contador de aristas en la solución*/
    unsigned a = 0;

    /*Inicializamos el peso de la solucion*/
    unsigned pesoMST = 0;

    /*Inicializamos el registro de componentes conexas: cada nodo está en su compomente conexa*/
    vector <unsigned> Raiz;
    Raiz.resize(n);
    for (unsigned q = 0;q < n; q++){
        Raiz[q]=q;
    };

 if(Aristas.size() != 0){ //debemos asegurarnos que el grafo contiene aristas
    /*Comenzamos Kruskal*/
    do {
        /* Implementamos el algoritmo de Kruskal */
        
        int mincoste = Aristas[head].peso;
        for(int i = head; i<m; i++)
         if(Aristas[i].peso <= mincoste){ //cambiamos la arista en la posición head por la de menor coste entre las sobrantes (sobrantes = desde head... hasta n-1)
          mincoste = Aristas[i].peso;
          AristaDummy = Aristas[head];
          Aristas[head] = Aristas[i];
          Aristas[i] = AristaDummy;        
         } //tenemos la arista i-esima de menor coste en la posición "head"
        
        if(Raiz[Aristas[head].extremo1] != Raiz[Aristas[head].extremo2]){ //si sus extremos tienen distitas raíces (diferentes componentes conexas):
         int kill = Raiz[Aristas[head].extremo1]; 
          for (unsigned q = 0;q < n; q++)
           if(Raiz[q] == kill)
            Raiz[q] = Raiz[Aristas[head].extremo2]; //todo nodo con "raiz = raiz del extremo1" será cambiada por la "raiz del extremo2"      

        cout << "Arista numero " << a+1 << " incorporada ("<< Aristas[head].extremo1+1 << ", " << Aristas[head].extremo2+1 << "), con peso " << Aristas[head].peso;
        cout << endl; //mostramos la arista incorporada de la forma: "extremo1-extremo2-coste"

        pesoMST += Aristas[head].peso; //actualizamos el peso, añadiéndole la nueva arista incoporada               

        a++; //actualizamos "a" cada vez que se incluya/muestre una arista
        }
        head++; //actualizamos siempre "head" al final del do-while
        } while ((a < (n-1)) && (head < m));

        if (a == (n - 1)){
            cout << "El peso del arbol generador de minimo coste es " << pesoMST << endl;
        }
        else {
            cout << "El grafo no es conexo, y el bosque generador de minimo coste tiene peso " << pesoMST << endl;
        };

  }else //Si el grafo no contiene aristas:
    cout << "El grafo es NO conexo y ademas no posee aristas, por lo que no podemos crear ni siquiera un solo arbol a partir de el mismo." << endl;

}

void GRAFO::ListaPredecesores()//__________
{
ElementoLista dummy;

if(Es_dirigido()){ //Nos aseguramos de que sea dirigido

LP.resize(n);//Lo redimensionamos

for(unsigned i=0; i<LS.size(); i++){
 dummy.j=i; //le damos valor al dummy a meter
 for(unsigned z=0; z<LS[i].size(); z++){
  dummy.c = LS[i][z].c;
  LP[(LS[i][z].j)].push_back(dummy); //para cada elemento de la lista de sucesores, colocamos su correspondiente en la de predecesores
}
}
}//es dirigido

}

