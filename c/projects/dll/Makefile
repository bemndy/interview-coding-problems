# Makefile - fill in the blanks marked TODO.
#
# Goal: `make` builds a `test_dll` binary from dll.c + test_dll.c,
# `make run` builds it and runs it, `make clean` removes build artifacts.
# `make leaks` runs it under a leak checker (uses `leaks` on macOS,
# falls back to valgrind elsewhere) -- confirm zero leaks.

CC		 = gcc
CFLAGS = -Wall -Wextra -g

TARGET = test_dll
SRCS   = dll.c test_dll.c

# TODO: derive OBJS from SRCS (hint: substitute .c -> .o using $(SRCS:.c=.o))
OBJS   = $(SRCS:.c=.o)

# TODO: default target. Should depend on $(TARGET).
all: $(TARGET)

# TODO: link rule. $(TARGET) depends on $(OBJS); link them with $(CC) and $(CFLAGS).
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# TODO: pattern rule to compile a .c into a .o.
# Hint: also depend on dll.h so edits to the header trigger a rebuild.
%.o: %.c dll.h
	$(CC) $(CFLAGS) -c -o $@ $<

# TODO: run target -- depends on $(TARGET), then executes ./$(TARGET)
run: $(TARGET)
	./$(TARGET)

leaks: $(TARGET)
	leaks -atExit -- ./$(TARGET) || valgrind --leak-check=full ./$(TARGET)

# TODO: clean target -- removes $(TARGET) and $(OBJS)
clean:
	rm -f $(TARGET) $(OBJS) 

.PHONY: all run clean leaks
