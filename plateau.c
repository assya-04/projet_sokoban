#include "sokoban.h"

void init_tab(char tab[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            tab[i][j] = ' ';
        }
    }

    for (int i = 0; i < SIZE; ++i) 
    {
        tab[0][i] = MUR;
        tab[SIZE - 1][i] = MUR;
        tab[i][0] = MUR;
        tab[i][SIZE - 1] = MUR;
    }
}

void placement(char tab[SIZE][SIZE], joueur *j, box *b, empl *em)
{
    do {
        j->x = rand() % (SIZE - 2) + 1;
        j->y = rand() % (SIZE - 2) + 1;
        b->x = rand() % (SIZE - 2) + 1;
        b->y = rand() % (SIZE - 2) + 1;
        em->x = rand() % (SIZE - 2) + 1;
        em->y = rand() % (SIZE - 2) + &&&&&&1;
    } while ((j->x == b->x && j->y == b->y) || 
             (b->x == em->x && b->y == em->y) || 
             (j->x == em->x && j->y == em->y));

    tab[j->x][j->y] = PLAYER;
    tab[b->x][b->y] = BOX;
    tab[em->x][em->y] = EMPLACEMENT;
}

void affiche_tab(char tab[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            printf("%c", tab[i][j]);
        }
        printf("\n"); 
    }
}