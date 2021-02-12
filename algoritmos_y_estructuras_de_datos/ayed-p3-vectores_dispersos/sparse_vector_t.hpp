// AUTOR: Adrián Glez Galván
// FECHA: 05/04/2020
// EMAIL: alu0101321219@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"
#include "pair_t.hpp"

using namespace std;


typedef vector_t<pair_t<double> > pair_vector_t;

class sparse_vector_t
{
public:
  sparse_vector_t(const vector_t<double>&); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia
  
  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t(); //destructor
  
  // getters
   int get_nz(void) const;
   int get_n(void) const;
   
   // operaciones
   double scal_prod(const vector_t<double>&);
   double scal_prod(const sparse_vector_t&);

   // E/S
   void write(ostream& = cout) const;
   
  //Modificación: Devolver el índice de menor valor de un vector disperso.
  int inx_min(void);


private:
  pair_vector_t pv_; // valores + índices
  int     nz_;       // nº de valores distintos de cero = tamaño del vector
  int     n_;        // tamaño del vector original
  
  bool is_not_zero(double, double = 1e-6) const;
};



// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v):
pv_(),
nz_(0),
n_(0)
{

n_=v.get_size(); //tamaño del vector original

 for(int i=0; i < v.get_size(); i++)
  if(is_not_zero(v[i]))
   nz_++; //tamaño del nuevo vector con elementos distintos de cero

pv_.resize(nz_); //redimensionamos nuestro vector de pares con el tamaño de los elementos distintos de cero

int j = 0;
 for( int i = 0; i < v.get_size() ; i++)
  if(is_not_zero(v[i])){
  pv_[j].set(v[i], i); //vector escaso de pares!!
  j++; 
  }

}



// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w)
{
  *this = w; // invocamos directamente al operator=
}



// operador de asignación
sparse_vector_t&
sparse_vector_t::operator=(const sparse_vector_t& w)
{
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}



sparse_vector_t::~sparse_vector_t() //destructor
{}


//getters
inline int
sparse_vector_t::get_nz() const
{
  return nz_;
}



inline int
sparse_vector_t::get_n() const
{
  return n_;
}


//S
void
sparse_vector_t::write(ostream& os) const
{ 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << endl;
}


//sobrecarga del operador de salida
ostream&
operator<<(ostream& os, const sparse_vector_t& sv)
{
  sv.write(os);
  return os;
}


//detectar si un valor flotante es cero
bool
sparse_vector_t::is_not_zero(double v, double eps) const
{
  return fabs(v) > eps;
}



// operaciones
// FASE III
double
sparse_vector_t::scal_prod(const vector_t<double>& v)
{
  assert(n_==v.get_size());

  double s = 0;

   for(int i=0; i< get_nz(); i++)
    s += pv_[i].get_val()*v[pv_[i].get_inx()];

  return s;
}



/// FASE IV
double
sparse_vector_t::scal_prod(const sparse_vector_t& sv)
{
  assert(n_==sv.n_);

  double s = 0;
  
   for(int i=0; i<get_nz();i++)
    for(int j=0; j<sv.get_nz();j++)
     if (pv_[i].get_inx()==sv.pv_[j].get_inx())
     s+= pv_[i].get_val()*sv.pv_[j].get_val();

  return s;
}
 
//Modificación:

int
sparse_vector_t::inx_min(void)
{

int indice= get_n()-1;

 for(int i=0; i<get_nz(); i++)
  if(pv_[i].get_inx()<=indice)
   indice=pv_[i].get_inx();

return indice;
}



