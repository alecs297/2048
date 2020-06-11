/**
 * @file fonctions.c
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

void check_malloc(void *p)
{
    if (p == NULL) {
        printf("Erreur d'allocation, arrêt du programme\n");
        exit(0);
    }
}

void vider_buffer(void)
{
  int c;
  while((c=getchar()) != EOF && c != '\n');
}

void clear_console(void)
{
    system("clear && printf \033c");
}

int numero_random(int x, int y)
{
    return(rand() % (y - x + 1) + x);
}

int saisie_taille(void)
{
    int n = 0;
    do {
        printf("Veuillez saisir une taille (2 < N < 10)\n\nN = ");
        scanf("%d", &n);
        vider_buffer();
    } while(n < 2 || n > 10);
    return n;
}

char saisie_sens(void)
{
    char c = 0;
    printf("Votre déplacement: ");
    scanf("%c", &c);
    vider_buffer();
    return c;
}

void couleur(int n)
{
    int i;
    int t_n[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int t_b[] = {255, 230, 230, 208, 202, 160, 228, 226, 226, 0, 0};
    for (i = 0; i < 11; i++) {
        if (t_n[i] == n) {
            printf("\e[38;5;%dm", t_b[i]);
        }
    }
}

int** nouveau_tableau(int** tab, int n)
{
    int i;
    int j;
    tab = (int**) malloc(n * sizeof(int*));
    check_malloc(&tab);
    for (i = 0; i < n; i++) {
        tab[i] = (int*) malloc(n * sizeof(int));
        check_malloc(&tab[i]);
        for (j = 0; j < n; j++) {
            tab[i][j] = 0;
        }
    }
    return tab;
}

int est_fini(int** tab, int n)
{
    int r = 0;
    int i = 0;
    int j = 0;
    int plein = 1;
    int jouable = 0;

    while (i < n && !r) {
        j = 0;
        while (j < n && !r) {
            r = (tab[i][j] == 2048);

            if (plein) {
                plein = tab[i][j];
            }
            if (j < n-1 && tab[i][j]) {
                jouable += (tab[i][j] == tab[i][j+1]);
            }
            if (i < n-1 && tab[i][j]) {
                jouable += (tab[i][j] == tab[i+1][j]);
            }
            j++;
        }
        i++;
    }
    if (plein && !jouable && !r) {
        r = -1;
    }
    return r;
}

void afficher_tableau(int** tab, int n)
{
    int i;
    int j;
    int k;
    int l;
    if (!est_fini(tab, n)) printf("Score actuel: %d\n\n", evaluer_tableau(tab, n));
    printf("╔════");
    for (i = 1; i < n; i++) {
        printf("╦════");
    }
    printf("╗\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\e[39m\e[49m║");
            if (!tab[i][j]) {
                l = 0;
            } else {
                couleur(tab[i][j]);
                l = (floor(log10(abs(tab[i][j]))) + 1);
            }
            for (k = 0; k < 4-l; k++) {
                printf(" ");
            }
            if (l) {
                printf("%d", tab[i][j]);
            }
        }
        printf("\e[39m\e[49m║\n");
        if (i != n-1) {
            printf("╠════");
            for (k = 1; k < n; k++) {
                printf("╬════");
            }
            printf("╣\n");
        }
        
    }
    printf("╚════");
    for (i = 1; i < n; i++) {
        printf("╩════");
    }
    printf("╝\n\n");
}

void miroir_horizontal(int** tab, int n)
{
    int x;
    int temp;
    int min;
    int max;
    for (x = 0; x < n; x++) {
        min = 0;
        max = n-1;
        while(min < max) {
            temp = tab[x][min];
            tab[x][min] = tab[x][max];
            tab[x][max] = temp;
            min++;
            max--;
        }
    }
}

void miroir_vertical(int** tab, int n)
{
    int y;
    int temp;
    int min;
    int max;
    for (y = 0; y < n; y++) {
        min = 0;
        max = n-1;
        while(min < max) {
            temp = tab[min][y];
            tab[min][y] = tab[max][y];
            tab[max][y] = temp;
            min++;
            max--;
        }
    }
}

int vider_horizontale(int** tab, int n)
{
    int i;
    int j;
    int k;
    int temp;
    int z;
    int r = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            z = 0;
            while (!tab[i][j] && z + j < n) {
                for (k = j; k < n-1; k++) {
                    temp = tab[i][k];
                    tab[i][k] = tab[i][k+1];
                    tab[i][k+1] = temp;
                }
                z++;
                if (tab[i][j]) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

int vider_verticale(int** tab, int n)
{
    int i;
    int j;
    int k;
    int temp;
    int z;
    int r = 0;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            z = 0;
            while (!tab[i][j] && z + i < n) {
                for (k = i; k < n-1; k++) {
                    temp = tab[k][j];
                    tab[k][j] = tab[k+1][j];
                    tab[k+1][j] = temp;
                }
                z++;
                if (tab[i][j]) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

int deplacement_horizontal(int** tab, int n, int r)
{
    int i;
    int j;
    int t = 0;
    if (r) {
        miroir_horizontal(tab, n);
    }
    t = vider_horizontale(tab, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            if (tab[i][j] && tab[i][j] == tab[i][j+1]) {
                tab[i][j] *= 2;
                tab[i][j+1] = 0;
                vider_horizontale(tab, n);
                t = 1;
            }
        }
    }
    if (r) {
        miroir_horizontal(tab, n);
    }
    return t;
}

int deplacement_vertical(int** tab, int n, int r)
{
    int i;
    int j;
    int t = 0;
    if (r) {
        miroir_vertical(tab, n);
    }
    t = vider_verticale(tab, n);
    for (j = 0; j < n; j++) {
        for (i = 0; i < n-1; i++) {
            if (tab[i][j] && tab[i][j] == tab[i+1][j]) {
                tab[i][j] *= 2;
                tab[i+1][j] = 0;
                vider_verticale(tab, n);
                t = 1;
            }
        }
    }
    if (r) {
        miroir_vertical(tab, n);
    }
    return t;
}

void placement_random(int** tab, int n)
{
    int x;
    int y;
    do {
        x = numero_random(0, n-1);
        y = numero_random(0, n-1);
    } while (tab[x][y] != 0);
    tab[x][y] = 2 + 2*(!numero_random(0, 9));
}

int evaluer_tableau(int** tab, int n)
{
    int i;
    int j;
    int r = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            r += tab[i][j];
        }
    }
    return r;
}

void jouer(int** tab, int n)
{
    int r = 1;
    char c;
    do {
        if (!est_fini(tab, n)) {
            clear_console();
            afficher_tableau(tab, n);
            if (r == -1) {
                printf("Mauvaise saisie!\n");
            } else if (r == 0) {
                printf("Rien à déplacer\n");
            }
            printf("Utilisez Z/Q/S/D ou 8/4/2/6 pour vous déplacer.\n");
            c = saisie_sens();
            r = 0;
            if (c == 'z' || c == 'Z' || c == '8') {
                r = (deplacement_vertical(tab, n, 0));
            } else if (c == 'q' || c == 'Q' || c == '4') {
                r = (r || deplacement_horizontal(tab, n, 0));
            } else if (c == 's' || c == 'S' || c == '2') {
                r = (r || deplacement_vertical(tab, n, 1));
            } else if (c == 'd' || c == 'D' ||c == '6') {
                r = (r || deplacement_horizontal(tab, n, 1));
            } else {
                r = -1;
            }
        } else {
            r = 0;
        }
    } while (r != 1 && !est_fini(tab, n));
}

void menu(void)
{
    clear_console();
    printf("\e[1m\e[38;5;148m\n $$$$$$\\   $$$$$$\\  $$\\   $$\\  $$$$$$\\  \n$$  __$$\\ $$$ __$$\\ $$ |  $$ |$$  __$$\\ \n\\__/  $$ |$$$$\\ $$ |$$ |  $$ |$$ /  $$ |\n $$$$$$  |$$\\$$\\$$ |$$$$$$$$ | $$$$$$  |\n$$  ____/ $$ \\$$$$ |\\_____$$ |$$  __$$< \n$$ |      $$ |\\$$$ |      $$ |$$ /  $$ |\n$$$$$$$$\\ \\$$$$$$  /      $$ |\\$$$$$$  |\n\\________| \\______/       \\__| \\______/\n\n\e[0m");
    printf("\e[4m\e[1mComment jouer?\n\n\e[0mDéplacez les tuiles en utilisant votre clavier. Lorsque deux tuiles de la même valeur se touchent, elles fusionnent!\nPour gagner la partie, atteignez \e[1m\e[38;5;148m2048\e[0m avec une tuile.\nAttention, le jeu se finit lorsqu'il n'y a plus de place sur le plateau!\n\n\e[4m\e[1mDifficulté\e[0m\n\nMoins il y a de cases, plus le jeu est difficile\n\n\e[91m[Expert : 2x2]  \e[38;5;148m[Normal: 4x4]  \e[92m[Amateur: 6x6]\n\n\e[0m");
}

void game_over(void)
{
    printf("\e[1m\e[38;5;148m $$$$$$\\                                                                                  \n$$  __$$\\                                                                                 \n$$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\         $$$$$$\\ $$\\    $$\\  $$$$$$\\   $$$$$$\\  \n$$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\       $$  __$$\\\\$$\\  $$  |$$  __$$\\ $$  __$$\\ \n$$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |      $$ /  $$ |\\$$\\$$  / $$$$$$$$ |$$ |  \\__|\n$$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|      $$ |  $$ | \\$$$  /  $$   ____|$$ |      \n\\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\       \\$$$$$$  |  \\$  /   \\$$$$$$$\\ $$ |      \n \\______/  \\_______|\\__| \\__| \\__| \\_______|       \\______/    \\_/     \\_______|\\__|\n\e[0m\n\n");
}