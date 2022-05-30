CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/map.o $(OBJ)/main.o
HDRS = $(INC)/map.hpp 
CFLAGS = -Wall -I$(INC) -Og -g

EXE = $(BIN)/tp02

all: $(EXE)

$(BIN)/tp02: $(OBJS)
	$(CC) -o $(BIN)/tp02 ${CFLAGS} $(OBJS) $(LIBS)

$(OBJ)/map.o: $(HDRS) $(SRC)/map.cpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/map.o $(SRC)/map.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -c -o $(OBJ)/main.o $(SRC)/main.cpp 
	
clean:
	rm $(OBJS) $(BIN)/tp02


