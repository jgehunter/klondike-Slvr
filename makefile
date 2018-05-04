 
LDFLAGS= -L/usr/local/lib     -lm   -framework GLUT -framework OpenGL -framework Cocoa   

all:
	gcc main.cpp GLstuff.cpp Personaje.cpp Figura.cpp $(LDFLAGS) -o ejem 
