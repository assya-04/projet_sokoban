#include "sokoban.h"

char ask_player_move() 
{
    char move;
    printf("Entrez votre mouvement (w/a/s/d) : ");
    scanf(" %c", &move);
    return move;
}

int deplacer(char tab[SIZE][SIZE], joueur *j, char move) 
{
    int new_x = j->x;
    int new_y = j->y;

    if(move=='w')
    {
        new_x=new_x-1;
    }
    else if(move=='s')
    {
        new_x=new_x+1;
    }
    else if(move=='a')
    {
        new_y=new_y-1;
    }
    else if(move=='d')
    {
        new_y=new_y+1;
    }
    else
    {
        return 0;
    }


    if (tab[new_x][new_y] == ' ' || tab[new_x][new_y] == EMPLACEMENT) {
        // Déplacer le joueur
        tab[j->x][j->y] = ' ';
        j->x = new_x;
        j->y = new_y;
        tab[j->x][j->y] = PLAYER;
        return 1;
    } else if (tab[new_x][new_y] == BOX) 
    {
        // Vérifier si on peut pousser la boîte
        int box_new_x = new_x + (new_x - j->x);
        int box_new_y = new_y + (new_y - j->y);
        if (tab[box_new_x][box_new_y] == ' ' || tab[box_new_x][box_new_y] == EMPLACEMENT) {
            // Pousser la boîte
            tab[box_new_x][box_new_y] = BOX;
            tab[new_x][new_y] = PLAYER;
            tab[j->x][j->y] = ' ';
            j->x = new_x;
            j->y = new_y;
            return 1;
        }
    }
    return 0; // mouvement impossible
}
