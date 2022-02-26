CC = g++
OUT = libuser_profile.so
LDFLAGS = -fPIC
SRC = user_profile.cpp user_profile_interface.cpp

all:
	$(CC) -shared $(LDFLAGS) -o $(OUT) $(SRC)

clean:
	rm $(OUT)
