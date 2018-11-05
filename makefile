CXX = g++
CCFLAGS = -O3 -Wall -Wextra -pedantic -Werror

all: htest_all

htest_all: htree.o test_htree.o hforest.o test_hforest.o
	$(CXX) $(CCFLAGS) htree.o test_htree.o hforest.o test_hforest.o -o htest_all

test_htree.o: test_htree.cc
	$(CXX) $(CCFLAGS) test_htree.cc -c

htree.o: htree.cc
	$(CXX) $(CCFLAGS) htree.cc -c

test_hforest.o: test_hforest.cc
	$(CXX) $(CCFLAGS) test_hforest.cc -c

hforest.o: hforest.cc
	$(CXX) $(CCFLAGS) hforest.cc -c

clean :
	rm *.o