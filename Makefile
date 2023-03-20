main: main.o OList.o lists.o node.o
	g++ -o main main.o OList.o lists.o node.o



tests: tests.o OList.o lists.o node.o
	g++ -o tests tests.o OList.o lists.o node.o


OList.o: OList.cpp OList.h node.cpp node.h node.h

lists.o: lists.cpp lists.h node.cpp node.h node.h

main.o: main.cpp OList.h lists.h node.h

tests.o: tests.cpp doctest.h OList.h lists.h node.h

node.o: node.cpp node.h

clean:
	rm -f main.o OList.o lists.o tests.o node.o