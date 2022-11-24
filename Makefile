CXX = g++
CXXFLAGS = -Wall -Wextra -Werror

output: main.o chessBoard.o
	$(CXX) $(CXXFLAGS) main.o chessBoard.o -o output

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

 chessBoard.o: chessBoard.cpp chessBoard.h
	$(CXX) $(CXXFLAGS) -c chessBoard.cpp




# remove executables and object code from the current folder -- the 
# executable created by unit_test is called a.out
clean: 
	rm *.o output