#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

struct lab
{

    int status, i, j;
    struct lab *prox;
};
struct pilha
{
    int pos;
    struct pilha *prox;
};
typedef struct lab lab;
typedef struct pilha pilha;
void clear()
{
    printf("\n\t");
    system("pause");
    system("cls");
}
Lab* new_lab()
{
    Lab* l = (Lab*) malloc(sizeof(Lab));
    if(l != NULL) *l = NULL;
    return l;
}
void del_lab(Lab* l)
{
    if(l == NULL) *l = NULL;
    else
    {
        lab* no;
        while((*l != NULL))
        {
            no = *l;
            *l = (*l)->prox;
            free(no);
        }
        free(l);
    };
}
int size_i(Lab* l)
{
    if(l == NULL) return 0;
    int c = 0;
    lab *no = *l;
    while(no != NULL)
    {
        if(no->i >= c)
            c = no->i;
        no = no->prox;
    }
    return (c + 1);
}
int size_j(Lab* l)
{
    if(l == NULL) return 0;
    int r = 0;
    lab *no = *l;
    while(no != NULL)
    {
        if(no->j >= r)
            r = no->j;
        no = no->prox;
    }
    return (r + 1);
}
int empty_lab(Lab* l)
{
    if(l == NULL) return 1;
    if(*l == NULL) return 1;
    return 0;
}
int insert_lab(Lab* l, int value, int i, int j)
{
    if(l == NULL) return 0;
    lab* no = (lab*) malloc(sizeof(lab));
    if(no == NULL) return 0;
    no->status = value;
    no->i = i;
    no->j = j;
    no->prox = NULL;
    if((*l) == NULL) *l = no;
    else
    {
        lab *aux = *l;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
    }
    return 1;
}
int remove_lab(Lab* l, int i, int j)
{
    if(l == NULL) return 0;
    lab *ant, *no = *l;
    while(no != NULL && (no->i != i || no->j != j))
    {
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0;
    if(no == *l) *l = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}
int lab_pos(Lab* l, int i, int j, int *res)
{
    if(empty_lab(l)) return 0;
    lab *no = *l;
    while(no != NULL && (no->i != i || no->j != j))
    {
        no = no->prox;
    };
    if(no == NULL) return 0;
    else
    {
        *res = no->status;
        return 1;
    }
}
int print_lab(Lab* l, Pilha* p)
{
    if(l == NULL) return 0;
    int t1 = size_i(l), t2 = size_j(l), mat [t1][t2], d = 0;
    consulta(p, &d);
    for(int i = 0; i < t1; i++)
    {
        printf("\t");
        for(int j = 0; j < t2; j++)
        {
            lab *no = *l;
            while(no != NULL && (no->i != i || no->j != j))
            {
                no = no->prox;
            }
            if(no == NULL)
                mat[i][j] = 1;
            else
            {
                mat[i][j] = no->status;
            }
            if(d/100 == i && d%100 == j)
                printf("%c", 1);
            else if(mat[i][j] == 0)
                printf(" ");
            else if(mat[i][j] == 1)
                printf("%c", 219);
            else if(mat[i][j] == 2)
                printf(".");
            else if(mat[i][j] == 3)
                printf("%c", 176);
            else
                printf("%c", 15);
        }
        printf("\n");
    }
    return 1;
}
Pilha* cria_pilha()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if(p != NULL) *p = NULL;
    return p;
}
void deleta(Pilha* p)
{
    if(p != NULL)
    {
        pilha *no;
        while((*p) != NULL)
        {
            no = *p;
            *p = (*p)->prox;
            free(no);
        }
        free(p);
    }
}
int pilha_vazia(Pilha* p)
{
    if(p == NULL) return 1;
    if(*p == NULL) return 1;
    return 0;
}
int insere(Pilha* p, int l, int c)
{
    if(p == NULL) return 0;
    pilha* no = (pilha*) malloc(sizeof(pilha));
    if(no == NULL) return 0;
    no->pos = ((l*100) + c);
    no->prox = (*p);
    *p = no;
    return 1;
}
int remove_pilha(Pilha* p)
{
    if(pilha_vazia(p)) return 0;
    pilha *no = *p;
    *p = no->prox;
    free(no);
    return 1;
}
int consulta(Pilha* p, int *x)
{
    if(p == NULL) return 0;
    if((*p) == NULL) return 0;
    *x = (*p)->pos;
    return 1;
}
int move_rato(Pilha* p, Lab* l)
{
    if(pilha_vazia(p)) return 0;
    if(empty_lab(l)) return 0;
    int d = 0, t1 = size_i(l), t2 = size_j(l);
    do
    {
        print_lab(l, p);
        consulta(p, &d);
        int cont0 = 0, cont2 = 0, arri[4], arrj[4];
        int d1 = d/100, d2 = d%100, value = 0;
        for(int i = d1 - 1; i < d1 + 2; i++)
        {
            for(int j = d2 - 1; j < d2 + 2; j++)
            {
                if((i == d1 && j == d2) || (i != d1 && j != d2));
                else
                {
                    lab_pos(l, i, j, &value);
                    if(value == 0)
                    {
                        arri[cont0] = i;
                        arrj[cont0] = j;
                        cont0++;
                    }
                    else if(value == 2)
                        cont2++;
                }
            }
        }
        if(cont0 > 0)
        {
            insere(p, arri[0], arrj[0]);
            remove_lab(l, d1, d2);
            insert_lab(l, 2, d1, d2);
        }
        else
        {
            remove_pilha(p);
            remove_lab(l, d1, d2);
            if(cont2 == 1)
                insert_lab(l, 3, d1, d2);
            else insert_lab(l, 2, d1, d2);
        }
        clear();
        if(pilha_vazia(p)) return 0;
    }
    while(d != (t1-2)*100 + (t2-1));
    return 1;
}
