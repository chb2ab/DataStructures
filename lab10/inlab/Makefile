#chb2ab, Crispin Bernier, lab06

CXX=clang++
CXXFLAGS= -O2 -Wall
OFILES=huffmandec.cpp HuffmanNode.cpp
.SUFFIXES: .o .cpp

make: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	-rm *.o *~

huffmandec.o: huffmandec.cpp HuffmanNode.h
HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h


