#ifndef YAM_H_
#define YAM_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 12
#define MAX_TRIES 3
#define MAX_DICES 7
#define FACES 8
#define PLAYERS 2

#define EVER (;;)
#define abs( a ) ( a > 0 ? a : -a )

void choice(int des[6]);
int numplayers( char *str );
void removePoints( int player, int points );
int get_score(int des[7]);

#endif // YAM_H_