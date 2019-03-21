// gcc test.c get_score.c utils.c

#include "yam.h"
#include <assert.h>

void test(int i, int a, int b) {
	printf("%d : %d\n", i, a);
	assert(a==b);
}

int score( int des[MAX_DICES] ) {
	int shapes[SHAPES];
	initTab(shapes, SHAPES);
	return get_score(des, shapes);
}

int main() {
	int shapes[SHAPES] 	= {0, 1, 1, 1, 1, 1, 1, 1};

	int des1[MAX_DICES] = {2, 2, 2, 2, 2, 2, 2}; // SCORE_YAHTZEE	= 50
	int des2[MAX_DICES] = {7, 6, 5, 4, 3, 2, 1}; // SCORE_SUITE		= 40
	int des3[MAX_DICES] = {2, 2, 2, 2, 2, 1, 1}; // SCORE_FULL		= 35
	int des4[MAX_DICES] = {4, 4, 4, 4, 3, 3, 3}; // SCORE_FULL		= 35
	int des5[MAX_DICES] = {5, 5, 5, 5, 5, 1, 1}; // SCORE_FULL		= 35
	int des6[MAX_DICES] = {5, 5, 5, 3, 3, 1, 1}; // 21
	int des7[MAX_DICES] = {5, 5, 4, 4, 2, 2, 2}; // 16
	int des8[MAX_DICES] = {7, 6, 5, 4, 3, 3, 1}; // 6
	int des9[MAX_DICES] = {8, 7, 6, 5, 4, 3, 1}; // 0

	test( 1, score(des1), SCORE_YAHTZEE);
	test( 2, score(des2), SCORE_SUITE);
	test( 3, score(des3), SCORE_FULL);
	test( 4, score(des4), SCORE_FULL);
	test( 5, score(des5), SCORE_FULL);
	test( 6, score(des6), 3*5 + 2*3);
	test( 7, score(des7), 5*2 + 2*3);
	test( 8, score(des8), 2*3);
	test( 9, score(des9), 0);

	printf("\n");
	
	test( 1, get_score(des1, shapes), 0);
	test( 2, get_score(des2, shapes), SCORE_SUITE);
	test( 3, get_score(des3, shapes), SCORE_FULL);
	test( 4, get_score(des4, shapes), 0);
	test( 5, get_score(des5, shapes), 0);
	test( 6, get_score(des6, shapes), 21);
	test( 7, get_score(des7, shapes), 0);
	test( 8, get_score(des8, shapes), 0);
	test( 9, get_score(des9, shapes), 0);

	return 0;
}