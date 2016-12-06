# Cave Runner
An openGL 3d game where you run in a cave collecting coins and avoiding obstacles.

## Description
The player runs inside a cave and we have categories of coins and each one increases the score with a different increment depending on the category of the coin collected.
The player will jump using the space keyboard button and will use the left and right keyboard buttons to avoid rocks.
The mouse will be used to control the camera view .
The main target is to complete 5 minutes without colliding with any obstacle and ending up having the maximum score possible.

## Controls
* a: move to the left
* d: move to the right
* w: move forward
* s: move backward
* space: Jump
* n: new game.
* esc: exit game

## Project Structure
```shell

├── /cave-runner.xcodeproj/             # Holds the xCode project configuration
├── /cave-runner/                       # Holds the full source code
│       ├── gameDrawing.cpp             # Holds the game's graphics modeling and drawing logic
│       ├── gameDrawing.hpp             # Holds the header for gameDrawing.cpp
│       ├── gameStructs.hpp             # Holds the game data structures and static variables
│       └── main.cpp                    # Holds the main source code of the game, connecting everything
├── LICENSE.txt                         # The License of the project; MIT License
└── README.md                           # The README file

```

## Getting Started
Clone this repo and cd into it:
```
git clone https://github.com/A-Tokyo/cave-runner
cd cave-runner
```
If you are using macOS:

>    - Open cave-runner.xcodeproj , it opens an xCode project.

If you are using windows:

>    - Open the cave-runner directory in Microsoft Visual Studio as a project
>    - comment the following lines:
>       * #include \<OpenGl/gl.h>
>       * #include \<OpenGl/glu.h>
>       * #include \<GLUT/glut.h>
>    - add the following line:
>       * #include \<glut.h>

## Contribution
#### Style Guide:
  This project uses camelCase naming, single-quotes, 4 space indentation and multiple comments per function.
  Use a single space after keywords.<br/>Ex:
* int x = 3;
* int main(int argc, char** argv) { ... }    
