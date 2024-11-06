CXX = g++ # Compiler
CXXFLAGS = -static-libstdc++ # Compiler Flags

SOURCES = src/main.cpp src/image.cpp src/features.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = main

all:  $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean