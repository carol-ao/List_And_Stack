/*
 * lista.h
 *
 *  Created on: 13 de fev de 2021
 *      Author: Carol
 */

#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>
#include "lista_abstract.h"
using namespace std;
template <class T>
class ListaArray: public ListaAbstract<T>
{
	private:
	// itens da lista, capacidade e tamanho atual
	T* itens;
	int capacidade;
	int tam;

	public: ListaArray(int capacidade_) {
		// inicilização do array, capacidade e tamanho
		itens= new T[capacidade_];
		capacidade= capacidade_;
		tam= 0;
	}
	~ListaArray() {
		//destruição do array
		delete itens;
	}
	void adiciona (const T & item) {
		//lança “Lista cheia” caso cheia
		// adiciona um item ao final da lista;
		if(tam== capacidade){
			throw "OVERFLOW";
		}
		else{
			itens[tam]= item;
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
			return itens[idx-1];
		}
	}
	void insere (int idx, const T & item) {
		// lança “Lista cheia” caso cheia
				// lança “Item inválido” se posição inválida
		if(tam==capacidade){
			throw "lista cheia";
		}
		else if(idx<1|| idx>capacidade||idx>tam+1){
			throw "item invalido";
		}
		else if(idx==tam+1){
			itens[idx-1]=item; //se a posição é uma após o fim da lista, é só colocar lá
			tam++;
		}
		else{
			// desloca itens existentes para a direita
			// insere um item na posição indicada (a partir de 1).
			int tmp[tam-idx];
			int j = idx-1;
			for(int i=0; i<tam-idx; ++i){
				tmp[i]=itens[j++];
			}
			j = idx;
			for(int i=0;i<tam-idx;++i ){
				itens[j++]=tmp[i];
			}
			itens[idx-1]=item;
			tam++;
		}


	}

	void remove(int idx) {
		// remove item de uma posição indicada
		// lança “Item inválido” se posição inválida
		// desloca itens para a esquerda sobre o item removido
				if(tam==0){
					throw "UNDERFLOW";
				}
				else if(idx<1||idx>tam+1){
					throw "item invalido";
				}
				else if(idx==tam){
					--tam;
					//se a posição é a do fim da lista, é só ajustar o tamanho
				}
				else{
					// desloca itens existentes para a esquerda
					// remove um item na posição indicada (a partir de 1).
					int tmp[tam-idx];
					int j = idx;
					for(int i=0; i<tam-idx; ++i){
						tmp[i]=itens[j];
						++j;

					}
					j=idx-1;
					for(int i=0;i<tam-idx;++i ){
						itens[j]=tmp[i];
						++j;
					}
					tam--;
				}

	}
	void exibe() {
		// exibe os itens da saida padrão separados por espaços
		for(int i=0;i<tam;++i){
			cout<<itens[i] <<" ";
		}
		cout << "\n";
	}
	int tamanho() { // retorna a quantidade de itens atualmente na lista
		return tam;
	}
};



#endif /* LISTA_H_ */
