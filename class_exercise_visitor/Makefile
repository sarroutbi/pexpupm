CC=g++
CCFLAGS=-ggdb
OUTPUT_DIR=o
SRC_DIR=./src
TICKET=./ticket
TICKET_SRC=$(wildcard $(SRC_DIR)/*.cpp)
TICKET_INC=-I. -Isrc/

all: $(TICKET)

$(TICKET): $(TICKET_SRC)
	$(CC) $(CCFLAGS) $(TICKET_INC) -o $@ $^

clean:
	@-rm $(TICKET)
	@-rm *~
	@-rm $(SRC_DIR)/*~
