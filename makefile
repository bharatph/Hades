CC=g++
LIBS=-lpthread `pkg-config --libs opencv` -lsqlite3
CFLAGS=-std=c++11 -Wall

clean : hades
	rm hades

hades : hades.cpp
	$(CC) hades.cpp -o hades $(LIBS) $(CFLAGS)

android: hades.cpp
	arm-linux-androideabi-g++ hades.cpp -o hades $(LIBS) $(CFLAGS)
