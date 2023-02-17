CC = g++
CFLAGS = -Wall -g

build:
	g++ sync.cpp task1.cpp task2.cpp -o sync -std=c++11 -Wall -g
	g++ bonus.cpp -o bonus -std=c++11 -Wall -g

.PHONY: clean

run: build
	./sync $(problem)

labyrinth: build
	./bonus

clean:
	rm -f *.o *~ sync bonus
