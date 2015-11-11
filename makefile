main.exe: game.o matrix.o
	g++ -std=c++11 -Wall -o main game.o nim.o

main.o: main.cpp matrix.h
	g++ -std=c++11 -Wall -c -o main.o game.cpp

matrix.o: matrix.cpp matrix.h
	g++ -std=c++11 -Wall -c -o matrix.o matrix.cpp

clean:
	erase *.o

cleanAll:
	erase *.o
	erase *.exe

build: Nim.exe

compile: game.o nim.o

rebuild: clean compile build
