// AUTOR: Adrián Glez Galván 
// FECHA: 05/04/2020
// EMAIL: alu0101321219@ull.edu.es 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g main_vector_t.cpp -o main_vector_t


#include <iostream>
#include <cmath>

#include "vector_t.hpp"
#include "sparse_vector_t.hpp"


using namespace std;

int main()
{
  vector_t<double> v1, v2, v3; //vectores
  cin >> v1 >> v2 >> v3;
  cout << "v1= " << v1;
  cout << "v2= " << v2;
  cout << "v3= " << v3;
  cout << endl;
  
  sparse_vector_t sv1(v1), sv2(v2), sv3(v3); //vectores dispersos
  cout << "sv1= " << sv1;
  cout << "sv2= " << sv2;
  cout << "sv3= " << sv3;
  cout << endl;
  
  cout << "sv3 * v1= " << sv3.scal_prod(v1) << endl; //producto escalar de vector normal por vector dispersos
  cout << "sv3 * sv2= " << sv3.scal_prod(sv2) << endl; //producto escalar de 2 vectores dispersos
  
  //modificación:
  cout << "Índice de menor valor de sv1:" << sv1.inx_min() << endl;
  cout << "Índice de menor valor de sv2:" << sv2.inx_min() << endl;
  cout << "Índice de menor valor de sv3:" << sv3.inx_min() << endl;
  

  return 0;
}
