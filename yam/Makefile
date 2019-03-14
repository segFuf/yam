CC=gcc -std=c99

SRC  = utils.c get_score.c yam.c
SRC2 = utils.c get_score.c test.c
HEAD=yam.h
OBJ = $(SRC:.c=.o)
OBJ2= $(SRC2:.c=.o)
CFLAGS= -Wall -Wextra -g

yahtzee	:	$(HEAD) $(OBJ)
		$(CC) -o $@ $(OBJ)

test_y    :	$(HEAD) $(OBJ2)
		$(CC) -o $@ $(OBJ2)




*.o	:	$(SRC)
	$(CC) -c $^ $(CFLAGS)


clean	:
		rm -rf *.o *.out yam yahtzee test

