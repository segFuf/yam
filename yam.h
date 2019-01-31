#ifndef YAM_H_
#define YAM_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BET_LOW 12
#define BET_HIGH 30
#define MAX_DICES 6
#define MIN_PLAYERS 2
#define MAX_PLAYERS 20
#define POINTS_START 30

#define EVER (;;)
#define abs( a ) ( a > 0 ? a : -a )

void choice(int des[6]);
int numplayers( char *str );
void removePoints( int player, int points );

#endif // YAM_H_