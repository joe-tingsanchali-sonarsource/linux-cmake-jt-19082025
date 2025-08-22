# Makefile
# This is a basic Makefile for the C project.
# It uses gcc to compile the main.c file and creates an executable named 'project'.

# The C compiler to use
CC = gcc

# The name of the executable file
TARGET = project

# The source file
SRC = main.c

# The default target
all: $(TARGET)

# Rule to build the executable from the source file
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

# Clean up build artifacts
clean:
	rm -f $(TARGET)
