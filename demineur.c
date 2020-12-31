#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jeu(int nb)
{
    char Tab_Mine[nb][nb];
    char Tab_Cache[nb][nb];
    int Tab_verif[9][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    // Genere les tableau
    for(int i=0; i < nb; i++)
    {
        for(int j=0; j < nb; j++)
        {
            Tab_Mine[i][j] = '-';
            Tab_Cache[i][j] = 'X';
        }
    }

    // Generation des mines
    int x = 0,y = 0;
    srand(time(NULL));
    for(int i = 0; i < nb; i++)
    {
        x = (rand()%(nb));
        y = (rand()%(nb));
        Tab_Mine[x][y] = 'M';
    }

    // Generation des Nombre d'indication
    for(int i=0; i < nb; i++)
    {
        for(int j=0; j < nb; j++)
        {
            // Toute le case du tableau
            char pos_x = 0, pos_y = 0;
            int nb_t = 0;

            // Met la case a part
            pos_x = i;
            pos_y = j;

            if (Tab_Mine[i][j] != 'M')
            {
                for (int z = 0; z < 9; z++)
                {   
                    // Met encore la case a part a partir de la case a part
                    int pos_x_temp = pos_x;
                    int pos_y_temp = pos_y;

                    // Ajoute la Tab_Verif
                    pos_x_temp += Tab_verif[z][0];
                    pos_y_temp += Tab_verif[z][1];
                    
                    // Verifie que sa ne soit pas une mine
                    /////// VERIFICATION DE SI IL EST SORTIT DE LA GRILLE (Reprend met en dessous de la case voulu mais pas voulu xDD)
                    if (pos_x_temp <= 9 && pos_x_temp >= 0 && pos_y_temp <= 9 && pos_y_temp >= 0)
                    {
                        if (Tab_Mine[pos_x_temp][pos_y_temp] == 'M')
                        {
                            nb_t += 1;
                        }
                    }
                }
                char caseBis;
                switch (nb_t)
                {
                    case 1:
                        caseBis = '1';
                        break;
                    case 2:
                        caseBis = '2';
                        break;
                    case 3:
                        caseBis = '3';
                        break;
                    case 4:
                        caseBis = '4';
                        break;
                    case 5:
                        caseBis = '5';
                        break;
                    case 6:
                        caseBis = '6';
                        break;
                    case 7:
                        caseBis = '7';
                        break;
                }
                // Verifie que le nombre n'est pas egal a 0
                if(nb_t != 0)
                {
                    Tab_Mine[i][j] = caseBis;
                }
                
                nb_t = 0;
            }
        }
    }

    // Commence a jouer
    
    int mine = nb;
    while (mine != 0)
    {
        // Affiche le tableau
        printf("   ");
        for (int i = 0; i < nb; i++)
        {
            printf(" %d ", i);
        }
        printf("\n");
        printf("   ");
        for (int i = 0; i < nb; i++)
        {
            printf("---");
        }
        printf("\n");
        for(int i=0; i < nb; i++)
        {
            printf("%d |", i);
            for(int j=0; j < nb; j++)
            {
                printf(" %c ", Tab_Cache[i][j]);
            }
            printf("\n");
        }
        // -----------------

        char casea = '?';

        printf("Case a coche ou a decouvrir ? (c ou d)");

        scanf("%c", &casea);

        switch (casea)
        {
        case 'd':
            printf("\nCase ? (x y) ");
            scanf("%d %d", &x, &y);
            Tab_Cache[x][y] = Tab_Mine[x][y];
            break;
        
        case 'c':
            printf("\nCase a decouvrir ? (x y) ");
            scanf("%d %d", &x, &y);
            Tab_Cache[x][y] = 'O';
            break;

        }

        if(Tab_Cache[x][y] == 'M')
        {
            mine = 0;
        }

    }
    
    // ---------------

    

}

int main(void)
{
    int nb = 0;
    printf("Tableau :\n");
    printf("1. 10x10\n");

    scanf("%d", &nb);

    switch (nb)
    {
    case 1:
        nb = 10;
        jeu(10);
        break;
    
    default:
        break;
    }

}