/**
 * @file fonctions.h
 * @author Moldovan Alexandru (alexandru.nicolae.moldovan@eisti.fr)
 * @author Bouillon Quentin (quentin.bouillon@eisti.fr)
 * @brief 
 * @version 0.1
 * @date 05-05-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __2048__
#define __2048__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * @brief Vérification de l'allocation mémoire
 * 
 * @param p Pointeur à vérifier
 */
void check_malloc(void *p);

/**
 * @brief Nettoyage de l'entrée utilisateur
 * 
 */
void vider_buffer(void);

/**
 * @brief Nettoyage de la console
 * 
 */
void clear_console(void);

/**
 * @brief Obtention d'un entier aléatoire entre deux valeurs données
 * 
 * @param x Entier minimum
 * @param y Entier maximum
 * @return int Entier aléatoire
 */
int numero_random(int x, int y);

/**
 * @brief Saisie d'une taille de tableau
 * 
 * @return int Taille entre 2 et 10
 */
int saisie_taille(void);

/**
 * @brief Saisie du caractère de déplacement
 * 
 * @return char caractère choisi
 */
char saisie_sens(void);

/**
 * @brief Affichage d'un code couleur spécifique pour une valeur donnée
 * 
 * @param n Valeur donnée
 */
void couleur(int n);

/**
 * @brief Initialisation d'un tableau
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 * @return int** Pointeur du tableau
 */
int** nouveau_tableau(int** tab, int n);

/**
 * @brief Affichage d'un tableau
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 */
void afficher_tableau(int** tab, int n);

/**
 * @brief Inverse un tableau horizontalement
 * 
 * @param tab Pointeur du tableau à inverser
 * @param n Taille du tableau
 */
void miroir_horizontal(int** tab, int n);

/**
 * @brief Inverse un tableau verticalement
 * 
 * @param tab Pointeur du tableau à inverser
 * @param n Taille du tableau
 */
void miroir_vertical(int** tab, int n);

/**
 * @brief Rapproche toutes les tuiles non-nulles horizontalement
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 * @return int Correspond à la modification ou non du tableau
 */
int vider_horizontale(int** tab, int n);

/**
 * @brief Rapproche toutes les tuiles non-nulles verticalement
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 * @return int Correspond à la modification ou non du tableau
 */
int vider_verticale(int** tab, int n);

/**
 * @brief Déplace les tuiles horizontalement et fusionne les mêmes valeurs
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 * @param r Correspond à la modification ou non du tableau précédemment
 * @return int Correspond à la modification ou non du tableau
 */
int deplacement_horizontal(int** tab, int n, int r);

/**
 * @brief Déplace les tuiles verticalement et fusionne les mêmes valeurs
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 * @param r Correspond à la modification ou non du tableau précédemment
 * @return int Correspond à la modification ou non du tableau
 */
int deplacement_vertical(int** tab, int n, int r);

/**
 * @brief Place 2 (ou 4 avec une chance de 10%)
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 */
void placement_random(int** tab, int n);

/**
 * @brief Evalue le tableau et attribue un score
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 * @return int Score calculé
 */
int evaluer_tableau(int** tab, int n);

/**
 * @brief Vérification de l'état du jeu
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 * @return int 1 si gagné, -1 si perdu, 0 si déplacement possible
 */
int est_fini(int** tab, int n);

/**
 * @brief Fait jouer le joueur
 * 
 * @param tab Pointeur du tableau
 * @param n Taille du tableau
 */
void jouer(int** tab, int n);

/**
 * @brief Affiche le menu avec l'ASCII art
 * 
 */
void menu(void);

/**
 * @brief Affiche Game Over en ASCII art
 * 
 */
void game_over(void);

#endif