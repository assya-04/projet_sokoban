
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

struct P_j
{
    int x;
    int y;
};
typedef struct P_j joueur;

struct B_b
{
    int x;
    int y;
};
typedef struct B_b box;

struct emplacement
{
    int x;
    int y;
};
typedef struct emplacement empl;

void init_tab(char tab[SIZE][SIZE]);
void placement(char tab[SIZE][SIZE], joueur *j, box *b, empl *em);
void affiche_tab(char tab[SIZE][SIZE]);
char ask_player_move();
//void check_deplacement(char tab[SIZE][SIZE], char move);
int deplacer(char tab[SIZE][SIZE], joueur *j, char move) ;

#endif