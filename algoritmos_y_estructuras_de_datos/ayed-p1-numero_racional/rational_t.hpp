// AUTOR: Adrián Glez Galván
// FECHA: 20/02/2020
// EMAIL: alu0101321219@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html


#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class rational_t
{

public:
  rational_t(const int = 0, const int = 1); //constructor: define un número irracional y le asigna por defecto los valores "0/1". No devuelve nada.
  ~rational_t() {} //destructor: destruye lo que crea el constructor, todo su constructor tiene su destructor. No lleva parametros ni devuelve nada.
  

  // getters: funciones que al llamarlas devuelven el "numerador" y el "denominador" respectivamente del numero racional al que se refieran.
  int get_num() const;
  int get_den() const;
  
  // setters: funciones que solo se llaman una vez dentro de la clase y establecen valores a los atributos "num_" y "den_" con "n" y "d" respectivamente.
  void set_num(const int);
  void set_den(const int);

  double value(void) const; //método que devuelve el valor flotante de dividir el numerador entre el denominador del número racional en concreto.

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);

  // MODIFICIACION: opuesto de un número racional.
  rational_t opposite(void) const;
  
  void write(ostream& = cout) const; //método para escritura a pantalla de forma compleja.
  void read(istream& = cin); //metodo para la lectura desde teclado de forma compleja.
  
private: //elementos privados.

  int num_, den_; //num_=numerador y den_=denominador son los elementos privados.
};
