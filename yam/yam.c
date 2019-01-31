#include "yam.h"

//A FAIRE :
// - clear l'ecran a des moments precis
// - plus belle interface graphique
// - rajouter des couleurs
// - ptits truc jolis qui servent a rien (genre un dessin de de en ascii ?)
// - mettre les define dans un .h et les fonctions abs et numplayers dans un autre .c
// - faire un makefile



int play() {
	int num_dices = MAX_DICES;
	int dice[MAX_DICES];
	int score = 0;
	int old_num_dices = 0;
	int des[MAX_DICES] = { };

	for( int i = 0; i < MAX_TRIES || num_dices; i++ ) {
		if( !old_num_dices ) {
			printf("Tour %i :\n", i + 1);
			for( int j = 0; j < num_dices; ) { //truc complexe pour juste afficher sur deux lignes les des
				for( int k = 0; k < 2; k++, j++ ) {
					if ( j == num_dices )
						break;
					dice[j] = rand() % 6 + 1;
					printf("des %i: %i		", j+1, dice[j]);
				}
				printf("\n");
			}
		}

		choice(des); //modifier choice

		for( int j = MAX_DICES - num_dices; des[j] != 0; j++ ) {
			if( des[j] > num_dices ) {
				printf("Un des des selectionnes n'existe pas!\n");
				num_dices = old_num_dices;
				break;
			}
		}
	}

	//vérifier les formes et changer le score

	return score;
}



int main( int argc, char **argv ) {
	time_t t;
	srand((unsigned) time(&t)); //initialisation du random

	int PLAYERS[2] = { };

	printf("Démarrage d'une partie à %i joueurs (nombre max de joueurs : %i)\n", NUM_PLAYERS, MAX_PLAYERS);

	for( int i = 0; i < MAX_ROUNDS; i++ ) {
		printf("\nNouveau tour !\n");
		for( int player = 0; player < PLAYERS; player++ ) {
			if( !PLAYERS[player] )
				continue;
			printf("Le joueur %i joue\n", player+1);
			PLAYERS[player] += play();
			printf("Votre score a la fin de ce tour est %i\n", PLAYERS[player]);
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