#include "yam.h"

void clear_des(int des[MAX_DICES])
{
	for (int i = 0; i < MAX_DICES; i++)
		des[i] = 0;
}

void choice(int des[MAX_DICES])
{
	char choice[7];
	int y = 0;
	
	clear_des(des);
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