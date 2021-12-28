CC = g++
CFLAGS = -c -Wall
OUT = main

all: main.o
	$(CC) main.o -o $(OUT)
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
	
clean:
	rm -rf *.o $(OUT)
