CC=g++

CPPFILES = .\src\Board.cc .\src\PlayerModel.cc .\src\Sokoban.cc .\src\Wrappers.cc .\src\Menu.cc .\src\Movement.cc \
		   .\src\__Logs.cc .\src\Chest.cc .\src\PlayerModel.cc .\src\Main.cc


OBJFILES = .\src\Board.o .\src\PlayerModel.o .\src\Sokoban.o .\src\Wrappers.o .\src\Menu.o .\src\Movement.o \
			.\src\__Logs.o .\src\Chest.o .\src\PlayerModel.o .\src\Main.o

BINARY = Sokoban
CC_FLAGS = -O3

all: $(BINARY)

$(BINARY): $(OBJFILES)
	$(CC) $^ -o $@ $(CC_FLAGS)

$.o: %.cc
	$(CC) -c $^ -o $@ $(CC_FLAGS)

clean:
	-del $(OBJFILES)

debug:
	make && make clean
	-move .\Sokoban.exe .\bin\debug

release:
	make && make clean
	-move .\Sokoban.exe .\bin\release