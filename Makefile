SFML_PATH = /opt/homebrew/Cellar/sfml/3.0.1

cppFileNames := $(shell find ./src -type f -name "*.cpp")

all: compile

compile:
	mkdir -p bin
	g++ -std=c++17 $(cppFileNames) -I$(SFML_PATH)/include -o bin/app -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network