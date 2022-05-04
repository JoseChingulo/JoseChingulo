#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

typedef struct lab* Lab;
typedef struct pilha* Pilha;

void clear();
Lab* new_lab();
void free_lab(Lab* l);
void del_lab(Lab* l);
int size_i(Lab* l);
int size_j(Lab* l);
int empty_lab(Lab* l);
int insert_lab(Lab* l, int value, int i, int j);
int remove_lab(Lab* l, int i, int j);
int lab_pos(Lab* l, int i, int j, int *res);
int print_lab(Lab* l, Pilha* p);
Pilha* cria_pilha();
void deleta(Pilha* p);
int pilha_vazia(Pilha* p);
int insere(Pilha* p, int l, int c);
int remove_pilha(Pilha* p);
int consulta(Pilha* p, int *x);
int move_rato(Pilha* p, Lab* l);


#endif // ARQUIVO_H_INCLUDED
