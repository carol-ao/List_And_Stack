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
		// iniciliza��o do array, capacidade e tamanho
		itens= new T[capacidade_];
		capacidade= capacidade_;
		tam= 0;
	}
	~ListaArray() {
		//destrui��o do array
		delete itens;
	}
	void adiciona (const T & item) {
		//lan�a �Lista cheia� caso cheia
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
		// pega um item pelo indice (come�a em 1);
		// lan�a �Item inv�lido� se posi��o inv�lida
		if(idx<1|| idx>tam){
			throw "item invalido";
		}
		else{
			return itens[idx-1];
		}
	}
	void insere (int idx, const T & item) {
		// lan�a �Lista cheia� caso cheia
				// lan�a �Item inv�lido� se posi��o inv�lida
		if(tam==capacidade){
			throw "lista cheia";
		}
		else if(idx<1|| idx>capacidade||idx>tam+1){
			throw "item invalido";
		}
		else if(idx==tam+1){
			itens[idx-1]=item; //se a posi��o � uma ap�s o fim da lista, � s� colocar l�
			tam++;
		}
		else{
			// desloca itens existentes para a direita
			// insere um item na posi��o indicada (a partir de 1).
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
		// remove item de uma posi��o indicada
		// lan�a �Item inv�lido� se posi��o inv�lida
		// desloca itens para a esquerda sobre o item removido
				if(tam==0){
					throw "UNDERFLOW";
				}
				else if(idx<1||idx>tam+1){
					throw "item invalido";
				}
				else if(idx==tam){
					--tam;
					//se a posi��o � a do fim da lista, � s� ajustar o tamanho
				}
				else{
					// desloca itens existentes para a esquerda
					// remove um item na posi��o indicada (a partir de 1).
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
		// exibe os itens da saida padr�o separados por espa�os
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
