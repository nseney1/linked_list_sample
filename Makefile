# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++14

# Define the final executable name
EXEC = program

# List of source files
SOURCES = main.cpp Node/Node.cpp LinkedList/LinkedList.cpp

# Generate names of object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target: build the executable
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target: remove object files and the executable
clean:
	rm -f $(OBJECTS) $(EXEC)

# Phony targets
.PHONY: all clean
