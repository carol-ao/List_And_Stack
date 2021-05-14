/*
 * fila_abstract.h
 *
 *  Created on: 15 de fev de 2021
 *      Author: Carol
 */

#ifndef FILA_ABSTRACT_H_
#define FILA_ABSTRACT_H_

template <class T>
class FilaAbstract{
	public:
		virtual void enfileira(const T & item) =0;
		virtual T desenfileira() =0;
		virtual int cheia() =0;
		virtual int vazia() =0;
		virtual int tamanho()= 0;

};



#endif /* FILA_ABSTRACT_H_ */
