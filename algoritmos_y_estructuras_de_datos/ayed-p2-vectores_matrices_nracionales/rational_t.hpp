// AUTOR: Adrián Glez Galván
// FECHA: 19/03/2020
// EMAIL: alu0101321219@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
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
  
public: //métodos
  rational_t(const int = 0, const int = 1); //constructor
  ~rational_t() {} //destructor
  

  
  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const; //retorna el valor flotante de un racional
  rational_t opposite(void) const; //retorna el opuesto del número racional
  rational_t reciprocal(void) const; //retorna el recíproco del número racional

  //comparaciones: "igual", "mayor que" & "menor que"
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;

  //operaciones(suma, resta, multiplicación y división)
  rational_t add(const rational_t&) const;
  rational_t substract(const rational_t&) const;
  rational_t multiply(const rational_t&) const;
  rational_t divide(const rational_t&) const;

  //LECTURA/ESCRITURA
  void write(ostream& os = cout) const;
  void read(istream& is = cin);
  
private: //atributos
  
  int num_, den_;
};


// sobrecarga de los operadores de E/S para que puedan tambíen imprimir y leer número racionales
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores sobrecargados
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);

