#include "yam.h"

//A FAIRE :
// - clear l'ecran a des moments precis
// - plus belle interface graphique
// - rajouter des couleurs
// - ptits truc jolis qui servent a rien (genre un dessin de de en ascii ?)
// - mettre les define dans un .h et les fonctions abs et numplayers dans un autre .c
// - faire un makefile


int PLAYERS[MAX_PLAYERS];
int NUM_PLAYERS;


int numplayers( char *str ) {
	int c = 0;
	for( int i = 0; str[i]; i++ ) {
		if( str[i] < '0' || str[i] > '9') continue;
		if( c ) c *= 10;
		c += str[i] - '0';
	}
	printf("%i\n", c);
	return ( c > MAX_PLAYERS ) ? MAX_PLAYERS : c;
}


void removePoints( int player, int points ) {
	if ( points > PLAYERS[player] ) {
		PLAYERS[player] = 0;
		printf("\nLe joueur %i a perdu\n", player+1);
	} else {
		PLAYERS[player] -= points;
		printf("\nLe joueur %i n'a plus que %i points\n", player+1, PLAYERS[player]);
	}
}

void play( int player ) {
	int bet = 0;
	int num_dices = MAX_DICES;
	int dice[MAX_DICES];
	int score = 0;
	int old_score = 0;
	int old_num_dices = 0;


	for EVER {
		if ( bet == BET_LOW ) break;
		if ( bet == BET_HIGH ) break;
		printf("Choisissez votre pari : 12 ou 30\n");
		scanf("%i", &bet);
	}

	printf("Vous avez choisi de faire un pari a %i\n", bet);


	while( num_dices ) {
		if( score != old_score || !old_num_dices ) {
			printf("Voici vos des pour ce tour :\n");
			for( int i = 0; i < num_dices; ) { //truc complexe pour juste afficher sur deux lignes les des
				for( int j = 0; j < 2; j++, i++ ) {
					if ( i == num_dices )
						break;
					dice[i] = rand() % 6 + 1;
					printf("des %i: %i		", i+1, dice[i]);
				}
				printf("\n");
			}
		}

		int des[MAX_DICES] = { };
		choice(des);

		old_score = score;
		old_num_dices = num_dices;

		int i;
		for( i = 0; des[i] != 0; i++ ) {
			if( des[i] > num_dices ) {
				printf("Un des des selectionnes n'existe pas!\n");
				score = old_score;
				num_dices = old_num_dices;
				break;
			}
			score += dice[des[i] - 1];
			printf("score : %d\n",score);
		}

		if( score != old_score )
			num_dices -= i;

		printf("Votre score actuel : %i\n", score);
		printf("%i des restant\n\n", num_dices);
	}

	printf("Votre score a la fin de ce tour est %i\n", score);
	printf("Votre pari pour ce tour etait %i\n", bet);
	int results = score - bet;

	if( ( bet == BET_LOW && results < 0 ) || ( bet == BET_HIGH && results > 0 ) ) {
		results = abs( results );
		printf("Vous pouvez enlever %i points a un joueur\n", results);
		printf("Lequel ? (tapez un nombre entre 1 et %i)\n", NUM_PLAYERS);
		int player_2;
		for(;;) {
			scanf("%i", &player_2);
			player_2--;

			if( player_2 > NUM_PLAYERS ) {
				printf("Ce joueur n'existe pas dans la partie en cours!\n");
				continue;
			}
			if( player_2 == player) {
				printf("Vous ne pouvez pas vous enlever de vie!\n");
				continue;
			}
			if( PLAYERS[player_2] )
				break;
			printf("Le joueur que vous avez selectionne a deja perdu. Essayez encore !\n");
		}
		printf("Vous enlevez %i points au joueur %i\n", results, player_2+1);
		removePoints( player_2, results );
	} else if( !results ) {
		printf("Vous vous en sortez bien !\n");
	} else {
		results = abs( results );
		printf("Vous perdez %i points\n", results);
		removePoints( player, results );
	}
}



int main( int argc, char **argv ) {
	time_t t;
	srand((unsigned) time(&t)); //initialisation du random


	if( argc < 2 ) {
		printf("Vous n'avez pas précisé le nombre de joueurs\n");
		return 1;
	}

	if( ( NUM_PLAYERS = numplayers( argv[1] ) ) < 2) { //transcrire le nombre de joueurs en int
		printf("Pas assez de joueurs pour commencer une partie\n");
		return 1;
	}

	for( int player = 0; player < NUM_PLAYERS; player++ ) { //Assignation des points de départ aux joueurs
		PLAYERS[player] = POINTS_START;
	}

	printf("Démarrage d'une partie à %i joueurs (nombre max de joueurs : %i)\n", NUM_PLAYERS, MAX_PLAYERS);

	for(;;) {
		printf("\nNouveau tour !\n");
		for( int player = 0; player < NUM_PLAYERS; player++ ) {
			if( !PLAYERS[player] )
				continue;
			printf("Le joueur %i joue\n", player+1);
			play( player );
		}

		int players_alive = -1;
		for( int player = 0; player < NUM_PLAYERS; player++ ) {
			if( PLAYERS[player] )
				players_alive++;
		}

		if( players_alive ) //n'est vrai qu'a partir de players_alive == 1 (donc 2 joueurs en vie)
			continue;
		break;
	}

	printf("\nFin de la partie !\n");
	for( int player = 0; player < NUM_PLAYERS; player++ ) {
		if( PLAYERS[player] ) {
			printf("\nLe joueur %i l'emporte avec %i points!\n", player+1, PLAYERS[player]);
			return 0;
		}
	}

	return 1;
}