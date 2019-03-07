#include "yam.h"

//A FAIRE :
// - clear l'ecran a des moments precis
// - plus belle interface graphique
// - rajouter des couleurs
// - ptits truc jolis qui servent a rien (genre un dessin de de en ascii ?)
// - mettre les define dans un .h et les fonctions abs et numplayers dans un autre .c
// - faire un makefile



int choices( int num_dices, int des_in[MAX_DICES], int des_out[MAX_DICES] ) {
	int j;
	int old_num_dices = num_dices;

	for EVER {
		int tmp[MAX_DICES] = { };
		choice( tmp );

		for( j = 0; tmp[j] != 0 && j < num_dices; j++ ) {
			if( tmp[j] > num_dices ) {
				j = 0;
				break;
			}
		}

		num_dices -= j;

		if( num_dices == old_num_dices ) {
			printf(" \x1b[91m--- Un des des selectionnes n'existe pas! ---\x1b[92m\n");
			continue;
		}
		

		for( j = MAX_DICES - old_num_dices; j < MAX_DICES - num_dices; j++ )
			des_out[j] = des_in[tmp[j]-1];

		break;
	}
	return num_dices;
}




int throwDices( int num_dices, int des[MAX_DICES] ) {
	int des_rand[MAX_DICES];		//tableau de des generes aleatoirement

	for( int j = 0; j < num_dices; j += 2 ) { //truc complexe pour juste afficher sur deux lignes les des
		des_rand[j] = rand() % FACES + 1;
		printf("des \x1b[92m%i \x1b[32m: \x1b[92m%i\x1b[32m", j + 1, des_rand[j]);
		if( j+1 < num_dices ) {
			des_rand[j+1] = rand() % FACES + 1;
			printf("\t\tdes \x1b[92m%i \x1b[32m: \x1b[92m%i\x1b[32m", j + 2, des_rand[j+1]);
		}
		printf("\n");
	}

	return choices( num_dices, des_rand, des );
}




void play( int *player ) {
	int num_dices = MAX_DICES;	//nombre maximum de des, diminuant petit a petit
	int des[MAX_DICES];			//tableau de des final, pour la creation d'une forme

	for( int i = 0; i < MAX_TRIES; i++ ) {
		printf("\x1b[32mEssai \x1b[92m%i \x1b[32msur \x1b[92m%i\x1b[32m\n\n", i + 1, MAX_TRIES);
		num_dices = throwDices( num_dices, des );

		if( num_dices == 0 )
			break;
	}

	*player += get_score( des );
}




int main() {
	time_t t;
	srand((unsigned) time(&t)); //initialisation du random

	int PLAYERS[NUM_PLAYERS] = { };

	printf("\n////////////////////////////////////////\n\
// Démarrage d'une partie à \x1b[34m%i \x1b[97mjoueurs //\n\
////////////////////////////////////////\n\n\n", NUM_PLAYERS);

	for( int i = 0; i < MAX_ROUNDS; i++ ) {
		printf("\x1b[93m  -------------------\n --- Tour \x1b[92m%i \x1b[93msur \x1b[32m%i \x1b[93m---\n  -------------------\n\x1b[97m\n\n", i + 1, MAX_ROUNDS);
		for( int player = 0; player < NUM_PLAYERS; player++ ) {
			printf("\x1b[91mLe joueur \x1b[36m%i \x1b[91mjoue\x1b[97m\n\n", player + 1);
			play( &PLAYERS[player] );
			printf("\x1b[93mVotre score a la fin de ce tour est \x1b[91m%i\x1b[97m\n\n", PLAYERS[player]);
			sleep(1);
		}
	}

	printf("\nFin de la partie !\n");
	int winner = 0;
	for( int player = 0; player < NUM_PLAYERS; player++ ) {
		printf("Joueur %i	:	%i\n", player + 1, PLAYERS[player]);
		if( PLAYERS[player] > PLAYERS[winner]) {
			winner = player;
		}
	}

	printf("Le joueur %i l'emporte avec %i points!\n", winner+1, PLAYERS[winner]);
	return 0;
}