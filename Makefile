CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LIBS = -lncurses
TARGET = snake_game
SOURCE = snake_game.cpp

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE) $(LIBS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

install-deps:
	sudo apt-get update && sudo apt-get install -y libncurses5-dev libncursesw5-dev

.PHONY: clean run install-deps