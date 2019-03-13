#include "yam.h"



/**

Cette fonction vérifie si la combinaison d'un joueur est une suite

Elle vérifie simplement si le dé précédent incrémenté de mod est égal au dé présent, en partant du 2e dé vers le dernier
La fonction retourne 0 si ça n'est pas le cas.
Sinon, si tous les tests se passent bien, elle renvoie la valeur de score

Le tableau étant trié, on a besoin de vérifier la suite que dans un sens.

**/

int suite( int des[MAX_DICES], int mod, int score )
{
	for( int i = 1; i < MAX_DICES; i++ )
		if( des[i] != des[i-1] + mod )
			return (0);

	return (score);
}

/**

Cette fonction vérifie si la combinaison d'un joueur contient des nombres identiques à la suite.

La fonction vérifie si le dé précédent est égal au dé présent. Dans ce cas, elle ajoute au score le nombre de fois que le nombre est trouvé
Sinon, elle augmente le nombre d'occurences de nombres différents dans le tableau.
Si le score est positif, qu'il n'y a que deux occurences de nombres dans la liste et que les deux occurences sont en plusieurs exemplaires, on retourne la valeur d'un FULL.
Sinon, on retourne le score obtenu.

**/

int double_triple( int des[MAX_DICES] )
{
	int val = 0, score = 0, occ = 0, occ_mult = 0;

	for( int i = 1; i < MAX_DICES; i++ ) {
		if( des[i] == des[i-1] ) {
			if( des[i] != val ) {
				val = des[i];
				score += val;
				occ_mult++;
			} score += val;
		} else
			occ++;
	}

	if( score && occ == 2 && occ_mult == 2 )
		return (FULL);
	return score;
}



/**

Cette fonction trie la combinaison de dés du joueurs, puis renvoie le score obtenu de cette combinaison, par ordre de priorité :
	- S'il n'y a pas Yahtzee, il peut y avoir suite
	- S'il n'y a pas suite, il peut y avoir full
	- S'il n'y a pas full, il peut y avoir des doubles ou des triples
	- Sinon, il n'y a rien ( 0 de score pour la combinaison )
À chaque vérifiaction, la variable `score` est modifiée et retournée si sa valeur est non nulle.

**/

int get_score( int des[MAX_DICES] )
{
	int score = 0;
	sort_des( des );

	for( int i = 0; i < 2; i++ )
		if ((score = suite(des, i, ( i == 0 ? SAME : SUITE ))))
			return (score);

	return double_triple( des );
}