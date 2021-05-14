/*
 * pilha2.h
 *
 *  Created on: 13 de fev de 2021
 *      Author: Carol
 */

#ifndef PILHA2_H_
#define PILHA2_H_


#include <iostream>
#include "pilha_abstract.h"
using namespace std;


template<class T>
class PilhaEncadeada: public PilhaAbstract<T> {

	  typedef struct No{
	    	T dados;
	    	No* prox;
	    };

        int capacidade;
        int tam;
        No* topo;


    public:
        PilhaEncadeada(int capacidade_) { // instancia array de items, inicializa capacidade e topo
           capacidade = capacidade_;
            topo = NULL;
            tam=0;
    }
        ~PilhaEncadeada(){

        }

    void empilha(T item) {
        // empilha um item no topo da pilha;
    	// lança “Estouro da pilha” se cheia
    	if(tam==capacidade){
    		throw "overflow";
    	}
    	else{
    		No* tmp = new No;
	    	tmp->prox = topo;
	    	tmp->dados=item;
	    	topo = tmp;
	    	++tam;
    	}
    }
    T desempilha() {
        // remove um item do topo da pilha;
        // lança “Pilha vazia” se vazia
    	if(tam==0){
    	    		throw "underflow";
    	    	}
    	    	else{
    	    		No* tmp= topo;
    	    		T dados = topo->dados;
    	    		topo = topo->prox;
    	    		delete tmp;
    	    		tam--;
    	    		return dados;
    	    	}
          }

    int tamanho() { // retorna o número de elementos na pilha.
        return tam;
    }

};




#endif /* PILHA2_H_ */
