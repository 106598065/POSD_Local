all: hw8 shell

hw8: mainExtion.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainExtion.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 mainExtion.o atom.o list.o struct.o -lgtest -lpthread
endif

shell: mainShell.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h
ifeq (${OS}, Windows_NT)
	g++ -o shell mainShell.o atom.o list.o struct.o -lgtest
else
	g++ -o shell mainShell.o atom.o list.o struct.o -lgtest -lpthread
endif
##
mainShell.o: mainExtion.cpp expression.h exception.h
	g++ -std=gnu++0x -c mainShell.cpp

mainExtion.o: mainExtion.cpp expression.h exception.h
	g++ -std=gnu++0x -c mainExtion.cpp
##
utAtom: mainAtom.o list.o atom.o struct.o
	g++ -o utAtom mainAtom.o atom.o list.o struct.o  -lgtest -lpthread
mainAtom.o: mainAtom.cpp utList.h utAtom.h atom.h utStruct.h struct.h
	g++ -std=c++11 -c mainAtom.cpp

atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp

utVariable: mainVariable.o atom.o struct.o
		g++ -o utVariable mainVariable.o atom.o struct.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h variable.h
		g++ -std=c++11 -c mainVariable.cpp
list.o:list.cpp list.h
		g++ -std=c++11 -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=c++11 -c struct.cpp

utScanner: mainScanner.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h
	g++ -o utScanner mainScanner.o atom.o list.o struct.o -lgtest -lpthread
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h utExp.h exception.h expression.h
		g++ -std=c++11 -c mainScanner.cpp
utIterator: mainIterator.o atom.o list.o struct.o iterator.h utIterator.h
	g++ -o utIterator mainIterator.o atom.o list.o struct.o -lgtest -lpthread


mainIterator.o: mainIterator.cpp utIterator.h
	g++ -std=c++11 -c mainIterator.cpp



clean:
	rm -f *.o madRace utAtom utVariable utScanner hw8 shell
stat:
	wc *.h *.cpp
