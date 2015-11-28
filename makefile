test.exe: matrix.o main.o
	g++ -std=c++11 -Wall -o test main.o matrix.o

main.o: main.cpp matrix.h
	g++ -std=c++11 -Wall -c -o main.o main.cpp

matrix.o: matrix.cpp matrix.h
	g++ -std=c++11 -Wall -c -o matrix.o matrix.cpp

clean:
	erase *.o

cleanAll:
	erase *.o
	erase *.exe

build: test.exe

compile: matrix.o main.o

rebuild: clean compile build
