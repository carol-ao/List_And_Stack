#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <iostream>
#include "pilha_abstract.h"
using namespace std;

template <class T>
class PilhaArray: public PilhaAbstract<T>{
    private: // Atributos para array de items, capacidade e topo da pilha
        T * itens ;
        int capacidade;
        int topo;

    public:
        PilhaArray(int capacidade_) { // instancia array de items, inicializa capacidade e topo
            itens = new T[capacidade_];
            capacidade = capacidade_;
            topo = 0;
        }
        ~PilhaArray() {
            delete itens;
        }
    void empilha(T item) {
        // empilha um item no topo da pilha;
        if(topo==capacidade){
            throw "overflow";
        }
        else{
            itens[topo]= item;
            ++topo;
        }
        // lança “Estouro da pilha” se cheia
    }
    T desempilha() {
        // remove um item do topo da pilha;
        // lança “Pilha vazia” se vazia
        if(topo==0){
            throw "underflow";
        }
        else{
            --topo;
            return itens[topo];
        }
    }

    int tamanho() { // retorna o número de elementos na pilha.
        return topo;
    }
};
#endif // PILHA_H_INCLUDED
