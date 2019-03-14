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

	test(get_score(des1), 50);
	test(get_score(des2), 40);
	test(get_score(des3), 35);
	test(get_score(des4), 35);
	test(get_score(des5), 35);
	test(get_score(des6), 23);
	test(get_score(des7), 24);
	test(get_score(des8), 6);
	test(get_score(des9), 0);

	return 0;
}