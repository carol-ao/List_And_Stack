/*
 * fila2.h
 *
 *  Created on: 14 de fev de 2021
 *      Author: Carol
 */

#ifndef FILA2_H_
#define FILA2_H_
#include "fila_abstract.h"

template <class T>
class FilaEncadeada: public FilaAbstract<T>{

	typedef struct No{
		    	T dados;
		    	No* prox;
		    };

	private:
        // array de itens, capacidade, tamanho, posição inicial, etc.
		int capacidade;
		int tam;
		No* inicio;
		No* fim;


    public: FilaEncadeada(int capacidade_) {

        inicio=nullptr;
        fim=nullptr;
        tam=0;
        capacidade= capacidade_;
    }
    ~FilaEncadeada(){

    }

    void enfileira(const T & item) {
        // adiciona um item ao final da fila;
    	if(cheia()){
    		throw "overflow";

    	}
    	else{

    		No * tmp = new No;
    		tmp->dados=item;
    		tmp->prox=nullptr;
    		if(inicio==nullptr){
    			inicio = tmp;
       		}
    		else{
    			fim->prox= tmp;
    		}
    		fim =tmp;
    		tam++;
    	}
    }

    T desenfileira() {
         // remove um item do inicio da fila; lança “Fila vazia” caso vazia
    	if(inicio==nullptr){
    		throw "underflow";
    	}
    	else{
    		T dados = inicio->dados;
    		No* tmp = inicio;
    		inicio = inicio->prox;
    		if(inicio==nullptr){
    			fim=nullptr;
    		}
    		delete tmp;
    		--tam;
    		return dados;
    	}

    }
    int cheia() {
           // retorna 1 se cheia, 0 caso contrário
           if(capacidade==tam)
               return 1;
           else
               return 0;
       }
       int vazia() {
           // retorna 1 se vazia, 0 caso contrário
           if(tam==0)
               return 1;
           else
               return 0;
       }


    int tamanho() {
        // retorna a quantidade de itens atualmente na fila
        return tam;
    }
};




#endif /* FILA2_H_ */
