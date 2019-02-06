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

void swap(int *a, int *b)
{
	int c = *b;
	*b = *a;
	*a = c;
}

void sort_des(int des[MAX_DICES]) 
{
	for( int i = 0; i < MAX_DICES - 1; i++ )
		for( int j = 0; j < MAX_DICES - i - 1; j++ )
			if( des[j] > des[j + 1] )
				swap(&des[j], &des[j+1]);
}