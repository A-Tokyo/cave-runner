#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
// Custom Includes
#include "gameStructs.hpp"
#include "gameDrawing.hpp"
// Definitions
using namespace std;
#define PI 3.14159265
#define toDeg 57.2957795131
#define toRad 0.01745329251

static int windowWidth = 1080;
static int windowHeight = 720;

// Game configuration
void newGame();
void endGame();
// Game I/O
void gameKeyUp(unsigned char k, int x,int y);
void gamePassiveMotion(int x, int y);
// OpenGL I/O
void passM(int x,int y);
void keyUp(unsigned char k, int x,int y);
// OpenGL Environment Configuration
void setupCamera();
void setupLights();
// Basic openGL
void Display();
void Anim();


//Basic game state
gameStatus gameStat("basic");
gameCamera gameCam(0, 0, 180, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Defining default camera

// Initial initialization, Control these vectors using the objects only

vector mainCharacterTranslation(0,0,0);
vector mainCharacterInitialTranslation(0,0,0);
quadraple mainCharacterRotation(0,0,0,0);
quadraple mainCharacterInitialRotation(0,0,0,0);
quadraple mainCharacterDeepRotation(0,0,0,0);
character mainCharacter(&mainCharacterTranslation, &mainCharacterRotation, &mainCharacterDeepRotation);



// Start of custom game functions


void newGame(){
    
}

void endGame() {
    gameStat.setGameOver(true);
    exit (0);
}

void gamePassiveMotion(int x, int y){
    
}

void gameKeyUp(unsigned char k, int x,int y){
    switch (k) {
        case 27:
            endGame();
            break;
    }
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    
    if(!gameStat.isGameOver()) {
        setupCamera();
        setupLights();
    }
    
    glPopMatrix();
    glFlush();
}

void anim() {
    glutPostRedisplay();
}

// I/O functions

void passM(int x,int y) {
    //Don't add any code here, add it in void gamePassiveMotion(int x, int y)
    gamePassiveMotion(x, y);
    glutPostRedisplay();//redisplay to update the screen with the changes
}

void keyUp(unsigned char k, int x,int y)//keyboard up function is called whenever the keyboard key is released
{
    //Don't add any code here, add it in void void gameKeyUp(unsigned char k, int x,int y)
    gameKeyUp(k, x, y);
    glutPostRedisplay();//redisplay to update the screen with the changes
}

// openGL Environment Initilization

void setupCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(1, 1, -1, 1, -1, 1);
    gluPerspective(80, 640 / 480, 0.001, 1000);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(gameCam.eyeX, gameCam.eyeY, gameCam.eyeZ, gameCam.centerX, gameCam.centerY, gameCam.centerZ, gameCam.upX, gameCam.upY, gameCam.upZ);
}

void setupLights() {
// TODO Setup Lights here
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutCreateWindow("Cave Runner");
    glutInitWindowSize(windowWidth, windowHeight);
    glutFullScreen();
    glutDisplayFunc(Display);
    glutIdleFunc(anim);
    glutPassiveMotionFunc(passM); // call passive motion function for mouse movements
    glutKeyboardUpFunc(keyUp);		//call the keyboard up function
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutSetCursor(GLUT_CURSOR_NONE);
    
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    
    newGame();
    
    glutMainLoop();
    
    return 0;
}
