TARGET = comp
CXX = g++
CXXFLAGS = -std=c++17 -Wall -pedantic -Wno-long-long -O2
FILE = ../test/simple.smt2



OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

# .PHONY: default all clean

default: $(TARGET)
all: $(TARGET)



%.o: %.cpp $(HEADERS)
	$(CXX)  $(CXXFLAGS) -c $< -o $@



$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)  -o $(TARGET)
	rm -f *.o 



echo:
	@echo $(TARGET)
	@echo $(HEADERS)
	@echo $(OBJECTS)

clean:
	  rm -f *.o $(TARGET)


run:
	./comp $(FILE)
	