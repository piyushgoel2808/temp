CC = clang
CXX = clang++
CFLAGS = -Wall -Wextra -O2
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

C_SRCS = $(wildcard *.c)
CPP_SRCS = $(wildcard *.cpp)

C_BINS = $(C_SRCS:.c=)
CPP_BINS = $(CPP_SRCS:.cpp=)
ALL_BINS = $(C_BINS) $(CPP_BINS)

.PHONY: all clean test

all: $(ALL_BINS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test:
	python3 test_programs.py

clean:
	rm -f $(ALL_BINS)
