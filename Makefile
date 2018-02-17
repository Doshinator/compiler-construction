CC = g++
EXE = basics

basics: basics.o
	g++ basics.o -o basics
basics.o: basics.cpp 
	g++ -c -g basics.cpp -o basics.o
clean:
	rm *.o $(EXE)
