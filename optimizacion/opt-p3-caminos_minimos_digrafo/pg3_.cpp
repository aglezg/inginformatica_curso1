 /*
 *  PG1.CPP - Actividad I de Optimiza!cion.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Fecha : Marzo-2020
 *               Trabajo realizado por: Adrián González Galván del Grupo 2 de Tarde
 */

#include <string.h>
#include "grafo.h"

void clrscr() //No funciona en todos los sistemas: opcional
{
	system("clear"); //para linux en vez de "cls"
}


void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{

cout << "Actividad I, Optimiza!ción: carga del grafo y conectividad" << endl;

cout << "c. [c]argar grafo desde fichero"<< endl; //Casos generales
cout << "i. Mostrar [i]nformación básica del grafo" << endl;
 
if(dirigido == 1){ //Si es dirigido
cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
cout << "d. Caminos mínimos: [d]ijkstra" << endl;
}

if(dirigido == 0){ //si NO es dirigido
cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
cout << "o. Mostrar c[o]mponentes conexas del grafo" << endl;
cout << "k. Mostrar el árbol generador de mínimo coste, [k]ruskal" << endl; //Nueva implementación: Kruskal para grafos pesados no dirigidos
}

cout << "q. Finalizar el programa" << endl; //finalización del programa

   cout << "Introduce la letra de la acción a ejecutar: "; //opción a ejecutar
   cin >> opcion;
    
    };


// El principal es simplemente un gestor de menu, diferenciando acciones para grafo dirigido y para no dirigido
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;

	clrscr();
    //Cargamos por defecto el fichero que se pasa como argumento del ejecutable
	if (argc > 1)
    {
		cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
		clrscr();
    }
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero: revisa nombre y formato" << endl;
    }
    else
    {
        do
        {
            menu(G.Es_dirigido(), opcion);
            switch (opcion)
            {

                case 'c': //Para todos los grafos: Actualización de un grafo
                clrscr(); 
                cout << "Introduce el nombre completo del fichero de datos" << endl;
                cin >> nombrefichero;
                G.actualizar(nombrefichero, error_apertura);
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                clrscr();
                break;

                case 'i': //Para todos los grafos: Información de un grafo
                clrscr();
                cout << "Grafo cargado desde " << nombrefichero << endl;
                G.Info_Grafo();
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                clrscr();
                break;

                case 's': //Para dirigidos: Lista de sucesores
                if(G.Es_dirigido()){
                clrscr();
                G.Mostrar_Listas(+1);
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                }
                clrscr();
                break;

                case 'p': //Para dirigidos: Lista de predecesores
                if(G.Es_dirigido()){
                clrscr();
                G.Mostrar_Listas(-1);
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                }
                clrscr();
                break;

                case 'a': //Para no dirigido: Lista de adyacentes
                if(G.Es_dirigido()==0){
                clrscr();
                G.Mostrar_Listas(0);
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                }
                clrscr();
                break;

                case 'o': //Para no dirigidos: componentes conexas
                if(G.Es_dirigido()==0){
                clrscr();
                G.ComponentesConexas();
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                }
                clrscr();
                break;

                case 'k': //Para no dirigidos: algoritmo de Kruskal
                if(G.Es_dirigido()==0){
                clrscr();
                G.Kruskal();
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                }
                clrscr();
                break;                
          
                case 'd': //Para dirigidos: algoritmo de Dijkstra (NUEVO)
                if(G.Es_dirigido()){
                clrscr();
                G.Dijkstra();
                cout << "Presione Enter para continuar . . ." << endl;
                getchar();
                getchar();
                }
                clrscr();
                break;

                case 'q': //Fin del programa
                clrscr();
                break;

                default: //Opción incorrecta
                clrscr();              
                break; 
            }
        }
        while (opcion != 'q');
    };
    cout << "Fin del programa"<< endl;
		return(0);
};
