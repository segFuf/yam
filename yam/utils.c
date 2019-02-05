#include "yam.h"

void choice(int des[MAX_DICES])
{
	char choice[MAX_DICES] = { };
	int y = 0;

	while ( !y ) {
		printf("Quels des choisissez-vous ?\n");
		scanf("%s", &choice);
		for (int i = 0; i < MAX_DICES; i++) {
			if (choice[i] >= '1' && choice[i] <= '7') {
				des[y] = choice[i] - '0';
				y++;
			}
		}
	}
}

void sort(int des[MAX_DICES]) {
	int tmp[MAX_DICES];

	for( int i = 0; i < MAX_DICES; i++ ) {
		int a = des[i];
		for( int j = 0; j < MAX_DICES; j++ ) {
			if( a > des[j] )
				a = des[j];
		}
		tmp[i] = a;
	}

	for( int i = 0; i < MAX_DICES; i++ ) {
		des[MAX_DICES] = tmp[MAX_DICES];
	}
}