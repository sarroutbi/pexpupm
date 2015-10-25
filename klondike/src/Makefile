CC=g++
CCFLAGS=-ggdb -std=c++11
OUTPUT_DIR=o
SRC_DIR=.
TEST_DIR=test
KLONDIKE=./klondike
KLONDIKE_SRC=$(wildcard $(SRC_DIR)/*.cpp)
KLONDIKE_INC=-I.

all: $(KLONDIKE)

$(KLONDIKE): $(KLONDIKE_SRC)
	$(CC) $(CCFLAGS) $(KLONDIKE_INC) -o $@ $^

clean:
	rm $(KLONDIKE) *~
