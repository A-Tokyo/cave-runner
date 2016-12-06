#include "gameDrawing.hpp"


void drawRunner(character* thisCharacter){
    glPushMatrix(); // pushing main matrix
        //Top Level Rotation (adjustable through thisCharacter)
        glRotated(thisCharacter->rotation->a ,thisCharacter->rotation->x, thisCharacter->rotation->y, thisCharacter->rotation->z);
        //Top Level Translation (adjustable through thisCharacter)
        glTranslated(thisCharacter->translation->x, thisCharacter->translation->y, thisCharacter->translation->z);
    
        // Creating the gluNewQuadric object
        GLUquadricObj * qobj;
        qobj = gluNewQuadric();
    
        glPushMatrix(); // pushing 1st level matrix
            // deep level rotation (adjustable through thisCharacter)
            glRotated(thisCharacter->deepRotation->a ,thisCharacter->deepRotation->x, thisCharacter->deepRotation->y, thisCharacter->deepRotation->z);
    
            glPushMatrix(); // pushing 3rd level matrix (draw runner)
    
            // TODO Draw runner here
    
            glPopMatrix(); // popping 3rd level matrix (draw runner)
    
        glPopMatrix(); // popping 1st level matrix
    
    glPopMatrix(); // popping main matrix
}

void drawCave(){
    glPushMatrix(); // pushing main matrix
    
    // TODO draw cave here
    
    glPopMatrix(); // popping main matrix
}

void drawRock(obstacle* thisObstacle){
    glPushMatrix(); // pushing main matrix
        //Top Level Rotation (adjustable through thisObstacle)
        glRotated(thisObstacle->rotation->a ,thisObstacle->rotation->x, thisObstacle->rotation->y, thisObstacle->rotation->z);
        //Top Level Translation (adjustable through thisObstacle)
        glTranslated(thisObstacle->translation->x, thisObstacle->translation->y, thisObstacle->translation->z);
    
        // Creating the gluNewQuadric object
        GLUquadricObj * qobj;
        qobj = gluNewQuadric();
    
        glPushMatrix(); // pushing 1st level matrix

            // TODO Draw rock here using the attributes of thisObstacle
    
        glPopMatrix(); // popping 1st level matrix
    
    glPopMatrix(); // popping main matrix
}


/*
 * Implement other drawing functions here.
 */

