objects = main.o Engine.o Game.o Graphics.o Keyboard.o Mouse.o MainWindow.o CoordinateTransformer.o Entity.o Camera.o Drawable.o Time.o IndexedTriangleList.o

warning_flags = -Wall -Wextra -pedantic -Wno-unknown-pragmas -Wno-unused-parameter

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

os_type = $(shell uname -s)
ifeq ($(os_type),Linux)
	CC = g++
	lib_flags = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
endif
ifeq ($(os_type),Darwin)
	CC = clang++
	build_flags += -arch x86_64 -std=c++17 -mmacosx-version-min=10.15
	lib_flags = -framework OpenGL -framework GLUT -lpng
	warning_flags += -Wno-unused-private-field -Wno-missing-braces
endif

build_flags += $(warning_flags)

install : $(objects)
	$(CC) -o output $(objects) $(build_flags) $(lib_flags)

main.o : main.cpp
	$(CC) -c -o main.o main.cpp $(build_flags)
Engine.o : Engine.cpp Engine.h
	$(CC) -c -o Engine.o Engine.cpp $(build_flags)
Game.o : Game.cpp Game.h
	$(CC) -c -o Game.o Game.cpp $(build_flags)
Graphics.o : Graphics.cpp Graphics.h
	$(CC) -c -o Graphics.o Graphics.cpp $(build_flags)
Keyboard.o : Keyboard.cpp Keyboard.h
	$(CC) -c -o Keyboard.o Keyboard.cpp $(build_flags)
Mouse.o : Mouse.cpp Mouse.h
	$(CC) -c -o Mouse.o Mouse.cpp $(build_flags)
MainWindow.o : MainWindow.cpp MainWindow.h
	$(CC) -c -o MainWindow.o MainWindow.cpp $(build_flags)
CoordinateTransformer.o : CoordinateTransformer.cpp CoordinateTransformer.h
	$(CC) -c -o CoordinateTransformer.o CoordinateTransformer.cpp $(build_flags)
Camera.o : Camera.cpp Camera.h
	$(CC) -c -o Camera.o Camera.cpp $(build_flags)
Entity.o : Entity.cpp Entity.h
	$(CC) -c -o Entity.o Entity.cpp $(build_flags)
Drawable.o : Drawable.cpp Drawable.h
	$(CC) -c -o Drawable.o Drawable.cpp $(build_flags)
Time.o : Time.cpp Time.h
	$(CC) -c -o Time.o Time.cpp $(build_flags)
IndexedTriangleList.o : IndexedTriangleList.cpp IndexedTriangleList.h
	$(CC) -c -o IndexedTriangleList.o IndexedTriangleList.cpp $(build_flags)

clean :
	rm -f output $(objects)
