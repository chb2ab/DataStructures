CXX	= clang++
CXXFLAGS	= -m32 -Wall -g
AS	= nasm
ASFLAGS	= -felf
OFILES	= threexplusone.o threexinput.o timer.o
.SUFFIXES: .o .cpp

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
