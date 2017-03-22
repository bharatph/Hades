CC=g++
LIBS=`pkg-config --libs opencv` -lsqlite3 #-lopencv_core -lopencv_contrib -lopencv_highgui -lpthread
CFLAGS=-std=c++11

ggdb : ggdb.cpp
	$(CC) ggdb.cpp -o ggdb $(LIBS) $(CFLAGS)
