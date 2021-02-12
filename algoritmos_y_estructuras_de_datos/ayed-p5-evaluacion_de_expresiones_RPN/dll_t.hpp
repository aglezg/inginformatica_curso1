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

#include "dll_node_t.hpp"

using namespace std;

namespace AED
{
template <class T>
class dll_t {

public:
  // constructor, constructor de copia y destructor
  dll_t(void);
  dll_t(const dll_t<T>&);
  ~dll_t(void); 
  
  // opeardor de asignación
  dll_t<T>& operator=(const dll_t<T>&);
  

  // getters
  dll_node_t<T>* get_tail(void) const;
  dll_node_t<T>* get_head(void) const;
  int get_size(void) const;
  bool empty(void) const;

  // operaciones
  void insert_head(dll_node_t<T>*);
  void insert_tail(dll_node_t<T>*);

  dll_node_t<T>* extract_head(void);
  dll_node_t<T>* extract_tail(void);

  void remove(dll_node_t<T>*);

  // E/S
  ostream& write(ostream& = cout);

private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


template <class T>
dll_t<T>::dll_t(void) :
head_(NULL),
tail_(NULL),
sz_(0)
{}



// constructor de copia
template<class T>
dll_t<T>::dll_t(const dll_t<T>& l)
{
  *this = l; // invocamos directamente al operator=
}



template <class T>
dll_t<T>::~dll_t(void)
{
  dll_node_t<T>* aux = NULL;

  while (head_ != NULL) {
    aux = head_;
    head_ = head_->get_next();
    delete aux;
    aux = NULL;
  }
  sz_ = 0;
  head_ = tail_ = NULL;
}



// operador de asignación
template<class T>
dll_t<T>&
dll_t<T>::operator=(const dll_t<T>& l)
{
  while (get_size())
    delete extract_head();
  
  dll_node_t<T>* aux = l.head_;

  while (aux != NULL) {
    dll_node_t<T>* nodo = new dll_node_t<T>(aux->get_data());
    assert(nodo != NULL);
    insert_tail(nodo);
    aux = aux ->get_next();
  }
  return *this;
}



template <class T>
dll_node_t<T>*
dll_t<T>::get_head(void) const
{
  return head_;
}



template <class T>
dll_node_t<T>*
dll_t<T>::get_tail(void) const
{
  return tail_;
}


template <class T>
int
dll_t<T>::get_size(void) const
{
  return sz_;
}



template <class T>
bool
dll_t<T>::empty(void) const
{
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else return false;
}



template <class T>
void
dll_t<T>::insert_head(dll_node_t<T>* nodo)
{
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}



template <class T>
void
dll_t<T>::insert_tail(dll_node_t<T>* nodo)
{
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }

  sz_++;
}



template <class T>
dll_node_t<T>*
dll_t<T>::extract_tail(void)
{
  assert(!empty());

  dll_node_t<T>* aux = tail_;

  tail_ = tail_->get_prev();
  
  if (tail_ != NULL) tail_->set_next(NULL);
  else               head_ = NULL;

  sz_--;
  
  aux->set_next(NULL);
  aux->set_prev(NULL);
  
  return aux;
}



template <class T>
dll_node_t<T>*
dll_t<T>::extract_head(void)
{
  assert(!empty());

  dll_node_t<T>* aux = head_;

  head_ = head_->get_next();

  if (head_ != NULL) head_->set_prev(NULL);
  else               tail_ = NULL;

  sz_--;

  aux->set_next(NULL);
  aux->set_prev(NULL);

  return aux;
}



template <class T>
void
dll_t<T>::remove(dll_node_t<T>* nodo)
{
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();

  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();

  delete nodo;

  sz_--;

}


template <class T>
ostream&
dll_t<T>::write(ostream& os)
{
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }

  return os;
}

} // namespace
