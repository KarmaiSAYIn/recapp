objects = main.o Game.o Graphics.o Keyboard.o Mouse.o MainWindow.o Engine.o 
flags = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

install : $(objects)
	g++ -o output $(objects) $(flags)

main.o : main.cpp
Engine.o : Engine.cpp Engine.h
Game.o : Game.cpp Game.h
Graphics.o : Graphics.cpp Graphics.h
Keyboard.o : Keyboard.cpp Keyboard.h
Mouse.o : Mouse.cpp Mouse.h
MainWindow.o : MainWindow.cpp MainWindow.h

clean :
	rm -f output $(objects)
