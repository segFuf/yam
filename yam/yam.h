#ifndef YAHTZEE_H_
#define YAHTZEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ROUNDS 12
#define MAX_TRIES 3
#define MAX_DICES 7
#define FACES 8
#define NUM_PLAYERS 2

//shapes
#define SAME 50
#define SUITE 40
#define FULL 35

#define EVER (;;)
#define abs( a ) ( a > 0 ? a : -a )

//utils.c
void choice(int des[MAX_DICES]);
void sort_des(int des[MAX_DICES]);

//get_score.c
int numplayers( char *str );
void removePoints( int player, int points );
int get_score(int des[MAX_DICES]);

#endif /*YAHTZEE_H_*/