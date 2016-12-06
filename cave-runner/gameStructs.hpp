//
//  gameStructs.hpp
//  cave-runner
//
//  Created by Ahmed Mohamed on 12/3/16.
//  Copyright © 2016 Ahmed Mohamed. All rights reserved.
//

#ifndef gameStructs_hpp
#define gameStructs_hpp

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


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
    vector unitVector() {
        float magnitude = sqrtf(pow(x,2)+pow(y,2)+pow(z,2));
        vector unitVector(x/magnitude,y/magnitude,z/magnitude);
        return unitVector;
    }
    float magnitude() {
        return sqrtf(pow(x,2)+pow(y,2)+pow(z,2));
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
    std::string toString() {
        return "["+ std::to_string(x) + ", "+ std::to_string(y) + ", "+std::to_string(z)+"]" ;
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
    bool controlPlayer;
    bool gameOver;
    gameStatus(std::string gameMode){
        this->gameMode = gameMode;
        this->gameOver = false;
        this->controlPlayer = false;
    }
    bool isGameOver(){
        return gameOver;
    }
    void setGameOver(bool gameOver){
        this->gameOver = gameOver;
    }
    bool canControlPlayer(){
        return controlPlayer;
    }
    void enableCanControlPlayer(){
        controlPlayer = true;
    }
    void disableCanControlPlayer(){
        controlPlayer = false;
    }
    void reset() {
        gameOver = false;
        controlPlayer = false;
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
        translation->set(&toTranslate);
    }
    void setTranslation(float x, float y, float z) {
        translation->set(x, y, z);
    }
    void setRotation(quadraple toRotate) {
        rotation->set(&toRotate);
    }
    void setRotation(float a, float x, float y, float z) {
        rotation->set(a, x, y, z);
    }
    void resetAttrs() {
        //TODO reset attributes here
    }
} character;
typedef struct obstacle {
    int length;
    int height;
    vector *translation;
    quadraple *rotation;
    obstacle(int length, int height, vector *translation, quadraple *rotation){
        this->length = length;
        this->height = height;
        this->translation = translation;
        this->rotation = rotation;
    }
    obstacle(){
        this->length = 15;
        this->height = 15;
        vector translation(0,0,0);
        this->translation = &translation;
        quadraple rotation(0,0,0,0);
        this->rotation = &rotation;
    }
}obstacle;
typedef struct coin {
    int radius;
    int scorePoint;
    vector *translation;
    quadraple *rotation;
    quadraple *deepRotation;
    coin(int radius, int scorePoint, vector *translation, quadraple *rotation, quadraple *deepRotation){
        this->radius = radius;
        this->scorePoint = scorePoint;
        this->translation = translation;
        this->rotation = rotation;
        this->deepRotation = deepRotation;
    }
    coin(){
        this->radius = 10;
        vector translation(0,0,0);
        this->translation = &translation;
        quadraple rotation(0,0,0,0);
        this->rotation = &rotation;
        quadraple deepRotation(0,0,1,0);
        this->deepRotation = &deepRotation;
    }
}coin;



#endif /* gameStructs_hpp */
