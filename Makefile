CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

output: main.o chessBoard.o Piece.o
	$(CXX) $(CXXFLAGS) main.o chessBoard.o Piece.o -o output

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

 chessBoard.o: chessBoard.cpp chessBoard.h
	$(CXX) $(CXXFLAGS) -c chessBoard.cpp

Piece.o: Piece.cpp Piece.h
	$(CXX) $(CXXFLAGS) -c Piece.cpp





# remove executables and object code from the current folder -- the 
# executable created by unit_test is called a.out
clean: 
	rm *.o output