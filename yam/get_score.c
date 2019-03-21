#include "yam.h"



/**

Cette fonction vérifie si la combinaison d'un joueur est une suite

Elle vérifie simplement si le dé précédent incrémenté de mod est égal au dé présent, en partant du 2e dé vers le dernier
La fonction retourne 0 si ça n'est pas le cas.
Sinon, si tous les tests se passent bien, elle renvoie 1

Le tableau étant trié, on a besoin de vérifier la suite que dans un sens.

**/

int suite( int des[MAX_DICES], int mod )
{
	for( int i = 1; i < MAX_DICES; i++ )
		if( des[i] != des[i-1] - mod )
			return 0;

	return 1;
}

/**

Cette fonction vérifie si la combinaison d'un joueur contient des nombres identiques à la suite.

La fonction vérifie si le dé précédent est égal au dé présent. Dans ce cas, elle ajoute au score le nombre de fois que le nombre est trouvé
Sinon, elle augmente le nombre d'occurences de nombres différents dans le tableau.
Si le score est positif, qu'il n'y a que deux occurences de nombres dans la liste et que les deux occurences sont en plusieurs exemplaires, on retourne la valeur d'un FULL.
Sinon, on retourne le score obtenu.

**/

int multiples( int des[MAX_DICES], int shapes[SHAPES] )
{
	int val = 0, score = 0;
	int occ_mult = 0, occ_val = 0, occ = 1;
	int multiples[SHAPES-3] = { };

	for( int i = 1; i < MAX_DICES; i++ ) {
		if( des[i] == des[i-1] ) {
			if( des[i] != val ) {
				if( shapes[occ_val+1] && occ_val > 1 ) {
					shapes[occ_val+1] = 0;
					multiples[occ_val-2] = 1;
					score += occ_val * val;
				}
				val = des[i];
				occ_val = 1;
				occ_mult++;
			}
			occ_val++;
		} else {
			occ++;
		}
	}

	if( shapes[occ_val+1] && occ_val > 1 ) {
		shapes[occ_val+1] = 0;
		multiples[occ_val-2] = 1;
		score += occ_val * val;
	}
	

	if( score && occ == 2 && occ_mult == 2 ) {
		for( int i = 0; i < SHAPES-3; i++ ) {
			if(multiples[i]) {
				shapes[i+3] = 1;
			}
		}

		if( shapes[FULL] ) {
			shapes[FULL] = 0;
			return (SCORE_FULL);
		}

		score = 0;
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

int get_score( int des[MAX_DICES], int shapes[SHAPES] )
{
	sort_des( des );

	for( int i = 0; i < 2; i++ ) {
		if( suite(des, i) ) {
			if( shapes[i] ) {
				shapes[i] = 0;
				return ( i == 0 ? SCORE_YAHTZEE : SCORE_SUITE );
			} return (0);
		}
	}

	return multiples( des, shapes );
}