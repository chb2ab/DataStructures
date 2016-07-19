#chb2ab, Crispin Bernier, lab06

CXX=clang++
CXXFLAGS= -O2 -Wall
OFILES=heap.cpp huffmanenc.cpp HuffmanNode.cpp
.SUFFIXES: .o .cpp

make: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	-rm *.o *~

fileio.o: fileio.cpp
heap.o: heap.cpp heap.h
huffmanenc.o: huffmanenc.cpp heap.h HuffmanNode.h
HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
inlab-skeleton.o: inlab-skeleton.cpp


