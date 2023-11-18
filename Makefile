CXX = g++ 

CFLAGS = -std=c++11 

TARGET = P0 

SRC = P0.cpp tree.cpp 

OBJ = $(SRC:.cpp=.o) 

all: $(TARGET) 

$(TARGET): $(OBJ) 
	$(CXX) $(CLAGS) -o $(TARGET) $(OBJ) 

%.o: %.cpp 
	$(CXX) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ) $(TARGET) 
