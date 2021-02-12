// AUTOR: Adrián González Galván
// FECHA: 17/05/2020
// EMAIL: alu0101321219@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase que implementa la clase RPN (Reverse Polish Notation)

#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>
#include "queue_l_t.hpp"

using namespace std;

namespace AED {

template <class T>
class rpn_t
{
public:
  rpn_t(void); //constructor
     ~rpn_t(); //destructor

  const int evaluate(queue_l_t<char>&); //evalúa

private: 
        T stack_;
	void operate_(const char operador);
};



template<class T>
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>
rpn_t<T>::~rpn_t()
{}



template<class T>
const int 
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	while (!q.empty())
	{
    char c = q.front();
    q.pop();
    cout << "Sacamos de la cola un carácter: " << c;

		if (isdigit(c)) //si es un dígito
		{
		  int i = c - '0'; 
                  stack_.push(i); //lo metemos en la pila

		  cout << " (es un dígito) " << endl << "   Lo metemos en la pila..." << endl;
		}
		else { //Si es un operando

		  cout << " (es un operador)" << endl;
		  
                  operate_(c); //nos dirigimos a la función "operate_"
		}
	}

  return stack_.top(); //top de la pila = resultado final de la operación
}



template<class T>
void
rpn_t<T>::operate_(const char c)
{
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');
  
  int a,b; 

  a = stack_.top(); //primer operando = a
  stack_.pop();
  cout << "   Sacamos de la pila un operando: " << a << endl;
  
if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') //solo sacamos un segundo operando para operaciones de aridad 2
{
  b = stack_.top(); //segundo operando = b
  stack_.pop();
  cout << "   Sacamos de la pila otro operando: " << b << endl;
}  
	switch (c)
	{
	  case '+': a=a+b; //reescribimos 'a' para no tener que usar otra variable
	            break;

          case '-': a=b-a;
                    break;

          case '*': a=a*b;
                    break;

          case '/': a=b/a;
                    break;
        
        //Fase 2: Operadores "exponente(^)" y "raiz_cuadrada(r)"

          case '^': a=pow(b,a); //b^a
                         break;
         
          case 'r': a=sqrt(a); //r(a)
                        break;

        //Fase 3: Operadores "logaritmo_en_base_2(l)" y "elevación_al_cuadrado(c)"
          
          case 'l': a=log2(a); //log(en_base_2) de 'a'
                    break;

          case 'c': a=pow(a,2); // a^2
                    break;
	}
 
        stack_.push(a); //push de 'a'(el resultado) en la pila

	cout << "   Metemos en la pila el resultado: " << a << endl;
}

}
