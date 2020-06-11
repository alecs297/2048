# Projet Final - Jeu 2048

## Introduction

![Logo du 2048](https://2048game.com/favicon.ico)

### Le 2048 est un des jeux vidéos de type puzzle les plus connus

Conçu en 2014 par Gabriele Cirulli, 2048 un jeu un joueur ayant vu le jour sur la majorité des plateformes (Navigateur, Android, iOS, Nintendo 3DS, Apple TV, etc...)

Il a originalement été écrit en Javascript et CSS en un seul weekend puis été publié en tant que logiciel Open-Source.

Le but du jeu est de fusionner les nombres ensemble (puissances de 2) et d’atteindre le nombre 2048. Une grille est constitué de 4 lignes et 4 colonnes.

Chaque cellule peut être vide ou contenir un nombre.A l’état initial la grille possède simplement deux carrés initialisés. Suivant les déplacements souhaités de l’utilisateur, les tuiles vont s’additionner ou se déplacer.

A chaque déplacement, une tuile apparaît de manière aléatoire sur le plateau.

> Source: Wikipédia

## Cahier des Charges & Répartition

| Tâches | Responsable |
| --- | --- |
| Initialisation d'un plateau de taille n x n | `Quentin` |
| Détection des coups légaux | `Quentin` |
| Déplacement des tuiles selon les règles | `Alexandru` |
| Evaluation et détection de l'Etat du tableau | `Alexandru` |
| Système de score et timer | `Quentin` |
| Affichage en couleur selon les valeurs des tuiles | `Alexandru` |
| MakeFile | `Quentin` |
| Documentation | `Alexandru` |

## Structure

``` main.c      => Gestion de la boucle principale et du tableau
fonctions.h => Fichiers en-tête des fonctions du jeu
fonctions.c => Fonctions du jeu
Makefile    => Makefile pour la compilation du jeu
README.txt  => Ce Fichier
README.MD   => Ce fichier mais en syntaxe MarkDown
2048.pdf    => Rapport du projet
```

## Compilation et Utilisation

### Pour compiler via MakeFile

```bash
make
```

### Pour lancer le jeu une fois compilé

```bash
./2048
```

## Interface (Images)

### Menu du jeu

![Menu du jeu](https://www.fouiny.wtf/p/sewgp5rdda.png)

### Interface en jeu

![Interface en jeu](https://www.fouiny.wtf/p/mcuvjhe5mb.png)

### Ecran de fin

![Ecran de fin](https://www.fouiny.wtf/p/kpr2ky5ber.png)
