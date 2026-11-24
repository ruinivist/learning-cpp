.PHONY: run
run: a.out
	./a.out

CXXFLAGS ?= -std=c++14 -Wall -Wextra -pedantic
sources := $(wildcard src/*.cpp)

a.out: $(sources) $(wildcard src/*.h)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(sources) -o $@
