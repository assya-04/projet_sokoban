#include "sokoban.h"

void init_tab(char tab[SIZE][SIZE]) 
{
    for(int i = 0; i < SIZE; ++i) 
    {
        for(int j = 0; j < SIZE; ++j) 
        {
            tab[i][j] = ' ';
        }
    }

    for(int i = 0; i < SIZE; ++i) 
    {
        tab[0][i] = MUR;
        tab[SIZE - 1][i] = MUR;
        tab[i][0] = MUR;
        tab[i][SIZE - 1] = MUR;
    }
}

void affiche_tab(char tab[SIZE][SIZE]) 
{
    for(int i = 0; i < SIZE; ++i) 
    {
        for(int j = 0; j < SIZE; ++j) 
        {
            printf("%c", tab[i][j]);
        }
        printf("\n"); 
    }
}

