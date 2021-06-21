TARGET = main
SOURCES = queue.c thread_pool.c main.c
CFLAGS = -Wall -Werror -g
LDFLAGS = -lpthread
CC = gcc

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm $(TARGET)
