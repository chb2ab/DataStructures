#chb2ab, Crispin Bernier, lab06

CXX=clang++
CXXFLAGS= -O2 -Wall
OFILES=traveling.cpp middleearth.cpp
.SUFFIXES: .o .cpp

make: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

clean:
	-rm *.o *~

topological.o: topological.cpp
middleearth.o: middleearth.cpp middleearth.h

