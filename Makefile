objects = main.o Game.o Graphics.o Keyboard.o Mouse.o MainWindow.o Engine.o 
flags = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

install : $(objects)
	g++ -o output $(objects) $(flags)

main.o : main.cpp
	g++ -c main.cpp
Engine.o : Engine.cpp Engine.h
	g++ -c Engine.cpp
Game.o : Game.cpp Game.h
	g++ -c Game.cpp
Graphics.o : Graphics.cpp Graphics.cpp
	g++ -c Graphics.cpp
Keyboard.o : Keyboard.cpp Keyboard.h
	g++ -c Keyboard.cpp
Mouse.o : Mouse.cpp Mouse.cpp
	g++ -c Mouse.cpp
MainWindow.o : MainWindow.cpp MainWindow.h
	g++ -c MainWindow.cpp

clean :
	rm -f output $(objects)
