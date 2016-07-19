#chb2ab, Crispin Bernier, lab06

CXX=clang++
CXXFLAGS= -O2 -Wall
OFILES=hashTable.cpp wordPuzzle.cpp timer.cpp
.SUFFIXES: .o .cpp

make: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	-rm *.o *~

avltree.o: avltree.cpp avltree.h avlnode.h
getWordInTable.o: getWordInTable.cpp
hashTable.o: hashTable.cpp hashTable.h avltree.h avlnode.h
primenumber.o: primenumber.cpp
timer.o: timer.cpp timer.h
timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h avltree.h avlnode.h timer.h

