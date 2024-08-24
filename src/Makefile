# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Targets for each executable
TARGETS = compare_sorts compare_lengths

# Source files
SRCS_COMPARE_SORTS = compare_sorts.cpp sorting_algorithms.cpp
SRCS_COMPARE_LENGTHS = compare_lengths.cpp sorting_algorithms.cpp

# Object files (automatically generated from source files)
OBJS_COMPARE_SORTS = $(SRCS_COMPARE_SORTS:.cpp=.o)
OBJS_COMPARE_LENGTHS = $(SRCS_COMPARE_LENGTHS:.cpp=.o)

# Default target: build all executables
all: $(TARGETS)

# Rule to build compare_sorts executable
compare_sorts: $(OBJS_COMPARE_SORTS)
	$(CXX) $(CXXFLAGS) -o compare_sorts $(OBJS_COMPARE_SORTS)

# Rule to build compare_lengths executable
compare_lengths: $(OBJS_COMPARE_LENGTHS)
	$(CXX) $(CXXFLAGS) -o compare_lengths $(OBJS_COMPARE_LENGTHS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove the executables and object files
clean:
	rm -f $(TARGETS) *.o
