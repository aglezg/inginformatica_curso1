// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: 

#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

namespace AED {

template <class T>
class dll_node_t
{
public:
  dll_node_t();         // constructor por defecto
  dll_node_t(const T&); // constructor

  ~dll_node_t(void);    // destructor

  // getters & setters
  const T& get_data(void) const;
  dll_node_t<T>* get_next(void) const;
  dll_node_t<T>* get_prev(void) const;

  void set_data(const T&);
  void set_next(dll_node_t<T>*);
  void set_prev(dll_node_t<T>*);

  // E/S
  ostream& write(ostream& = cout) const;

private:
  dll_node_t<T>* prev_;
  T              data_;
  dll_node_t<T>* next_;
};



template <class T>
dll_node_t<T>::dll_node_t():
prev_(NULL),
data_(),
next_(NULL)
{}



template <class T>
dll_node_t<T>::dll_node_t(const T& data) :
prev_(NULL),
data_(data),
next_(NULL)
{}



template <class T>
dll_node_t<T>::~dll_node_t(void)
{
  prev_ = NULL;
  next_ = NULL;
}



template <class T>
const T&
dll_node_t<T>::get_data(void) const
{
  return data_;
}



template <class T>
dll_node_t<T>*
dll_node_t<T>::get_next(void) const
{
  return next_;
}



template <class T>
dll_node_t<T>*
dll_node_t<T>::get_prev(void) const
{
  return prev_;
}



template <class T>
void
dll_node_t<T>::set_data(const T& data)
{
  data_ = data;
}



template <class T>
void
dll_node_t<T>::set_next(dll_node_t<T>* next)
{
  next_ = next;
}



template <class T>
void
dll_node_t<T>::set_prev(dll_node_t<T>* prev)
{
  prev_ = prev;
}



template <class T>
ostream&
dll_node_t<T>::write(ostream& os) const
{
  os << data_;
  return os;
}

} // namespace
