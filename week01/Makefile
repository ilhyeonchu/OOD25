TIDYFLAGS = --checks=-*,cppcoreguidlines-*,-cppcoreguidelines-owning-memory,readability-*

all: hw1.cc
	clang++ -std=c++17 hw1.cc -o hw1

clean:
	rm -f hw1

tidy:
	clang-tidy $(shell find . -name "*.cc" -o -name "*.h") $(TIDYFLAGS) --fix -- -x c++ -std=c++17

.PHONY: all clean
