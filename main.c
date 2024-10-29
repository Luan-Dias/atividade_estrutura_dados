#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Definindo a estrutura de um nó
typedef struct no{
    int indice;
    float nota;
} No;

// Definindo a estrutura de uma lista
typedef struct lista{
    No* listaDeNos[MAX];
    int numElem;
} Lista;

// declaração das funções
void inicializarLista(Lista* lista);
int inserirElemento(Lista* lista, No* no);
void exibirLista(Lista* lista);
void excluirElemLista(Lista* lista, int indice);
void verificarVazia(Lista* lista);
void buscarLista(Lista* lista, int indice);
void excluirLista(Lista* lista);
void liberarLista(Lista* lista);

int main(){
    
    Lista l;
    inicializarLista(&l);
    exibirLista(&l);
    printf("Num de elementos: %d\n", l.numElem);
    
    No* n1;
    n1 = (No*) malloc(sizeof(No));
    n1->indice = 1;
    n1->nota = 5.5;
    inserirElemento(&l, n1);
    
    No* n2;
    n2 = (No*) malloc(sizeof(No));
    n2->indice = 2;
    n2->nota = 8.5;
    inserirElemento(&l, n2);
    
    No* n3;
    n3 = (No*) malloc(sizeof(No));
    n3->indice = 3;
    n3->nota = 9.5;
    inserirElemento(&l, n3);

    exibirLista(&l);

    excluirElemLista(&l, 2);
    exibirLista(&l);
    
    verificarVazia(&l);
    buscarLista(&l, 1);
    buscarLista(&l, 4);
    
    excluirLista(&l);
    verificarVazia(&l);
    
    liberarLista(&l);

}

// Escopo das funções
void inicializarLista(Lista* lista){
    lista -> numElem = 0;
}

int inserirElemento(Lista* lista, No* no){
    if (lista -> numElem == MAX){
        printf("lista cheia!\n");
        return 0;
    } else {
        lista -> listaDeNos[lista -> numElem] = no;
        lista -> numElem++;
        printf("Elemento inserido\n");
        return 1;
    }
}

void exibirLista(Lista* lista){
    if (lista -> numElem == 0){
        printf("Lista vazia!\n");
    } else {
        printf("\n=====LISTA=====\n");
        for(int i = 0; i < lista -> numElem; i++){
            printf("%d: %.2f\n", lista->listaDeNos[i]->indice, lista->listaDeNos[i]->nota);
        }
    printf("===============\n");
    }
}

void excluirElemLista(Lista* lista, int indice) {
    int i, j, found = 0;
    for (i = 0; i < lista->numElem; i++) {
        if (lista->listaDeNos[i]->indice == indice) {
            found = 1;
            free(lista->listaDeNos[i]);
            for (j = i; j < lista->numElem - 1; j++) {
                lista->listaDeNos[j] = lista->listaDeNos[j + 1];
            }
            lista->numElem--;
            printf("Elemento com indice %d excluido.\n", indice);
            break;
        }
    }
    if (!found) {
        printf("Elemento com indice %d nao encontrado.\n", indice);
    }
}

void verificarVazia(Lista* lista) {
    if (lista->numElem == 0) {
        printf("Lista vazia.\n");
    } else {
        printf("Lista nao esta vazia.\n");
    }
}

void buscarLista(Lista* lista, int indice) {
    for (int i = 0; i < lista->numElem; i++) {
        if (lista->listaDeNos[i]->indice == indice) {
            printf("Elemento encontrado: %d: %.2f\n", lista->listaDeNos[i]->indice, lista->listaDeNos[i]->nota);
            return;
        }
    }
    printf("Elemento com indice %d nao encontrado.\n", indice);
}

void excluirLista(Lista* lista) {
    for (int i = 0; i < lista->numElem; i++) {
        free(lista->listaDeNos[i]);
    }
    lista->numElem = 0;
    printf("Todos os elementos foram excluidos da lista.\n");
}

void liberarLista(Lista* lista) {
    excluirLista(lista);
    printf("Memoria liberada.\n");
}