CC = g++
CFLAGS = -g
DIRECTORY = project-drkujawa21/input/
DIRECTORY_FILES = $(wildcard $(DIRECTORY)/*txt)

all: ecosystem.bin

ecosystem.bin: main.cpp Species.cpp Map.cpp
	$(CC) $(CFLAGS) -o ecosystem.bin main.cpp Species.cpp Map.cpp $(DIRECTORY_FILES)

sample.bin: main.cpp Species.cpp Map.cpp 
	$(CC) $(CFLAGS) -o sample.bin -I $(DIRECTORY_FILES)

clean:
	rm -f *.o *.bin