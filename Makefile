main: main.o Olist.o lists.o Node.o
	g++ -o main main.o Olist.o lists.o node.o


tests: tests.o Olists.o lists.o Node.o
	g++ -o tests tests.o Olist.o lists.o node.o


Olist.o: Olist.cpp Olist.h node.cpp node.h Node.h

lists.o: lists.cpp lists.h node.cpp node.h Node.h

main.o: main.cpp Olist.h lists.h Node.h

tests.o: tests.cpp doctest.h Olists.h lists.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f main.o Olist.o lists.o tests.o node.o