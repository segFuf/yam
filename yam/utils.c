#include "yam.h"

void choice(int des[MAX_DICES])
{
	char choice[7] = { };
	int y = 0;

	while ( !y ) {
		printf("Quels des choisissez-vous ?\n");
		scanf("%s", &choice);
		for (int i = 0; i < 7; i++) {
			if (choice[i] >= '1' && choice[i] <= '6') {
				des[y] = choice[i] - '0';
				y++;
			}
		}
	}

}