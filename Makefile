objects = main.o Engine.o Game.o Graphics.o Keyboard.o Mouse.o MainWindow.o CoordinateTransformer.o Entity.o Camera.o Drawable.o Starfield.o Star.o
flags = -Wno-unknown-pragmas -Wall -pedantic -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

install : $(objects)
	g++ -o output $(objects) $(flags)

main.o : main.cpp
	g++ -c -o main.o main.cpp $(flags)
Engine.o : Engine.cpp Engine.h
	g++ -c -o Engine.o Engine.cpp $(flags)
Game.o : Game.cpp Game.h
	g++ -c -o Game.o Game.cpp $(flags)
Graphics.o : Graphics.cpp Graphics.h
	g++ -c -o Graphics.o Graphics.cpp $(flags)
Keyboard.o : Keyboard.cpp Keyboard.h
	g++ -c -o Keyboard.o Keyboard.cpp $(flags)
Mouse.o : Mouse.cpp Mouse.h
	g++ -c -o Mouse.o Mouse.cpp $(flags)
MainWindow.o : MainWindow.cpp MainWindow.h
	g++ -c -o MainWindow.o MainWindow.cpp $(flags)
CoordinateTransformer.o : CoordinateTransformer.cpp CoordinateTransformer.h
	g++ -c -o CoordinateTransformer.o CoordinateTransformer.cpp $(flags)
Camera.o : Camera.cpp Camera.h
	g++ -c -o Camera.o Camera.cpp $(flags)
Entity.o : Entity.cpp Entity.h
	g++ -c -o Entity.o Entity.cpp $(flags)
Drawable.o : Drawable.cpp Drawable.h
	g++ -c -o Drawable.o Drawable.cpp $(flags)
Starfield.o : Starfield.cpp Starfield.h
	g++ -c -o Starfield.o Starfield.cpp $(flags)
Star.o : Star.cpp Star.h
	g++ -c -o Star.o Star.cpp $(flags)

clean :
	rm -f output $(objects)
