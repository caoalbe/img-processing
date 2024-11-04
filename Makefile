CXX = g++ # Compiler
CXXFLAGS = -static-libstdc++ # Compiler Flags

SOURCES = src/main.cpp src/image.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = imgprocessing

all:  $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean