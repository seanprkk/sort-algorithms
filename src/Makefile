# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Source Files
SRCS = compare_sorts.cpp compare_lengths.cpp print_times.cpp sorting_algorithms.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Executable Files
EXES = compare_sorts compare_lengths print_times

# Default target
all: $(EXES)

# Rule to build compare_sorts executable
compare_sorts: compare_sorts.o sorting_algorithms.o
	$(CXX) $(CXXFLAGS) -o compare_sorts compare_sorts.o sorting_algorithms.o

# Rule to build compare_lengths executable
compare_lengths: compare_lengths.o sorting_algorithms.o
	$(CXX) $(CXXFLAGS) -o compare_lengths compare_lengths.o sorting_algorithms.o

# Rule to build print_times executable
print_times: print_times.o sorting_algorithms.o
	$(CXX) $(CXXFLAGS) -o print_times print_times.o sorting_algorithms.o

# Clean up object files and executables
clean:
	rm -f $(OBJS) $(EXES)
