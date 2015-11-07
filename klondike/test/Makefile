SRC_DIR=../src
INC_FILES=../src
SOURCES=$(shell ls $(SRC_DIR)/*.cpp | grep -v main)
TEST_FILE=test_klondike.cpp
GTEST_FILE=gtest
GTEST_LIBS=gtest gtest_main pthread
GTEST_LINK_LIBS=$(addprefix -l,$(GTEST_LIBS))
CC=g++
CC_FLAGS=-ggdb -std=c++0x

all: gtest

$(GTEST_FILE): $(TEST_FILE) $(SOURCES)
	$(CC) $(CC_FLAGS) -I$(INC_FILES) $(SOURCES) $(TEST_FILE) -o $@ $(GTEST_LINK_LIBS)

clean:
	rm -f $(GTEST_FILE) *~
