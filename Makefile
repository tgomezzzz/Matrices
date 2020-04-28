CC = clang++
CXX = clang++

CFLAGS = -g -Wall
CXXFLAGS = -g -Wall -std=c++11

executables = runner
objects = matrix.o runner.o

.PHONY: default
default: $(executables)

$(executables): matrix.o

$(objects): matrix.h

.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
