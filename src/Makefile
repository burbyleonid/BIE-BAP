TARGET = comp
CXX = clang++

CXXFLAGS = 




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
	./comp $(file)
	clang++ OutputFile.ll
	./a.out
	