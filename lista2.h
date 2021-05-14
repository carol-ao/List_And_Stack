/*
 * lista2.h
 *
 *  Created on: 14 de fev de 2021
 *      Author: Carol
 */

#ifndef LISTA2_H_
#define LISTA2_H_
#include <iostream>
#include "lista_abstract.h"

using namespace std;
template <class T>
class ListaEncadeada: public ListaAbstract<T>
{
	struct No{
		T dados;
		No* prox;
	};
	private:
	// itens da lista, capacidade e tamanho atual
		int capacidade;
		int tam;
		No* inicio;
		No* fim;

	public: ListaEncadeada(int capacidade_) {
		inicio= nullptr;
		fim=nullptr;
		capacidade= capacidade_;
		tam= 0;
	}
	~ListaEncadeada() {
	}
	void adiciona (const T & item) {
		if(tam== capacidade){
			throw "OVERFLOW";
		}
		else{
		  No* tmp = new No;
		  tmp->dados=item;
		  tmp->prox= nullptr;
		  if(inicio==nullptr){
			inicio= tmp;
		  }
		  else{
			  fim->prox=tmp;
		  }
		  fim= tmp;
		  ++tam;
		}
	}
	T pega(int idx) {
		// pega um item pelo indice (começa em 1);
		// lança “Item inválido” se posição inválida
		if(idx<1|| idx>tam){
			throw "item invalido";
		}
		else{
			No* find_pos;
			find_pos=inicio;
			for(int i=1;i<idx;++i){
				find_pos=find_pos->prox;
			}
			return find_pos->dados;
		}
	}
	No* find(int idx){
		No* no= inicio;
		--idx;
		while(idx>0){
			no= no->prox;
			--idx;
		}
		return no;
	}
	void insere (int idx, const T & item) {
		// lança “Lista cheia” caso cheia
				// lança “Item inválido” se posição inválida
		if(tam==capacidade){
			throw "lista cheia";
		}
		else if(idx<1||idx>tam+1){
			throw "item invalido";
		}
		else if(inicio==nullptr){
			  No* tmp = new No;
			  tmp->dados=item;
			  tmp->prox= nullptr;
			  inicio= tmp;
			  fim= tmp;
			  ++tam;
		}
		else if(idx==1){
			 No* tmp = new No;
			 tmp->dados=item;
			 tmp->prox= inicio;
			 inicio=tmp;
			 ++tam;
		}
		else{
			No* prev_pos= find(idx-1); //achar posicao anterior à desejada
			No* tmp = new No;
			tmp->dados=item;
			tmp->prox= prev_pos->prox;
			prev_pos->prox=tmp;
			++tam;
		}
	}

	void remove(int idx) {
				if(tam==0){
					throw "UNDERFLOW";
				}
				else if(idx<1||idx>tam+1){
					throw "item invalido";
				}
				else if(idx==1){
					No* tmp = inicio;
					inicio= inicio->prox;
					if(fim==tmp){
						fim=nullptr;
					}
					delete tmp;
					--tam;
				}
				else{
					No* prev_pos= find(idx-1);
					No* tmp = prev_pos->prox;
					prev_pos->prox= tmp->prox;
					if(tmp==fim){
						fim = prev_pos;
					}
					delete tmp;
					--tam;
				}

	}
	void exibe() {
		// exibe os itens da saida padrão separados por espaços
		if(inicio!=nullptr){
			No* no = inicio;
			for(int i=0;i<tam;++i){
				cout << no->dados <<" ";
				no= no->prox;
			}
		}

	}

	int tamanho() { // retorna a quantidade de itens atualmente na lista
		return tam;
	}
};





#endif /* LISTA2_H_ */
