all: main.o calculator.o mylib.a
	g++ main.o calculator.o -o output
	
main.o: main.cpp
	g++ -c -Wall main.cpp

calculator.o: calculator.cpp
	g++ -c -Wall calculator.cpp

mylib.a: calculator.cpp
	ar -rcs mylib.a calculator.o

clean:
	rm -rf *.o output
