# Makefile variables
CC := g++              # Compiler
CFLAGS := -Wall -g     # Compiler flags: Wall for warnings, g for debugging information
TARGET := main          # Target executable name

# Find all source files with a .cpp extension in the current directory
SRCS := $(wildcard *.cpp)

# Generate a list of object files by replacing .cpp extension with .o for each source file
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

# Default target: build the main executable
all: $(TARGET)

# Rule to build the main executable by linking object files
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# Clean rule: remove the target executable and all object files
clean:
	rm -rf $(TARGET) *.o

# .PHONY rule: specifies that 'all' and 'clean' targets are not files and should always be executed
.PHONY: all clean
