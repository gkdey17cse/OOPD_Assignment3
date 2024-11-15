# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -fPIC

# Static library target
STATIC_LIB = libstatIRlib.a
STATIC_OBJ = Station.o Line.o Platform.o

# Dynamic library target
DYNAMIC_LIB = libdynIRlib.so

# Executable target
EXEC = main

# Default target: build static and dynamic libraries, and main executable
all: $(STATIC_LIB) $(DYNAMIC_LIB) $(EXEC)

# Create static library (.a)
$(STATIC_LIB): $(STATIC_OBJ)
	ar rcs $@ $^

# Create dynamic library (.so)
$(DYNAMIC_LIB): $(STATIC_OBJ)
	$(CXX) -shared -o $@ $^

# Compile Station.cpp to object file
Station.o: Station.cpp Station.h Platform.h
	$(CXX) $(CXXFLAGS) -c Station.cpp -o $@

# Compile Platform.cpp to object file
Platform.o: Platform.cpp Platform.h
	$(CXX) $(CXXFLAGS) -c Platform.cpp -o $@

# Compile Line.cpp to object file
Line.o: Line.cpp Line.h
	$(CXX) $(CXXFLAGS) -c Line.cpp -o $@

# Compile main.cpp and link with the static library
$(EXEC): main.cpp $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) main.cpp -L. -lstatIRlib -o $@

# Clean up generated files
clean:
	rm -f *.o $(STATIC_LIB) $(DYNAMIC_LIB) $(EXEC)

.PHONY: all clean
