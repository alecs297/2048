/**
 * @file main.c
 * @author Moldovan Alexandru (alexandru.nicolae.moldovan@eisti.fr)
 * @author Bouillon Quentin (quentin.bouillon@eisti.fr)
 * @brief 
 * @version 0.1
 * @date 05-05-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "fonctions.h"

/**
 * @brief Fonction principale, gère le bon fonctionnement du 2048
 * 
 * @return int 
 */
int main(void) {
    int n = 0;
    int r = 0;
    int score = 0;
    int** tab = NULL;
    time_t timer;
    srand ( time(NULL) );
    atexit(clear_console);

    menu();
    n = saisie_taille();
    tab = nouveau_tableau(tab, n);
    timer = time(NULL);

    do {

        placement_random(tab, n);
        jouer(tab, n);
        r = est_fini(tab, n);

    } while (!r);

    score = evaluer_tableau(tab, n);
    clear_console();
    game_over();
    afficher_tableau(tab, n);
    printf("Temps total: \e[94m%.2f\e[0m sec\n\n", (double) ((time(NULL) - timer)));
    if (r == 1) {
        printf("2048!\nVous avez gagné avec un score de \e[92m%d\e[0m\n\n\n", score);
    } else {
        printf("\e[91m\e[1mAucun coup disponible!\e[0m\n\nVous avez perdu avec un score de \e[91m%d\e[0m\n\n\n", score);
    }
    for (r = 0; r < n; r++) {
        free(tab[r]);
    }
    free(tab);
    printf("\n\nAppuyez sur entrée pour quitter\n");
    getchar();
    return 0;
}
