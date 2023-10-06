typedef struct no {
	struct no* pai; //ponteiro para o n� pai
	struct no* esquerda; //ponteiro para o n� filho a esquerda
	struct no* direita; //ponteiro para o n� filho a direita
	float valor; //conte�do de um n� arbitr�rio da �rvore
} No;

typedef struct arvore {
	struct no* raiz;
} Arvore;

Arvore* cria();
int vazia(Arvore* arvore);
No* adiciona(Arvore* arvore, No* pai, float valor);
void remover(Arvore* arvore, No* no);
void percorrer(No* no);
int altura(No* no);
int fb(No* no);
No* rse(No* no);
No* rsd(No* no);
No* rde(No* no);
No* rdd(No* no);
