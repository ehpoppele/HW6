CXX = g++
CCFLAGS = -O3 -Wall -Wextra -pedantic -Werror

all: htreetest 

htreetest: htreetest.cc
	$(CXX) $(CCFLAGS) htreetest.cc -o htreetest

clean :
	rm test_tree.o