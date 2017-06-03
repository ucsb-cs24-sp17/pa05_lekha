all: expresstest expresstest.o

expresstest: expresstest.cpp express.cpp
	g++ -std=c++11 -o expresstest expresstest.cpp express.cpp -g

expresstest.o: express.h expresstest.cpp
	g++ -c expresstest.cpp -g
clean:
	rm -f expresstest
