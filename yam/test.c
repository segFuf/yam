// gcc test.c get_score.c utils.c

#include "yam.h"
#include <assert.h>

void test(int a, int b) {
	printf("%d\n", a);
	assert(a==b);
}

int main() {
	int des1[MAX_DICES] = {2, 2, 2, 2, 2, 2, 2}; // 50
	int des2[MAX_DICES] = {1, 2, 3, 4, 5, 6, 7}; // 40
	int des3[MAX_DICES] = {1, 1, 2, 2, 2, 2, 2}; // 35
	int des4[MAX_DICES] = {3, 3, 3, 4, 4, 4, 4}; // 35
	int des5[MAX_DICES] = {1, 1, 5, 5, 5, 5, 5}; // 35
	int des6[MAX_DICES] = {1, 1, 3, 3, 5, 5, 5}; // 23
	int des7[MAX_DICES] = {2, 2, 2, 4, 4, 5, 5}; // 24
	int des8[MAX_DICES] = {1, 3, 3, 4, 5, 6, 7}; // 6
	int des9[MAX_DICES] = {1, 2, 4, 5, 6, 7, 8}; // 0

	test(get_score(des1), SAME);
	test(get_score(des2), SEQUEL);
	test(get_score(des3), FULL);
	test(get_score(des4), FULL);
	test(get_score(des5), FULL);
	test(get_score(des6), 2*1 + 2*3 + 3*5);
	test(get_score(des7), 3*2 + 2*4 + 2*5);
	test(get_score(des8), 2*3);
	test(get_score(des9), 0);

	return 0;
}