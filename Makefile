.default: all

all: azul

clean:
	rm -f Bag.o Engine.o Factory.o GameBoard.o LinkedList.o main.o Player.o Tile.o WallTile.o


azul: Bag.o Engine.o Factory.o GameBoard.o LinkedList.o main.o Player.o Tile.o WallTile.o
		g++ -Wall -Werror -std=c++14 -g -O -o $@ $^


%.o: %.cpp
		g++ -Wall -Werror -std=c++14 -g -O -c $^
