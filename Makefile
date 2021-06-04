objects = main.o Engine.o Game.o Graphics.o Keyboard.o Mouse.o MainWindow.o CoordinateTransformer.o Entity.o Camera.o Drawable.o Starfield.o
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
CoordinateTransformer.o : CoordinateTransformer.cpp CoordinateTransformer.h
Camera.o : Camera.cpp Camera.h
Entity.o : Entity.cpp Entity.h
Drawable.o : Drawable.cpp Drawable.h
Starfield.o : Starfield.cpp Starfield.h

clean :
	rm -f output $(objects)
