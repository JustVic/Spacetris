CC     =  gcc
CFLAGS= -I/usr/X11R6/lib/ -I/usr/local/include/SDL 
LIB    = -lX11 -lSDL -lSDL_ttf	
SRC    = main.c io.c board.c tetr.c
OBJECT = main.o io.o board.o tetr.o
TARGET = spacetris



all:
	    @$(CC) $(CFLAGS) $(LIB) $(SRC) -o $(TARGET);
	       @echo "Usage: ./$(TARGET)";
		        
clean:
	    @rm -f $(TARGET);
	        @echo "\"$(TARGET)\" remove...";
