// AUTOR: Adrián González Galván
// FECHA: 26/04/2020
// EMAIL: alu0101321219@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

using namespace std;

namespace AED
{
template<class T>
class pair_t
{
public:
  // constructores
	pair_t(void); 
	pair_t(T, int);

  // destructor
	~pair_t(void);

  // getters & setters
	T   get_val(void) const;
	int get_inx(void) const;
	void set(T, int);

  // E/S
	istream& read(istream& is = cin);
	ostream& write(ostream& os = cout) const;

private:
	T   val_;
	int inx_;
};


//constructor por defecto
template<class T>
pair_t<T>::pair_t():
val_(),
inx_(-1)
{} 


//constructor
template<class T>
pair_t<T>::pair_t(T val, int inx):
val_(val),
inx_(inx)
{}

//destructor
template<class T>
pair_t<T>::~pair_t()
{}


//setters
template<class T>
void
pair_t<T>::set(T val, int inx)
{
	val_ = val;
  inx_ = inx;
}


//getters
template<class T>
int
pair_t<T>::get_inx() const
{
  return inx_;
}



template<class T>
T
pair_t<T>::get_val() const
{
  return val_;
}


//E/S
template<class T>
ostream&
pair_t<T>::write(ostream& os) const
{
  return os << "(" << inx_ << ":" << val_ << ")";
}



template<class T>
istream&
pair_t<T>::read(istream& is)
{
  return is >> inx_ >> val_;
}

//Sobrecarga de operadores de E/S
template<class T>
ostream& operator<<(ostream& os, const pair_t<T>& p)
{
  p.write(os);
  return os;
}

} // namespace
