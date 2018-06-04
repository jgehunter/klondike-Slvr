CC = g++
CFLAGS = -g -Wall -Wno-deprecated
LDFLAGS=
OS = $(shell uname)
ifeq ($(OS), Darwin)
	LIBS = -framework OpenGL -framework GLUT -L/usr/local/lib
else ifeq ($(OS), Linux)
	LIBS = -lglut -lGLU -lGL
else
	LIBS = -lglut32 -lglu32 -lopengl32
endif

Klondike:
	$(CC) main.cpp GLstuff.cpp Personaje.cpp Figura.cpp Camino.cpp nodo.cpp -std=c++11 $(CFLAGS)   $(LIBS) -o Klondikeapp
