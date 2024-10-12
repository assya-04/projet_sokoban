#include "sokoban.h"


int main()
{
    char tab[SIZE][SIZE];
    joueur j;
    empl em;
    box b;
    srand(time(NULL));
    init_tab(tab);
    placement(tab, &j, &b, &em);
    while(1)
    {
        //system("clear");
        affiche_tab(tab);
        char move=ask_player_move();
        if(deplacer(tab, &j,move,&b, &em)==0)
        {
            printf("mouvement impossible.\n");
        }
    }
   
    return 0;
}