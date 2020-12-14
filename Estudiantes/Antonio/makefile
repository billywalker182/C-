compilador: compiladorV01.o parser.o lexer.o token.o
	g++ -g -o compilador compiladorV01.o parser.o lexer.o token.o

compiladorV01.o: compiladorV01.cpp parser.o
	g++ -g -c compiladorV01.cpp

parser.o: parser.cpp parser.h lexer.o
	g++ -g -c parser.cpp

lexer.o: lexer.cpp lexer.h evalex.h token.o token.h
	g++ -g -c lexer.cpp

token.o: token.cpp token.h
	g++ -g -c token.cpp

clean:
	rm -f *.o *.exe
