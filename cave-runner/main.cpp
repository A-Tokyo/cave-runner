#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define PI 3.14159265
#define toDeg 57.2957795131
#define toRad 0.01745329251

// Global Data Structures
typedef struct vector {
    float x;
    float y;
    float z;
    vector(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z =z;
    }
    vector() {
        this->x = 0;
        this->y = 0;
        this->z =0;
    }
    std::string toString() {
        return "["+ std::to_string(x) + ", "+ std::to_string(y) + ", "+std::to_string(z)+"]" ;
    }
    vector unitVector() {
        float magnitude = sqrtf(pow(x,2)+pow(y,2)+pow(z,2));
        vector unitVector(x/magnitude,y/magnitude,z/magnitude);
        return unitVector;
    }
    void set(float newx, float newy, float newz) {
        x = newx;
        y = newy;
        z = newz;
    }
    void set(vector* vector) {
        x = vector->x;
        y = vector->y;
        z = vector->z;
    }
    float magnitude() {
        return sqrtf(pow(x,2)+pow(y,2)+pow(z,2));
    }
} vector;
typedef struct quadraple {
    float a;
    float x;
    float y;
    float z;
    quadraple(float a, float x, float y, float z) {
        this-> a = a;
        this->x = x;
        this->y = y;
        this->z =z;
    }
    quadraple() {
        this-> a = 0;
        this->x = 0;
        this->y = 0;
        this->z =0;
    }
    void set(float a, float x, float y, float z) {
        this-> a = a;
        this->x = x;
        this->y = y;
        this->z =z;
    }
    void set(quadraple* quadraple) {
        this-> a = quadraple->a;
        this->x = quadraple->x;
        this->y = quadraple->y;
        this->z = quadraple->z;
    }
    std::string toString() {
        return "["+ std::to_string(a) + ", "+ std::to_string(x) + ", "+ std::to_string(y) + std::to_string(z)+"]" ;
    }
} quadraple;
typedef struct rgbColor {
    float r;
    float g;
    float b;
    rgbColor(float r, float g, float b){
        this->r = r;
        this->g = g;
        this->b =b;
    }
    rgbColor(){
        this->r = 1;
        this->g = 1;
        this->b =1;
    }
}rgbColor;
typedef struct gameCamera {
    double eyeX;
    double eyeY;
    double eyeZ;
    double centerX;
    double centerY;
    double centerZ;
    double upX;
    double upY;
    double upZ;
    vector DefaultEye;
    vector DefaultCenter;
    vector DefaultUp;
    gameCamera(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ) {
        this->eyeX = eyeX;
        this->eyeY = eyeY;
        this->eyeZ = eyeZ;
        this->centerX = centerX;
        this->centerY = centerY;
        this->centerZ = centerZ;
        this->upX = upX;
        this->upY = upY;
        this->upZ = upZ;
        vector DefaultEye(eyeX,eyeY,eyeZ);
        vector DefaultCenter(centerX,centerY,centerZ);
        vector DefaultUp(upX,upY,upZ);
        this->DefaultEye = DefaultEye;
        this->DefaultCenter = DefaultCenter;
        this->DefaultUp = DefaultUp;
    }
    void incrementEye(double eyeX, double eyeY, double eyeZ) {
        this->eyeX += eyeX;
        this->eyeY += eyeY;
        this->eyeZ += eyeZ;
    }
    void setEye(double eyeX, double eyeY, double eyeZ) {
        this->eyeX = eyeX;
        this->eyeY = eyeY;
        this->eyeZ = eyeZ;
    }
    void setCenter(double centerX, double centerY, double centerZ) {
        this->centerX = centerX;
        this->centerY = centerY;
        this->centerZ = centerZ;
    }
    void set(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ) {
        this->eyeX = eyeX;
        this->eyeY = eyeY;
        this->eyeZ = eyeZ;
        this->centerX = centerX;
        this->centerY = centerY;
        this->centerZ = centerZ;
        this->upX = upX;
        this->upY = upY;
        this->upZ = upZ;
    }
    void reset(){
        this->eyeX = DefaultEye.x;
        this->eyeY = DefaultEye.y;
        this->eyeZ = DefaultEye.z;
        this->centerX = DefaultCenter.x;
        this->centerY = DefaultCenter.y;
        this->centerZ = DefaultCenter.z;
        this->upX = DefaultUp.x;
        this->upY = DefaultUp.y;
        this->upZ = DefaultUp.z;
    }
    std::string eyeToString() {
        return "[" + std::to_string(eyeX) + ", " + std::to_string(eyeY) + ", " + std::to_string(eyeZ) + "]" ;
    }
} gameCamera;
typedef struct gameStatus {
    std::string gameMode;
    bool gameOver;
    gameStatus(std::string gameMode){
        this->gameMode = gameMode;
        this->gameOver = false;
    }
    bool isGameOver(){
        return gameOver;
    }
    void setGameOver(bool gameOver){
        this->gameOver = gameOver;
    }
    void reset() {
        gameOver = false;
    }
}gameStatus;
typedef struct playerStatus {
    std::string name;
    int score;
    playerStatus(std::string name){
        this->name = name;
        score = 0;
    }
    int getScore(){
        return score;
    }
    void setScore(int score){
        this->score = score;
    }
    void incrementScore(int scoreIncrement){
        this->score += scoreIncrement;
    }
}playerStatus;
typedef struct character {
    vector *translation;
    quadraple *rotation;
    quadraple *deepRotation;
    character(vector *translation, quadraple *rotation, quadraple *deepRotation) {
        this->translation = translation;
        this->rotation = rotation;
        this->deepRotation = deepRotation;
    }
    void setTranslation(vector toTranslate) {
        translation->x = toTranslate.x;
        translation->y = toTranslate.y;
        translation->z = toTranslate.z;
    }
    void setRotation(quadraple toRotate) {
        rotation->a = toRotate.a;
        rotation->x = toRotate.x;
        rotation->y = toRotate.y;
        rotation->z = toRotate.z;
    }
    void setRotation(float a, float x, float y, float z) {
        rotation->a = a;
        rotation->x = x;
        rotation->y = y;
        rotation->z = z;
    }
    void resetAttrs() {
        //TODO reset attributes here
    }
} character;

static int windowWidth = 1080;
static int windowHeight = 720;

// Game configuration
void newGame();
void endGame();
// I/O
void passM(int x,int y);
void keyUp(unsigned char k, int x,int y);
// Environment Configuration
void setupCamera();
void setupLights();
// basic openGL
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

}

void keyUp(unsigned char k, int x,int y)//keyboard up function is called whenever the keyboard key is released
{
    switch (k) {
        case 27:
            endGame();
            break;
    }
    glutPostRedisplay();//redisplay to update the screen with the changed
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
    // insert code here...
    std::cout << "Hello, World!\n";
    
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
