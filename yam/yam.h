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
#define SHAPES MAX_DICES+1

//score patterns
#define SCORE_YAHTZEE 50
#define SCORE_SUITE 40
#define SCORE_FULL 35

#define abs( a ) ( a > 0 ? a : -a )

enum {
	YAHTZEE		= 0,
	SUITE		= 1,
	FULL		= 2
};

/*           */
/*  utils.c  */
/*           */

///Affiche les dés du tableau 'des' de 0 à 'max'
void displayDices( int des[MAX_DICES], int max );
///L'utilisateur choisit un ou plusieurs dés parmi une liste de dés
void choice(int des[MAX_DICES]);
///Intervertit deux valeurs
void swap(int *a, int *b);
/// Trie les dés
void sort_des(int des[MAX_DICES]);
/// Mets un tableau à 1
void initTab( int *tab, int size );

/*               */
/*  get_score.c  */
/*               */

///Renvoie si une config de des correspond à une suite
int suite(int des[MAX_DICES], int mod);
///Renvoie le score d'un full si la combinaison du joueur est un full
int full(int des[MAX_DICES]);
///Renvoie le score des doubles et triples que le joueur a dans sa combinaison
int multiples(int des[MAX_DICES], int shapes[SHAPES]);
///Renvoie le score correspondant à la combinaison de dés du joueur
int get_score(int des[MAX_DICES], int shapes[SHAPES]);


/*               */
/*     yam.c     */
/*               */

///Permet de choisir les des à garder d'une combinaison. Renvoie le nombre de dés restants
int chooseDices(int num_dices, int des_in[MAX_DICES], int des_out[MAX_DICES], int trial);
///Déroulement d'un lancer de dés. Renvoie le nombre de dés restants
int throwDices(int num_dices, int des[MAX_DICES], int trial);
///Déroulement d'un tour de joueur, en MAX_TRIES lancers. Ajoute le score obtenu au score du joueur.
void play(int *player, int shapes[SHAPES]);

#endif /*YAHTZEE_H_*/