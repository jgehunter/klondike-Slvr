CC = g++
CFLAGS = -g -Wall -Wno-deprecated
LDFLAGS= 
OS = $(shell uname)
ifeq ($(OS), Darwin)
	LIBS = -framework OpenGL -framework GLUT -L/usr/local/lib
else ifeq ($(OS), Linux) 
	LIBS = -lglut -lGLU -lGL
else
#	CC=i686-pc-mingw32-g++
#	CC=i686-w64-mingw32-g++
	CC=x86_64-w64-mingw32-g++
	LIBS = -lglut32 -lglu32 -lopengl32
#	LIBS = -lglut -lGLU -lGL
endif

Klondike:
	$(CC) main.cpp GLstuff.cpp Personaje.cpp Figura.cpp Camino.cpp nodo.cpp -std=c++11 $(CFLAGS)   $(LIBS) -o Klondikeapp 