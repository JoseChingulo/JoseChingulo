#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arquivo.h"

int main()
{
    Lab *l;
    l = new_lab();
    Pilha *p;
    p = cria_pilha();
    insere(p, 2, 2);
    srand(time(NULL));
    int lc = 10;
    for(int i = 0; i < lc; i++)
        for(int j = 0; j < lc; j++)
        {
            if(i == 0 || i == lc - 1)
                insert_lab(l, 1, i, j);
            else if(j == 0 || j == lc - 1)
            {
                if(i == lc - 2 && j == lc - 1)
                    insert_lab(l, 0, i, j);
                else
                    insert_lab(l, 1, i, j);
            }
            else if(i == 2 && j == 2)
                insert_lab(l, 0, i, j);
            else
                insert_lab(l, rand()%2, i, j);
        }
    if(move_rato(p, l)) printf("\n\tParabens! Seu rato chegou ao fim do labirinto!\n");
    else printf("\n\tO labirinto nao possui saida!\n");
    del_lab(l);
    deleta(p);

    return 0;

}
