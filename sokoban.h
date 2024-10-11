#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define MUR '#'
#define BOX 'X'
#define PLAYER 'P'
#define EMPLACEMENT 'O'

void init_tab(char tab[SIZE][SIZE]);
void affiche_tab(char tab[SIZE][SIZE]);

#endif