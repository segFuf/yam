CC=gcc -std=c99
SRC=utils.c get_score.c yam.c
HEAD=yam.h
OBJ=$(SRC:.c=.o)
CFLAGS= -Wall -Wextra -g

yam	:	$(OBJ) $(HEAD)
		$(CC) -o $@ $(OBJ)



*.o	:	%.c
	$(CC) -c $^ $(CFLAGS)


clean	:
		rm -rf *.o *.out yam