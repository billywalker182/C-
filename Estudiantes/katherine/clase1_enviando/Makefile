all: main

main: main.o persona.o 
	g++ -o main main.o persona.o 

main.o: main.cpp Persona.h 
	g++ -c -o main.o main.cpp


persona.o: Persona.cpp Persona.h 
	g++ -c -o Persona.o Persona.cpp

run: main
	./main

.PHONY: clean
clean:
	rm *.o main