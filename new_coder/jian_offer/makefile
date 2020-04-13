CXX=g++-9
FLAG=-fno-asm -O2 -Wall  -std=c++11 

SOURCE = $(wildcard *.cpp)
OBJS:=$(patsubst %cpp,%o,$(SOURCE))

all:$(OBJS)
$(OBJS):%.o:%.cpp
	$(CXX) $< -o $@ $(FLAG)
	

.PHONY:clean
clean:
	rm -f *.o *.exe
