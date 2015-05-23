CC=g++
CCFLAGS=-ggdb
OUTPUT_DIR=o
SRC_DIR=./src
OBJ_DIR=./obj
INTERPRETER=./interpreter
INTERPRETER_OBJ=$(OBJ_DIR)/$(INTERPRETER)
INTERPRETER_SRC=$(wildcard main.cpp $(SRC_DIR)/*.cpp)
INTERPRETER_INC=-I. -Iinclude/ -Iinc/

all: $(INTERPRETER)

$(INTERPRETER): $(INTERPRETER_SRC)
	$(CC) $(CCFLAGS) $(INTERPRETER_INC) -o $@ $^

clean:
	@-rm -f $(INTERPRETER)
	@-rm -f *~
	@-rm -f $(SRC_DIR)/*~
	@-rm -f $(INC_DIR)/*~
