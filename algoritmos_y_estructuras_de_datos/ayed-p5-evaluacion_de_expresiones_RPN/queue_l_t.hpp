// AUTOR: Adrián González Galván
// FECHA: 17/05/2020
// EMAIL: alu0101321219@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase TAD cola implementada con una lista

#pragma once

#include <iostream>
#include <cassert>

#include "dll_t.hpp"

using namespace std;

namespace AED
{
template <class T>
class queue_l_t //COLA
{
private:
	dll_t<T>    l_;
        //modificación
        int sum_even_(void) const;        

public:
	// constructor y destructor
	queue_l_t(void);
	~queue_l_t(void);

	bool empty(void) const;
	int size(void) const;

	// operaciones
	void push(const T& dato);
	void pop(void);
	const T& front(void) const;
	const T& back(void) const;

	void write(ostream& os = cout) const;
};



template<class T>
queue_l_t<T>::queue_l_t(void):
l_()
{}



template<class T>
queue_l_t<T>::~queue_l_t(void)
{}



template<class T>
bool
queue_l_t<T>::empty(void) const
{
	return l_.empty();
}


template<class T>
int
queue_l_t<T>::size(void) const
{
	return l_.get_size();		
}


template<class T>
void
queue_l_t<T>::push(const T& dato) //encolar
{
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
	l_.insert_head(node);
}



template<class T>
void
queue_l_t<T>::pop(void) //abandonar cola
{
	assert(!empty());
	delete l_.extract_tail();
}



template<class T>
const T&
queue_l_t<T>::front(void) const //elemento al frente de la cola
{
	assert(!empty());
	return (l_.get_tail()->get_data());
}



template<class T>
const T&
queue_l_t<T>::back(void) const //elemento al final de la cola
{
	assert(!empty());
	return (l_.get_head()->get_data());
}


template<class T>
void
queue_l_t<T>::write(ostream& os) const
{
	dll_node_t<T>* aux = l_.get_head();
	while(aux != NULL)
	{
		os << aux->get_data() << " ";
		aux = aux->get_next();
	}
	os << endl;

//Modificación: En el write() mostramos también la suma de los elementos impares

cout << "La suma de sus elementos pares da: " << sum_even_() << endl;

}



template<class T>
ostream&
operator<<(ostream& os, const queue_l_t<T>& q)
{
	q.write(os);
	return os;
}

//Modificación: Método privado que devuelve la suma de los elementos pares de una cola
template<class T>
int 
queue_l_t<T>::sum_even_(void) const
{
 assert(!l_.empty());

 T a;
 dll_node_t<T>* aux = l_.get_head();
 int i, suma=0;

 while(aux != NULL)
 {
  a = aux->get_data();
 
   if(isdigit(a)){
    i = a - '0';
     if(i%2==0)
      suma+=i;
   }

  aux=aux->get_next();
 }

return suma;
}


} // namespace




