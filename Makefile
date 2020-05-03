CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_wektora
	./test_wektora

obj:
	mkdir -p obj

./test_wektora: obj obj/main.o obj/LZespolona.o
	g++ -o ./test_wektora obj/main.o obj/LZespolona.o

obj/main.o: src/main.cpp inc/UkladRownan.hh inc/Macierz.hh inc/SWektor.hh inc/LZespolona.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${CXXFLAGS} -o obj/LZespolona.o src/LZespolona.cpp
