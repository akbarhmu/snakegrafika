# snakegrafika

OpenGL based snake game for computer graphic subject

Blogsite : https://snakegame-opengl.blogspot.com

## Requirements

- [GNU C++ Compiler / MinGW](https://osdn.net/projects/mingw/releases/)
- [FreeGLUT](https://www.deborahrfowler.com/OpenGLResources/usingOpenGLwithMinGWandFreeGlut.html)

## Compiling
Clone this repository.
```
git clone https://github.com/Archiruz/snakegrafika.git
```
Enter the folder.
```
cd snakegrafika
```
Compile the program.
```
g++ -o snake *.cpp -I"C:\MinGW\freeglut\include" -L"C:\MinGW\freeglut\lib" -lfreeglut -lopengl32 -lwinmm
```

## Usage

```./snake.exe``` or open the executable file.

## Shortcut Key

`e` Exit

`p` Pause
