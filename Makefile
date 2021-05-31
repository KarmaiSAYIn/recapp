objects = main.o Game.o Graphics.o Keyboard.o Mouse.o MainWindow.o Engine.o 
flags = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

install : $(objects)
	g++ -o output $(objects) $(flags)

main.o :
Engine.o :
Game.o :
Graphics.o :
Keyboard.o :
Mouse.o :
MainWindow.o :

clean :
	rm -f output $(objects)
