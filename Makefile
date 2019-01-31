CC=gcc -std=c99
SRC=utils.c yam.c
HEAD=yam.h
OBJ=$(SRC:.c=.o)
CFLAGS= -Wall -Wextra -g

yam2	:	$(OBJ) $(HEAD)
		$(CC) -o $@ $(OBJ)



*.o	:	%.c
	$(CC) -c $^ $(CFLAGS)


clean	:
		rm -rf *.o *.out