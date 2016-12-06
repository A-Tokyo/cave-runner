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


void drawRunner(character* thisCharacter);
void drawCave();
void drawRock(obstacle* thisObstacle);

/*
 * Add drawing functions' signatures here.
 */

#endif /* gameDrawing_hpp */
