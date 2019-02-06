#include "yam.h"


int same_number(int des[MAX_DICES])
{
	for ( int i = 1; i < MAX_DICES; i++ )
		if ( des[i] != des[i-1] )
			return (0);

	return (SAME);
}


int suite(int des[MAX_DICES])
{
	for( int i = 1; i < MAX_DICES; i++ )
		if( des[i] != des[i-1] + 1 )
			return (0);

	return (SUITE);
}


int full(int des[MAX_DICES])
{
    int occurences = 0;
    for( int i = 1; i < MAX_DICES; i++ )
        if( des[i] != des[i-1] ) {
            if( i >= 1 && i <= MAX_DICES-2 && !occurences) {
                occurences++;
                continue;
            }
            return 0;
        }

    return (FULL);
}


int double_triple(int des[MAX_DICES])
{
	int score = 0;
	int num = 0;

	for( int i = 1; i < MAX_DICES; i++ ) {
		if( des[i] == des[i-1] ) {
			num++;
		} else if ( des[i] && num != 0) {
			score += des[i-1] * (num + 1);
			num = 0;
		}
	}

	return (score);
}


int get_score(int des[MAX_DICES])
{
	int score = 0;

	sort_des(des);
	for (int i = 0; i < MAX_DICES; i++)
		printf("des[%d] : %d\n",i,des[i]);
	if ((score = same_number(des)))
		return (score);
	if ((score = suite(des)))
		return (score);
	if ((score = full(des)))
		return (score);
	if ((score = double_triple(des)))
		return (score);

	return 0;
}