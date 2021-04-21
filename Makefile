CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRC_BINARIES = LCSp1.o LCSp2.o file-reader.o

main: main.cpp $(SRC_BINARIES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	rm -rf test/*.dSYM
	$(RM) *.o *.gc* test/*.o $(TEST_BINARIES) core main