#include "yam.h"


/**

Cette fonction vérifie si la combinaison d'un joueur est un YAHTZEE

Elle vérifie simplement si le dé précédent est égal au dé présent, en partant du 2e dé vers le dernier
La fonction retourne 0 si ça n'est pas le cas.
Sinon, si tous les tests se passent bien, elle renvoie la valeur de YAHTZEE.

**/

/*int same_number(int des[MAX_DICES])
{
	for ( int i = 1; i < MAX_DICES; i++ )
		if ( des[i] != des[i-1] )
			return (0);

	return (SAME);
}*/

/**

Cette fonction vérifie si la combinaison d'un joueur est une suite

Elle vérifie simplement si le dé précédent incrémenté de 1 est égal au dé présent, en partant de 2e dé vers le dernier
La fonction retourne 0 si ça n'est pas le cas.
Sinon, si tous les tests se passent bien, elle renvoie la valeur de SUITE

Le tableau étant trié, on a besoin de vérifier la suite que dans un sens.

**/

/*int suite(int des[MAX_DICES])
{

	for( int i = 1; i < MAX_DICES; i++ )
		if( des[i] != des[i-1] + 1 )
			return (0);

	return (SUITE);
}*/


/**

Cette fonction vérifie si la combinaison d'un joueur est une suite

Elle vérifie simplement si le dé précédent incrémenté de mod est égal au dé présent, en partant du 2e dé vers le dernier
La fonction retourne 0 si ça n'est pas le cas.
Sinon, si tous les tests se passent bien, elle renvoie la valeur de score

Le tableau étant trié, on a besoin de vérifier la suite que dans un sens.

**/

int suite(int des[MAX_DICES], int mod, int score)
{

	for( int i = 1; i < MAX_DICES; i++ )
		if( des[i] != des[i-1] + mod )
			return (0);

	return (score);
}

/**

Cette fonction vérifie si la combinaison d'un joueur est un full

La fonction vérifie si le dé précédent est égal au dé présent
Sinon, si le dé présent actuel est compris entre le 3e et l'avant-dernier dé alors qu'on a rencontré qu'un type de dé jusque là.
Dans ce cas, occurences est incrémenté pour être vrai au prochain test (il y a au moins 2 valeurs)

**/

int full(int des[MAX_DICES])
{
    int occurences = 0;
    for( int i = 1; i < MAX_DICES; i++ )
        if( des[i] != des[i-1] ) {
            if( i >= 2 && i <= MAX_DICES-2 && !occurences ) {
                occurences++;
                continue;
            }
            return (0);
        }

    return (FULL);
}

/**

C

**/

int double_triple(int des[MAX_DICES])
{
	int score = 0;
	int num = 0;

	for( int i = 1; i < MAX_DICES; i++ ) {
		if( des[i] == des[i-1] ) {
			num++;
		} else if ( des[i] && num != 0) {
			score += des[i-1] * (num + 1);
			num = 0;
		}
	}

	return (score);
}


/**

Cette fonction trie la combinaison de dés du joueurs, puis renvoie le score obtenu de cette combinaison, par ordre de priorité :
	- S'il n'y a pas Yahtzee, il peut y avoir suite
	- S'il n'y a pas suite, il peut y avoir full
	- S'il n'y a pas full, il peut y avoir des doubles ou des triples
	- Sinon, il n'y a rien ( 0 de score pour la combinaison )
À chaque vérifiaction, la variable `score` est modifiée et retournée si sa valeur est non nulle.

**/

int get_score(int des[MAX_DICES])
{
	int score = 0;

	sort_des(des);
	if ((score = suite(des, 0, SAME)))
		return (score);
	if ((score = suite(des, 1, SUITE)))
		return (score);
	if ((score = full(des)))
		return (score);
	if ((score = double_triple(des)))
		return (score);

	return 0;
}