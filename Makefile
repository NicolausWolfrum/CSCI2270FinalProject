
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
OBJ = GoFish.o Final_Project.o
OUT = GoFish.out

all : program

program : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)

Final_Project.o : Final_Project.cpp GoFish.h
	$(CXX) $(CXXFLAGS) -c Final_Project.cpp

GoFish.o : GoFish.cpp GoFish.h
	$(CXX) $(CXXFLAGS) -c GoFish.cpp

clean :
	rm *.o
