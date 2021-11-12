CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./src/fork.cc ./includes/fork.hpp
	$(CXX) $(CXXFLAGS) ./src/driver.cc ./src/fork.cc  -o $@

bin/tests: ./tests/tests.cc ./src/fork.cc ./includes/fork.hpp
	$(CXX) $(CXXFLAGS) ./tests/tests.cc ./src/fork.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -rf ./bin/*
