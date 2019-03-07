CC=gcc -std=c99
SRC=utils.c get_score.c yam.c
HEAD=yam.h
OBJ=$(SRC:.c=.o)
CFLAGS= -Wall -Wextra -g

yahtzee	:	$(HEAD) $(OBJ)
		$(CC) -o $@ $(OBJ)



*.o	:	$(SRC)
	$(CC) -c $^ $(CFLAGS)


clean	:
		rm -rf *.o *.out yam yahtzee