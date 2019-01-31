#include "yam.h"

int *choice(void)
{
	char choice[7];
	int des[6];
	int y = 0;
	
	printf("Quels des choisissez-vous ?\n");
	scanf("%s", &choice);

	for (int i = 0; i < 7; i++) {
		if (choice[i] >= '0' || choice[i] <= '9') {
			des[y] = choice[i] - '0';
			y++;
		} else if (choice[i] != ' ') {
			printf("entrez un chiffre !");
		}
	}
	return (des);
}