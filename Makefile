objects = main.o Engine.o Game.o Graphics.o Keyboard.o Mouse.o MainWindow.o CoordinateTransformer.o Entity.o Camera.o Drawable.o Starfield.o Star.o

warning_build_flags = -Wno-unknown-pragmas -Wall -pedantic

# Handle debug or release compile; debug without any arguements,
# pass -r if you want release. As far as my knowledge goes, if you compile for debug before release,
# compiling for release afterward will just relink the object files,
# unless there were changes to their prerequisites; thus not actually improving performance.
# Always do make clean install -r after compiling for debug.
ifneq (,$(findstring r,$(MAKEFLAGS)))
	build_flags = -DNDEBUG
else
	build_flags = -g3
endif

build_flags += $(warning_build_flags)

os_type = $(shell uname -s)
ifeq ($(os_type),Linux)
	lib_flags = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
endif
ifeq ($(os_type),Darwin)
	lib_flags = -arch x86_64 -std=c++17 -mmacosx-version-min=10.15 -framework OpenGL -framework GLUT -lpng
endif

install : $(objects)
	g++ -o output $(objects) $(build_flags) $(lib_flags)

main.o : main.cpp
	g++ -c -o main.o main.cpp $(build_flags)
Engine.o : Engine.cpp Engine.h
	g++ -c -o Engine.o Engine.cpp $(build_flags)
Game.o : Game.cpp Game.h
	g++ -c -o Game.o Game.cpp $(build_flags)
Graphics.o : Graphics.cpp Graphics.h
	g++ -c -o Graphics.o Graphics.cpp $(build_flags)
Keyboard.o : Keyboard.cpp Keyboard.h
	g++ -c -o Keyboard.o Keyboard.cpp $(build_flags)
Mouse.o : Mouse.cpp Mouse.h
	g++ -c -o Mouse.o Mouse.cpp $(build_flags)
MainWindow.o : MainWindow.cpp MainWindow.h
	g++ -c -o MainWindow.o MainWindow.cpp $(build_flags)
CoordinateTransformer.o : CoordinateTransformer.cpp CoordinateTransformer.h
	g++ -c -o CoordinateTransformer.o CoordinateTransformer.cpp $(build_flags)
Camera.o : Camera.cpp Camera.h
	g++ -c -o Camera.o Camera.cpp $(build_flags)
Entity.o : Entity.cpp Entity.h
	g++ -c -o Entity.o Entity.cpp $(build_flags)
Drawable.o : Drawable.cpp Drawable.h
	g++ -c -o Drawable.o Drawable.cpp $(build_flags)
Starfield.o : Starfield.cpp Starfield.h
	g++ -c -o Starfield.o Starfield.cpp $(build_flags)
Star.o : Star.cpp Star.h
	g++ -c -o Star.o Star.cpp $(build_flags)

clean :
	rm -f output $(objects)
