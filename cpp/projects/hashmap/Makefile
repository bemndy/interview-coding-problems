# Makefile - fill in the blanks marked TODO.
#
# Goal: `make` builds a `test_hashmap` binary from test_hashmap.cpp
# (hashmap.h/.tpp are header-only, so nothing else to compile),
# `make run` builds it and runs it, `make clean` removes build artifacts.

CXX      = c++
CXXFLAGS = -Wall -Wextra -g -std=c++17

TARGET = test_hashmap
SRCS   = test_hashmap.cpp
# TODO: derive OBJS from SRCS (hint: substitute .cpp -> .o using $(SRCS:.cpp=.o))
OBJS   =

# TODO: default target. Should depend on $(TARGET).
all:

# TODO: link rule. $(TARGET) depends on $(OBJS); link them with $(CXX) and $(CXXFLAGS).
$(TARGET):

# TODO: pattern rule to compile a .cpp into a .o.
# Hint: also depend on hashmap.h and hashmap.tpp so edits trigger a rebuild.
%.o: %.cpp hashmap.h hashmap.tpp

# TODO: run target -- depends on $(TARGET), then executes ./$(TARGET)
run:

# TODO: clean target -- removes $(TARGET) and $(OBJS)
clean:

.PHONY: all run clean
