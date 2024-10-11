# Variables
CC = clang
CFLAGS = -Wall -Wextra -g
LDFLAGS = 
TARGET = parser
SRC = command_parser.c chunk.c debug.c value.c memory.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean