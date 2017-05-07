CC=g++
LIBS=`pkg-config --libs opencv` -lsqlite3 #-lopencv_core -lopencv_contrib -lopencv_highgui -lpthread
CFLAGS=-std=c++11

hades : hades.cpp
	$(CC) hades.cpp -o hades $(LIBS) $(CFLAGS)
