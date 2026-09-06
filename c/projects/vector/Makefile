# Makefile - fill in the blanks marked TODO.
#
# Goal: `make` builds a `test_vector` binary from vector.c + test_vector.c,
# `make run` builds it and runs it, `make clean` removes build artifacts.

CC     = cc
CFLAGS = -Wall -Wextra -g

TARGET = test_vector
SRCS   = vector.c test_vector.c
# TODO: derive OBJS from SRCS (hint: substitute .c -> .o using $(SRCS:.c=.o))
OBJS   =

# TODO: default target. Should depend on $(TARGET).
all:

# TODO: link rule. $(TARGET) depends on $(OBJS); link them with $(CC) and $(CFLAGS).
$(TARGET):

# TODO: pattern rule to compile a .c into a .o.
# Hint: also depend on vector.h so edits to the header trigger a rebuild.
%.o: %.c vector.h

# TODO: run target -- depends on $(TARGET), then executes ./$(TARGET)
run:

# TODO: clean target -- removes $(TARGET) and $(OBJS)
clean:

.PHONY: all run clean
