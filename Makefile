main: image.o main.o
	g++ -ggdb `pkg-config --cflags opencv` -std=c++11 -o `basename main.cpp .cpp` image.o main.o `pkg-config --libs opencv`

image.o: image.cpp
	g++ -o image.o -c image.cpp -std=c++11

main.o: main.cpp image.h
	g++ -o main.o -c main.cpp -std=c++11


clean:
	rm *.o main
