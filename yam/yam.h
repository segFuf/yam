#ifndef YAHTZEE_H_
#define YAHTZEE_H_


#include <stdio.h>	//printf()
#include <stdlib.h>	//rand(), srand()
#include <unistd.h>	//sleep()
#include <time.h>	//time()


#define MAX_ROUNDS 12
#define MAX_TRIES 3
#define MAX_DICES 7
#define FACES 8
#define NUM_PLAYERS 2

//score patterns
#define SAME 50
#define SUITE 40
#define FULL 35

#define abs( a ) ( a > 0 ? a : -a )

/*           */
/*  utils.c  */
/*           */

///L'utilisateur choisit un ou plusieurs dés parmi une liste de dés
void choice(int des[MAX_DICES]);
///Intervertit deux valeurs
void swap(int *a, int *b);
/// Trie les dés
void sort_des(int des[MAX_DICES]);



/*               */
/*  get_score.c  */
/*               */

///Renvoie le score score d'une suite de modifier mod
int suite(int des[MAX_DICES], int mod, int score);
///Renvoie le score d'un full si la combinaison du joueur est un full
int full(int des[MAX_DICES]);
///Renvoie le score des doubles et triples que le joueur a dans sa combinaison
int double_triple(int des[MAX_DICES]);
///Renvoie le score correspondant à la combinaison de dés du joueur
int get_score(int des[MAX_DICES]);


/*               */
/*     yam.c     */
/*               */

///Permet de choisir les des à garder d'une combinaison. Renvoie le nombre de dés restants
int chooseDices(int num_dices, int des_in[MAX_DICES], int des_out[MAX_DICES], int trial);
///Déroulement d'un lancer de dés. Renvoie le nombre de dés restants
int throwDices(int num_dices, int des[MAX_DICES], int trial);
///Déroulement d'un tour de joueur, en MAX_TRIES lancers. Ajoute le score obtenu au score du joueur.
void play(int *player);

#endif /*YAHTZEE_H_*/