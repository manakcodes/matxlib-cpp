# Makefile for matxlib-cpp

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Iassets
SRC = Main.cpp
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)