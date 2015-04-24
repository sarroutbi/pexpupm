CC=g++
CCFLAGS=-ggdb
OUTPUT_DIR=o
SRC_DIR=.
COMMUNITY=./printers
COMMUNITY_SRC=$(wildcard $(SRC_DIR)/*.cpp)
COMMUNITY_INC=-I.

all: $(COMMUNITY)

$(COMMUNITY): $(COMMUNITY_SRC)
	$(CC) $(CCFLAGS) $(COMMUNITY_INC) -o $@ $^

clean:
	-rm $(COMMUNITY)
	-rm *~
