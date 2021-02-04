prog: main.o 
	g++ -g -std=c++11 -Wall main.o -o StacksAndQueues

main.o: main.cpp Node.h Node.tpp Stack.h Stack.tpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o StacksAndQueues
