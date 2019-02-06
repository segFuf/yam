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
	int old_num_dices = 0;
	int dice[MAX_DICES];
	int des[MAX_DICES];

	for( int i = 0; i < MAX_TRIES || num_dices; i++ ) {
		if( !old_num_dices ) {
			printf("Tour %i :\n", i + 1);
			for( int j = 0; j < num_dices; ) { //truc complexe pour juste afficher sur deux lignes les des
				for( int k = 0; k < 2; k++, j++ ) {
					if ( j == num_dices )
						break;
					dice[j] = rand() % 6 + 1;
					printf("des %i: %i		", j + 1, dice[j]);
				}
				printf("\n");
			}
		}

		for EVER {
			int tmp[MAX_DICES] = { };
			choice( tmp );

			for( int j = 0; tmp[j] != 0 || j < num_dices; j++ ) {
				if( tmp[j] > num_dices ) {
					num_dices = old_num_dices;
					break;
				}
				num_dices--;
			}

			if( num_dices != old_num_dices ) {
				printf("Un des des selectionnes n'existe pas!\n");
				break;
			}
			

			for( int j = MAX_DICES - old_num_dices; j < MAX_DICES; j++ )
				des[j] = tmp[j];

			old_num_dices = num_dices;
		}
	}

	sort( des );
	return get_score( des );
}



int main() {
	time_t t;
	srand((unsigned) time(&t)); //initialisation du random

	int PLAYERS[2] = { };

	printf("Démarrage d'une partie à %i joueurs\n", NUM_PLAYERS);

	for( int i = 0; i < MAX_ROUNDS; i++ ) {
		printf("\nTour %i sur %i !\n", i + 1, MAX_ROUNDS);
		for( int player = 0; player < NUM_PLAYERS; player++ ) {
			printf("Le joueur %i joue\n", player + 1);
			PLAYERS[player] += play();
			printf("Votre score a la fin de ce tour est %i\n", PLAYERS[player]);
		}
	}

	printf("\nFin de la partie !\n");
	int winner = 0;
	for( int player = 0; player < NUM_PLAYERS; player++ ) {
		printf("Joueur %i	:	%i\n", player + 1, PLAYERS[player]);
		if( PLAYERS[player] > PLAYERS[winner])
			winner = player;
	}

	printf("Le joueur %i l'emporte avec %i points!\n", winner+1, PLAYERS[winner]);
	return 0;
}