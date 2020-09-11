.default: all

all: assign2

clean:


assign2 : 

%.o: %.cpp
		g++ -Wall -Werror -std=c++14 -g -O -c $^
