OBJ=main
SRC=queue.c thread_pool.c main.c
CFLAGS=-Wall -Werror -g
LIBS=-lpthread
CC=gcc

all:
	$(CC) $(CFLAGS) -o $(OBJ) $(SRC) $(LIBS)

clean:
	rm $(OBJ)
