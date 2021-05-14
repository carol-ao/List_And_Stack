/*
 * pilha_abstract.h
 *
 *  Created on: 14 de fev de 2021
 *      Author: Carol
 */

#ifndef PILHA_ABSTRACT_H_
#define PILHA_ABSTRACT_H_

template <class T> class PilhaAbstract{

	public:
		virtual void empilha(T item) =0;
		virtual T desempilha() = 0;
		virtual int tamanho() =0;
};



#endif /* PILHA_ABSTRACT_H_ */
