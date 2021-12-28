CC = g++
CFLAGS = -c -Wall
OUT = output

all: main.o calculator.o mylib.a
	$(CC) main.o calculator.o -o $(OUT)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

calculator.o: calculator.cpp
	$(CC) $(CFLAGS) calculator.cpp

mylib.a: calculator.cpp
	ar -rcs mylib.a calculator.o

clean:
	rm -rf *.o $(OUT)
