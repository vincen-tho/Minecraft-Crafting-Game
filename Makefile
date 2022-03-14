CC = g++

SRC_DIR = src
BIN_DIR = bin

MAIN_FILE = main.cpp
EXEC_NAME = main

COMP_CPP = $(shell find $(SRC_DIR) -name "*.cpp"  ! -name "main_*" ! -name "main.cpp")
COMP_OBJ = $(patsubst %.cpp, build/%.o, $(COMP_CPP))

.PHONY:	test clear

test:
	echo BELUM DIIMPLEMENTASIKAN

./build/src/%.o: ./src/%.cpp
	mkdir -p $(dir $@)
	$(CC) --std=c++17 -c $< -o $@

./bin/$(EXEC_NAME): $(COMP_OBJ) build/src/main.o
	mkdir -p bin
	$(CC) $^ -o $@

./bin/%/main: build/src/%/main.o $(COMP_OBJ)
	mkdir -p $(dir $@)
	$(CC) $^ -o $@

build: ./bin/$(EXEC_NAME)

run: build
	./bin/$(EXEC_NAME)

clear:
	rm -rf build/* bin/*

drive_test: ./bin/$(TDIR)/main
	$<

# TC_FOLDER = tests
# EXT_IN = in
# EXT_OUT = out
# EXT_ANS = ans
# EXECUTABLE_FILENAME = main
# # ALL_SRCS := $(wildcard *.cpp)
# ALL_SRCS = $(shell find src/ -type f -name '*.cpp')
# SRCS     := $(filter-out main.cpp, $(ALL_SRCS))
#
# all: compile test check
#
# # Compile all cpp files except check.cpp
# compile:
# 	# g++ -std=c++17 -o $(EXECUTABLE_FILENAME) $(SRCS)
# 	g++ -std=c++17 -o $(EXECUTABLE_FILENAME) $(ALL_SRCS)
#
# # Test
# test: $(TC_FOLDER)/*.$(EXT_IN) $(EXECUTABLE_FILENAME)
# 	for inputfile in $(TC_FOLDER)/*.$(EXT_IN); do \
# 		./$(EXECUTABLE_FILENAME) < $$inputfile; \
# 	done;
#
# # Check
# check: FORCE check.cpp
# 	g++ -std=c++17 -o check check.cpp
# 	./check
#
# FORCE: ;
#
# listfile:
# 	echo $(SRCS)
