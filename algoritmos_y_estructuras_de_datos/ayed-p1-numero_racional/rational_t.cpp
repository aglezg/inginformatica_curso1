// AUTOR: Adrián González Galván
// FECHA: 20/02/2020
// EMAIL: alu0101321219@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html


#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}
 


int
rational_t::get_num() const //getter 1: devuelve el numerador del número racional.
{
  return num_;
}



int
rational_t::get_den() const //getter 2: devuelve el denominador en este caso.
{
  return den_;
}


  
void
rational_t::set_num(const int n) //setter 1: establece valor al numerador a través de una constante "n".
{
  num_ = n;
}


  
void
rational_t::set_den(const int d) //setter 2: establece valor al denominador a través de la constante "d".
{
  assert(d != 0);
  den_ = d;
}



double
rational_t::value() const //método que devuelve el valor flotante de dividir el número racional en sí.
{ 
  return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
return (fabs(value() - r.value()) < precision);
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{

return( (r.value() - value() )  > precision);

}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
return( ( value() - r.value() ) > precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r)
{
rational_t x ((get_num()*r.get_den()+get_den()*r.get_num()), (get_den()*r.get_den()));
return x;
}



rational_t
rational_t::substract(const rational_t& r)
{
rational_t x ((get_num()*r.get_den()-get_den()*r.get_num()), (get_den()*r.get_den()));
return x;
}



rational_t
rational_t::multiply(const rational_t& r)
{
rational_t x((get_num()*r.get_num()), (get_den()*r.get_den()));
return x;
}


rational_t
rational_t::divide(const rational_t& r)
{
rational_t x((get_num()*r.get_den()), (get_den()*r.get_num()));
return x;
}



// E/S
void
rational_t::write(ostream& os) const //método para imprimir en pantalla.
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void 
rational_t::read(istream& is) //método para leer desde teclado.
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

// MODIFICIACION: opuesto de un número racional.

rational_t
rational_t::opposite(void){

rational_t x ( ((-1)*get_num()), get_den());

return x;

}










