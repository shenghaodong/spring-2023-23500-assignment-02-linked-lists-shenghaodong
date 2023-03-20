main: main.o OList.o lists.o Node.o
	g++ -o main main.o OList.o lists.o node.o



tests: tests.o OList.o lists.o Node.o
	g++ -o tests tests.o OList.o lists.o node.o


OList.o: OList.cpp OList.h node.cpp node.h Node.h

lists.o: lists.cpp lists.h node.cpp node.h Node.h

main.o: main.cpp OList.h lists.h Node.h

tests.o: tests.cpp doctest.h OList.h lists.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f main.o OList.o lists.o tests.o node.o