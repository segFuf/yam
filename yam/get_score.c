#include "yam.h"

#define SAME 50
#define SUITE 40
#define FULL 35

int check_des(int des[7], int y)
{
	int a;

	for (int i = 1; i < 9; i++) {
		a = 0;
		for (int z = 0; z < 7; z++)
			if (des[z] == i && i != y)
				a++;

		switch (a) {
			case 2:	return (2);
			case 3: return (3);
			case 4: return (4);
			case 5: return (5);
		}
	}
	return (0);
}

int double_triple_full(int des[7])
{
	int tmp, n;
	int score = 0;

	for (int y = 1; y < 9; y++) {
		n = 0;
		for (int i = 0; i < 7; i++)
			if (y == des[i])
				n++;
		switch (n) {
			case 2: score += (2 * y);
				if (check_des(des, y) == 5)
					return (FULL);
				break;
			case 3: score += (3 * y);
				if (check_des(des, y) == 4)
					return (FULL);
				break;
			case 4: if (check_des(des, y) == 3)
					return (FULL);
				break;
			case 5: if (check_des(des, y) == 2)
					return (FULL);
				break;
		}
	}
	return (score);
}

int same_number(int des[7])
{
	int a = des[0];

	for (int i = 0; i < 7; i++)
		if (des[i] != a)
			return (0);

	return (SAME);
}

int suite(int des[7])
{
	int test;
	for (int i = 1; i < 9; i++) {
		test = 0;
		for (int y = 0; y < 7; y++)
			if (des[y] == i)
				test = 1;

		if (!test && i != 1 && i != 8)
			return (0);
	}
	return (SUITE);
}



int get_score(int des[7])
{
	int score = 0;

	if ((score = same_number(des)))
		return (score);
	if ((score = suite(des)))
		return (score);
	if ((score = double_triple_full(des)))
		return (score);
}