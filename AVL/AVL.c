#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

Arvore* cria() {
	Arvore *arvore;
	arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	
	return arvore;
}

int vazia(Arvore* arvore) {
	return (arvore->raiz == NULL);
}

No* adiciona(Arvore* arvore, No* pai, float valor) {
	No *no = malloc(sizeof(No));
	
	no->pai = pai;
	no->esquerda = NULL;
	no->direita = NULL;
	no->valor = valor;
	
	if (pai == NULL) {
		
		arvore->raiz = no;
	}
	
	return no;
}

void remover(Arvore* arvore, No* no) {
	if (no->esquerda != NULL)
		remover(arvore, no->esquerda);
	
	if (no->direita != NULL)
		remover(arvore, no->direita);
	
	if (no->pai == NULL) {
		
		arvore->raiz = NULL;
	} else {
		
		if (no->pai->esquerda == no)
			no->pai->esquerda = NULL;
		else
			no->pai->direita = NULL;
	}
	
	free(no);
}

void percorrer(No* no) {
	if (no != NULL) {
		
		printf("%f", no->valor);
		percorrer(no->esquerda);
		percorrer(no->direita);
	}
}

int altura(No* no) {
	int esquerda = 0,direita = 0;
		if (no->esquerda != NULL) {
		
			esquerda = altura(no->esquerda) + 1;
		}
		if (no->direita != NULL) {
			
			direita = altura(no->direita) + 1;
		}
	
	return esquerda > direita ? esquerda : direita;
}

int fb(No* no) {
	int esquerda = 0,direita = 0;
	
	if (no->esquerda != NULL) {
		
		esquerda = altura(no->esquerda) + 1;
	}
	if (no->direita != NULL) {
		
		direita = altura(no->direita) + 1;
	}
	
	return esquerda - direita;
}

No* rse(No* no) {
	No* pai = no->pai;
	No* direita = no->direita;
	
	no->direita = direita->esquerda;
	no->pai = direita;
	
	direita->esquerda = no;
	direita->pai = pai;
	
	return direita;
}

No* rsd(No* no) {
	No* pai = no->pai;
	No* esquerda = no->esquerda;
	
	no->esquerda = esquerda->direita;
	no->pai = esquerda;
	
	esquerda->direita = no;
	esquerda->pai = pai;
	
	return esquerda;
}

No* rde(No* no) {
	no->direita = rsd(no->direita);
	return rse(no);
}

No* rdd(No* no) {
	no->esquerda = rse(no->esquerda);
	return rsd(no);
}
