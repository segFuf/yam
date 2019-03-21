#include "yam.h"

//A FAIRE :
// - plus belle interface graphique
// - ptits truc jolis qui servent a rien (genre un dessin de de en ascii ?)



/**

Cette fonction encapsule tout le choix des dés parmi des dés d'entrée, pour les ajouter au tableau de dés en sortie
Si le/les choix n'est/ne sont pas valable(s), la boucle est relancée.
La fonction retourne le nombre de dés restants

**/

int chooseDices( int num_dices, int des_in[MAX_DICES], int des_out[MAX_DICES], int trial ) {
	int j, old_num_dices = num_dices;

	for (;;) {
		displayDices( des_in, old_num_dices );

		if( trial == MAX_TRIES-1 ) {
			for( int i = 0, j = MAX_DICES - num_dices; j < MAX_DICES; i++, j++ )
				des_out[j] = des_in[i];
			return 0;
		}

		int tmp[MAX_DICES] = { };
		choice( tmp );

		if( tmp[0] == -1 )
			return num_dices;

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

		int i = 0;
		for( j = MAX_DICES - old_num_dices; j < MAX_DICES - num_dices; j++, i++ )
			des_out[j] = des_in[tmp[i]-1];

		break;
	}

	return num_dices;
}


/**

Fonction simulant le lancer de dés pour un tour. La fonction se charge de générer le nombre de dés restants.
La fonction prends en charge l'affichage des dés en 2 colonnes.
Elle retourne le résultat de chooseDices, soit le nombre de dés restant à la fin du choix des dés.

**/

int throwDices( int num_dices, int des[MAX_DICES], int trial ) {
	int des_rand[MAX_DICES];		//tableau de des generes aleatoirement

	for( int i = 0; i < num_dices; i += 2 ) { //truc complexe pour juste afficher sur deux lignes les des
		des_rand[i] = rand() % FACES + 1;
		if( i + 1 < num_dices )
			des_rand[i+1] = rand() % FACES + 1;
	}

	return chooseDices( num_dices, des_rand, des, trial );
}


/**

Cette fonction lance le déroulement du tour d'un joueur, avec MAX_TRIES lancers de dé.
Elle lance la fonction throwDices et attribue sa valeur de retour à num_dices.
La fonction ajoute le score obtenu à la fin du tour au score du joueur une fois que num_dices est égale à 0 ou que le nombre de tours est dépassé

**/

void play( int *player, int shapes[SHAPES] ) {
	int num_dices = MAX_DICES;	//nombre maximum de des, diminuant petit a petit
	int des[MAX_DICES];			//tableau de des final, pour la creation d'une forme

	for( int i = 0; i < MAX_TRIES; i++ ) {
		printf("\x1b[32mEssai \x1b[92m%i \x1b[32msur \x1b[92m%i\n\n", i + 1, MAX_TRIES);
		num_dices = throwDices( num_dices, des, i );

		if( num_dices == 0 )
			break;
	}

	// displayDices( des, MAX_DICES );

	*player += get_score( des, shapes );
}




int main() {
	time_t t;
	srand((unsigned) time(&t)); //initialisation du random


	int PLAYERS[NUM_PLAYERS] = { };
	int DONE_SHAPES[NUM_PLAYERS][SHAPES];
	for( int i = 0; i < NUM_PLAYERS; i++ )
		initTab(DONE_SHAPES[i], SHAPES);

	system("clear");
	printf("\n\x1b[36m////////////////////////////////////////\n\
// Démarrage d'une partie à \x1b[96m%i \x1b[36mjoueurs //\n\
////////////////////////////////////////\n\n\n\x1b[97m", NUM_PLAYERS);


	for( int i = 0; i < MAX_ROUNDS; i++ ) {
		printf("\x1b[93m  -------------------\n --- Tour \x1b[92m%i \x1b[93msur \x1b[32m%i \x1b[93m---\n  -------------------\n\x1b[97m\n\n", i + 1, MAX_ROUNDS);
		for( int player = 0; player < NUM_PLAYERS; player++ ) {
			printf("\x1b[91mLe joueur \x1b[36m%i \x1b[91mjoue\x1b[97m\n\n", player + 1);
			play( &PLAYERS[player], DONE_SHAPES[player] );
			printf("\x1b[93mVotre score a la fin de ce tour est \x1b[91m%i\x1b[97m\n\n", PLAYERS[player]);
			sleep(1);
			system("clear");
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