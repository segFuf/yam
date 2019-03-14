#include "yam.h"


/**

Cette fonction affiche un tableau de des contenant 'max' des.
Elle est surtout utile pour les actions de debogage.

**/

void displayDices( int des[MAX_DICES], int max )
{
	for( int i = 0; i < max; i++ ) //truc complexe pour juste afficher sur deux lignes les des
		printf("%s\x1b[32mdes \x1b[92m%i \x1b[32m: \x1b[92m%i\x1b[32m%s", ( i % 2 == 0 ? " " : "\t\t" ), i + 1, des[i], ( i % 2 == 0 ? "" : "\n" ));
	printf("\n");
}

/**

Cette fonction permet au joueur de choisir les dés qu'il veut garder à la suite d'un lancer.
Le joueur choisit le numéro d'un dé, pas sa valeur
Seules 7 valeurs peuvent être entrées, et ces valeurs doivent être entre 1 et 7 compris.
Si elles le sont, elle sont ajoutées au tableau des dés à ajouter à la combinaison du joueur

**/

void choice(int des[MAX_DICES])
{
	char choice[MAX_DICES] = { };
	int y = 0;

	printf("\x1b[95mQuels des choisissez-vous ?\x1b[97m\n");
	scanf("%s", &choice);
	for (int i = 0; i < MAX_DICES; i++) {
		if (choice[i] >= '1' && choice[i] <= ('0' + MAX_DICES) ) {
			des[y] = choice[i] - '0';
			y++;
		}
	} printf("\n");
}

/**

Cette fonction permet d'intervertir deux valeurs entières

**/

void swap(int *a, int *b)
{
	int c = *b;
	*b = *a;
	*a = c;
}

/**

Cette fonction trie un tableau contenant des valeurs de dés de la plus petite à la plus grande valeur.
Cette fonction sert à simplifier les calculs des scores.

**/

void sort_des(int des[MAX_DICES]) 
{
	for( int i = 0; i < MAX_DICES - 1; i++ )
		for( int j = 0; j < MAX_DICES - i - 1; j++ )
			if( des[j] > des[j + 1] )
				swap( &des[j], &des[j+1] );
}