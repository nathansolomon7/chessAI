CXX = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 



main.o: main.cpp chessBoard.h chessBoard.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp chessBoard.cpp




# remove executables and object code from the current folder -- the 
# executable created by unit_test is called a.out
clean: 
	rm *.o