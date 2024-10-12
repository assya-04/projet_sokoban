#include "sokoban.h"


char ask_player_move() 
{
    char move;
    printf("Entrez votre mouvement (w/a/s/d) : ");
    scanf(" %c", &move);
    return move;
}

int deplacer(char tab[SIZE][SIZE], joueur *j, char move, box *b, empl *em) 
{
    int new_x = j->x;
    int new_y = j->y;

    if(move == 'w') {
        new_x--;
    } else if(move == 's') {
        new_x++;
    } else if(move == 'a') {
        new_y--;
    } else if(move == 'd') {
        new_y++;
    } else {
        return 0; // Mouvement invalide
    }

    // Déplacer le joueur si possible
    if (tab[new_x][new_y] == ' ' || tab[new_x][new_y] == EMPLACEMENT) {
        // Déplacer le joueur
        tab[j->x][j->y] = ' ';
        j->x = new_x;
        j->y = new_y;
        tab[j->x][j->y] = PLAYER;
    } else if (tab[new_x][new_y] == BOX) {
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
            // Mettre à jour la position de la boîte
            b->x = box_new_x;
            b->y = box_new_y;
        } else {
            return 0; // Mouvement impossible
        }
    } else {
        return 0; // Mouvement impossible
    }

    // Vérification de la victoire
    if (b->x == em->x && b->y == em->y) {
        printf("Félicitations vous avez gagné !\n");
        exit(0);
    }

    // Vérification de la défaite
    if ((b->x == 1 && b->y == 1) ||
        (b->x == 1 && b->y == (SIZE - 1)) ||
        (b->x == (SIZE - 1) && b->y == 1) ||
        (b->x == (SIZE - 1) && b->y == (SIZE - 1))) {
        printf("Boîte coincée, vous avez perdu !\n");
        exit(0);
    }

    return 1; // Mouvement réussi
}
