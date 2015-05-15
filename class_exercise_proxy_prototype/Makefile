CC=g++
CCFLAGS=-ggdb
OUTPUT_DIR=o
SRC_DIR=./src
OBJ_DIR=./obj
CALC=calc
CALC_OBJ=$(OBJ_DIR)/$(CALC)
CALC_SRC=$(wildcard main.cpp $(SRC_DIR)/*.cpp)
CALC_INC=-I. -Iinclude/ -Iinc/

all: $(CALC)

$(CALC): $(CALC_SRC)
	$(CC) $(CCFLAGS) $(CALC_INC) -o $@ $^

clean:
	@-rm -f $(CALC)
	@-rm -f *~
	@-rm -f $(SRC_DIR)/*~
	@-rm -f $(INC_DIR)/*~
