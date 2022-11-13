CC=g++

CPPFILES = .\src\Board.cpp .\src\PlayerModel.cpp .\src\Sokoban.cpp .\src\Wrappers.cpp

OBJFILES = .\src\Board.o .\src\PlayerModel.o .\src\Sokoban.o .\src\Wrappers.o

BINARY = Sokoban
CC_FLAGS = -O3

all: $(BINARY)

$(BINARY): $(OBJFILES)
	$(CC) $^ -o $@ $(CC_FLAGS)

$.o: %.cpp
	$(CC) -c $^ -o $@ $(CC_FLAGS)

clean:
	-del $(OBJFILES)

debug:
	make && make clean
	-move .\Sokoban.exe .\bin\debug

release:
	make && make clean
	-move .\Sokoban.exe .\bin\release