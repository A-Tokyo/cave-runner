#ifndef gameDrawing_hpp
#define gameDrawing_hpp

#include <OpenGl/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
// Custom Includes
#include "gameStructs.hpp"


void drawCave();
void drawRunner(character* thisCharacter);
void drawRock(obstacle* thisObstacle);
void drawCoin(coin* thisCoin);


/*
 * Add drawing functions' signatures here.
 */

#endif /* gameDrawing_hpp */
