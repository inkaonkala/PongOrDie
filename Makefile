CXX = g++

# SFML include and lib paths (adjust if versions change)
INCLUDE_DIR = /opt/homebrew/Cellar/sfml/2.6.1/include
LIB_DIR = /opt/homebrew/Cellar/sfml/2.6.1/lib

CXXFLAGS = -std=c++17 -I$(INCLUDE_DIR) -Wall
LDFLAGS = -L$(LIB_DIR) -lsfml-graphics -lsfml-window -lsfml-system

# Name of the binary
TARGET = ponging

# Source files in the src/ folder
SRCS = $(wildcard src/*.cpp)

# Output rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)
