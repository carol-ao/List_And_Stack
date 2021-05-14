/*
 * lista_abstract.h
 *
 *  Created on: 14 de fev de 2021
 *      Author: Carol
 */

#ifndef LISTA_ABSTRACT_H_
#define LISTA_ABSTRACT_H_
#include <iostream>

using namespace std;

template <class T> class ListaAbstract
{

	public:

		virtual void adiciona (const T & item)= 0;
		virtual T pega(int idx) =0;
	    virtual void insere (int idx, const T & item)= 0;
	    virtual void remove(int idx)=0;
	    virtual void exibe() = 0;
	    virtual int tamanho() =0;

};


#endif /* LISTA_ABSTRACT_H_ */
