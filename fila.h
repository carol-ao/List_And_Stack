#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "fila_abstract.h"

template <class T>
class FilaArray: public FilaAbstract<T> {
    private:
        // array de itens, capacidade, tamanho, posição inicial, etc.
        T* itens;
        int capacidade;
        int tam;
        int inicio;

    public: FilaArray(int cap) {
        // inicializar array de items, capacidade, tamanho, posição inicial
        itens = new T[cap];
        capacidade= cap;
        tam=0;
        inicio=0;
    }
    ~FilaArray() {
         // destruir array de itens
        delete itens;
    }
    void enfileira(const T & item) {
        // adiciona um item ao final da fila;
        //lança “Fila cheia” caso cheia
        if(tam==capacidade){
            throw "overflow";
        }
        else{
            int prox_idx = (inicio+tam)%capacidade;
            itens[prox_idx]= item;
            ++tam;
        }
    }
    T desenfileira() {
         // remove um item do inicio da fila; lança “Fila vazia” caso vazia
         if(tam==0){
            throw "underflow";
         }
         else{
            int idx_da_vez = inicio;
            inicio = (inicio+1)%capacidade;
            --tam;
            return itens[idx_da_vez];
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

#endif // FILA_H_INCLUDED
