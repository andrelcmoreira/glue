CC = gcc
LDFLAGS = -Wl,--rpath=lib -Llib -luser_profile
OUT = client

.PHONY: lib

all: lib
	$(CC) $(LDFLAGS) -o $(OUT) $(OUT).c

lib:
	make -C lib all

clean:
	rm $(OUT)
	make -C lib clean
