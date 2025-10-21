
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#define PI 3.14159265358979323846


void sound()
{

    PlaySound("new.wav", NULL, SND_ASYNC|SND_FILENAME);
    //PlaySound("new.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

// Global variable to track the current scene
int currentScene = -1;


////////1st Scene functions/////////////////////////////////////////////////////////////////////////////////
// LiftManYellow motion
GLfloat liftmanyellowposition = -280.0f;  // Initial X-axis position (starts from the right)
GLfloat liftmanyyellowposition = -10.0f;   // Initial Y-axis position (centered vertically)
GLfloat liftmanyyellowspeed = 2.40f;       // Speed for X-axis
GLfloat liftmanyyellowspeedy = 5.50f;      // Speed for Y-axis (negative for decreasing)
GLfloat liftmanyellowpositionScaleX = 1.3f;       // Initial scaling factor for X-axis
GLfloat liftmanyellowpositionScaleY = 1.3f;       // Initial scaling factor for Y-axis
GLfloat scaleSpeedy = 0.004f;   // Speed for scaling


bool liftmanyellowIsVisible = true;

void updateliftmanyellow(int value) {
 // Update positions and scaling
    if (liftmanyellowIsVisible)
    {
        liftmanyellowposition += liftmanyyellowspeed;
        liftmanyyellowposition += liftmanyyellowspeedy; // Move down
        liftmanyellowpositionScaleX -= scaleSpeedy;
        liftmanyellowpositionScaleY -= scaleSpeedy;

        // Check if the object has crossed the threshold
        if (liftmanyyellowposition >= 534.0f)
        {
            liftmanyellowIsVisible = false; // Set visibility to false
        }
    }

    // Trigger a redraw
    glutPostRedisplay();

    // Call update again after 100 ms
    glutTimerFunc(100, updateliftmanyellow, 0);
}

// LiftManPink motion
GLfloat liftmanPinkposition = -110.0f;  // Initial X-axis position (starts from the right)
GLfloat liftmanyPinkposition = -10.0f;   // Initial Y-axis position (centered vertically)
GLfloat liftmanyPinkspeed = 2.53f;       // Speed for X-axis
GLfloat liftmanyPinkspeedy = 5.50f;      // Speed for Y-axis (negative for decreasing)
GLfloat liftmanPinkpositionScaleX = 1.1f;       // Initial scaling factor for X-axis
GLfloat liftmanPinkpositionScaleY = 1.1f;       // Initial scaling factor for Y-axis
GLfloat scaleSpeedPink = 0.004f;   // Speed for scaling


bool liftmanPinkIsVisible = true;

void updateliftmanPink(int value) {
 // Update positions and scaling
    if (liftmanPinkIsVisible)
    {
        liftmanPinkposition += liftmanyPinkspeed;
        liftmanyPinkposition += liftmanyPinkspeedy; // Move down
        liftmanPinkpositionScaleX -= scaleSpeedPink;
        liftmanPinkpositionScaleY -= scaleSpeedPink;

        // Check if the object has crossed the threshold
        if (liftmanyPinkposition >= 320.0f)
        {
            liftmanPinkIsVisible = false; // Set visibility to false
        }
    }

    // Trigger a redraw
    glutPostRedisplay();

    // Call update again after 100 ms
    glutTimerFunc(100, updateliftmanPink, 0);
}

// LiftManGreen motion
GLfloat liftmanGreenposition = -90.0f;  // Initial X-axis position (starts from the right)
GLfloat liftmanyGreenposition = -10.0f;   // Initial Y-axis position (centered vertically)
GLfloat liftmanyGreenspeed = 1.70f;       // Speed for X-axis
GLfloat liftmanyGreenspeedy = 2.80f;      // Speed for Y-axis (negative for decreasing)
GLfloat liftmanGreenpositionScaleX = 1.1f;       // Initial scaling factor for X-axis
GLfloat liftmanGreenpositionScaleY = 1.1f;       // Initial scaling factor for Y-axis
GLfloat scaleSpeedGreen = 0.0045f;   // Speed for scaling




void updateliftmanGreen(int value) {
 // Update positions and scaling

        liftmanGreenposition -= liftmanyGreenspeed;
        liftmanyGreenposition -= liftmanyGreenspeedy; // Move down
        liftmanGreenpositionScaleX += scaleSpeedGreen;
        liftmanGreenpositionScaleY += scaleSpeedGreen;

        // Check if the object has crossed the threshold


    // Trigger a redraw
    glutPostRedisplay();

    // Call update again after 100 ms
    glutTimerFunc(20, updateliftmanGreen, 0);
}


///////for station///////
  void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
///////for cover/////////
void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Man motion
GLfloat manposition = -1000.0f;  // Initial X-axis position (starts from the right)
GLfloat manyposition = -700.0f;  // Initial Y-axis position (centered vertically)
GLfloat manspeed = 6.50f;          // Speed for X-axis
GLfloat manspeedy = 10.0f;        // Speed for Y-axis (negative for decreasing)
GLfloat scaleX = 2.10f;          // Initial scaling factor for X-axis
GLfloat scaleY = 2.10f;          // Initial scaling factor for Y-axis
GLfloat scaleSpeed = 0.0095f;      // Speed for scaling

bool isVisible = true; // Global variable to track visibility

void update6(int value)
{
    // Update positions and scaling
    if (isVisible)
    {
        manposition += manspeed;
        manyposition += manspeedy; // Move down
        scaleX -= scaleSpeed;
        scaleY -= scaleSpeed;

        // Check if the object has crossed the threshold
        if (manyposition >= 41.50f)
        {
            isVisible = false; // Set visibility to false
        }
    }

    // Trigger a redraw
    glutPostRedisplay();

    // Call update again after 100 ms
    glutTimerFunc(100, update6, 0);
}



//train motion
GLfloat trainposition = 1505.0f;
GLfloat trainspeed = 4;

bool isTrainStop =false;


void update(int value)
{
     if(!isTrainStop)
     {
            if (trainposition > 0.0f) // If the train is ahead of position 0
            {
               trainposition -= trainspeed; // Move the train
            }
            else
            {
            trainposition = trainposition; // Stop the train at position 0
       // return; // Exit the update function to prevent further movement
            isTrainStop =true;

             glutTimerFunc(17000, update, 1);
               return;

            }

     }
     else
     {
          trainposition -= trainspeed;

     }

	glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}
//right door motion
GLfloat passdoorposition = -180.0f;
GLfloat passdoortrainspeed = 2;
bool isStopped = false;
GLfloat initialPosition = -180.0;
void update2(int value)
{
    if (!isStopped)
    {
        if (passdoorposition >= 0.0)
        {
            passdoorposition = 0;
            isStopped = true; // Stop the door
            glutTimerFunc(11000, update2, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition += passdoortrainspeed; // Move door closer to -140
    }
    else
    {
        if (passdoorposition > initialPosition)
        {
            passdoorposition -= passdoortrainspeed; // Move back to the initial position
        }
        else
        {
            passdoorposition = initialPosition; // Ensure it stops at the initial position
            isStopped = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, update2, 0);
}
//left door motion
GLfloat passdoorposition1 = 200.0f;
GLfloat passdoortrainspeed1 = 2;
bool isStopped1 = false;
GLfloat initialPosition1 = 200.0;
void update3(int value)
{
    if (!isStopped1)
    {
        if (passdoorposition1 <= 0.0)
        {
            passdoorposition1 = 0;
            isStopped1 = true; // Stop the door
            glutTimerFunc(11000, update3, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition1 -= passdoortrainspeed1; // Move door closer to -140
    }
    else
    {
        if (passdoorposition1 < initialPosition1)
        {
            passdoorposition1 += passdoortrainspeed1; // Move back to the initial position
        }
        else
        {
            passdoorposition1 = initialPosition1; // Ensure it stops at the initial position
            isStopped1 = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, update3, 0);
}

// train right door motion
GLfloat passdoorposition3 = 0.0f;
GLfloat passdoortrainspeed3 = 2;
bool isStopped3 = false;
GLfloat initialPosition3 = 0.0;
void update5(int value)
{
    if (!isStopped3)
    {
        if (passdoorposition3 >= 100.0)
        {
            passdoorposition3 = 100;
            isStopped3 = true; // Stop the door
            glutTimerFunc(7000, update5, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition3 += passdoortrainspeed3; // Move door closer to -140
    }
    else
    {
        if (passdoorposition3 > initialPosition3)
        {
            passdoorposition3 -= passdoortrainspeed3; // Move back to the initial position
        }
        else
        {
            passdoorposition3 = initialPosition3; // Ensure it stops at the initial position
            isStopped3 = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, update5, 0);
}


//train left door motion
GLfloat passdoorposition2 = 0.0f;
GLfloat passdoortrainspeed2 = 2;
bool isStopped2 = false;
GLfloat initialPosition2 = 0.0;
void update4(int value)
{
    if (!isStopped2)
    {
        if (passdoorposition2 <= -100.0)
        {
            passdoorposition2 = -100;
            isStopped2 = true; // Stop the door
            glutTimerFunc(7000, update4, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition2 -= passdoortrainspeed2; // Move door closer to -140
    }
    else
    {
        if (passdoorposition2 < initialPosition2)
        {
            passdoorposition2 += passdoortrainspeed2; // Move back to the initial position
        }
        else
        {
            passdoorposition2 = initialPosition2; // Ensure it stops at the initial position
            isStopped2 = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, update4, 0);
}


//////////////////for the 4th scene//////////////////////////////////////////


// Man motion2222222222222
GLfloat manposition8 = -512.5f;  // Initial X-axis position (starts from the right)
GLfloat manyposition8 = 50.0f;   // Initial Y-axis position (centered vertically)
GLfloat manspeed8 = 6.50f;       // Speed for X-axis
GLfloat manspeedy8 = 10.0f;      // Speed for Y-axis (negative for decreasing)
GLfloat scaleX8 = 1.3875f;       // Initial scaling factor for X-axis
GLfloat scaleY8 = 1.3875f;       // Initial scaling factor for Y-axis
GLfloat scaleSpeed8 = 0.0095f;   // Speed for scaling

bool isVisible8 = false;         // Tracks visibility (initially false)
bool isMoving8 = false;          // Tracks movement (initially false)
int movementDelay = 0;          // Delay counter (for 2 seconds)

void updatem(int value) {
    static int elapsedTime = 0; // Tracks elapsed time in milliseconds

    // Increment elapsed time
    elapsedTime += 100;

    // Make object visible after 5500 milliseconds
    if (elapsedTime >= 100) {
        isVisible8 = true;
    }

    if (isVisible8 && !isMoving8) {
        // Count delay after visibility
        movementDelay += 100;
        if (movementDelay >= 2000) { // Wait for 2 seconds (2000ms)
            isMoving8 = true;
        }
    }

    if (isMoving8) {
        // Update positions and scaling
        manposition8 -= manspeed8;
        manyposition8 -= manspeedy8; // Move down
        scaleX8 += scaleSpeed8;
        scaleY8 += scaleSpeed8;
    }

    // Trigger a redraw
    glutPostRedisplay();

    // Call update again after 100 ms
    glutTimerFunc(100, updatem, 0);
}




//train motion222222222222
GLfloat trainposition8 = 1505.0f;
GLfloat trainspeed8 = 4;

bool isTrainStop8 =false;


void updatet(int value)
{
     if(!isTrainStop8)
     {
            if (trainposition8 > 0.0f) // If the train is ahead of position 0
            {
               trainposition8 -= trainspeed8; // Move the train
            }
            else
            {
            trainposition8 = trainposition8; // Stop the train at position 0
       // return; // Exit the update function to prevent further movement
            isTrainStop8 =true;

             glutTimerFunc(16000, updatet, 1);
               return;

            }

     }
     else
     {
          trainposition8 -= trainspeed8;

     }

	glutPostRedisplay();
	glutTimerFunc(10, updatet, 0);
}
//right door motion2222222222
GLfloat passdoorposition8 = -180.0f;
GLfloat passdoortrainspeed8 = 2;
bool isStopped9 = false;
GLfloat initialPosition8 = -180.0;
void updatep1(int value)
{
    if (!isStopped9)
    {
        if (passdoorposition8 >= 0.0)
        {
            passdoorposition8 = 0;
            isStopped9 = true; // Stop the door
            glutTimerFunc(9000, updatep1, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition8 += passdoortrainspeed8; // Move door closer to -140
    }
    else
    {
        if (passdoorposition8 > initialPosition8)
        {
            passdoorposition8 -= passdoortrainspeed8; // Move back to the initial position
        }
        else
        {
            passdoorposition8 = initialPosition8; // Ensure it stops at the initial position
            isStopped9 = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, updatep1, 0);
}
//left door motion2222222222
GLfloat passdoorposition18 = 200.0f;
GLfloat passdoortrainspeed18 = 2;
bool isStopped110 = false;
GLfloat initialPosition18 = 200.0;
void updatep2(int value)
{
    if (!isStopped110)
    {
        if (passdoorposition18 <= 0.0)
        {
            passdoorposition18 = 0;
            isStopped110 = true; // Stop the door
            glutTimerFunc(9000, updatep2, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition18 -= passdoortrainspeed18; // Move door closer to -140
    }
    else
    {
        if (passdoorposition18 < initialPosition18)
        {
            passdoorposition18 += passdoortrainspeed18; // Move back to the initial position
        }
        else
        {
            passdoorposition18 = initialPosition18; // Ensure it stops at the initial position
            isStopped110 = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, updatep2, 0);
}

// train right door motion222222222222222
GLfloat passdoorposition38 = 0.0f;
GLfloat passdoortrainspeed38 = 2;
bool isStopped311 = false;
GLfloat initialPosition38 = 0.0;
void updated2(int value)
{
    if (!isStopped311)
    {
        if (passdoorposition38 >= 100.0)
        {
            passdoorposition38 = 100;
            isStopped311 = true; // Stop the door
            glutTimerFunc(5000, updated2, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition38 += passdoortrainspeed38; // Move door closer to -140
    }
    else
    {
        if (passdoorposition38 > initialPosition38)
        {
            passdoorposition38 -= passdoortrainspeed38; // Move back to the initial position
        }
        else
        {
            passdoorposition38 = initialPosition38; // Ensure it stops at the initial position
            isStopped311 = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, updated2, 0);
}


//train left door motion2222222222222
GLfloat passdoorposition28 = 0.0f;
GLfloat passdoortrainspeed28 = 2;
bool isStopped212 = false;
GLfloat initialPosition28 = 0.0;
void updated1(int value)
{
    if (!isStopped212)
    {
        if (passdoorposition28 <= -100.0)
        {
            passdoorposition28 = -100;
            isStopped212 = true; // Stop the door
            glutTimerFunc(5000, updated1, 1); // Wait 10 seconds and restart
            return;
        }

        passdoorposition28 -= passdoortrainspeed28; // Move door closer to -140
    }
    else
    {
        if (passdoorposition28 < initialPosition28)
        {
            passdoorposition28 += passdoortrainspeed28; // Move back to the initial position
        }
        else
        {
            passdoorposition28 = initialPosition28; // Ensure it stops at the initial position
            isStopped212 = false; // Reset the flag to allow normal behavior
            return;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(10, updated1, 0);
}

///////////////////////////////////////////////for 3rd scene/////////////////////////////////////////////////////////

//////////////////////////////////////////////for the cloud motion/////////////////////////////////////////////////////////


//////////////////////////////////////////////for the train motion/////////////////////////////////////////////////////////


GLfloat trainposition3 = 800.0f;  // Initial X-axis position (starts from the right)
GLfloat trainyposition3 = 224.0f;  // Initial Y-axis position (centered vertically)
GLfloat trainspeed3 = 2.0f;        // Speed for X-axis
GLfloat trainspeedY3 = 0.55f;       // Speed for Y-axis
GLfloat scaleX3 = 0.7f;          // Initial scaling factor for X-axis
GLfloat scaleY3 = 0.7f;          // Initial scaling factor for Y-axis
GLfloat scaleSpeed3 = 0.0012f;
bool isDay = true;
bool isNight = false;
float timeOfDay = 0.0f; // Simulates time of day (0.0f to 1.0f)


void train3update(int value)
{
    // Update X-axis position
    trainposition3 -= trainspeed3;




    // Update Y-axis position (oscillation)
    trainyposition3 -= trainspeedY3;


    scaleX3 += scaleSpeed3;
    scaleY3 += scaleSpeed3;


    // Trigger a redraw
    glutPostRedisplay();

    // Call update again after 1 ms
    glutTimerFunc(8, train3update, 0);
}

//////////////////////////////////////////////for the cloud motion/////////////////////////////////////////////////////////
GLfloat cloudSpeed = 1.5f; // Speed of cloud movement
GLfloat cloudOffsetX = 0.0f; // Offset for X-axis movement



////////////////////////////////for mouse handle

void updateCloud(int value)
{

    cloudOffsetX -= cloudSpeed;


    if (cloudOffsetX < -1000.0f) {
        cloudOffsetX = 0.0f;
    }


    glutPostRedisplay();


    glutTimerFunc(100, updateCloud, 0);
}

////////////////////////////////////for scene 5/////////////////////////////////



// LiftManYellow motion
GLfloat liftmanyellowposition5 = -43.62;  // Initial X-axis position (starts from the right)
GLfloat liftmanyyellowposition5 = 534.0f;   // Initial Y-axis position (centered vertically)
GLfloat liftmanyyellowspeed5 = 2.40f;       // Speed for X-axis
GLfloat liftmanyyellowspeedy5 = 5.50f;      // Speed for Y-axis (negative for decreasing)
GLfloat liftmanyellowpositionScaleX5 = 0.9044f;       // Initial scaling factor for X-axis
GLfloat liftmanyellowpositionScaleY5 = 0.9044f;       // Initial scaling factor for Y-axis
GLfloat scaleSpeed5 = 0.004f;   // Speed for scaling




void updateliftmanyellow5(int value) {

        liftmanyellowposition5 -= liftmanyyellowspeed5;
        liftmanyyellowposition5 -= liftmanyyellowspeedy5;
        liftmanyellowpositionScaleX5 += scaleSpeed5;
        liftmanyellowpositionScaleY5 += scaleSpeed5;




    glutPostRedisplay();


    glutTimerFunc(70, updateliftmanyellow5, 0);
}

// LiftManPink motion
GLfloat liftmanPinkposition5 = 41.8f;  // Initial X-axis position (starts from the right)
GLfloat liftmanyPinkposition5 = 320.0f;   // Initial Y-axis position (centered vertically)
GLfloat liftmanyPinkspeed5 = 2.53f;       // Speed for X-axis
GLfloat liftmanyPinkspeedy5 = 5.50f;      // Speed for Y-axis (negative for decreasing)
GLfloat liftmanPinkpositionScaleX5 = 0.86f;       // Initial scaling factor for X-axis
GLfloat liftmanPinkpositionScaleY5 = 0.86f;       // Initial scaling factor for Y-axis
GLfloat scaleSpeedPink5 = 0.004f;   // Speed for scaling




void updateliftmanPink5(int value) {

        liftmanPinkposition5 -= liftmanyPinkspeed5;
        liftmanyPinkposition5 -= liftmanyPinkspeedy5; // Move down
        liftmanPinkpositionScaleX5 += scaleSpeedPink5;
        liftmanPinkpositionScaleY5 += scaleSpeedPink5;





    glutPostRedisplay();


    glutTimerFunc(70, updateliftmanPink5, 0);
}

// LiftManGreen motion
GLfloat liftmanGreenposition5 = -90.0f;  // Initial X-axis position (starts from the right)
GLfloat liftmanyGreenposition5 = -10.0f;   // Initial Y-axis position (centered vertically)
GLfloat liftmanyGreenspeed5 = 1.70f;       // Speed for X-axis
GLfloat liftmanyGreenspeedy5 = 2.80f;      // Speed for Y-axis (negative for decreasing)
GLfloat liftmanGreenpositionScaleX5 = 1.1f;       // Initial scaling factor for X-axis
GLfloat liftmanGreenpositionScaleY5 = 1.1f;       // Initial scaling factor for Y-axis
GLfloat scaleSpeedGreen5 = 0.0045f;   // Speed for scaling




void updateliftmanGreen5(int value) {
 // Update positions and scaling

        liftmanGreenposition5 -= liftmanyGreenspeed5;
        liftmanyGreenposition5 -= liftmanyGreenspeedy5; // Move down
        liftmanGreenpositionScaleX5 += scaleSpeedGreen5;
        liftmanGreenpositionScaleY5 += scaleSpeedGreen5;

        // Check if the object has crossed the threshold


    // Trigger a redraw
    glutPostRedisplay();

    // Call update again after 100 ms
    glutTimerFunc(20, updateliftmanGreen5, 0);
}




// Function for Scene 1
void displayScene2() {

    glClear(GL_COLOR_BUFFER_BIT);
     //////for top/////////////////////////////////////////////////////////////


glBegin(GL_QUADS);

     glColor3f(0.45,0.45,0.45);
    glVertex2f(0.0f, 700.0f);
    glVertex2f(1.0f, 632.6f);
    glVertex2f(1500.0f, 610.0f);
    glVertex2f(1500.0f, 700.0f);

    //1
    glColor3f(0.6,0.6,0.6);
     glVertex2f(0.0f, 470.0f);
    glVertex2f(0.0f, 595.0f);
    glVertex2f(1500.0f, 595.0f);
    glVertex2f(1500.0f, 470.0f);


    //2
    glColor3f(0.6,0.6,0.9);
    glVertex2f(0.0f, 470.0f);
    glVertex2f(0.0f, 390.0f);
    glVertex2f(172.0f, 401.7f);
    glVertex2f(1500.0f, 470.0f);
 glEnd();


      //for train//////////////////////////////////////////////////////////////////////////////////////////////////
    //body





  glPushMatrix();
    glTranslatef(trainposition,0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.9,0.9,0.9);
    glVertex2f(180.0f, 180.7f);
    glVertex2f(200.0f, 530.7f);
    glVertex2f(260.0f, 570.0f);
    glVertex2f(4500.9f, 563.8f);
    glVertex2f(4500.0f, 260.0f);

    glEnd();
    glBegin(GL_QUADS);

     glVertex2f(172.0f, 401.7f);
    glVertex2f(172.0f, 200.0f);
    glVertex2f(1500.0f, 270.0f);
    glVertex2f(1500.0f, 430.0f);

    //green line
    glColor3f(0.0,0.778,0.0);
     glVertex2f(330.0f, 511.0f);
    glVertex2f(320.0f, 530.0f);
    glVertex2f(4500.0f, 530.0f);
    glVertex2f(4500.0f, 510.0f);


     //white space
     glColor3f(1.0,1.0,1.0);
    glVertex2f(172.0f, 401.7f);
    glVertex2f(240.0f, 490.0f);
    glVertex2f(330.0f, 511.0f);
    glVertex2f(346.7f, 404.0f);


    //1st window
     glColor3f(0.4,0.4,0.4);
     glVertex2f(393.0f, 406.0f);
    glVertex2f(390.0f, 470.0f);
    glVertex2f(473.0f, 469.6f);
    glVertex2f(472.3f, 406.5f);



    //body window
    glVertex2f(1110.0f, 420.0f);
    glVertex2f(1110.0f, 484.0f);
    glVertex2f(1416.0f, 488.0f);
    glVertex2f(1412.0f, 426.0f);
    glEnd();


//train door/////////////////////////////////////////////////////////////////////////////////////


 ////////////////////////////train black room/////////

   glBegin(GL_QUADS);

     glColor3f(0.4,0.4,0.4);


   glVertex2f(954.4f, 262.5f);
    glVertex2f(954.0f, 500.0f);
     glVertex2f(690.0f, 500.0f);
     glVertex2f(701.4f, 248.5f);

      glEnd();


     glPushMatrix();
    glTranslatef(passdoorposition2,0.0f, 0.0f);
    glBegin(GL_QUADS);

    //left door
    glColor3f(0.58,0.58,0.58);
    glVertex2f(701.4f, 248.5f);
    glVertex2f(690.0f, 500.0f);
    glVertex2f(823.9f, 497.0f);
    glVertex2f(830.5f, 258.0f);
    //left window
    glColor3f(0.4,0.4,0.4);
    glVertex2f(720.0f, 370.0f);
    glVertex2f(720.0f, 470.0f);
    glVertex2f(790.0f, 470.0f);
    glVertex2f(790.0f, 370.0f);
    //left door red line
    glColor3f(0.8,0.0,0.0);
     glVertex2f(802.1f, 496.7f);
    glVertex2f(809.3f, 255.05f);
    glVertex2f(822.5f, 255.5f);
    glVertex2f(817.1f, 496.54f);

     glEnd();

     glPopMatrix();


      glPushMatrix();
    glTranslatef(passdoorposition3,0.0f, 0.0f);
     glBegin(GL_QUADS);
     //right door
     glColor3f(0.58,0.58,0.58);
     glVertex2f(823.9f, 497.0f);
    glVertex2f(830.5f, 258.0f);
    glVertex2f(954.4f, 262.5f);
    glVertex2f(954.0f, 499.5f);


    //door window

      glColor3f(0.4,0.4,0.4);
     glVertex2f(857.0f, 370.0f);
    glVertex2f(857.0f, 470.0f);
    glVertex2f(927.0f, 470.0f);
    glVertex2f(927.0f, 370.0f);


    //right door red line
     glColor3f(0.8,0.0,0.0);
    glVertex2f(833.2f, 497.4f);
    glVertex2f(838.0f, 258.0f);
    glVertex2f(854.0f, 258.0f);
    glVertex2f(847.3f, 497.25f);


    glEnd();

    glPopMatrix();


    ///////////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);

    //1st green space
    glColor3f(0.0,0.778,0.0);
    glVertex2f(172.0f, 401.7f);
    glVertex2f(200.0f, 530.7f);
    glVertex2f(260.0f, 570.0f);
    glVertex2f(328.0f, 568.0f);
    glVertex2f(330.0f, 511.0f);
    glVertex2f(240.0f, 490.0f);

    glEnd();

    //up side of the train
    glBegin(GL_POLYGON);

    glColor3f(0.82,0.82,0.82);
    glVertex2f(329.0f, 538.0f);
    glVertex2f(358.0f, 570.0f);
    glVertex2f(376.0f, 573.1f);
    glVertex2f(1500.0f, 565.0f);
    glVertex2f(1500.0f, 534.3f);

    glEnd();

    glBegin(GL_TRIANGLES);


     glVertex2f(329.0f, 538.0f);
    glVertex2f(375.0f, 573.0f);
    glVertex2f(346.7f, 573.4f);


    glEnd();


    //upper tomb
      glBegin(GL_POLYGON);


    glVertex2f(1032.5f, 616.0f);
    glVertex2f(944.5f, 585.0f);
    glVertex2f(934.5f, 568.0f);
    glVertex2f(1066.2f, 565.8f);
    glVertex2f(1062.0f, 586.6f);

    glEnd();

     glBegin(GL_QUADS);


    glVertex2f(1032.5f, 616.0f);
    glVertex2f(1062.0f, 586.6f);
    glVertex2f(1500.0f, 584.0f);
    glVertex2f(1500.0f, 610.0f);

    glColor3f(0.76,0.76,0.76);
    glVertex2f(1062.0f, 586.6f);
    glVertex2f(1066.2f, 565.8f);
    glVertex2f(1500.0f, 565.0f);
    glVertex2f(1500.0f, 584.0f);

    glEnd();


    /////////extention of the train part ///////////////////////////////////////////////////
    //divider quad
    glBegin(GL_QUADS);
     glColor3f(0.65,0.65,0.65);
    glVertex2f(1600.0f, 250.0f);
    glVertex2f(1600.0f, 570.0f);
    glVertex2f(1550.0f, 570.0f);
    glVertex2f(1550.0f, 250.0f);

    glEnd();
glBegin(GL_QUADS);
    //1st window

glColor3f(0.4,0.4,0.4);
glVertex2f(1703.0f, 406.0f);
glVertex2f(1700.0f, 470.0f);
glVertex2f(1783.0f, 469.6f);
glVertex2f(1782.3f, 406.5f);

//body window
glVertex2f(2420.0f, 420.0f);
glVertex2f(2420.0f, 484.0f);
glVertex2f(2726.0f, 488.0f);
glVertex2f(2722.0f, 426.0f);

//train door
glColor3f(0.58,0.58,0.58);
glVertex2f(2011.4f, 248.5f);
glVertex2f(2000.0f, 500.0f);
glVertex2f(2133.9f, 497.0f);
glVertex2f(2140.5f, 258.0f);

glVertex2f(2133.9f, 497.0f);
glVertex2f(2140.5f, 258.0f);
glVertex2f(2264.4f, 262.5f);
glVertex2f(2264.0f, 499.5f);

//door window
glColor3f(0.4,0.4,0.4);
glVertex2f(2030.0f, 370.0f);
glVertex2f(2030.0f, 470.0f);
glVertex2f(2100.0f, 470.0f);
glVertex2f(2100.0f, 370.0f);

glVertex2f(2167.0f, 370.0f);
glVertex2f(2167.0f, 470.0f);
glVertex2f(2237.0f, 470.0f);
glVertex2f(2237.0f, 370.0f);

//door red line
glColor3f(0.8,0.0,0.0);
glVertex2f(2112.1f, 496.7f);
glVertex2f(2119.3f, 255.05f);
glVertex2f(2132.5f, 255.5f);
glVertex2f(2127.1f, 496.54f);

glVertex2f(2143.2f, 497.4f);
glVertex2f(2148.0f, 258.0f);
glVertex2f(2164.0f, 258.0f);
glVertex2f(2157.3f, 497.25f);


  glEnd();
  /////////extention part 2//////////////////////////////////////////////////

   //divider quad
    glBegin(GL_QUADS);
    glColor3f(0.65,0.65,0.65);
glVertex2f(2910.0f, 250.0f);
glVertex2f(2910.0f, 570.0f);
glVertex2f(2860.0f, 570.0f);
glVertex2f(2860.0f, 250.0f);

    glEnd();
  glBegin(GL_QUADS);
  glColor3f(0.4,0.4,0.4);
glVertex2f(3013.0f, 406.0f);
glVertex2f(3010.0f, 470.0f);
glVertex2f(3093.0f, 469.6f);
glVertex2f(3092.3f, 406.5f);

//body window
glVertex2f(3730.0f, 420.0f);
glVertex2f(3730.0f, 484.0f);
glVertex2f(4036.0f, 488.0f);
glVertex2f(4032.0f, 426.0f);

//train door
glColor3f(0.58,0.58,0.58);
glVertex2f(3321.4f, 248.5f);
glVertex2f(3310.0f, 500.0f);
glVertex2f(3443.9f, 497.0f);
glVertex2f(3450.5f, 258.0f);

glVertex2f(3443.9f, 497.0f);
glVertex2f(3450.5f, 258.0f);
glVertex2f(3574.4f, 262.5f);
glVertex2f(3574.0f, 499.5f);

//door window
glColor3f(0.4,0.4,0.4);
glVertex2f(3340.0f, 370.0f);
glVertex2f(3340.0f, 470.0f);
glVertex2f(3410.0f, 470.0f);
glVertex2f(3410.0f, 370.0f);

glVertex2f(3477.0f, 370.0f);
glVertex2f(3477.0f, 470.0f);
glVertex2f(3547.0f, 470.0f);
glVertex2f(3547.0f, 370.0f);

//door red line
glColor3f(0.8,0.0,0.0);
glVertex2f(3422.1f, 496.7f);
glVertex2f(3429.3f, 255.05f);
glVertex2f(3442.5f, 255.5f);
glVertex2f(3437.1f, 496.54f);

glVertex2f(3443.2f, 497.4f);
glVertex2f(3448.0f, 258.0f);
glVertex2f(3464.0f, 258.0f);
glVertex2f(3457.3f, 497.25f);
 glEnd();
/////end of the train
glBegin(GL_QUADS);
    glColor3f(0.65,0.65,0.65);


glVertex2f(4500.9f, 563.8f);
glVertex2f(4500.0f, 250.0f);
glVertex2f(4450.0f, 250.0f);
glVertex2f(4450.9f, 563.8f);


  glEnd();
  glPopMatrix();
  glFlush();

//////////////////////////////////////////



 //for ground//////////////////////////////////////////////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);

     glColor3f(0.475,0.478,0.475);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 170.0f);
    glVertex2f(176.9f, 179.3f);


    glVertex2f(0.0f, 0.0f);
    glVertex2f(176.9f, 179.3f);
    glVertex2f(565.4f, 203.5f);
    glVertex2f(1041.7f, 232.4f);
    glVertex2f(1500.0f, 260.0f);
    glVertex2f(1500.0f, 0.0f);



    glEnd();

//for yollow line
    glBegin(GL_POLYGON);
    glColor3f(0.961,0.608,0.027);
    glVertex2f(0.7f, 28.6f);
     glVertex2f(177.4f, 178.3f);
    glVertex2f(349.0f, 188.3f);
    glVertex2f(245.3f, 1.0f);
    glVertex2f(0.0f, 0.0f);


    glEnd();

     glBegin(GL_QUADS);

    glColor3f(0.961,0.608,0.027);

    glVertex2f(328.0f, 149.6f);
    glVertex2f(340.0f, 171.9f);
    glVertex2f(610.2f, 188.5f);
    glVertex2f(616.3f, 171.2f);

    glVertex2f(616.3f, 171.2f);
    glVertex2f(599.2f, 204.0f);
    glVertex2f(1013.6f, 230.0f);
    glVertex2f(1080.0f, 202.0f);

    glVertex2f(1080.0f, 202.0f);
    glVertex2f(1033.3f, 217.0f);
    glVertex2f(1370.4f, 237.5f);
    glVertex2f(1393.3f, 222.4f);

    glEnd();


    glBegin(GL_POLYGON);


     glColor3f(0.961,0.608,0.027);
    glVertex2f(1393.3f, 222.4f);
    glVertex2f(1370.4f, 237.5f);
    glVertex2f(1500.0f, 246.0f);
    glVertex2f(1500.0f, 210.0f);
    glVertex2f(1454.4f, 206.6f);

    glEnd();



    // left pass gate
    glBegin(GL_QUADS);
//down

     glColor3f(0.775,0.778,0.775);
    glVertex2f(1500.0f, 260.0f);
    glVertex2f(1500.0f, 422.0f);
    glVertex2f(1042.0f, 410.0f);
    glVertex2f(1040.6f, 233.4f);


    //up
    glVertex2f(1022.0f, 418.0f);
    glVertex2f(1042.0f, 410.0f);
    glVertex2f(1500.0f, 422.0f);
    glVertex2f(1500.0f, 430.0f);



    //left pass gste
    glVertex2f(566.3f, 205.8f);
    glVertex2f(554.0f, 399.5f);
    glVertex2f(0.0f, 383.5f);
    glVertex2f(0.0f, 165.0f);

    //up
    glVertex2f(550.2f, 408.0f);
    glVertex2f(554.0f, 399.5f);
    glVertex2f(0.8f, 383.5f);
    glVertex2f(0.0f, 397.5f);


     glEnd();




      glPushMatrix();
    glTranslatef(passdoorposition,0.0f, 0.0f);
      // right door
      glBegin(GL_QUADS);
    glColor3f(1,0,0);

    glVertex2f(1245.0f, 400.0f);
    glVertex2f(1241.3f, 247.0f);
    glVertex2f(986.0f, 230.0f);
    glVertex2f(987.0f, 389.0f);
      glEnd();

       glPopMatrix();

   glPushMatrix();
    glTranslatef(passdoorposition1,0.0f, 0.0f);
      glBegin(GL_QUADS);
       // left door
    glColor3f(1,0,0);
   glVertex2f(616.0f, 230.0f);
    glVertex2f(359.0f, 221.0f);
    glVertex2f(346.0f, 388.0f);
    glVertex2f(608.0f, 389.0f);
      glEnd();

 glPopMatrix();


 ////////////////////////////////////////////////////////////man//////////////////////
 if (isVisible)
{
      glPushMatrix();
      glTranslatef(manposition, manyposition, 0.0f);
      glScalef(scaleX, scaleY, 1.0f);
     glBegin(GL_POLYGON);
    //for men-1 g
    glColor3ub(255,255,204);
	glVertex2f(940.0f, 270.0f);
    glVertex2f(940.0f, 280.0f);
    glVertex2f(960.0f,280.0f);
    glVertex2f(960.0f,270.0f);
    glEnd();
      //Men circle
    int i;

	GLfloat x=950.0f; GLfloat y=300.0f; GLfloat radius =25.0f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3ub(0.0f, 51.0f, 102.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-1 s-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f,210.0f);
    glVertex2f(925.0f,210.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-2
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 210.0f);
    glVertex2f(975.0f, 210.0f);
    glVertex2f(975.0f,200.0f);
    glVertex2f(925.0f,200.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 200.0f);
    glVertex2f(950.0f, 200.0f);
    glVertex2f(935.0f,150.0f);
    glVertex2f(925.0f,150.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(51,51,0);
	glVertex2f(925.0f, 150.0f);
    glVertex2f(935.0f, 150.0f);
    glVertex2f(937.0f,145.0f);
    glVertex2f(923.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(204,255,255);
	glVertex2f(950.0f, 200.0f);
    glVertex2f(975.0f, 200.0f);
    glVertex2f(975.0f,150.0f);
    glVertex2f(965.0f,150.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(51,51,0);
	glVertex2f(975.0f, 150.0f);
    glVertex2f(965.0f, 150.0f);
    glVertex2f(963.0f,145.0f);
    glVertex2f(977.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(925.0f, 240.0f);
    glVertex2f(920.0f,215.0f);
    glVertex2f(910.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(920.0f, 215.0f);
    glVertex2f(910.0f, 215.0f);
    glVertex2f(909.0f,210.0f);
    glVertex2f(919.0f,210.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,0);
	glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f, 240.0f);
    glVertex2f(980.0f,215.0f);
    glVertex2f(990.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(980.0f, 215.0f);
    glVertex2f(990.0f, 215.0f);
    glVertex2f(991.0f,210.0f);
    glVertex2f(981.0f,210.0f);
    glEnd();



    glPopMatrix();

}


   glFlush ();


    glutSwapBuffers();
}

// Function for Scene 2
void displayScene4() {
    glClear(GL_COLOR_BUFFER_BIT);

    //////for top/////////////////////////////////////////////////////////////
glBegin(GL_QUADS);

     glColor3f(0.45,0.45,0.45);
    glVertex2f(0.0f, 700.0f);
    glVertex2f(1.0f, 632.6f);
    glVertex2f(1500.0f, 610.0f);
    glVertex2f(1500.0f, 700.0f);

    //1
    glColor3f(0.6,0.6,0.6);
     glVertex2f(0.0f, 470.0f);
    glVertex2f(0.0f, 595.0f);
    glVertex2f(1500.0f, 595.0f);
    glVertex2f(1500.0f, 470.0f);


    //2
    glColor3f(0.6,0.6,0.9);
    glVertex2f(0.0f, 470.0f);
    glVertex2f(0.0f, 390.0f);
    glVertex2f(172.0f, 401.7f);
    glVertex2f(1500.0f, 470.0f);
 glEnd();


      //for train//////////////////////////////////////////////////////////////////////////////////////////////////
    //body





  glPushMatrix();
    glTranslatef(trainposition8,0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.9,0.9,0.9);
    glVertex2f(180.0f, 180.7f);
    glVertex2f(200.0f, 530.7f);
    glVertex2f(260.0f, 570.0f);
    glVertex2f(4500.9f, 563.8f);
    glVertex2f(4500.0f, 260.0f);

    glEnd();
    glBegin(GL_QUADS);

     glVertex2f(172.0f, 401.7f);
    glVertex2f(172.0f, 200.0f);
    glVertex2f(1500.0f, 270.0f);
    glVertex2f(1500.0f, 430.0f);

    //green line
    glColor3f(0.0,0.778,0.0);
     glVertex2f(330.0f, 511.0f);
    glVertex2f(320.0f, 530.0f);
    glVertex2f(4500.0f, 530.0f);
    glVertex2f(4500.0f, 510.0f);


     //white space
     glColor3f(1.0,1.0,1.0);
    glVertex2f(172.0f, 401.7f);
    glVertex2f(240.0f, 490.0f);
    glVertex2f(330.0f, 511.0f);
    glVertex2f(346.7f, 404.0f);


    //1st window
     glColor3f(0.4,0.4,0.4);
     glVertex2f(393.0f, 406.0f);
    glVertex2f(390.0f, 470.0f);
    glVertex2f(473.0f, 469.6f);
    glVertex2f(472.3f, 406.5f);



    //body window
    glVertex2f(1110.0f, 420.0f);
    glVertex2f(1110.0f, 484.0f);
    glVertex2f(1416.0f, 488.0f);
    glVertex2f(1412.0f, 426.0f);
    glEnd();

///////////////////////////////// door black portion///////////
    glBegin(GL_QUADS);

     glColor3f(0.58,0.58,0.58);


    glVertex2f(954.4f, 262.5f);
    glVertex2f(954.0f, 499.5f);
     glVertex2f(690.0f, 500.0f);
     glVertex2f(701.4f, 248.5f);
    //glVertex2f(690.0f, 500.0f);
      glEnd();




//train door/////////////////////////////////////////////////////////////////////////////////////
     glPushMatrix();
    glTranslatef(passdoorposition28,0.0f, 0.0f);
    glBegin(GL_QUADS);

    //left door
    glColor3f(0.58,0.58,0.58);
    glVertex2f(701.4f, 248.5f);
    glVertex2f(690.0f, 500.0f);
    glVertex2f(823.9f, 497.0f);
    glVertex2f(830.5f, 258.0f);
    //left window
    glColor3f(0.4,0.4,0.4);
    glVertex2f(720.0f, 370.0f);
    glVertex2f(720.0f, 470.0f);
    glVertex2f(790.0f, 470.0f);
    glVertex2f(790.0f, 370.0f);
    //left door red line
    glColor3f(0.8,0.0,0.0);
     glVertex2f(802.1f, 496.7f);
    glVertex2f(809.3f, 255.05f);
    glVertex2f(822.5f, 255.5f);
    glVertex2f(817.1f, 496.54f);

     glEnd();

     glPopMatrix();


      glPushMatrix();
    glTranslatef(passdoorposition38,0.0f, 0.0f);
     glBegin(GL_QUADS);
     //right door
     glColor3f(0.58,0.58,0.58);
     glVertex2f(823.9f, 497.0f);
    glVertex2f(830.5f, 258.0f);
    glVertex2f(954.4f, 262.5f);
    glVertex2f(954.0f, 499.5f);


    //door window

      glColor3f(0.4,0.4,0.4);
     glVertex2f(857.0f, 370.0f);
    glVertex2f(857.0f, 470.0f);
    glVertex2f(927.0f, 470.0f);
    glVertex2f(927.0f, 370.0f);


    //right door red line
     glColor3f(0.8,0.0,0.0);
    glVertex2f(833.2f, 497.4f);
    glVertex2f(838.0f, 258.0f);
    glVertex2f(854.0f, 258.0f);
    glVertex2f(847.3f, 497.25f);


    glEnd();

    glPopMatrix();


    ///////////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);

    //1st green space
    glColor3f(0.0,0.778,0.0);
    glVertex2f(172.0f, 401.7f);
    glVertex2f(200.0f, 530.7f);
    glVertex2f(260.0f, 570.0f);
    glVertex2f(328.0f, 568.0f);
    glVertex2f(330.0f, 511.0f);
    glVertex2f(240.0f, 490.0f);

    glEnd();

    //up side of the train
    glBegin(GL_POLYGON);

    glColor3f(0.82,0.82,0.82);
    glVertex2f(329.0f, 538.0f);
    glVertex2f(358.0f, 570.0f);
    glVertex2f(376.0f, 573.1f);
    glVertex2f(1500.0f, 565.0f);
    glVertex2f(1500.0f, 534.3f);

    glEnd();

    glBegin(GL_TRIANGLES);


     glVertex2f(329.0f, 538.0f);
    glVertex2f(375.0f, 573.0f);
    glVertex2f(346.7f, 573.4f);


    glEnd();


    //upper tomb
      glBegin(GL_POLYGON);


    glVertex2f(1032.5f, 616.0f);
    glVertex2f(944.5f, 585.0f);
    glVertex2f(934.5f, 568.0f);
    glVertex2f(1066.2f, 565.8f);
    glVertex2f(1062.0f, 586.6f);

    glEnd();

     glBegin(GL_QUADS);


    glVertex2f(1032.5f, 616.0f);
    glVertex2f(1062.0f, 586.6f);
    glVertex2f(1500.0f, 584.0f);
    glVertex2f(1500.0f, 610.0f);

    glColor3f(0.76,0.76,0.76);
    glVertex2f(1062.0f, 586.6f);
    glVertex2f(1066.2f, 565.8f);
    glVertex2f(1500.0f, 565.0f);
    glVertex2f(1500.0f, 584.0f);

    glEnd();


    /////////extention of the train part ///////////////////////////////////////////////////
    //divider quad
    glBegin(GL_QUADS);
     glColor3f(0.65,0.65,0.65);
    glVertex2f(1600.0f, 250.0f);
    glVertex2f(1600.0f, 570.0f);
    glVertex2f(1550.0f, 570.0f);
    glVertex2f(1550.0f, 250.0f);

    glEnd();
glBegin(GL_QUADS);
    //1st window

glColor3f(0.4,0.4,0.4);
glVertex2f(1703.0f, 406.0f);
glVertex2f(1700.0f, 470.0f);
glVertex2f(1783.0f, 469.6f);
glVertex2f(1782.3f, 406.5f);

//body window
glVertex2f(2420.0f, 420.0f);
glVertex2f(2420.0f, 484.0f);
glVertex2f(2726.0f, 488.0f);
glVertex2f(2722.0f, 426.0f);

//train door
glColor3f(0.58,0.58,0.58);
glVertex2f(2011.4f, 248.5f);
glVertex2f(2000.0f, 500.0f);
glVertex2f(2133.9f, 497.0f);
glVertex2f(2140.5f, 258.0f);

glVertex2f(2133.9f, 497.0f);
glVertex2f(2140.5f, 258.0f);
glVertex2f(2264.4f, 262.5f);
glVertex2f(2264.0f, 499.5f);

//door window
glColor3f(0.4,0.4,0.4);
glVertex2f(2030.0f, 370.0f);
glVertex2f(2030.0f, 470.0f);
glVertex2f(2100.0f, 470.0f);
glVertex2f(2100.0f, 370.0f);

glVertex2f(2167.0f, 370.0f);
glVertex2f(2167.0f, 470.0f);
glVertex2f(2237.0f, 470.0f);
glVertex2f(2237.0f, 370.0f);

//door red line
glColor3f(0.8,0.0,0.0);
glVertex2f(2112.1f, 496.7f);
glVertex2f(2119.3f, 255.05f);
glVertex2f(2132.5f, 255.5f);
glVertex2f(2127.1f, 496.54f);

glVertex2f(2143.2f, 497.4f);
glVertex2f(2148.0f, 258.0f);
glVertex2f(2164.0f, 258.0f);
glVertex2f(2157.3f, 497.25f);


  glEnd();
  /////////extention part 2//////////////////////////////////////////////////

   //divider quad
    glBegin(GL_QUADS);
    glColor3f(0.65,0.65,0.65);
glVertex2f(2910.0f, 250.0f);
glVertex2f(2910.0f, 570.0f);
glVertex2f(2860.0f, 570.0f);
glVertex2f(2860.0f, 250.0f);

    glEnd();
  glBegin(GL_QUADS);
  glColor3f(0.4,0.4,0.4);
glVertex2f(3013.0f, 406.0f);
glVertex2f(3010.0f, 470.0f);
glVertex2f(3093.0f, 469.6f);
glVertex2f(3092.3f, 406.5f);

//body window
glVertex2f(3730.0f, 420.0f);
glVertex2f(3730.0f, 484.0f);
glVertex2f(4036.0f, 488.0f);
glVertex2f(4032.0f, 426.0f);

//train door
glColor3f(0.58,0.58,0.58);
glVertex2f(3321.4f, 248.5f);
glVertex2f(3310.0f, 500.0f);
glVertex2f(3443.9f, 497.0f);
glVertex2f(3450.5f, 258.0f);

glVertex2f(3443.9f, 497.0f);
glVertex2f(3450.5f, 258.0f);
glVertex2f(3574.4f, 262.5f);
glVertex2f(3574.0f, 499.5f);

//door window
glColor3f(0.4,0.4,0.4);
glVertex2f(3340.0f, 370.0f);
glVertex2f(3340.0f, 470.0f);
glVertex2f(3410.0f, 470.0f);
glVertex2f(3410.0f, 370.0f);

glVertex2f(3477.0f, 370.0f);
glVertex2f(3477.0f, 470.0f);
glVertex2f(3547.0f, 470.0f);
glVertex2f(3547.0f, 370.0f);

//door red line
glColor3f(0.8,0.0,0.0);
glVertex2f(3422.1f, 496.7f);
glVertex2f(3429.3f, 255.05f);
glVertex2f(3442.5f, 255.5f);
glVertex2f(3437.1f, 496.54f);

glVertex2f(3443.2f, 497.4f);
glVertex2f(3448.0f, 258.0f);
glVertex2f(3464.0f, 258.0f);
glVertex2f(3457.3f, 497.25f);
 glEnd();
/////end of the train
glBegin(GL_QUADS);
    glColor3f(0.65,0.65,0.65);


glVertex2f(4500.9f, 563.8f);
glVertex2f(4500.0f, 250.0f);
glVertex2f(4450.0f, 250.0f);
glVertex2f(4450.9f, 563.8f);


  glEnd();
  glPopMatrix();
  glFlush();

//////////////////////////////////////////



 //for ground//////////////////////////////////////////////////////////////////////////////////////////////////

	glBegin(GL_POLYGON);

     glColor3f(0.475,0.478,0.475);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 170.0f);
    glVertex2f(176.9f, 179.3f);


    glVertex2f(0.0f, 0.0f);
    glVertex2f(176.9f, 179.3f);
    glVertex2f(565.4f, 203.5f);
    glVertex2f(1041.7f, 232.4f);
    glVertex2f(1500.0f, 260.0f);
    glVertex2f(1500.0f, 0.0f);



    glEnd();

//for yollow line
    glBegin(GL_POLYGON);
    glColor3f(0.961,0.608,0.027);
    glVertex2f(0.7f, 28.6f);
     glVertex2f(177.4f, 178.3f);
    glVertex2f(349.0f, 188.3f);
    glVertex2f(245.3f, 1.0f);
    glVertex2f(0.0f, 0.0f);


    glEnd();

     glBegin(GL_QUADS);

    glColor3f(0.961,0.608,0.027);

    glVertex2f(328.0f, 149.6f);
    glVertex2f(340.0f, 171.9f);
    glVertex2f(610.2f, 188.5f);
    glVertex2f(616.3f, 171.2f);

    glVertex2f(616.3f, 171.2f);
    glVertex2f(599.2f, 204.0f);
    glVertex2f(1013.6f, 230.0f);
    glVertex2f(1080.0f, 202.0f);

    glVertex2f(1080.0f, 202.0f);
    glVertex2f(1033.3f, 217.0f);
    glVertex2f(1370.4f, 237.5f);
    glVertex2f(1393.3f, 222.4f);

    glEnd();


    glBegin(GL_POLYGON);


     glColor3f(0.961,0.608,0.027);
    glVertex2f(1393.3f, 222.4f);
    glVertex2f(1370.4f, 237.5f);
    glVertex2f(1500.0f, 246.0f);
    glVertex2f(1500.0f, 210.0f);
    glVertex2f(1454.4f, 206.6f);

    glEnd();



    // left pass gate
    glBegin(GL_QUADS);
//down

     glColor3f(0.775,0.778,0.775);
    glVertex2f(1500.0f, 260.0f);
    glVertex2f(1500.0f, 422.0f);
    glVertex2f(1042.0f, 410.0f);
    glVertex2f(1040.6f, 233.4f);


    //up
    glVertex2f(1022.0f, 418.0f);
    glVertex2f(1042.0f, 410.0f);
    glVertex2f(1500.0f, 422.0f);
    glVertex2f(1500.0f, 430.0f);



    //left pass gste
    glVertex2f(566.3f, 205.8f);
    glVertex2f(554.0f, 399.5f);
    glVertex2f(0.0f, 383.5f);
    glVertex2f(0.0f, 165.0f);

    //up
    glVertex2f(550.2f, 408.0f);
    glVertex2f(554.0f, 399.5f);
    glVertex2f(0.8f, 383.5f);
    glVertex2f(0.0f, 397.5f);


     glEnd();




      glPushMatrix();
    glTranslatef(passdoorposition8,0.0f, 0.0f);
      // right door
      glBegin(GL_QUADS);
    glColor3f(1,0,0);

    glVertex2f(1245.0f, 400.0f);
    glVertex2f(1241.3f, 247.0f);
    glVertex2f(986.0f, 230.0f);
    glVertex2f(987.0f, 389.0f);
      glEnd();

       glPopMatrix();

   glPushMatrix();
    glTranslatef(passdoorposition18,0.0f, 0.0f);
      glBegin(GL_QUADS);
       // left door
    glColor3f(1,0,0);
   glVertex2f(616.0f, 230.0f);
    glVertex2f(359.0f, 221.0f);
    glVertex2f(346.0f, 388.0f);
    glVertex2f(608.0f, 389.0f);
      glEnd();

 glPopMatrix();

  ////////////////////////////////////////////////////////////man//////////////////////

   if (isVisible8) {
    glPushMatrix(); // Translation block
        glTranslatef(manposition8, manyposition8, 0.0f); // Apply translation
        glPushMatrix(); // Scaling block (independent of translation)
            glScalef(scaleX8, scaleY8, 1.0f); // Apply scaling independently

            glBegin(GL_POLYGON);
            // Body part - Example for simplicity
            glColor3ub(255, 255, 204);
            glVertex2f(940.0f, 270.0f);
            glVertex2f(940.0f, 280.0f);
            glVertex2f(960.0f, 280.0f);
            glVertex2f(960.0f, 270.0f);
            glEnd();

            // Draw head (circle)
            int i;
            GLfloat x = 950.0f, y = 300.0f, radius = 25.0f;
            int triangleAmount = 100; // # of triangles to approximate circle
            GLfloat twicePi = 2.0f * PI;

           glColor3f(1.0f, 0.85f, 0.55f);
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(x, y); // Center of circle
                for (i = 0; i <= triangleAmount; i++) {
                    glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                               y + (radius * sin(i * twicePi / triangleAmount)));
                }
            glEnd();

             glBegin(GL_POLYGON);
    //for men-1 s-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f,210.0f);
    glVertex2f(925.0f,210.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-2
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 210.0f);
    glVertex2f(975.0f, 210.0f);
    glVertex2f(975.0f,200.0f);
    glVertex2f(925.0f,200.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 200.0f);
    glVertex2f(950.0f, 200.0f);
    glVertex2f(935.0f,150.0f);
    glVertex2f(925.0f,150.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(51,51,0);
	glVertex2f(925.0f, 150.0f);
    glVertex2f(935.0f, 150.0f);
    glVertex2f(937.0f,145.0f);
    glVertex2f(923.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(204,255,255);
	glVertex2f(950.0f, 200.0f);
    glVertex2f(975.0f, 200.0f);
    glVertex2f(975.0f,150.0f);
    glVertex2f(965.0f,150.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(51,51,0);
	glVertex2f(975.0f, 150.0f);
    glVertex2f(965.0f, 150.0f);
    glVertex2f(963.0f,145.0f);
    glVertex2f(977.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(925.0f, 240.0f);
    glVertex2f(920.0f,215.0f);
    glVertex2f(910.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(920.0f, 215.0f);
    glVertex2f(910.0f, 215.0f);
    glVertex2f(909.0f,210.0f);
    glVertex2f(919.0f,210.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,0);
	glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f, 240.0f);
    glVertex2f(980.0f,215.0f);
    glVertex2f(990.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(980.0f, 215.0f);
    glVertex2f(990.0f, 215.0f);
    glVertex2f(991.0f,210.0f);
    glVertex2f(981.0f,210.0f);
    glEnd();



        glPopMatrix(); // End scaling
    glPopMatrix(); // End translation


}



   glFlush ();

    glutSwapBuffers();
}

void displayScene3() {
    glClear(GL_COLOR_BUFFER_BIT);


     glBegin(GL_POLYGON);
//for bridge
    glColor3f(0.596,0.612,0.62);
	glVertex2f(65.0f, 0.61f);
    glVertex2f(1500.0f, 408.05f);
    glVertex2f(1500.0f, 403.95f);
    glVertex2f(540.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
//for bridge
    glColor3f(0.596,0.612,0.62);
	glVertex2f(0.0f, 186.63f);
    glVertex2f(1500.0f, 423.39f);
    glVertex2f(1500.0,418.74f);
    glVertex2f(0.0f, 113.29f);
    glEnd();

     glBegin(GL_POLYGON);
//for middle line
    glColor3f(0.302,0.306,0.31);
	glVertex2f(0.0f, 113.29f);
    glVertex2f(1500.0f, 418.74f);
    glVertex2f(1500.0f, 408.05f);
    glVertex2f(65.0f, 0.61f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

     glBegin(GL_POLYGON);
//for  railline1
    glColor3f(0.278,0.373,0.471);
    glVertex2f(40.0f, 0.0f);
    glVertex2f(1500.0f, 410.0f);
    glVertex2f(1500.0f, 408.05f);
    glVertex2f(65.0f, 0.0f);
    glEnd();

     glBegin(GL_POLYGON);
//for  railline2
    glColor3f(0.278,0.373,0.471);
    glVertex2f(0.0f, 47.83f);
    glVertex2f(1500.0f, 414.33f);
    glVertex2f(1500.0f, 412.48f);
    glVertex2f(0.0f, 35.96f);
    glEnd();

     glBegin(GL_POLYGON);
//for  railline3
    glColor3f(0.278,0.373,0.471);
    glVertex2f(1500.0f, 417.7f);
    glVertex2f(1500.0f, 415.76f);
    glVertex2f(0.0f, 74.26f);
    glVertex2f(0.0f, 83.04f);
    glEnd();

    glBegin(GL_POLYGON);
//for piller-1
    glColor3f(0.596,0.612,0.62);
	glVertex2f(947.72f, 173.11f);
    glVertex2f(940.0f, 0.0f);
    glVertex2f(992.0f, 0.0f);
    glVertex2f(998.12f, 139.78f);
    glVertex2f(1022.33f, 169.92f);
    glVertex2f(1019.3f, 203.5f);
    glEnd();

    glBegin(GL_POLYGON);
//for piller-2
    glColor3f(0.596,0.612,0.62);
	glVertex2f(1171.83f, 268.26f);
    glVertex2f(1167.51f, 141.23f);
    glVertex2f(1200.0f, 140.0f);
    glVertex2f(1205.69f, 249.14f);
    glVertex2f(1226.2f, 272.1f);
    glVertex2f(1226.47f, 291.46f);
    glEnd();

    glBegin(GL_POLYGON);
//for piller-3
    glColor3f(0.596,0.612,0.62);
	glVertex2f(1270.12f, 309.99f);
    glVertex2f(1266.87f, 217.86f);
    glVertex2f(1292.77f, 218.04f);
    glVertex2f(1296.02f, 294.43f);
    glVertex2f(1313.02f, 314.31f);
    glVertex2f(1312.46f, 327.97f);
    glEnd();

    glBegin(GL_POLYGON);
//for piller-4
    glColor3f(0.596,0.612,0.62);
	glVertex2f(1369.92f, 352.36f);
    glVertex2f(1369.56f, 290.3f);
    glVertex2f(1388.19f, 291.95f);
    glVertex2f(1387.77f, 337.9f);
    glVertex2f(1401.02f, 353.22f);
    glVertex2f(1399.14f, 364.77f);
    glEnd();





    glBegin(GL_POLYGON);
//for Building-1
    glColor3f(0.357,0.561,0.192);
    glVertex2f(0.0f, 520.0f);
    glVertex2f(173.73f, 520.0f);
    glVertex2f(176.97f, 400.52f);
    glVertex2f(71.98f, 400.52f);
    glVertex2f(91.39f, 200.3f);
    glVertex2f(0.0f, 186.63f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
    glColor3f(0.867,0.922,0.922);
    glVertex2f(10.51f, 500.33f);
    glVertex2f(50.0f, 500.0f);
    glVertex2f(50.52f, 459.44f);
    glVertex2f(11.2f, 459.44f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
    glColor3f(0.867,0.922,0.922);
    glVertex2f(70.13f, 499.58f);
    glVertex2f(109.05f, 499.58f);
    glVertex2f(109.05f, 459.58f);
    glVertex2f(70.13f, 459.58f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
    glColor3f(0.867,0.922,0.922);
    glVertex2f(127.41f, 499.58f);
    glVertex2f(164.15f, 499.58f);
    glVertex2f(164.15f, 459.58f);
    glVertex2f(127.41f, 459.58f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-1
    glColor3f(0.867,0.922,0.922);
    glVertex2f(10.51f, 423.0f);
    glVertex2f(50.0f, 423.0f);
    glVertex2f(50.0f, 378.71f);
    glVertex2f(10.51f, 378.71f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
    glColor3f(0.867,0.922,0.922);
    glVertex2f(10.51f, 335.33f);
    glVertex2f(50.0f, 335.33f);
    glVertex2f(50.0f, 292.96f);
    glVertex2f(10.51f, 292.96f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-1
    glColor3f(0.867,0.922,0.922);
    glVertex2f(10.51f,267.0 );
    glVertex2f(50.0f, 267.0f);
    glVertex2f(50.0f, 225.66f);
    glVertex2f(10.51f, 225.66f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-2
    glColor3f(0.573,0.62,0.31);
    glVertex2f(71.98f, 400.52f);
    glVertex2f(218.23f, 400.52f);
    glVertex2f(218.23f, 221.02f);
    glVertex2f(91.39f, 200.3f);
    glEnd();

    glBegin(GL_POLYGON);
//for Building-2
    glColor3f(0.573,0.62,0.31);
    glVertex2f(218.23f, 400.52f);
    glVertex2f(324.23f, 430.6f);
    glVertex2f(324.23f, 237.81f);
    glVertex2f(218.23f, 221.02f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-2
    glColor3f(0.325,0.329,0.31);
    glVertex2f(218.23f, 400.52f);
    glVertex2f(227.62f, 403.93f);
    glVertex2f(231.78f, 223.51f);
    glVertex2f(218.23f, 221.02f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(101.68f,375.1f );
    glVertex2f(136.94f, 375.1f);
    glVertex2f(136.94f, 339.84f);
    glVertex2f(101.68f, 339.84f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(164.07f,375.1f );
    glVertex2f(199.33f, 375.1f);
    glVertex2f(199.33f, 339.84f);
    glVertex2f(164.07f, 339.84f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(102.76f,315.97f );
    glVertex2f(138.03f, 315.97f);
    glVertex2f(138.03f, 280.7f);
    glVertex2f(102.76f, 280.7f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(164.61f,314.34f );
    glVertex2f(199.87f, 314.34f);
    glVertex2f(199.87f, 279.07f);
    glVertex2f(164.61f, 279.07f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(104.93f,256.83f );
    glVertex2f(140.2f, 256.83f);
    glVertex2f(140.2f, 221.57f);
    glVertex2f(104.93f, 221.57f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(165.7f,259.0f );
    glVertex2f(200.96f, 259.0f);
    glVertex2f(200.96f, 223.74f);
    glVertex2f(165.7f, 223.74f);
    glEnd();


     glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(239.15f,384.33f );
    glVertex2f(274.42f, 384.33f);
    glVertex2f(274.42f, 349.06f);
    glVertex2f(239.15f, 349.06f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(287.49f,384.33f );
    glVertex2f(318.76f, 384.33f);
    glVertex2f(318.76f, 349.06f);
    glVertex2f(287.49f, 349.06f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(240.35f,315.7f );
    glVertex2f(275.61f, 315.7f);
    glVertex2f(275.61f, 280.43f);
    glVertex2f(240.35f, 280.43f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(289.86f,315.7f );
    glVertex2f(318.76f, 315.7f);
    glVertex2f(318.76f, 280.43f);
    glVertex2f(289.86f, 280.43f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(240.35f,269.48f );
    glVertex2f(277.06f, 269.48f);
    glVertex2f(277.06f, 234.22f);
    glVertex2f(240.35f, 234.22f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
    glColor3f(0.867,0.922,0.922);
    glVertex2f(289.86f,269.48f );
    glVertex2f(318.76f, 269.48f);
    glVertex2f(318.76f, 240.12f);
    glVertex2f(289.86f, 240.12f);
    glEnd();



     glBegin(GL_POLYGON);
//for Building-3
    glColor3f(0.243,0.059,0.361);
    glVertex2f(322.23f, 237.81f);
     glVertex2f(324.23f, 430.6f);
    glVertex2f(324.23f, 555.76f);
    glVertex2f(506.94f, 555.76f);
    glVertex2f(512.82f, 265.09f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(351.72f,530.88f );
    glVertex2f(378.41f, 530.88f);
    glVertex2f(378.41f, 489.5f);
    glVertex2f(351.721f, 489.5f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(399.51f,530.88f );
    glVertex2f(427.59f, 530.88f);
    glVertex2f(427.59f, 489.5f);
    glVertex2f(399.51f, 489.5f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(452.88f,530.88f );
    glVertex2f(479.68f, 530.88f);
    glVertex2f(479.68f, 489.5f);
    glVertex2f(452.88f, 489.5f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(351.72f,460.27f );
    glVertex2f(378.41f, 460.27f);
    glVertex2f(378.41f, 420.0f);
    glVertex2f(351.721f, 420.0f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(399.51f,460.27f );
    glVertex2f(427.59f, 460.27f);
    glVertex2f(427.59f, 420.0f);
    glVertex2f(399.51f, 420.0f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(452.88f,460.27f );
    glVertex2f(479.68f, 460.27f);
    glVertex2f(479.68f, 420.0f);
    glVertex2f(452.88f, 420.0f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(351.72f,392.22f );
    glVertex2f(378.41f, 392.22f);
    glVertex2f(378.41f, 351.12f);
    glVertex2f(351.721f, 351.12f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(399.51f,392.22f );
    glVertex2f(427.59f, 392.22f);
    glVertex2f(427.59f, 351.12f);
    glVertex2f(399.51f, 351.12f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(452.88f,392.22f );
    glVertex2f(479.68f, 392.22f);
    glVertex2f(479.68f, 351.12f);
    glVertex2f(452.88f, 351.12f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(351.72f,320.06f );
    glVertex2f(378.41f, 320.06f);
    glVertex2f(378.41f, 280.0f);
    glVertex2f(351.721f, 280.0f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(399.51f,320.06f );
    glVertex2f(427.59f, 320.06f);
    glVertex2f(427.59f, 280.0f);
    glVertex2f(399.51f, 280.0f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-3
    glColor3f(0.867,0.922,0.922);
    glVertex2f(452.88f,320.06f );
    glVertex2f(479.68f, 320.06f);
    glVertex2f(479.68f, 280.0f);
    glVertex2f(452.88f, 280.0f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-4
    glColor3f(0.678,0.502,0.224);
    glVertex2f(508.86f, 384.09f);
     glVertex2f(613.21f, 384.09f);
    glVertex2f(613.21f,281.04f);
    glVertex2f(512.82f, 265.02f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-4
    glColor3f(0.867,0.922,0.922);
    glVertex2f(517.72f,373.15f );
    glVertex2f(548.98f, 373.15f);
    glVertex2f(548.98f, 337.88f);
    glVertex2f(517.72f, 337.88f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-4
    glColor3f(0.867,0.922,0.922);
    glVertex2f(562.45f,373.15f );
    glVertex2f(593.72f, 373.15f);
    glVertex2f(593.72f, 337.88f);
    glVertex2f(562.45f, 337.88f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-4
    glColor3f(0.867,0.922,0.922);
    glVertex2f(517.72f,320.0f );
    glVertex2f(548.98f, 320.0f);
    glVertex2f(548.98f, 284.74f);
    glVertex2f(517.72f, 284.74f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-4
    glColor3f(0.867,0.922,0.922);
    glVertex2f(562.45f,320.0f );
    glVertex2f(593.72f, 320.0f);
    glVertex2f(593.72f, 284.74f);
    glVertex2f(562.45f, 284.74f);
    glEnd();


     glBegin(GL_POLYGON);
//for Building-5
    glColor3f(0.357,0.561,0.192);
    glVertex2f(613.21f, 450.0f);
     glVertex2f(700.0f, 450.0f);
    glVertex2f(700.0f,295.01f);
    glVertex2f(613.21f, 281.04f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-5
    glColor3f(0.867,0.922,0.922);
    glVertex2f(621.82f,439.88f );
    glVertex2f(643.95f, 439.88f);
    glVertex2f(643.95f, 404.61f);
    glVertex2f(621.82f, 404.61f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-5
    glColor3f(0.867,0.922,0.922);
    glVertex2f(671.09f,439.88f );
    glVertex2f(692.35f, 439.88f);
    glVertex2f(692.35f, 404.61f);
    glVertex2f(671.09f, 404.61f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-5
    glColor3f(0.867,0.922,0.922);
    glVertex2f(621.82f,389.18f );
    glVertex2f(643.95f, 389.18f);
    glVertex2f(643.95f, 353.92f);
    glVertex2f(621.82f, 353.92f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-5
    glColor3f(0.867,0.922,0.922);
    glVertex2f(671.09f,389.18f );
    glVertex2f(692.35f, 389.18f);
    glVertex2f(692.35f, 353.92f);
    glVertex2f(671.09f, 353.92f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-5
    glColor3f(0.867,0.922,0.922);
    glVertex2f(621.82f,338.94f );
    glVertex2f(643.95f, 338.94f);
    glVertex2f(643.95f, 303.68f);
    glVertex2f(621.82f, 303.68f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-5
    glColor3f(0.867,0.922,0.922);
    glVertex2f(671.09f,338.94f );
    glVertex2f(692.35f, 338.94f);
    glVertex2f(692.35f, 303.68f);
    glVertex2f(671.09f, 303.68f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-6
    glColor3f(0.788,0.588,0.396);
    glVertex2f(702.11f, 659.7f);
     glVertex2f(893.33f, 659.7f);
    glVertex2f(898.22f, 326.5f);
    glVertex2f(702.11f, 295.01f);
    glEnd();


     glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(713.15f,640.8f );
    glVertex2f(745.42f, 640.8f);
    glVertex2f(745.42f, 605.54f);
    glVertex2f(713.15f, 605.54f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(781.65f,640.8f );
    glVertex2f(813.92f, 640.8f);
    glVertex2f(813.92f, 605.54f);
    glVertex2f(781.65f, 605.54f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(848.19f,640.8f );
    glVertex2f(880.46f, 640.8f);
    glVertex2f(880.46f, 605.54f);
    glVertex2f(848.19f, 605.54f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(713.15f,573.61f );
    glVertex2f(745.42f, 573.61f);
    glVertex2f(745.42f, 538.35f);
    glVertex2f(713.15f, 538.35f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(781.65f,573.61f );
    glVertex2f(813.92f, 573.61f);
    glVertex2f(813.92f, 538.35f);
    glVertex2f(781.65f, 538.35f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(848.19f,573.61f );
    glVertex2f(880.46f, 573.61f);
    glVertex2f(880.46f, 538.35f);
    glVertex2f(848.19f, 538.35f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(713.15f,505.11f );
    glVertex2f(745.42f, 505.11f);
    glVertex2f(745.42f, 469.85f);
    glVertex2f(713.15f, 469.85f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(781.65f,505.11f );
    glVertex2f(813.92f, 505.11f);
    glVertex2f(813.92f, 469.85f);
    glVertex2f(781.65f, 469.85f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(848.19f,505.11f );
    glVertex2f(880.46f, 505.11f);
    glVertex2f(880.46f, 469.85f);
    glVertex2f(848.19f, 469.85f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(713.15f,432.7f );
    glVertex2f(745.42f, 432.7f);
    glVertex2f(745.42f, 397.44f);
    glVertex2f(713.15f, 397.44f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(781.65f,432.7f );
    glVertex2f(813.92f, 432.7f);
    glVertex2f(813.92f, 397.44f);
    glVertex2f(781.65f, 397.44f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(848.19f,432.7f );
    glVertex2f(880.46f, 432.7f);
    glVertex2f(880.46f, 397.44f);
    glVertex2f(848.19f, 397.44f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(713.15f,364.2f );
    glVertex2f(745.42f, 364.2f);
    glVertex2f(745.42f, 328.94f);
    glVertex2f(713.15f, 328.94f);
    glEnd();

         glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(781.65f,364.2f );
    glVertex2f(813.92f, 364.2f);
    glVertex2f(813.92f, 328.94f);
    glVertex2f(781.65f, 328.94f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-6
    glColor3f(0.867,0.922,0.922);
    glVertex2f(848.19f,364.2f );
    glVertex2f(880.46f, 364.2f);
    glVertex2f(880.46f, 328.94f);
    glVertex2f(848.19f, 328.94f);
    glEnd();


     glBegin(GL_POLYGON);
//for Building-7
    glColor3f(0.345,0.388,0.247);
    glVertex2f(895.22f, 524.84f);
     glVertex2f(1041.97f, 524.84f);
    glVertex2f(1044.25f, 349.02f);
    glVertex2f(898.22f, 324.5f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(911.34f,504.11f );
    glVertex2f(942.61f, 504.11f);
    glVertex2f(942.61f, 468.84f);
    glVertex2f(911.34f, 468.84f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(959.49f,504.11f );
    glVertex2f(990.76f, 504.11f);
    glVertex2f(990.76f, 468.84f);
    glVertex2f(959.49f, 468.84f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1004.64f,504.11f );
    glVertex2f(1035.91f, 504.11f);
    glVertex2f(1035.91f, 468.84f);
    glVertex2f(1004.64f, 468.84f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(911.34f,448.85f );
    glVertex2f(942.61f, 448.85f);
    glVertex2f(942.61f, 413.59f);
    glVertex2f(911.34f, 413.59f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(959.49f,448.85f );
    glVertex2f(990.76f,448.85f);
    glVertex2f(990.76f, 413.59f);
    glVertex2f(959.49f, 413.59f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1004.64f, 448.85f );
    glVertex2f(1035.91f, 448.85f);
    glVertex2f(1035.91f, 413.59f);
    glVertex2f(1004.64f, 413.59f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(911.34f,388.07f );
    glVertex2f(942.61f, 388.07f);
    glVertex2f(942.61f, 352.81f);
    glVertex2f(911.34f, 352.81f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(959.49f,388.07f );
    glVertex2f(990.76f,388.07f);
    glVertex2f(990.76f, 352.81f);
    glVertex2f(959.49f, 352.81f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-7
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1004.64f, 388.07f );
    glVertex2f(1035.91f, 388.07f);
    glVertex2f(1035.91f, 352.81f);
    glVertex2f(1004.64f, 352.81f);
    glEnd();



    glBegin(GL_POLYGON);
//for Building-8
    glColor3f(0.047,0.18,0.31);
    glVertex2f(1068.47f, 420.04f);
    glVertex2f(1148.73f, 420.04f);
    glVertex2f(1148.73f, 366.67f);
    glVertex2f(1068.47f, 355.12f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-8
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1075.97f, 403.14f );
    glVertex2f(1099.86f, 403.14f);
    glVertex2f(1099.86f, 375.24f);
    glVertex2f(1075.97f, 375.24f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-8
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1111.97f, 403.14f );
    glVertex2f(1137.86f, 403.14f);
    glVertex2f(1137.86f, 375.24f);
    glVertex2f(1111.97f, 375.24f);
    glEnd();

    glBegin(GL_POLYGON);
//for Building-9
    glColor3f(0.573,0.62,0.31);
    glVertex2f(1148.73f, 580.1f);
    glVertex2f(1252.71f, 580.1f);
    glVertex2f(1252.89f, 383.63f);
    glVertex2f(1148.73f, 366.67f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1156.48f,572.15f );
    glVertex2f(1176.06f,572.15f);
    glVertex2f(1176.06f, 536.04f);
    glVertex2f(1156.48f, 536.04f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1191.72f,572.15f );
    glVertex2f(1210.0f,572.15f);
    glVertex2f(1210.0f, 536.04f);
    glVertex2f(1191.72f, 536.04f);
    glEnd();


      glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1223.92f,572.15f );
    glVertex2f(1243.5f,572.15f);
    glVertex2f(1243.5f, 536.04f);
    glVertex2f(1223.92f, 536.04f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1156.48f,501.23f );
    glVertex2f(1176.06f,501.23f);
    glVertex2f(1176.06f, 463.82f);
    glVertex2f(1156.48f, 463.82f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1191.72f,501.23f );
    glVertex2f(1210.0f,501.23);
    glVertex2f(1210.0f, 463.82f);
    glVertex2f(1191.72f,463.82f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1223.92f,501.23f );
    glVertex2f(1243.5f,501.23f);
    glVertex2f(1243.5f, 463.82f);
    glVertex2f(1223.92f, 463.82f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1156.48f,428.14f );
    glVertex2f(1176.06f,428.14f);
    glVertex2f(1176.06f, 393.34f);
    glVertex2f(1156.48f, 393.34f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1191.72f,428.14f );
    glVertex2f(1210.0f,428.14);
    glVertex2f(1210.0f, 393.34f);
    glVertex2f(1191.72f,393.34f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-9
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1223.92f,428.14f );
    glVertex2f(1243.5f,428.14f);
    glVertex2f(1243.5f, 393.34f);
    glVertex2f(1223.92f,393.34f);
    glEnd();



    glBegin(GL_POLYGON);
//for Building-10
    glColor3f(0.082,0.502,0.447);
    glVertex2f(1252.89f, 481.0f);
    glVertex2f(1300.0f, 481.0f);
    glVertex2f(1300.0f, 390.51f);
    glVertex2f(1252.89f, 383.63f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-10
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1268.76f,472.08f );
    glVertex2f(1285.26f,472.08f);
    glVertex2f(1285.26f, 449.03f);
    glVertex2f(1268.76f, 449.03f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-10
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1268.76f,426.4f );
    glVertex2f(1285.26f,426.4f);
    glVertex2f(1285.26f, 403.78f);
    glVertex2f(1268.76f, 403.78f);
    glEnd();


    glBegin(GL_POLYGON);
//for Building-11
    glColor3f(0.678,0.502,0.224);
    glVertex2f(1300.0f, 500.0f);
    glVertex2f(1358.31f, 500.0f);
    glVertex2f(1360.02f, 400.17f);
    glVertex2f(1300.0f, 390.51f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-11
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1304.86f,493.97f );
    glVertex2f(1325.29f,493.97f);
    glVertex2f(1325.29f, 462.86f);
    glVertex2f(1304.86f, 462.86f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-11
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1336.17f,493.97f );
    glVertex2f(1351.83f,493.97f);
    glVertex2f(1351.83f, 462.86f);
    glVertex2f(1336.17f, 462.86f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-11
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1304.86f,436.41f );
    glVertex2f(1325.29f,436.41f);
    glVertex2f(1325.29f, 410.35f);
    glVertex2f(1304.86f, 410.35f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-11
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1336.17f,436.41f );
    glVertex2f(1351.83f,436.41f);
    glVertex2f(1351.83f, 410.35f);
    glVertex2f(1336.17f, 410.35f);
    glEnd();


    glBegin(GL_POLYGON);
//for Building-12
    glColor3f(0.431,0.376,0.102);
    glVertex2f(1360.02f, 543.67f);
    glVertex2f(1416.27f, 543.67);
    glVertex2f(1415.86f, 409.57f);
    glVertex2f(1360.02f, 400.17f);
    glEnd();


     glBegin(GL_QUADS);
//for Building-12
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1368.36f,531.25f );
    glVertex2f(1385.33f,531.25f);
    glVertex2f(1385.33f, 507.76f);
    glVertex2f(1368.36f, 507.76f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-12
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1395.77f,531.25f );
    glVertex2f(1411.0f,531.25f);
    glVertex2f(1411.0f, 507.76f);
    glVertex2f(1395.77f, 507.76f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-12
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1368.36f,486.01f );
    glVertex2f(1385.33f,486.01f);
    glVertex2f(1385.33f, 465.12f);
    glVertex2f(1368.36f, 465.12f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-12
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1395.77f,486.01f );
    glVertex2f(1411.0f,486.01f);
    glVertex2f(1411.0f, 465.12f);
    glVertex2f(1395.77f, 465.12f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-12
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1368.36f,443.8f );
    glVertex2f(1385.33f,443.8f);
    glVertex2f(1385.33f, 424.23f);
    glVertex2f(1368.36f, 424.23f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-12
    glColor3f(0.867,0.922,0.922);
    glVertex2f(1395.77f,443.8f );
    glVertex2f(1411.0f,443.8f);
    glVertex2f(1411.0f, 424.23f);
    glVertex2f(1395.77f, 424.23f);
    glEnd();







    //soil
     glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(540.0f,0.0f );
    glVertex2f(947.72f,173.11f);
    glVertex2f(940.0f,0.0f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1019.3f,203.5f );
    glVertex2f(1022.33f,169.92f);
    glVertex2f(1170.91f,241.16f );
    glVertex2f(1171.83f,268.26f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1022.33f,169.92f);
    glVertex2f(998.12f, 139.78f);
    glVertex2f(992.0f,0.0f);
    glVertex2f(1167.51f,141.23f);
    glVertex2f(1170.91f,241.16f );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1226.47f,291.46f );
    glVertex2f(1270.12f,309.99f);
    glVertex2f(1269.36f,288.54f );
    glVertex2f(1226.2f,272.1f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1226.2f,272.1f);
    glVertex2f(1205.69f, 249.14f);
    glVertex2f(1200.0f,140.0f);
    glVertex2f(1266.87f,217.86f);
    glVertex2f(1269.36f,288.54f );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1312.46f,327.97f );
    glVertex2f(1369.92f,352.36f);
    glVertex2f(1369.84f,338.26f );
    glVertex2f(1313.02f,314.31f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1313.02f,314.31f);
    glVertex2f(1296.02f, 294.43f);
    glVertex2f(1292.77f,218.04f);
    glVertex2f(1369.56f,290.3f);
    glVertex2f(1369.84f,338.26f );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1399.14f,364.77f );
    glVertex2f(1450.86f,386.73f);
    glVertex2f(1450.82f,374.23f);
    glVertex2f(1401.02f,353.22f );
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1401.02f,353.22f);
    glVertex2f(1387.77f, 337.9f);
    glVertex2f(1388.19f,291.95f);
    glVertex2f(1450.67f,319.81f);
    glVertex2f(1450.82f,374.23f );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1200.0f,140.0f);
    glVertex2f(1292.77f, 218.04f);
    glVertex2f(1266.87f,217.86f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(992.0f,0.0f);
    glVertex2f(1200.0f, 140.0f);
    glVertex2f(1167.51f,141.23f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1292.77f,218.04f);
    glVertex2f(1388.19f, 291.95f);
    glVertex2f(1369.56f,290.3f);
    glEnd();

    glBegin(GL_POLYGON);
//for piller-2
    glColor3f(0.596,0.612,0.62);
	glVertex2f(1266.87f, 217.86f);
    glVertex2f(1278.87f, 206.35f);
    glVertex2f(1292.77f, 218.04f);
    glEnd();

    glBegin(GL_POLYGON);
//for piller-3
    glColor3f(0.596,0.612,0.62);
	glVertex2f(1167.51f, 141.23f);
    glVertex2f(1181.77f, 127.73f);
    glVertex2f(1200.0f,140.0f);
    glEnd();

    glBegin(GL_POLYGON);
//for piller-4
    glColor3f(0.596,0.612,0.62);
	glVertex2f(1369.56f, 290.3f);
    glVertex2f(1380.24f, 285.8f);
    glVertex2f(1388.19f,291.95f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(146,116,91);
    glVertex2f(1450.86f,386.73f);
    glVertex2f(1500.0f, 403.95f);
    glVertex2f(1500.0f,338.56f);
    glVertex2f(1450.67f,319.81f);
    glEnd();



    //road
     glBegin(GL_POLYGON);
    glColor3ub(52,52,52);
     glVertex2f(992.0f,0.0f);
    glVertex2f(1500.0f, 0.0f);
    glVertex2f(1500.0f,338.56f);
    glVertex2f(1450.67f,319.81f);
     glVertex2f(1388.19f, 291.95f);
     glVertex2f(1292.77f,218.04f);
    glVertex2f(1500.0f,308.54f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.929,0.925,0.85);
    glVertex2f(1250.21f,78.36f);
    glVertex2f(1335.38f, 160.95f);
    glVertex2f(1349.54f,159.93f);
    glVertex2f(1261.53f,75.97f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.929,0.925,0.85);
    glVertex2f(1382.7f,204.07f);
    glVertex2f(1450.76f, 266.35f);
    glVertex2f(1458.53f,258.57f);
    glVertex2f(1392.08f,199.89f);
    glEnd();

///////////////////////////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
//for Building-1
    glColor3f(0.357,0.451,0.192);
    glVertex2f(0.0f, 520.0f);
    glVertex2f(173.73f, 520.0f);
    glVertex2f(176.97f, 400.52f);
    glVertex2f(71.98f, 400.52f);
    glVertex2f(91.39f, 200.3f);
    glVertex2f(0.0f, 186.63f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
    glColor3ub(246,241, 213);
    glVertex2f(10.51f, 500.33f);
    glVertex2f(50.0f, 500.0f);
    glVertex2f(50.52f, 459.44f);
    glVertex2f(11.2f, 459.44f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
    glColor3ub(246,241, 213);
    glVertex2f(70.13f, 499.58f);
    glVertex2f(109.05f, 499.58f);
    glVertex2f(109.05f, 459.58f);
    glVertex2f(70.13f, 459.58f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
    glColor3ub(246,241, 213);
    glVertex2f(127.41f, 499.58f);
    glVertex2f(164.15f, 499.58f);
    glVertex2f(164.15f, 459.58f);
    glVertex2f(127.41f, 459.58f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-1
    glColor3ub(246,241, 213);
    glVertex2f(10.51f, 423.0f);
    glVertex2f(50.0f, 423.0f);
    glVertex2f(50.0f, 378.71f);
    glVertex2f(10.51f, 378.71f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-1
   glColor3ub(246,241, 213);
    glVertex2f(10.51f, 335.33f);
    glVertex2f(50.0f, 335.33f);
    glVertex2f(50.0f, 292.96f);
    glVertex2f(10.51f, 292.96f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-1
    glColor3ub(246,241, 213);
    glVertex2f(10.51f,267.0 );
    glVertex2f(50.0f, 267.0f);
    glVertex2f(50.0f, 225.66f);
    glVertex2f(10.51f, 225.66f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-2
   glColor3f(0.573,0.541,0.361);
    glVertex2f(71.98f, 400.52f);
    glVertex2f(218.23f, 400.52f);
    glVertex2f(218.23f, 221.02f);
    glVertex2f(91.39f, 200.3f);
    glEnd();

    glBegin(GL_POLYGON);
//for Building-2
    glColor3f(0.573,0.541,0.361);
    glVertex2f(218.23f, 400.52f);
    glVertex2f(324.23f, 430.6f);
    glVertex2f(324.23f, 237.81f);
    glVertex2f(218.23f, 221.02f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-2
   glColor3f(0.325,0.329,0.231);
    glVertex2f(218.23f, 400.52f);
    glVertex2f(227.62f, 403.93f);
    glVertex2f(231.78f, 223.51f);
    glVertex2f(218.23f, 221.02f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-2
    glColor3ub(246,241, 213);
    glVertex2f(101.68f,375.1f );
    glVertex2f(136.94f, 375.1f);
    glVertex2f(136.94f, 339.84f);
    glVertex2f(101.68f, 339.84f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-2
    glColor3ub(246,241, 213);
    glVertex2f(164.07f,375.1f );
    glVertex2f(199.33f, 375.1f);
    glVertex2f(199.33f, 339.84f);
    glVertex2f(164.07f, 339.84f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
    glColor3ub(246,241, 213);
    glVertex2f(102.76f,315.97f );
    glVertex2f(138.03f, 315.97f);
    glVertex2f(138.03f, 280.7f);
    glVertex2f(102.76f, 280.7f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-2
   glColor3ub(246,241, 213);
    glVertex2f(164.61f,314.34f );
    glVertex2f(199.87f, 314.34f);
    glVertex2f(199.87f, 279.07f);
    glVertex2f(164.61f, 279.07f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
   glColor3ub(246,241, 213);
    glVertex2f(104.93f,256.83f );
    glVertex2f(140.2f, 256.83f);
    glVertex2f(140.2f, 221.57f);
    glVertex2f(104.93f, 221.57f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
    glColor3ub(246,241, 213);
    glVertex2f(165.7f,259.0f );
    glVertex2f(200.96f, 259.0f);
    glVertex2f(200.96f, 223.74f);
    glVertex2f(165.7f, 223.74f);
    glEnd();


     glBegin(GL_QUADS);
//for Building-2
    glColor3ub(246,241, 213);
    glVertex2f(239.15f,384.33f );
    glVertex2f(274.42f, 384.33f);
    glVertex2f(274.42f, 349.06f);
    glVertex2f(239.15f, 349.06f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-2
   glColor3ub(246,241, 213);
    glVertex2f(287.49f,384.33f );
    glVertex2f(318.76f, 384.33f);
    glVertex2f(318.76f, 349.06f);
    glVertex2f(287.49f, 349.06f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-2
     glColor3ub(246,241, 213);
    glVertex2f(240.35f,315.7f );
    glVertex2f(275.61f, 315.7f);
    glVertex2f(275.61f, 280.43f);
    glVertex2f(240.35f, 280.43f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
     glColor3ub(246,241, 213);
    glVertex2f(289.86f,315.7f );
    glVertex2f(318.76f, 315.7f);
    glVertex2f(318.76f, 280.43f);
    glVertex2f(289.86f, 280.43f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-2
     glColor3ub(246,241, 213);
    glVertex2f(240.35f,269.48f );
    glVertex2f(277.06f, 269.48f);
    glVertex2f(277.06f, 234.22f);
    glVertex2f(240.35f, 234.22f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-2
     glColor3ub(246,241, 213);
    glVertex2f(289.86f,269.48f );
    glVertex2f(318.76f, 269.48f);
    glVertex2f(318.76f, 240.12f);
    glVertex2f(289.86f, 240.12f);
    glEnd();



     glBegin(GL_POLYGON);
//for Building-3
    glColor3f(0.243,0.239,0.361);
    glVertex2f(322.23f, 237.81f);
     glVertex2f(324.23f, 430.6f);
    glVertex2f(324.23f, 555.76f);
    glVertex2f(506.94f, 555.76f);
    glVertex2f(512.82f, 265.09f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-3
     glColor3ub(246,241, 213);
    glVertex2f(351.72f,530.88f );
    glVertex2f(378.41f, 530.88f);
    glVertex2f(378.41f, 489.5f);
    glVertex2f(351.721f, 489.5f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
     glColor3ub(246,241, 213);
    glVertex2f(399.51f,530.88f );
    glVertex2f(427.59f, 530.88f);
    glVertex2f(427.59f, 489.5f);
    glVertex2f(399.51f, 489.5f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
     glColor3ub(246,241, 213);
    glVertex2f(452.88f,530.88f );
    glVertex2f(479.68f, 530.88f);
    glVertex2f(479.68f, 489.5f);
    glVertex2f(452.88f, 489.5f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-3
     glColor3ub(246,241, 213);
    glVertex2f(351.72f,460.27f );
    glVertex2f(378.41f, 460.27f);
    glVertex2f(378.41f, 420.0f);
    glVertex2f(351.721f, 420.0f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3ub(246,241, 213);
    glVertex2f(399.51f,460.27f );
    glVertex2f(427.59f, 460.27f);
    glVertex2f(427.59f, 420.0f);
    glVertex2f(399.51f, 420.0f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
     glColor3ub(246,241, 213);
    glVertex2f(452.88f,460.27f );
    glVertex2f(479.68f, 460.27f);
    glVertex2f(479.68f, 420.0f);
    glVertex2f(452.88f, 420.0f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3ub(246,241, 213);
    glVertex2f(351.72f,392.22f );
    glVertex2f(378.41f, 392.22f);
    glVertex2f(378.41f, 351.12f);
    glVertex2f(351.721f, 351.12f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
    glColor3ub(246,241, 213);
    glVertex2f(399.51f,392.22f );
    glVertex2f(427.59f, 392.22f);
    glVertex2f(427.59f, 351.12f);
    glVertex2f(399.51f, 351.12f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-3
    glColor3ub(246,241, 213);
    glVertex2f(452.88f,392.22f );
    glVertex2f(479.68f, 392.22f);
    glVertex2f(479.68f, 351.12f);
    glVertex2f(452.88f, 351.12f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-3
     glColor3ub(246,241, 213);
    glVertex2f(351.72f,320.06f );
    glVertex2f(378.41f, 320.06f);
    glVertex2f(378.41f, 280.0f);
    glVertex2f(351.721f, 280.0f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-3
     glColor3ub(246,241, 213);
    glVertex2f(399.51f,320.06f );
    glVertex2f(427.59f, 320.06f);
    glVertex2f(427.59f, 280.0f);
    glVertex2f(399.51f, 280.0f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-3
    glColor3ub(246,241, 213);
    glVertex2f(452.88f,320.06f );
    glVertex2f(479.68f, 320.06f);
    glVertex2f(479.68f, 280.0f);
    glVertex2f(452.88f, 280.0f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-4
    glColor3f(0.678,0.502,0.4);
    glVertex2f(508.86f, 384.09f);
     glVertex2f(613.21f, 384.09f);
    glVertex2f(613.21f,281.04f);
    glVertex2f(512.82f, 265.02f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-4
     glColor3ub(246,241, 213);
    glVertex2f(517.72f,373.15f );
    glVertex2f(548.98f, 373.15f);
    glVertex2f(548.98f, 337.88f);
    glVertex2f(517.72f, 337.88f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-4
     glColor3ub(246,241, 213);
    glVertex2f(562.45f,373.15f );
    glVertex2f(593.72f, 373.15f);
    glVertex2f(593.72f, 337.88f);
    glVertex2f(562.45f, 337.88f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-4
     glColor3ub(246,241, 213);
    glVertex2f(517.72f,320.0f );
    glVertex2f(548.98f, 320.0f);
    glVertex2f(548.98f, 284.74f);
    glVertex2f(517.72f, 284.74f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-4
     glColor3ub(246,241, 213);
    glVertex2f(562.45f,320.0f );
    glVertex2f(593.72f, 320.0f);
    glVertex2f(593.72f, 284.74f);
    glVertex2f(562.45f, 284.74f);
    glEnd();


     glBegin(GL_POLYGON);
//for Building-5
     glColor3f(0.357,0.451 ,0.192);
    glVertex2f(613.21f, 450.0f);
     glVertex2f(700.0f, 450.0f);
    glVertex2f(700.0f,295.01f);
    glVertex2f(613.21f, 281.04f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-5
     glColor3ub(246,241, 213);
    glVertex2f(621.82f,439.88f );
    glVertex2f(643.95f, 439.88f);
    glVertex2f(643.95f, 404.61f);
    glVertex2f(621.82f, 404.61f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-5
     glColor3ub(246,241, 213);
    glVertex2f(671.09f,439.88f );
    glVertex2f(692.35f, 439.88f);
    glVertex2f(692.35f, 404.61f);
    glVertex2f(671.09f, 404.61f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-5
     glColor3ub(246,241, 213);
    glVertex2f(621.82f,389.18f );
    glVertex2f(643.95f, 389.18f);
    glVertex2f(643.95f, 353.92f);
    glVertex2f(621.82f, 353.92f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-5
     glColor3ub(246,241, 213);
    glVertex2f(671.09f,389.18f );
    glVertex2f(692.35f, 389.18f);
    glVertex2f(692.35f, 353.92f);
    glVertex2f(671.09f, 353.92f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-5
     glColor3ub(246,241, 213);
    glVertex2f(621.82f,338.94f );
    glVertex2f(643.95f, 338.94f);
    glVertex2f(643.95f, 303.68f);
    glVertex2f(621.82f, 303.68f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-5
   glColor3ub(246,241, 213);
    glVertex2f(671.09f,338.94f );
    glVertex2f(692.35f, 338.94f);
    glVertex2f(692.35f, 303.68f);
    glVertex2f(671.09f, 303.68f);
    glEnd();

     glBegin(GL_POLYGON);
//for Building-6
    glColor3f(0.678,0.533,0.384);
    glVertex2f(702.11f, 659.7f);
     glVertex2f(893.33f, 659.7f);
    glVertex2f(898.22f, 326.5f);
    glVertex2f(702.11f, 295.01f);
    glEnd();


     glBegin(GL_QUADS);
//for Building-6
   glColor3ub(246,241, 213);
    glVertex2f(713.15f,640.8f );
    glVertex2f(745.42f, 640.8f);
    glVertex2f(745.42f, 605.54f);
    glVertex2f(713.15f, 605.54f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(781.65f,640.8f );
    glVertex2f(813.92f, 640.8f);
    glVertex2f(813.92f, 605.54f);
    glVertex2f(781.65f, 605.54f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(848.19f,640.8f );
    glVertex2f(880.46f, 640.8f);
    glVertex2f(880.46f, 605.54f);
    glVertex2f(848.19f, 605.54f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(713.15f,573.61f );
    glVertex2f(745.42f, 573.61f);
    glVertex2f(745.42f, 538.35f);
    glVertex2f(713.15f, 538.35f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(781.65f,573.61f );
    glVertex2f(813.92f, 573.61f);
    glVertex2f(813.92f, 538.35f);
    glVertex2f(781.65f, 538.35f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(848.19f,573.61f );
    glVertex2f(880.46f, 573.61f);
    glVertex2f(880.46f, 538.35f);
    glVertex2f(848.19f, 538.35f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(713.15f,505.11f );
    glVertex2f(745.42f, 505.11f);
    glVertex2f(745.42f, 469.85f);
    glVertex2f(713.15f, 469.85f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-6
   glColor3ub(246,241, 213);
    glVertex2f(781.65f,505.11f );
    glVertex2f(813.92f, 505.11f);
    glVertex2f(813.92f, 469.85f);
    glVertex2f(781.65f, 469.85f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(848.19f,505.11f );
    glVertex2f(880.46f, 505.11f);
    glVertex2f(880.46f, 469.85f);
    glVertex2f(848.19f, 469.85f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(713.15f,432.7f );
    glVertex2f(745.42f, 432.7f);
    glVertex2f(745.42f, 397.44f);
    glVertex2f(713.15f, 397.44f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(781.65f,432.7f );
    glVertex2f(813.92f, 432.7f);
    glVertex2f(813.92f, 397.44f);
    glVertex2f(781.65f, 397.44f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(848.19f,432.7f );
    glVertex2f(880.46f, 432.7f);
    glVertex2f(880.46f, 397.44f);
    glVertex2f(848.19f, 397.44f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(713.15f,364.2f );
    glVertex2f(745.42f, 364.2f);
    glVertex2f(745.42f, 328.94f);
    glVertex2f(713.15f, 328.94f);
    glEnd();

         glBegin(GL_QUADS);
//for Building-6
    glColor3ub(246,241, 213);
    glVertex2f(781.65f,364.2f );
    glVertex2f(813.92f, 364.2f);
    glVertex2f(813.92f, 328.94f);
    glVertex2f(781.65f, 328.94f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-6
   glColor3ub(246,241, 213);
    glVertex2f(848.19f,364.2f );
    glVertex2f(880.46f, 364.2f);
    glVertex2f(880.46f, 328.94f);
    glVertex2f(848.19f, 328.94f);
    glEnd();


     glBegin(GL_POLYGON);
//for Building-7
    glColor3f(0.502,0.541,0.376);
    glVertex2f(895.22f, 524.84f);
     glVertex2f(1041.97f, 524.84f);
    glVertex2f(1044.25f, 349.02f);
    glVertex2f(898.22f, 324.5f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(911.34f,504.11f );
    glVertex2f(942.61f, 504.11f);
    glVertex2f(942.61f, 468.84f);
    glVertex2f(911.34f, 468.84f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(959.49f,504.11f );
    glVertex2f(990.76f, 504.11f);
    glVertex2f(990.76f, 468.84f);
    glVertex2f(959.49f, 468.84f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(1004.64f,504.11f );
    glVertex2f(1035.91f, 504.11f);
    glVertex2f(1035.91f, 468.84f);
    glVertex2f(1004.64f, 468.84f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(911.34f,448.85f );
    glVertex2f(942.61f, 448.85f);
    glVertex2f(942.61f, 413.59f);
    glVertex2f(911.34f, 413.59f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(959.49f,448.85f );
    glVertex2f(990.76f,448.85f);
    glVertex2f(990.76f, 413.59f);
    glVertex2f(959.49f, 413.59f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(1004.64f, 448.85f );
    glVertex2f(1035.91f, 448.85f);
    glVertex2f(1035.91f, 413.59f);
    glVertex2f(1004.64f, 413.59f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
   glColor3ub(246,241, 213);
    glVertex2f(911.34f,388.07f );
    glVertex2f(942.61f, 388.07f);
    glVertex2f(942.61f, 352.81f);
    glVertex2f(911.34f, 352.81f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(959.49f,388.07f );
    glVertex2f(990.76f,388.07f);
    glVertex2f(990.76f, 352.81f);
    glVertex2f(959.49f, 352.81f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-7
    glColor3ub(246,241, 213);
    glVertex2f(1004.64f, 388.07f );
    glVertex2f(1035.91f, 388.07f);
    glVertex2f(1035.91f, 352.81f);
    glVertex2f(1004.64f, 352.81f);
    glEnd();



    glBegin(GL_POLYGON);
//for Building-8
    glColor3f(0.267,0.329,0.388);
    glVertex2f(1068.47f, 420.04f);
    glVertex2f(1148.73f, 420.04f);
    glVertex2f(1148.73f, 366.67f);
    glVertex2f(1068.47f, 355.12f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-8
    glColor3ub(246,241, 213);
    glVertex2f(1075.97f, 403.14f );
    glVertex2f(1099.86f, 403.14f);
    glVertex2f(1099.86f, 375.24f);
    glVertex2f(1075.97f, 375.24f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-8
    glColor3ub(246,241, 213);
    glVertex2f(1111.97f, 403.14f );
    glVertex2f(1137.86f, 403.14f);
    glVertex2f(1137.86f, 375.24f);
    glVertex2f(1111.97f, 375.24f);
    glEnd();

    glBegin(GL_POLYGON);
//for Building-9
    glColor3f(0.557,0.588,0.373);
    glVertex2f(1148.73f, 580.1f);
    glVertex2f(1252.71f, 580.1f);
    glVertex2f(1252.89f, 383.63f);
    glVertex2f(1148.73f, 366.67f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1156.48f,572.15f );
    glVertex2f(1176.06f,572.15f);
    glVertex2f(1176.06f, 536.04f);
    glVertex2f(1156.48f, 536.04f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1191.72f,572.15f );
    glVertex2f(1210.0f,572.15f);
    glVertex2f(1210.0f, 536.04f);
    glVertex2f(1191.72f, 536.04f);
    glEnd();


      glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1223.92f,572.15f );
    glVertex2f(1243.5f,572.15f);
    glVertex2f(1243.5f, 536.04f);
    glVertex2f(1223.92f, 536.04f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1156.48f,501.23f );
    glVertex2f(1176.06f,501.23f);
    glVertex2f(1176.06f, 463.82f);
    glVertex2f(1156.48f, 463.82f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1191.72f,501.23f );
    glVertex2f(1210.0f,501.23);
    glVertex2f(1210.0f, 463.82f);
    glVertex2f(1191.72f,463.82f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-9
   glColor3ub(246,241, 213);
    glVertex2f(1223.92f,501.23f );
    glVertex2f(1243.5f,501.23f);
    glVertex2f(1243.5f, 463.82f);
    glVertex2f(1223.92f, 463.82f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1156.48f,428.14f );
    glVertex2f(1176.06f,428.14f);
    glVertex2f(1176.06f, 393.34f);
    glVertex2f(1156.48f, 393.34f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1191.72f,428.14f );
    glVertex2f(1210.0f,428.14);
    glVertex2f(1210.0f, 393.34f);
    glVertex2f(1191.72f,393.34f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-9
    glColor3ub(246,241, 213);
    glVertex2f(1223.92f,428.14f );
    glVertex2f(1243.5f,428.14f);
    glVertex2f(1243.5f, 393.34f);
    glVertex2f(1223.92f,393.34f);
    glEnd();



    glBegin(GL_POLYGON);
//for Building-10
    glColor3f(0.263,0.478,0.451);
    glVertex2f(1252.89f, 481.0f);
    glVertex2f(1300.0f, 481.0f);
    glVertex2f(1300.0f, 390.51f);
    glVertex2f(1252.89f, 383.63f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-10
    glColor3ub(246,241, 213);
    glVertex2f(1268.76f,472.08f );
    glVertex2f(1285.26f,472.08f);
    glVertex2f(1285.26f, 449.03f);
    glVertex2f(1268.76f, 449.03f);
    glEnd();

       glBegin(GL_QUADS);
//for Building-10
    glColor3ub(246,241, 213);
    glVertex2f(1268.76f,426.4f );
    glVertex2f(1285.26f,426.4f);
    glVertex2f(1285.26f, 403.78f);
    glVertex2f(1268.76f, 403.78f);
    glEnd();


    glBegin(GL_POLYGON);
//for Building-11
    glColor3f(0.678,0.58,0.42);
    glVertex2f(1300.0f, 500.0f);
    glVertex2f(1358.31f, 500.0f);
    glVertex2f(1360.02f, 400.17f);
    glVertex2f(1300.0f, 390.51f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-11
    glColor3ub(246,241, 213);
    glVertex2f(1304.86f,493.97f );
    glVertex2f(1325.29f,493.97f);
    glVertex2f(1325.29f, 462.86f);
    glVertex2f(1304.86f, 462.86f);
    glEnd();

    glBegin(GL_QUADS);
//for Building-11
   glColor3ub(246,241, 213);
    glVertex2f(1336.17f,493.97f );
    glVertex2f(1351.83f,493.97f);
    glVertex2f(1351.83f, 462.86f);
    glVertex2f(1336.17f, 462.86f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-11
    glColor3ub(246,241, 213);
    glVertex2f(1304.86f,436.41f );
    glVertex2f(1325.29f,436.41f);
    glVertex2f(1325.29f, 410.35f);
    glVertex2f(1304.86f, 410.35f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-11
    glColor3ub(246,241, 213);
    glVertex2f(1336.17f,436.41f );
    glVertex2f(1351.83f,436.41f);
    glVertex2f(1351.83f, 410.35f);
    glVertex2f(1336.17f, 410.35f);
    glEnd();


    glBegin(GL_POLYGON);
//for Building-12
    glColor3f(0.49,0.459,0.31);
    glVertex2f(1360.02f, 543.67f);
    glVertex2f(1416.27f, 543.67);
    glVertex2f(1415.86f, 409.57f);
    glVertex2f(1360.02f, 400.17f);
    glEnd();


     glBegin(GL_QUADS);
//for Building-12
   glColor3ub(246,241, 213);
    glVertex2f(1368.36f,531.25f );
    glVertex2f(1385.33f,531.25f);
    glVertex2f(1385.33f, 507.76f);
    glVertex2f(1368.36f, 507.76f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-12
    glColor3ub(246,241, 213);
    glVertex2f(1395.77f,531.25f );
    glVertex2f(1411.0f,531.25f);
    glVertex2f(1411.0f, 507.76f);
    glVertex2f(1395.77f, 507.76f);
    glEnd();

      glBegin(GL_QUADS);
//for Building-12
    glColor3ub(246,241, 213);
    glVertex2f(1368.36f,486.01f );
    glVertex2f(1385.33f,486.01f);
    glVertex2f(1385.33f, 465.12f);
    glVertex2f(1368.36f, 465.12f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-12
    glColor3ub(246,241, 213);
    glVertex2f(1395.77f,486.01f );
    glVertex2f(1411.0f,486.01f);
    glVertex2f(1411.0f, 465.12f);
    glVertex2f(1395.77f, 465.12f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-12
    glColor3ub(246,241, 213);
    glVertex2f(1368.36f,443.8f );
    glVertex2f(1385.33f,443.8f);
    glVertex2f(1385.33f, 424.23f);
    glVertex2f(1368.36f, 424.23f);
    glEnd();

     glBegin(GL_QUADS);
//for Building-12
   glColor3ub(246,241, 213);
    glVertex2f(1395.77f,443.8f );
    glVertex2f(1411.0f,443.8f);
    glVertex2f(1411.0f, 424.23f);
    glVertex2f(1395.77f, 424.23f);
    glEnd();




///////////////////////////////////////////////metro//////////////
  glPushMatrix();
    glTranslatef(trainposition3, trainyposition3, 0.0f);
    glScalef(scaleX3, scaleY3, 1.0f);
    //for metro
     glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(344.99f, 149.11f);
    glVertex2f(357.37f,135.33f);
    glVertex2f(363.74f, 125.41f);
    glVertex2f(369.64f,120.45f);
     glVertex2f(374.84f, 116.67f);
    glVertex2f(382.63f,112.9f);
    glVertex2f(394.67f,109.12f);
    glVertex2f(403.64f,107.23f);
    glVertex2f(414.26f,103.93f);
    glVertex2f(425.83f,103.45f);
     glVertex2f(466.03f,117.92f);
    glEnd();

    glBegin(GL_POLYGON);
//for metro
    glColor3f(1.0,1.0,1.0);
    glVertex2f(491.71f, 244.75f);
    glVertex2f(484.48f,135.33f);
    glVertex2f(480.0f, 240.0f);
    glVertex2f(472.03f,235.51f);
     glVertex2f(466.41f,229.09f);
    glVertex2f(463.6f,219.45f);
    glVertex2f(461.19f,209.41f);
    glVertex2f(460.38f,194.95f);
    glVertex2f(466.03f,117.92f);
    glVertex2f(501.47f,129.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(462.23f,169.75f);
    glVertex2f(343.32f,193.72f);
    glVertex2f(344.99f,149.11f);
    glVertex2f(466.03f,117.92f);
    glEnd();


    glBegin(GL_POLYGON);////
    glColor3ub(220, 220, 220);//Light gray
    glVertex2f(380.02,284.54f);
    glVertex2f(490.22f,254.04f);
    glVertex2f(970.42f,330.43);
    glVertex2f(945.05f,359.94f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.165,0.522,0.31);//green
    glVertex2f(343.32f,255.74f);
    glVertex2f(460.0f,240.0f);
    glVertex2f(462.23f,169.75f);
    glVertex2f(343.32f,193.72f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.165,0.522,0.31);//green
    glVertex2f(343.32f,255.74f);
    glVertex2f(346.63f,264.16f);
    glVertex2f(350.0f,270.0f);
    glVertex2f(357.03f,276.41f);
    glVertex2f(364.27f,280.87f);
    glVertex2f(372.25,283.09f);
    glVertex2f(380.02,284.54f);
    glVertex2f(394.02f,284.54f);
    glVertex2f(408.44f,284.11f);
    glVertex2f(426.41f,282.21f);
    glVertex2f(441.85f,276.86f);
    glVertex2f(451.94f,271.22f);
    glVertex2f(460.85f,263.8f);
    glVertex2f(465.37f,258.06f);
     glVertex2f(468.68f,252.55f);
    glVertex2f(471.39f,248.25f);
    glVertex2f(468.81f,246.83f);
    glVertex2f(465.2f,243.99f);
    glVertex2f(460.0f,240.0f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.165,0.522,0.31);//green
    glVertex2f(490.22f,254.04f);
    glVertex2f(484.23f,253.26f);
    glVertex2f(479.74f,251.33f);
    glVertex2f(474.92f,249.4f);
    glVertex2f(468.81f,246.83f);
    glVertex2f(465.2f,243.99f);
    glVertex2f(460.0f,240.0f);
    glVertex2f(460.19f,213.25f);
    glVertex2f(463.6f,219.45f);
    glVertex2f(466.41f,229.09f);
    glVertex2f(472.03f,235.51f);
    glVertex2f(480.0f,240.0f);
    glVertex2f(484.48f,242.34f);
    glVertex2f(491.71f,244.75f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.867,0.922,0.922);
    glVertex2f(351.68f,251.9f );
    glVertex2f(451.54f,239.88f);
    glVertex2f(451.54f,183.7f);
    glVertex2f(351.68f,203.57f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.165,0.522,0.31);//green
    glVertex2f(490.22f,254.04f );
    glVertex2f(970.42f,330.43f);
    glVertex2f(971.35f,325.19f);
    glVertex2f(491.71f,244.75f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);//Light gray
    glVertex2f(491.71f,244.75f );
    glVertex2f(971.12f,326.19f);
    glVertex2f(971.74f,260.32f);
    glVertex2f(501.47f,129.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(220, 220, 220);//Light gray
    glVertex2f(460.85f,263.8f);
    glVertex2f(465.37f,258.06f);
     glVertex2f(468.68f,252.55f);
    glVertex2f(471.39f,248.25f);
   // glVertex2f(468.81f,246.83f);
    glVertex2f(474.92f,249.4f);
    glVertex2f(479.74f,251.33f);
    glVertex2f(484.23f,253.26f);
    glVertex2f(490.22f,254.04f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.576,0.702,0.443);//Sunset fan
    glVertex2f(580.0f,280.0f);
    glVertex2f(584.65f,295.33f);
    glVertex2f(600.22f,312.77f);
    glVertex2f(700.22f,326.91f);
    glVertex2f(720.86f,316.67f);
    glVertex2f(728.82f,303.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.576,0.702,0.443);//Sunset fan
    glVertex2f(787.83f,312.55f);
    glVertex2f(792.21f,325.85f);
    glVertex2f(808.41f,341.17f);
    glVertex2f(888.84f,352.66f);
    glVertex2f(908.19f,343.37);
    glVertex2f(919.21f,331.94f);
    glEnd();

//Door
    glBegin(GL_QUADS);
   glColor3f(0.58,0.58,0.58);
    glVertex2f(567.23f,248.39f );
    glVertex2f(628.43f,259.52f);
    glVertex2f(632.24f,174.01f);
    glVertex2f(573.67f,158.49f);
    glEnd();

     glBegin(GL_QUADS);
   glColor3f(0.8,0.094,0.094);
    glVertex2f(591.84f,252.87f );
    glVertex2f(595.72f,253.57f);
    glVertex2f(599.96f,165.45f);
    glVertex2f(596.26f,164.47f);
    glEnd();

      glBegin(GL_QUADS);
   glColor3f(0.8,0.094,0.094);
    glVertex2f(599.92f,254.34f );
    glVertex2f(603.72f,255.03f);
    glVertex2f(608.01f,167.59f);
    glVertex2f(604.08f,166.55f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(572.99f,244.15f );
    glVertex2f(588.02f,246.11f);
    glVertex2f(590.73f,204.09f);
    glVertex2f(575.5f,200.75f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(608.19f,249.48f );
    glVertex2f(623.7f,252.54f);
    glVertex2f(625.41f,212.43f);
    glVertex2f(610.07f,208.14f);
    glEnd();

//window
    glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(660.0f,260.0f );
    glVertex2f(725.31f,272.11f);
    glVertex2f(726.0f,236.84f);
    glVertex2f(660.0f,222.84f);
    glEnd();

//door
     glBegin(GL_QUADS);
   glColor3f(0.58,0.58,0.58);
    glVertex2f(752.05f,281.36f );
    glVertex2f(807.86f,290.69f);
    glVertex2f(814.39f,222.76f);
    glVertex2f(758.14f,208.78f);
    glEnd();

      glBegin(GL_QUADS);
   glColor3f(0.8,0.094,0.094);
    glVertex2f(773.83f,285.333f );
    glVertex2f(778.22f,286.07f);
    glVertex2f(784.37f,215.13f);
    glVertex2f(779.99f,215.03f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3f(0.8,0.094,0.094);
    glVertex2f(784.02f,287.04f );
    glVertex2f(787.87f,287.68f);
    glVertex2f(794.63f,218.77f);
    glVertex2f(789.36f,217.43f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(757.1f,277.94f );
    glVertex2f(768.92f,280.35f);
    glVertex2f(771.09f,246.49f);
    glVertex2f(759.58f,242.62f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(792.31f,284.71f );
    glVertex2f(804.44f,285.88f);
    glVertex2f(806.76f,255.44f);
    glVertex2f(794.73f,252.3f);
    glEnd();

//window
        glBegin(GL_QUADS);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(843.89f,294.62f );
    glVertex2f(912.58f,307.2f);
    glVertex2f(913.18f,275.39f);
    glVertex2f(844.08f,262.39f);
    glEnd();
    glPopMatrix();

////////////////////////////////////////////////////////////////////////////////cloud//////



    glPushMatrix();
    glTranslatef(cloudOffsetX, 0.0f, 0.0f);

    int i;

	GLfloat x=138.32f; GLfloat y=616.01f; GLfloat radius =31.6f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}

    glEnd();

    int j;

	GLfloat x1=186.52f; GLfloat y1=616.01; GLfloat radius1 =26.6f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f( x1 + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(j * twicePi1 / triangleAmount1)) );
		}

    glEnd();


    int k;
	GLfloat x2=168.68f; GLfloat y2=648.72; GLfloat radius2 =24.6f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(k = 0; k <= triangleAmount2;k++) {
			glVertex2f( x2 + (radius2 * cos(k *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(k * twicePi2 / triangleAmount2)) );
		}

    glEnd();

     int l;
	GLfloat x3=155.59f; GLfloat y3=640.83; GLfloat radius3 =15.1f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	GLfloat twicePi3 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(l = 0; l <= triangleAmount3;l++) {
			glVertex2f( x3 + (radius3 * cos(l *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(l * twicePi3 / triangleAmount3)) );
		}

    glEnd();

     int m;
	GLfloat x4=107.4f; GLfloat y4=625.74; GLfloat radius4 =25.1f;
	int triangleAmount4 = 100; //# of lines used to draw circle

	GLfloat twicePi4 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4); // center of circle
		for(m = 0; m <= triangleAmount3;m++) {
			glVertex2f( x4 + (radius4 * cos(m *  twicePi4 / triangleAmount4)),
                        y4 + (radius4 * sin(m* twicePi4 / triangleAmount4)) );
		}

    glEnd();


     int n;
	GLfloat x5=360.0f; GLfloat y5=620.0; GLfloat radius5 =25.0f;
	int triangleAmount5 = 100; //# of lines used to draw circle

	GLfloat twicePi5 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5); // center of circle
		for(n = 0; n <= triangleAmount5;n++) {
			glVertex2f( x5+ (radius5 * cos(n *  twicePi5 / triangleAmount5)),
                        y5 + (radius5 * sin(n * twicePi5 / triangleAmount5)) );
		}

    glEnd();

    int p;
	GLfloat x6=404.08f; GLfloat y6=620.0; GLfloat radius6 =25.0f;
	int triangleAmount6 = 100; //# of lines used to draw circle

	GLfloat twicePi6 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6); // center of circle
		for(p = 0; p <= triangleAmount5;p++) {
			glVertex2f( x6+ (radius6 * cos(p *  twicePi6 / triangleAmount6)),
                        y6 + (radius6 * sin(p * twicePi6 / triangleAmount6)) );
		}

    glEnd();



     int q;
	GLfloat x7=451.48f; GLfloat y7=620.0; GLfloat radius7 =25.0f;
	int triangleAmount7 = 100; //# of lines used to draw circle

	GLfloat twicePi7 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7); // center of circle
		for(q = 0; q <= triangleAmount7;q++) {
			glVertex2f( x7+ (radius7 * cos(q *  twicePi7 / triangleAmount7)),
                        y7 + (radius7 * sin(q * twicePi7 / triangleAmount7)) );
		}

    glEnd();

    int r;
	GLfloat x8=381.89f; GLfloat y8=631.39; GLfloat radius8 =30.0f;
	int triangleAmount8 = 100; //# of lines used to draw circle

	GLfloat twicePi8 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(r = 0; r <= triangleAmount8;r++) {
			glVertex2f( x8+ (radius8 * cos(r *  twicePi8 / triangleAmount8)),
                        y8 + (radius8 * sin(r * twicePi8 / triangleAmount8)) );
		}

    glEnd();

     int s;
	GLfloat x9=428.79f; GLfloat y9=631.39; GLfloat radius9 =30.0f;
	int triangleAmount9 = 100; //# of lines used to draw circle

	GLfloat twicePi9 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(s = 0; s <= triangleAmount9;s++) {
			glVertex2f( x9+ (radius9 * cos(s *  twicePi9 / triangleAmount9)),
                        y9 + (radius9 * sin(s * twicePi9 / triangleAmount9)) );
		}

    glEnd();

     int t;
	GLfloat x10=382.42f; GLfloat y10=607.0; GLfloat radius10 =30.0f;
	int triangleAmount10 = 100; //# of lines used to draw circle

	GLfloat twicePi10 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(t = 0; t <= triangleAmount10;t++) {
			glVertex2f( x10+ (radius10 * cos(t *  twicePi10 / triangleAmount10)),
                        y10+ (radius10* sin(t * twicePi10 / triangleAmount10)) );
		}

    glEnd();

       int u;
	GLfloat x11=427.78f; GLfloat y11=608.29; GLfloat radius11 =30.0f;
	int triangleAmount11 = 100; //# of lines used to draw circle

	GLfloat twicePi11 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11); // center of circle
		for(u = 0; u <= triangleAmount11;u++) {
			glVertex2f( x11+ (radius11 * cos(u *  twicePi11 / triangleAmount11)),
                        y11+ (radius11* sin(u * twicePi11 / triangleAmount11)) );
		}

    glEnd();

     int n1;
	GLfloat x12=1033.35f; GLfloat y12=620.0; GLfloat radius12 =25.0f;
	int triangleAmount12 = 100; //# of lines used to draw circle

	GLfloat twicePi12 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x12, y12); // center of circle
		for(n1 = 0; n1 <= triangleAmount5;n1++) {
			glVertex2f( x12+ (radius12 * cos(n1 *  twicePi12 / triangleAmount12)),
                        y12 + (radius12 * sin(n1 * twicePi12 / triangleAmount12)) );
		}

    glEnd();

    int p1;
	GLfloat x13=1076.8f; GLfloat y13=620.0; GLfloat radius13 =25.0f;
	int triangleAmount13 = 100; //# of lines used to draw circle

	GLfloat twicePi13 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x13, y13); // center of circle
		for(p1 = 0; p1 <= triangleAmount13;p1++) {
			glVertex2f( x13+ (radius13 * cos(p1 *  twicePi13 / triangleAmount13)),
                        y13 + (radius13 * sin(p1 * twicePi13 / triangleAmount13)) );
		}

    glEnd();



     int q1;
	GLfloat x14=1119.46f; GLfloat y14=620.0; GLfloat radius14 =25.0f;
	int triangleAmount14 = 100; //# of lines used to draw circle

	GLfloat twicePi14 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x14, y14); // center of circle
		for(q1 = 0; q1 <= triangleAmount14;q1++) {
			glVertex2f( x14+ (radius14 * cos(q1 *  twicePi14 / triangleAmount14)),
                        y14+ (radius14 * sin(q1 * twicePi14 / triangleAmount14)) );
		}

    glEnd();

    int r1;
	GLfloat x15=1055.47f; GLfloat y15=631.39; GLfloat radius15 =30.0f;
	int triangleAmount15 = 100; //# of lines used to draw circle

	GLfloat twicePi15 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x15, y15); // center of circle
		for(r1= 0; r1 <= triangleAmount15;r1++) {
			glVertex2f( x15+ (radius15 * cos(r1 *  twicePi15 / triangleAmount15)),
                        y15 + (radius15 * sin(r1 * twicePi15 / triangleAmount15)) );
		}

    glEnd();

     int s1;
	GLfloat x16=1097.34f; GLfloat y16=631.39; GLfloat radius16 =30.0f;
	int triangleAmount16 = 100; //# of lines used to draw circle

	GLfloat twicePi16 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x16, y16); // center of circle
		for(s1 = 0; s1 <= triangleAmount16;s1++) {
			glVertex2f( x16+ (radius16 * cos(s1 *  twicePi16 / triangleAmount16)),
                        y16 + (radius16 * sin(s1 * twicePi16 / triangleAmount16)) );
		}

    glEnd();

     int t1;
	GLfloat x17=1055.47f; GLfloat y17=607.0; GLfloat radius17 =30.0f;
	int triangleAmount17 = 100; //# of lines used to draw circle

	GLfloat twicePi17 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x17, y17); // center of circle
		for(t1 = 0; t1 <= triangleAmount17;t1++) {
			glVertex2f( x17+ (radius17 * cos(t1 *  twicePi17 / triangleAmount17)),
                        y17+ (radius17* sin(t1 * twicePi17 / triangleAmount17)) );
		}

    glEnd();

       int u1;
	GLfloat x18=1094.34f; GLfloat y18=608.29; GLfloat radius18 =30.0f;
	int triangleAmount18 = 100; //# of lines used to draw circle

	GLfloat twicePi18 = 2.0f * PI;

	glColor3ub(246,246, 246);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x18, y18); // center of circle
		for(u1 = 0; u1 <= triangleAmount18;u1++) {
			glVertex2f( x18+ (radius18 * cos(u1 *  twicePi18 / triangleAmount18)),
                        y18+ (radius18* sin(u1 * twicePi18 / triangleAmount18)) );
		}

    glEnd();


    glPopMatrix();
////////////////////////////////////////////moon///////////////
       int a;

    GLfloat x19 = 1236.34f;
    GLfloat y19 = 646.24f;
    GLfloat radius19 = 30.0f;
    int triangleAmount19 = 100; // Number of lines used to draw the circle

    GLfloat twicePi19 = 2.0f * PI;

    // Set the moon's color based on day or night
    if (isDay) {
       glColor3ub(255, 223, 0); // Soft yellow
 // Golden color for day
    } else if (isNight) {
        glColor3ub(255, 255, 255); // White color for night
    }

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x19, y19); // Center of the circle
        for (a = 0; a <= triangleAmount19; a++) {
            glVertex2f(
                x19 + (radius19 * cos(a * twicePi19 / triangleAmount19)),
                y19 + (radius19 * sin(a * twicePi19 / triangleAmount19))
            );
        }
    glEnd();

    glFlush();
    glutSwapBuffers();
}







void day()
{
    glClearColor(0.471f, 0.816f, 0.941f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

   displayScene3();



    glFlush();


}

void night() {
    glClearColor(0.05f, 0.05f, 0.2f, 1.0f);
  //  glClear(GL_COLOR_BUFFER_BIT);


   displayScene3();



    glFlush();


}


///////////////////////////////////////////1st Scene code/////////////////////////////////////////////
void displayScene1()
{
     glClear (GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
//for ground
    glColor3ub(167,153,137);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(1500.0f,0.0f);
    glVertex2f(1500.0f, 700.0f);
    glVertex2f(0.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for ground yellow-1
    glColor3ub(255,204,0);
	glVertex2f(0.0f, 80.0f);
    glVertex2f(0.0f,120.0f);
    glVertex2f(600.0f, 390.0f);
    glVertex2f(630.0f, 390.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for ground yellow-2
    glColor3ub(255,204,0);
	glVertex2f(330.0f, 390.0f);
    glVertex2f(330.0f,400.0f);
    glVertex2f(800.0f, 400.0f);
    glVertex2f(800.0f, 390.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for upper floar
    glColor3ub(255,255,204);
	glVertex2f(0.0f, 450.0f);
    glVertex2f(0.0f,700.0f);
    glVertex2f(1500.0f, 700.0f);
    glVertex2f(1500.0f, 450.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for attach wall-1
    glColor3ub(204,255,204);
	glVertex2f(0.0f, 400.0f);
    glVertex2f(0.0f,640.0f);
    glVertex2f(620.0f,480.0f);
    glVertex2f(620.0f, 430.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for attach wall-1(door)
    glColor3ub(192,192,192);
	glVertex2f(110.0f, 405.0f);
    glVertex2f(110.0f,520.0f);
    glVertex2f(210.0f,500.0f);
    glVertex2f(210.0f, 410.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for attach wall-2
    glColor3ub(204,255,204);
	glVertex2f(620.0f, 430.0f);
    glVertex2f(620.0f,480.0f);
    glVertex2f(790.0f,490.0f);
    glVertex2f(800.0f, 430.0f);
    glEnd();


     glBegin(GL_POLYGON);
    //for attach wall-3
    glColor3ub(204,255,204);
	glVertex2f(910.0f, 650.0f);
    glVertex2f(1500.0f,700.0f);
    glVertex2f(1500.0f,210.0f);
    glVertex2f(1420.0f, 230.0f);
	glVertex2f(1048.0f, 373.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for upper  second floar-1
    glColor3ub(255,204,153);
	glVertex2f(880.0f, 670.0f);
    glVertex2f(870.0f,700.0f);
    glVertex2f(780.0f,700.0f);
    glVertex2f(780.0f, 670.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for  glass-1
    glColor3ub(128,128,128);
	glVertex2f(1130.0f, 430.0f);
    glVertex2f(1130.0f,550.0f);
    glVertex2f(1500.0f,650.0f);
    glVertex2f(1500.0f, 410.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for  glass-2
    glColor3ub(255,255,255);
	glVertex2f(1140.0f, 440.0f);
    glVertex2f(1140.0f,540.0f);
    glVertex2f(1500.0f,640.0f);
    glVertex2f(1500.0f, 420.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for  glass-3-1
    glColor3ub(128,128,128);
	glVertex2f(1170.0f,560.0f);
    glVertex2f(1170.0f,430.0f);
    glVertex2f(1183.0f,430.0f);
    glVertex2f(1183.0f, 565.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for  glass-3-2
    glColor3ub(128,128,128);
	glVertex2f(1240.0f,580.0f);
    glVertex2f(1253.0f,580.0f);
    glVertex2f(1253.0f,430.0f);
    glVertex2f(1240.0f, 430.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for  glass-3-3
    glColor3ub(128,128,128);
	glVertex2f(1330.0f,605.0f);
    glVertex2f(1345.0f,608.0f);
    glVertex2f(1345.0f,425.0f);
    glVertex2f(1330.0f, 425.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for  glass-3-4
    glColor3ub(128,128,128);
	glVertex2f(1480.0f,645.0f);
    glVertex2f(1495.0f,648.0f);
    glVertex2f(1495.0f,412.0f);
    glVertex2f(1480.0f, 415.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for pilar-1
    glColor3ub(255,255,153);
	glVertex2f(210.0f, 310.0f);
    glVertex2f(170.0f,660.0f);
    glVertex2f(310.0f, 660.0f);
    glVertex2f(350.0f, 310.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for pilar-1
    glColor3ub(255,255,153);
	glVertex2f(350.0f, 310.0f);
    glVertex2f(400.0f,350.0f);
    glVertex2f(370.0f, 640.0f);
    glVertex2f(310.0f, 660.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-2
    glColor3ub(255,255,153);
	glVertex2f(570.0f, 420.0f);
    glVertex2f(630.0f,420.0f);
    glVertex2f(620.0f, 540.0f);
    glVertex2f(560.0f, 540.0f);
    glEnd();




    glBegin(GL_POLYGON);
    //for pilar-3
    glColor3ub(51,51,51);
	glVertex2f(650.0f, 140.0f);
    glVertex2f(750.0f,140.0f);
    glVertex2f(750.0f, 180.0f);
    glVertex2f(650.0f, 180.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3 counter-A
    glColor3ub(51,51,0);
	glVertex2f(660.0f, 440.0f);
    glVertex2f(660.0f, 470.0f);
    glVertex2f(740.0f, 470.0f);
    glVertex2f(740.0f, 440.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for pilar-3 counter
    glColor3ub(150,150,150);
	glVertex2f(663.0f, 443.0f);
    glVertex2f(663.0f, 467.0f);
    glVertex2f(737.0f, 467.0f);
    glVertex2f(737.0f, 443.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3 counter-B
    glColor3ub(51,51,0);
	glVertex2f(681.0f, 443.0f);
    glVertex2f(681.0f,467.0f);
    glVertex2f(684.0f, 467.0f);
    glVertex2f(684.0f, 443.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3 counter-B
    glColor3ub(51,51,0);
	glVertex2f(718.0f, 443.0f);
    glVertex2f(718.0f, 467.0f);
    glVertex2f(715.0f, 467.0f);
    glVertex2f(715.0f, 443.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3
    glColor3ub(0,51,0);
	glVertex2f(695.0f, 160.0f);
    glVertex2f(705.0f,160.0f);
    glVertex2f(705.0f, 700.0f);
    glVertex2f(695.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for silver floar
    glColor3ub(128,128,128);
	glVertex2f(780.0f, 180.0f);
    glVertex2f(780.0f,0.0f);
    glVertex2f(1500.0f,0.0f);
    glVertex2f(1500.0f, 80.0f);
    glVertex2f(1350.0f, 150.0f);
    glVertex2f(1180.0f, 190.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-1
    glColor3ub(51,51,0);
	glVertex2f(870.0f, 180.0f);
    glVertex2f(1180.0f,190.0f);
    glVertex2f(1060.0f, 270.0f);
    glVertex2f(840.0f, 270.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-2
    glColor3ub(0,51,0);
	glVertex2f(840.0f, 270.0f);
    glVertex2f(1060.0f,270.0f);
    glVertex2f(1060.0f, 280.0f);
    glVertex2f(830.0f, 280.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-2
    glColor3ub(51,51,0);
	glVertex2f(840.0f, 280.0f);
    glVertex2f(1060.0f,280.0f);
    glVertex2f(1050.0f, 300.0f);
    glVertex2f(840.0f, 300.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-3
    glColor3ub(0,51,0);
	glVertex2f(840.0f, 300.0f);
    glVertex2f(1050.0f,300.0f);
    glVertex2f(1040.0f, 315.0f);
    glVertex2f(840.0f, 315.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-3
    glColor3ub(51,51,0);
	glVertex2f(840.0f, 315.0f);
    glVertex2f(1040.0f,315.0f);
    glVertex2f(1040.0f, 330.0f);
    glVertex2f(840.0f, 330.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-4
    glColor3ub(0,51,0);
	glVertex2f(840.0f, 330.0f);
    glVertex2f(1040.0f,330.0f);
    glVertex2f(1030.0f, 345.0f);
    glVertex2f(830.0f, 345.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-4
    glColor3ub(51,51,0);
	glVertex2f(830.0f, 345.0f);
    glVertex2f(1030.0f,345.0f);
    glVertex2f(1030.0f, 360.0f);
    glVertex2f(830.0f, 360.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-5
    glColor3ub(0,51,0);
	glVertex2f(830.0f, 360.0f);
    glVertex2f(1030.0f,360.0f);
    glVertex2f(1020.0f, 375.0f);
    glVertex2f(820.0f, 375.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-5
    glColor3ub(51,51,0);
	glVertex2f(820.0f, 375.0f);
    glVertex2f(1020.0f,375.0f);
    glVertex2f(1020.0f, 390.0f);
    glVertex2f(820.0f, 390.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-6
    glColor3ub(0,51,0);
	glVertex2f(820.0f, 390.0f);
    glVertex2f(1020.0f,390.0f);
    glVertex2f(1010.0f, 405.0f);
    glVertex2f(810.0f, 405.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-6
    glColor3ub(51,51,0);
	glVertex2f(810.0f, 405.0f);
    glVertex2f(1010.0f,405.0f);
    glVertex2f(1010.0f, 420.0f);
    glVertex2f(810.0f, 420.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-7
    glColor3ub(0,51,0);
	glVertex2f(810.0f, 420.0f);
    glVertex2f(1010.0f,420.0f);
    glVertex2f(1010.0f, 435.0f);
    glVertex2f(800.0f, 435.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-7
    glColor3ub(51,51,0);
	glVertex2f(800.0f, 435.0f);
    glVertex2f(1010.0f,435.0f);
    glVertex2f(1010.0f, 450.0f);
    glVertex2f(800.0f, 450.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-8
    glColor3ub(0,51,0);
	glVertex2f(800.0f, 450.0f);
    glVertex2f(1010.0f,450.0f);
    glVertex2f(1000.0f, 465.0f);
    glVertex2f(800.0f, 465.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-8
    glColor3ub(51,51,0);
	glVertex2f(800.0f, 465.0f);
    glVertex2f(1000.0f,465.0f);
    glVertex2f(1000.0f, 480.0f);
    glVertex2f(800.0f, 480.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-9
    glColor3ub(0,51,0);
	glVertex2f(800.0f, 480.0f);
    glVertex2f(1000.0f,480.0f);
    glVertex2f(990.0f, 495.0f);
    glVertex2f(790.0f, 495.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-9
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 495.0f);
    glVertex2f(990.0f,495.0f);
    glVertex2f(990.0f, 510.0f);
    glVertex2f(790.0f, 510.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-10
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 510.0f);
    glVertex2f(990.0f,510.0f);
    glVertex2f(970.0f, 524.0f);
    glVertex2f(790.0f, 524.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-10
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 524.0f);
    glVertex2f(970.0f, 524.0f);
    glVertex2f(970.0f, 538.0f);
    glVertex2f(790.0f, 538.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-11
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 538.0f);
    glVertex2f(970.0f, 538.0f);
    glVertex2f(960.0f, 551.0f);
    glVertex2f(790.0f, 551.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-11
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 551.0f);
    glVertex2f(960.0f, 551.0f);
    glVertex2f(960.0f, 564.0f);
    glVertex2f(790.0f, 564.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-12
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 564.0f);
    glVertex2f(960.0f, 564.0f);
    glVertex2f(940.0f, 576.0f);
    glVertex2f(790.0f, 576.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-12
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 576.0f);
    glVertex2f(940.0f, 576.0f);
    glVertex2f(940.0f, 588.0f);
    glVertex2f(790.0f, 588.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-13
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 588.0f);
    glVertex2f(940.0f, 588.0f);
    glVertex2f(930.0f, 599.0f);
    glVertex2f(780.0f, 599.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-13
    glColor3ub(51,51,0);
	glVertex2f(780.0f, 599.0f);
    glVertex2f(930.0f, 599.0f);
    glVertex2f(930.0f, 610.0f);
    glVertex2f(780.0f, 610.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-14
    glColor3ub(0,51,0);
	glVertex2f(780.0f, 610.0f);
    glVertex2f(930.0f, 610.0f);
    glVertex2f(920.0f, 620.0f);
    glVertex2f(780.0f, 620.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-14
    glColor3ub(51,51,0);
	glVertex2f(780.0f, 620.0f);
    glVertex2f(920.0f, 620.0f);
    glVertex2f(920.0f, 630.0f);
    glVertex2f(780.0f, 630.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-15
    glColor3ub(0,51,0);
	glVertex2f(780.0f, 630.0f);
    glVertex2f(920.0f, 630.0f);
    glVertex2f(910.0f, 639.0f);
    glVertex2f(780.0f, 639.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-15
    glColor3ub(51,51,0);
	glVertex2f(780.0f, 639.0f);
    glVertex2f(910.0f, 639.0f);
    glVertex2f(910.0f, 648.0f);
    glVertex2f(780.0f, 648.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-16
    glColor3ub(0,51,0);
	glVertex2f(780.0f, 648.0f);
    glVertex2f(910.0f, 648.0f);
    glVertex2f(900.0f, 656.0f);
    glVertex2f(770.0f, 656.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-16
    glColor3ub(51,51,0);
	glVertex2f(770.0f, 656.0f);
    glVertex2f(900.0f, 656.0f);
    glVertex2f(900.0f, 664.0f);
    glVertex2f(770.0f, 664.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-17
    glColor3ub(0,51,0);
	glVertex2f(770.0f, 664.0f);
    glVertex2f(900.0f, 664.0f);
    glVertex2f(890.0f, 670.0f);
    glVertex2f(770.0f, 670.0f);
    glEnd();


     glBegin(GL_POLYGON);
    //for lift-1 silver-1L
    glColor3ub(192,192,192);
	glVertex2f(780.0f, 180.0f);
    glVertex2f(890.0f,180.0f);
    glVertex2f(860.0f, 330.0f);
    glVertex2f(770.0f, 330.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 silver-2L
    glColor3ub(192,192,192);
	glVertex2f(770.0f, 330.0f);
    glVertex2f(860.0f,330.0f);
    glVertex2f(830.0f, 400.0f);
    glVertex2f(780.0f, 400.0f);
    glEnd();

      glBegin(GL_POLYGON);
    //for lift-1 silver-3L
    glColor3ub(192,192,192);
	glVertex2f(780.0f, 400.0f);
    glVertex2f(830.0f,400.0f);
    glVertex2f(780.0f, 700.0f);
    glVertex2f(760.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-1L
    glColor3ub(0,51,0);
    glVertex2f(850.0f, 330.0f);
    glVertex2f(817.0f, 330.0f);
	glVertex2f(837.0f, 180.0f);
    glVertex2f(870.0f,180.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-2L
    glColor3ub(0,51,0);
	glVertex2f(850.0f, 330.0f);
    glVertex2f(817.0f,330.0f);
    glVertex2f(813.0f, 400.0f);
    glVertex2f(825.0f, 400.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black-3L
    glColor3ub(0,51,0);
	glVertex2f(813.0f, 400.0f);
    glVertex2f(825.0f,400.0f);
    glVertex2f(778.0f, 700.0f);
    glVertex2f(769.0f, 700.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 silver-4R
    glColor3ub(192,192,192);
	glVertex2f(1060.0f, 270.0f);
    glVertex2f(1100.0f,380.0f);
    glVertex2f(870.0f, 700.0f);
    glVertex2f(870.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-4R
    glColor3ub(192,192,192);
	glVertex2f(890.0f, 670.0f);
    glVertex2f(865.0f,670.0f);
    glVertex2f(870.0f, 700.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 silver-5R
    glColor3ub(192,192,192);
	glVertex2f(1060.0f, 270.0f);
    glVertex2f(1180.0f,190.0f);
    glVertex2f(1320.0f, 320.0f);
    glVertex2f(1100.0f, 380.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-6R
    glColor3ub(192,192,192);
	glVertex2f(1180.0f, 190.0f);
    glVertex2f(1250.0f,150.0f);
    glVertex2f(1430.0f, 320.0f);
    glVertex2f(1320.0f, 320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-7R
    glColor3ub(192,192,192);
	glVertex2f(1250.0f, 150.0f);
    glVertex2f(1350.0f,150.0f);
    glVertex2f(1440.0f, 260.0f);
    glVertex2f(1430.0f, 320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-8R
    glColor3ub(192,192,192);
	glVertex2f(1320.0f, 320.0f);
    glVertex2f(1430.0f,320.0f);
    glVertex2f(1140.0f, 390.0f);
    glVertex2f(1100.0f, 380.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-9R
    glColor3ub(192,192,192);
	glVertex2f(1100.0f, 380.0f);
    glVertex2f(1140.0f,390.0f);
    glVertex2f(890.0f, 700.0f);
    glVertex2f(870.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-1R
    glColor3ub(0,51,0);
	glVertex2f(1270.0f, 150.0f);
    glVertex2f(1300.0f,150.0f);
    glVertex2f(1380.0f,260.0f);
    glVertex2f(1350.0f, 260.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-2R
    glColor3ub(0,51,0);
	glVertex2f(1350.0f,260.0f);
    glVertex2f(1380.0f,260.0f);
    glVertex2f(1350.0f,320.0f);
    glVertex2f(1330.0f,320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-3R
    glColor3ub(0,51,0);
	glVertex2f(1330.0f,320.0f);
    glVertex2f(1350.0f,320.0f);
    glVertex2f(1125.0f,382.0f);
    glVertex2f(1110.0f,380.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-2R
    glColor3ub(0,51,0);
	glVertex2f(1125.0f,382.0f);
    glVertex2f(1110.0f,380.0f);
    glVertex2f(875.0f,700.0f);
    glVertex2f(882.0f,700.0f);
    glEnd();



    glBegin(GL_POLYGON);
    //for lift-1 yellow-1
    glColor3ub(255,204,0);
	glVertex2f(830.0f, 670.0f);
    glVertex2f(840.0f,670.0f);
    glVertex2f(970.0f, 270.0f);
    glVertex2f(950.0f, 270.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 yellow-2
    glColor3ub(255,204,0);
	glVertex2f(950.0f, 270.0f);
    glVertex2f(970.0f,270.0f);
    glVertex2f(1075.0f, 150.0f);
    glVertex2f(1040.0f, 160.0f);
    glEnd();

          glBegin(GL_POLYGON);
    //for silver floar-2 yellow hide
    glColor3ub(128,128,128);
	glVertex2f(780.0f, 180.0f);
    glVertex2f(780.0f,0.0f);
    glVertex2f(1180.0f,0.0f);
    glVertex2f(1180.0f,190.0f);
    glEnd();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (liftmanyellowIsVisible)
{

    glPushMatrix();
        glTranslatef(liftmanyellowposition, liftmanyyellowposition, 0.0f);
        glPushMatrix();
        glScalef(liftmanyellowpositionScaleX, liftmanyellowpositionScaleY, 1.0f);

     glBegin(GL_POLYGON);
    //for men-1 g
    glColor3ub(255,255,204);
	glVertex2f(940.0f, 270.0f);
    glVertex2f(940.0f, 280.0f);
    glVertex2f(960.0f,280.0f);
    glVertex2f(960.0f,270.0f);
    glEnd();

    //Men circle
    int i;

	GLfloat x=950.0f; GLfloat y=300.0f; GLfloat radius =25.0f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3ub(0.0f, 51.0f, 102.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-1 s-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f,210.0f);
    glVertex2f(925.0f,210.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-2
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 210.0f);
    glVertex2f(975.0f, 210.0f);
    glVertex2f(975.0f,200.0f);
    glVertex2f(925.0f,200.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 200.0f);
    glVertex2f(950.0f, 200.0f);
    glVertex2f(935.0f,150.0f);
    glVertex2f(925.0f,150.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(51,51,0);
	glVertex2f(925.0f, 150.0f);
    glVertex2f(935.0f, 150.0f);
    glVertex2f(937.0f,145.0f);
    glVertex2f(923.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(204,255,255);
	glVertex2f(950.0f, 200.0f);
    glVertex2f(975.0f, 200.0f);
    glVertex2f(975.0f,150.0f);
    glVertex2f(965.0f,150.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(51,51,0);
	glVertex2f(975.0f, 150.0f);
    glVertex2f(965.0f, 150.0f);
    glVertex2f(963.0f,145.0f);
    glVertex2f(977.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(925.0f, 240.0f);
    glVertex2f(920.0f,215.0f);
    glVertex2f(910.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(920.0f, 215.0f);
    glVertex2f(910.0f, 215.0f);
    glVertex2f(909.0f,210.0f);
    glVertex2f(919.0f,210.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,0);
	glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f, 240.0f);
    glVertex2f(980.0f,215.0f);
    glVertex2f(990.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(980.0f, 215.0f);
    glVertex2f(990.0f, 215.0f);
    glVertex2f(991.0f,210.0f);
    glVertex2f(981.0f,210.0f);
    glEnd();


        glPopMatrix(); // End scaling
        glPopMatrix(); // End translation

}

/////////////////////////////////////////////////////////////////////////////////////////////////

if (liftmanPinkIsVisible) //
{


            glPushMatrix();
        glTranslatef(liftmanPinkposition, liftmanyPinkposition, 0.0f);
        glPushMatrix();
        glScalef(liftmanPinkpositionScaleX, liftmanPinkpositionScaleY, 1.0f);


         glBegin(GL_POLYGON);
    //for men-2 g
    glColor3ub(255,255,204);
	glVertex2f(880.0f, 520.0f);
    glVertex2f(900.0f, 520.0f);
    glVertex2f(900.0f,530.0f);
    glVertex2f(880.0f,530.0f);
    glEnd();

    //Men circle
    int j;

	GLfloat x1=890.0f; GLfloat y1=550.0f; GLfloat radius1 =25.0f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3ub(102.0f, 102.0f, 153.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f( x1 + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(j * twicePi1 / triangleAmount1)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-2 s-1
    glColor3ub(255,128,128);
	glVertex2f(865.0f, 520.0f);
    glVertex2f(915.0f, 520.0f);
    glVertex2f(915.0f, 470.0f);
    glVertex2f(865.0f, 470.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 s-2
   glColor3ub(153,153,255);
	glVertex2f(915.0f, 470.0f);
    glVertex2f(865.0f, 470.0f);
    glVertex2f(865.0f,460.0f);
    glVertex2f(915.0f,460.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 p-1
    glColor3ub(153,153,255);
	glVertex2f(865.0f, 460.0f);
    glVertex2f(890.0f, 460.0f);
    glVertex2f(875.0f,410.0f);
    glVertex2f(865.0f,410.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-2 p-1
    glColor3ub(0,128,128);
	glVertex2f(865.0f, 410.0f);
    glVertex2f(875.0f, 410.0f);
    glVertex2f(877.0f, 405.0f);
    glVertex2f(863.0f, 405.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-2 p-2
    glColor3ub(153,153,255);
	glVertex2f(915.0f, 460.0f);
    glVertex2f(890.0f, 460.0f);
    glVertex2f(905.0f,410.0f);
    glVertex2f(915.0f,410.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 p-2
    glColor3ub(0,128,128);
	glVertex2f(905.0f, 410.0f);
    glVertex2f(915.0f, 410.0f);
    glVertex2f(917.0f, 405.0f);
    glVertex2f(903.0f, 405.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-2 s-1-h-1
    glColor3ub(255,128,128);
	glVertex2f(865.0f, 520.0f);
    glVertex2f(865.0f, 490.0f);
    glVertex2f(860.0f, 470.0f);
    glVertex2f(850.0f, 470.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(850.0f, 470.0f);
    glVertex2f(860.0f, 470.0f);
    glVertex2f(859.0f, 465.0f);
    glVertex2f(849.0f, 465.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-2 s-1-h-2
    glColor3ub(255,128,128);
	glVertex2f(915.0f, 520.0f);
    glVertex2f(915.0f, 490.0f);
    glVertex2f(920.0f, 470.0f);
    glVertex2f(930.0f, 470.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(920.0f, 470.0f);
    glVertex2f(930.0f, 470.0f);
    glVertex2f(931.0f, 465.0f);
    glVertex2f(921.0f, 465.0f);
    glEnd();


        glPopMatrix(); // End scaling
        glPopMatrix(); // End translation

}

  glPushMatrix();
        glTranslatef(liftmanGreenposition, liftmanyGreenposition, 0.0f);
        glPushMatrix();
        glScalef(liftmanGreenpositionScaleX, liftmanGreenpositionScaleY, 1.0f);
         glBegin(GL_POLYGON);
    //for men-3 g
    glColor3ub(255,255,204);
	glVertex2f(460.0f, 420.0f);
    glVertex2f(480.0f, 420.0f);
    glVertex2f(480.0f, 405.0f);
    glVertex2f(460.0f, 405.0f);
    glEnd();

    //Men circle
    int k;

	GLfloat x2=470.0f; GLfloat y2=430.0f; GLfloat radius2 =20.0f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(1.0f, 0.85f, 0.55f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(k = 0; k <= triangleAmount2;k++) {
			glVertex2f( x2 + (radius2 * cos(k *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(k * twicePi2 / triangleAmount2)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-3 s-1
    glColor3ub(0,128,128);
	glVertex2f(450.0f, 405.0f);
    glVertex2f(490.0f, 405.0f);
    glVertex2f(490.0f, 365.0f);
    glVertex2f(450.0f, 365.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 s-2
   glColor3ub(128,0,128);
	glVertex2f(450.0f,365.0f);
    glVertex2f(490.0f,365.0f);
    glVertex2f(490.0f,357.0f);
    glVertex2f(450.0f,357.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 p-1
    glColor3ub(128,0,128);
	glVertex2f(450.0f, 357.0f);
    glVertex2f(470.0f, 357.0f);
    glVertex2f(460.0f, 320.0f);
    glVertex2f(450.0f, 320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-3 p-1
    glColor3ub(0,0,128);
	glVertex2f(460.0f, 320.0f);
    glVertex2f(450.0f, 320.0f);
    glVertex2f(449.0f, 315.0f);
    glVertex2f(461.0f, 315.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-3 p-2
   glColor3ub(128,0,128);
	glVertex2f(490.0f, 357.0f);
    glVertex2f(470.0f, 357.0f);
    glVertex2f(480.0f, 320.0f);
    glVertex2f(490.0f, 320.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 p-2
    glColor3ub(0,0,128);
	glVertex2f(490.0f, 320.0f);
    glVertex2f(480.0f, 320.0f);
    glVertex2f(480.0f, 315.0f);
    glVertex2f(490.0f, 315.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-3 s-1-h-1
    glColor3ub(0,128,128);
	glVertex2f(450.0f, 405.0f);
    glVertex2f(450.0f, 380.0f);
    glVertex2f(445.0f, 365.0f);
    glVertex2f(435.0f, 365.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(445.0f, 365.0f);
    glVertex2f(435.0f, 365.0f);
    glVertex2f(434.0f, 361.0f);
    glVertex2f(444.0f, 361.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-3 s-1-h-2
    glColor3ub(0,128,128);
	glVertex2f(490.0f, 405.0f);
    glVertex2f(490.0f, 380.0f);
    glVertex2f(495.0f, 365.0f);
    glVertex2f(505.0f, 365.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(495.0f, 365.0f);
    glVertex2f(505.0f, 365.0f);
    glVertex2f(506.0f, 361.0f);
    glVertex2f(496.0f, 361.0f);
    glEnd();

    glPopMatrix(); // End scaling
    glPopMatrix(); // End translation



         glBegin(GL_POLYGON);
    //for men-4 g
    glColor3ub(255,255,204);
	glVertex2f(666.0f, 450.0f);
    glVertex2f(674.0f, 450.0f);
    glVertex2f(674.0f, 445.0f);
    glVertex2f(666.0f, 445.0f);
    glEnd();

    //Men circle
    int l;

	GLfloat x3=670.0f; GLfloat y3=455.0f; GLfloat radius3 =8.0f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3ub(204.0f, 255.0f, 255.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(l = 0; l <= triangleAmount3;l++) {
			glVertex2f( x3 + (radius3 * cos(l *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(l * twicePi3 / triangleAmount3)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-4 s-1
    glColor3ub(128,0,0);
	glVertex2f(678.0f, 445.0f);
    glVertex2f(662.0f, 445.0f);
    glVertex2f(662.0f, 430.0f);
    glVertex2f(678.0f, 430.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 s-2
   glColor3ub(0,128,0);
	glVertex2f(662.0f, 430.0f);
    glVertex2f(678.0f, 430.0f);
    glVertex2f(678.0f, 426.0f);
    glVertex2f(662.0f, 426.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 p-1
    glColor3ub(0,128,0);
	glVertex2f(662.0f, 426.0f);
    glVertex2f(670.0f, 426.0f);
    glVertex2f(665.0f, 410.0f);
    glVertex2f(662.0f, 410.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-4 p-1
    glColor3ub(0,0,0);
	glVertex2f(665.0f, 410.0f);
    glVertex2f(662.0f, 410.0f);
    glVertex2f(662.0f, 407.0f);
    glVertex2f(665.0f, 407.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-4 p-2
   glColor3ub(0,128,0);
	glVertex2f(678.0f, 426.0f);
    glVertex2f(670.0f, 426.0f);
    glVertex2f(675.0f, 410.0f);
    glVertex2f(678.0f, 410.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 p-2
    glColor3ub(0,0,0);
	glVertex2f(675.0f, 410.0f);
    glVertex2f(678.0f, 410.0f);
    glVertex2f(678.0f, 407.0f);
    glVertex2f(675.0f, 407.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-4 s-1-h-1
    glColor3ub(128,0,0);
	glVertex2f(662.0f, 445.0f);
    glVertex2f(662.0f, 435.0f);
    glVertex2f(660.0f, 430.0f);
    glVertex2f(656.0f, 430.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(660.0f, 430.0f);
    glVertex2f(656.0f, 430.0f);
    glVertex2f(655.0f, 428.0f);
    glVertex2f(659.0f, 428.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-4 s-1-h-2
    glColor3ub(128,0,0);
	glVertex2f(678.0f, 445.0f);
    glVertex2f(678.0f, 435.0f);
    glVertex2f(680.0f, 430.0f);
    glVertex2f(684.0f, 430.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1Black1
    glColor3ub(1,1,1);
	glVertex2f(520.0f, 535.0f);
    glVertex2f(530.0f, 535.0f);
    glVertex2f(530.0f, 545.0f);
    glVertex2f(520.0f, 545.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1Black2
    glColor3ub(1,1,1);
	glVertex2f(575.0f, 535.0f);
    glVertex2f(585.0f, 535.0f);
    glVertex2f(585.0f, 545.0f);
    glVertex2f(575.0f, 545.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1green
    glColor3ub(0,128,0);
	glVertex2f(420.0f, 500.0f);
    glVertex2f(420.0f, 535.0f);
    glVertex2f(685.0f, 535.0f);
    glVertex2f(685.0f, 500.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1white
    glColor3ub(255,255,255);
	glVertex2f(423.0f, 503.0f);
    glVertex2f(423.0f, 532.0f);
    glVertex2f(682.0f, 532.0f);
    glVertex2f(682.0f, 503.0f);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    renderBitmapString(435.0f, 510.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, " Welcome to Dhaka Metro");


   glFlush ();
   glutSwapBuffers();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
void displayScene5()
{ glClear (GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);
//for ground
    glColor3ub(167,153,137);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(1500.0f,0.0f);
    glVertex2f(1500.0f, 700.0f);
    glVertex2f(0.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for ground yellow-1
    glColor3ub(255,204,0);
	glVertex2f(0.0f, 80.0f);
    glVertex2f(0.0f,120.0f);
    glVertex2f(600.0f, 390.0f);
    glVertex2f(630.0f, 390.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for ground yellow-2
    glColor3ub(255,204,0);
	glVertex2f(330.0f, 390.0f);
    glVertex2f(330.0f,400.0f);
    glVertex2f(800.0f, 400.0f);
    glVertex2f(800.0f, 390.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for upper floar
    glColor3ub(255,255,204);
	glVertex2f(0.0f, 450.0f);
    glVertex2f(0.0f,700.0f);
    glVertex2f(1500.0f, 700.0f);
    glVertex2f(1500.0f, 450.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for attach wall-1
    glColor3ub(204,255,204);
	glVertex2f(0.0f, 400.0f);
    glVertex2f(0.0f,640.0f);
    glVertex2f(620.0f,480.0f);
    glVertex2f(620.0f, 430.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for attach wall-1(door)
    glColor3ub(192,192,192);
	glVertex2f(110.0f, 405.0f);
    glVertex2f(110.0f,520.0f);
    glVertex2f(210.0f,500.0f);
    glVertex2f(210.0f, 410.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for attach wall-2
    glColor3ub(204,255,204);
	glVertex2f(620.0f, 430.0f);
    glVertex2f(620.0f,480.0f);
    glVertex2f(790.0f,490.0f);
    glVertex2f(800.0f, 430.0f);
    glEnd();


     glBegin(GL_POLYGON);
    //for attach wall-3
    glColor3ub(204,255,204);
	glVertex2f(910.0f, 650.0f);
    glVertex2f(1500.0f,700.0f);
    glVertex2f(1500.0f,210.0f);
    glVertex2f(1420.0f, 230.0f);
	glVertex2f(1048.0f, 373.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for upper  second floar-1
    glColor3ub(255,204,153);
	glVertex2f(880.0f, 670.0f);
    glVertex2f(870.0f,700.0f);
    glVertex2f(780.0f,700.0f);
    glVertex2f(780.0f, 670.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for  glass-1
    glColor3ub(128,128,128);
	glVertex2f(1130.0f, 430.0f);
    glVertex2f(1130.0f,550.0f);
    glVertex2f(1500.0f,650.0f);
    glVertex2f(1500.0f, 410.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for  glass-2
    glColor3ub(255,255,255);
	glVertex2f(1140.0f, 440.0f);
    glVertex2f(1140.0f,540.0f);
    glVertex2f(1500.0f,640.0f);
    glVertex2f(1500.0f, 420.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for  glass-3-1
    glColor3ub(128,128,128);
	glVertex2f(1170.0f,560.0f);
    glVertex2f(1170.0f,430.0f);
    glVertex2f(1183.0f,430.0f);
    glVertex2f(1183.0f, 565.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for  glass-3-2
    glColor3ub(128,128,128);
	glVertex2f(1240.0f,580.0f);
    glVertex2f(1253.0f,580.0f);
    glVertex2f(1253.0f,430.0f);
    glVertex2f(1240.0f, 430.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for  glass-3-3
    glColor3ub(128,128,128);
	glVertex2f(1330.0f,605.0f);
    glVertex2f(1345.0f,608.0f);
    glVertex2f(1345.0f,425.0f);
    glVertex2f(1330.0f, 425.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for  glass-3-4
    glColor3ub(128,128,128);
	glVertex2f(1480.0f,645.0f);
    glVertex2f(1495.0f,648.0f);
    glVertex2f(1495.0f,412.0f);
    glVertex2f(1480.0f, 415.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for pilar-1
    glColor3ub(255,255,153);
	glVertex2f(210.0f, 310.0f);
    glVertex2f(170.0f,660.0f);
    glVertex2f(310.0f, 660.0f);
    glVertex2f(350.0f, 310.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for pilar-1
    glColor3ub(255,255,153);
	glVertex2f(350.0f, 310.0f);
    glVertex2f(400.0f,350.0f);
    glVertex2f(370.0f, 640.0f);
    glVertex2f(310.0f, 660.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-2
    glColor3ub(255,255,153);
	glVertex2f(570.0f, 420.0f);
    glVertex2f(630.0f,420.0f);
    glVertex2f(620.0f, 540.0f);
    glVertex2f(560.0f, 540.0f);
    glEnd();




    glBegin(GL_POLYGON);
    //for pilar-3
    glColor3ub(51,51,51);
	glVertex2f(650.0f, 140.0f);
    glVertex2f(750.0f,140.0f);
    glVertex2f(750.0f, 180.0f);
    glVertex2f(650.0f, 180.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3 counter-A
    glColor3ub(51,51,0);
	glVertex2f(660.0f, 440.0f);
    glVertex2f(660.0f, 470.0f);
    glVertex2f(740.0f, 470.0f);
    glVertex2f(740.0f, 440.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for pilar-3 counter
    glColor3ub(150,150,150);
	glVertex2f(663.0f, 443.0f);
    glVertex2f(663.0f, 467.0f);
    glVertex2f(737.0f, 467.0f);
    glVertex2f(737.0f, 443.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3 counter-B
    glColor3ub(51,51,0);
	glVertex2f(681.0f, 443.0f);
    glVertex2f(681.0f,467.0f);
    glVertex2f(684.0f, 467.0f);
    glVertex2f(684.0f, 443.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3 counter-B
    glColor3ub(51,51,0);
	glVertex2f(718.0f, 443.0f);
    glVertex2f(718.0f, 467.0f);
    glVertex2f(715.0f, 467.0f);
    glVertex2f(715.0f, 443.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for pilar-3
    glColor3ub(0,51,0);
	glVertex2f(695.0f, 160.0f);
    glVertex2f(705.0f,160.0f);
    glVertex2f(705.0f, 700.0f);
    glVertex2f(695.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for silver floar
    glColor3ub(128,128,128);
	glVertex2f(780.0f, 180.0f);
    glVertex2f(780.0f,0.0f);
    glVertex2f(1500.0f,0.0f);
    glVertex2f(1500.0f, 80.0f);
    glVertex2f(1350.0f, 150.0f);
    glVertex2f(1180.0f, 190.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-1
    glColor3ub(51,51,0);
	glVertex2f(870.0f, 180.0f);
    glVertex2f(1180.0f,190.0f);
    glVertex2f(1060.0f, 270.0f);
    glVertex2f(840.0f, 270.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-2
    glColor3ub(0,51,0);
	glVertex2f(840.0f, 270.0f);
    glVertex2f(1060.0f,270.0f);
    glVertex2f(1060.0f, 280.0f);
    glVertex2f(830.0f, 280.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-2
    glColor3ub(51,51,0);
	glVertex2f(840.0f, 280.0f);
    glVertex2f(1060.0f,280.0f);
    glVertex2f(1050.0f, 300.0f);
    glVertex2f(840.0f, 300.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-3
    glColor3ub(0,51,0);
	glVertex2f(840.0f, 300.0f);
    glVertex2f(1050.0f,300.0f);
    glVertex2f(1040.0f, 315.0f);
    glVertex2f(840.0f, 315.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-3
    glColor3ub(51,51,0);
	glVertex2f(840.0f, 315.0f);
    glVertex2f(1040.0f,315.0f);
    glVertex2f(1040.0f, 330.0f);
    glVertex2f(840.0f, 330.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-4
    glColor3ub(0,51,0);
	glVertex2f(840.0f, 330.0f);
    glVertex2f(1040.0f,330.0f);
    glVertex2f(1030.0f, 345.0f);
    glVertex2f(830.0f, 345.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-4
    glColor3ub(51,51,0);
	glVertex2f(830.0f, 345.0f);
    glVertex2f(1030.0f,345.0f);
    glVertex2f(1030.0f, 360.0f);
    glVertex2f(830.0f, 360.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-5
    glColor3ub(0,51,0);
	glVertex2f(830.0f, 360.0f);
    glVertex2f(1030.0f,360.0f);
    glVertex2f(1020.0f, 375.0f);
    glVertex2f(820.0f, 375.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-5
    glColor3ub(51,51,0);
	glVertex2f(820.0f, 375.0f);
    glVertex2f(1020.0f,375.0f);
    glVertex2f(1020.0f, 390.0f);
    glVertex2f(820.0f, 390.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-6
    glColor3ub(0,51,0);
	glVertex2f(820.0f, 390.0f);
    glVertex2f(1020.0f,390.0f);
    glVertex2f(1010.0f, 405.0f);
    glVertex2f(810.0f, 405.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-6
    glColor3ub(51,51,0);
	glVertex2f(810.0f, 405.0f);
    glVertex2f(1010.0f,405.0f);
    glVertex2f(1010.0f, 420.0f);
    glVertex2f(810.0f, 420.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-7
    glColor3ub(0,51,0);
	glVertex2f(810.0f, 420.0f);
    glVertex2f(1010.0f,420.0f);
    glVertex2f(1010.0f, 435.0f);
    glVertex2f(800.0f, 435.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-7
    glColor3ub(51,51,0);
	glVertex2f(800.0f, 435.0f);
    glVertex2f(1010.0f,435.0f);
    glVertex2f(1010.0f, 450.0f);
    glVertex2f(800.0f, 450.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-8
    glColor3ub(0,51,0);
	glVertex2f(800.0f, 450.0f);
    glVertex2f(1010.0f,450.0f);
    glVertex2f(1000.0f, 465.0f);
    glVertex2f(800.0f, 465.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-8
    glColor3ub(51,51,0);
	glVertex2f(800.0f, 465.0f);
    glVertex2f(1000.0f,465.0f);
    glVertex2f(1000.0f, 480.0f);
    glVertex2f(800.0f, 480.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-9
    glColor3ub(0,51,0);
	glVertex2f(800.0f, 480.0f);
    glVertex2f(1000.0f,480.0f);
    glVertex2f(990.0f, 495.0f);
    glVertex2f(790.0f, 495.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-9
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 495.0f);
    glVertex2f(990.0f,495.0f);
    glVertex2f(990.0f, 510.0f);
    glVertex2f(790.0f, 510.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-10
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 510.0f);
    glVertex2f(990.0f,510.0f);
    glVertex2f(970.0f, 524.0f);
    glVertex2f(790.0f, 524.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-10
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 524.0f);
    glVertex2f(970.0f, 524.0f);
    glVertex2f(970.0f, 538.0f);
    glVertex2f(790.0f, 538.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-11
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 538.0f);
    glVertex2f(970.0f, 538.0f);
    glVertex2f(960.0f, 551.0f);
    glVertex2f(790.0f, 551.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-11
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 551.0f);
    glVertex2f(960.0f, 551.0f);
    glVertex2f(960.0f, 564.0f);
    glVertex2f(790.0f, 564.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-12
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 564.0f);
    glVertex2f(960.0f, 564.0f);
    glVertex2f(940.0f, 576.0f);
    glVertex2f(790.0f, 576.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-12
    glColor3ub(51,51,0);
	glVertex2f(790.0f, 576.0f);
    glVertex2f(940.0f, 576.0f);
    glVertex2f(940.0f, 588.0f);
    glVertex2f(790.0f, 588.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-13
    glColor3ub(0,51,0);
	glVertex2f(790.0f, 588.0f);
    glVertex2f(940.0f, 588.0f);
    glVertex2f(930.0f, 599.0f);
    glVertex2f(780.0f, 599.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-13
    glColor3ub(51,51,0);
	glVertex2f(780.0f, 599.0f);
    glVertex2f(930.0f, 599.0f);
    glVertex2f(930.0f, 610.0f);
    glVertex2f(780.0f, 610.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-14
    glColor3ub(0,51,0);
	glVertex2f(780.0f, 610.0f);
    glVertex2f(930.0f, 610.0f);
    glVertex2f(920.0f, 620.0f);
    glVertex2f(780.0f, 620.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-14
    glColor3ub(51,51,0);
	glVertex2f(780.0f, 620.0f);
    glVertex2f(920.0f, 620.0f);
    glVertex2f(920.0f, 630.0f);
    glVertex2f(780.0f, 630.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-15
    glColor3ub(0,51,0);
	glVertex2f(780.0f, 630.0f);
    glVertex2f(920.0f, 630.0f);
    glVertex2f(910.0f, 639.0f);
    glVertex2f(780.0f, 639.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-15
    glColor3ub(51,51,0);
	glVertex2f(780.0f, 639.0f);
    glVertex2f(910.0f, 639.0f);
    glVertex2f(910.0f, 648.0f);
    glVertex2f(780.0f, 648.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-16
    glColor3ub(0,51,0);
	glVertex2f(780.0f, 648.0f);
    glVertex2f(910.0f, 648.0f);
    glVertex2f(900.0f, 656.0f);
    glVertex2f(770.0f, 656.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black_s-16
    glColor3ub(51,51,0);
	glVertex2f(770.0f, 656.0f);
    glVertex2f(900.0f, 656.0f);
    glVertex2f(900.0f, 664.0f);
    glVertex2f(770.0f, 664.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black_s-17
    glColor3ub(0,51,0);
	glVertex2f(770.0f, 664.0f);
    glVertex2f(900.0f, 664.0f);
    glVertex2f(890.0f, 670.0f);
    glVertex2f(770.0f, 670.0f);
    glEnd();


     glBegin(GL_POLYGON);
    //for lift-1 silver-1L
    glColor3ub(192,192,192);
	glVertex2f(780.0f, 180.0f);
    glVertex2f(890.0f,180.0f);
    glVertex2f(860.0f, 330.0f);
    glVertex2f(770.0f, 330.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 silver-2L
    glColor3ub(192,192,192);
	glVertex2f(770.0f, 330.0f);
    glVertex2f(860.0f,330.0f);
    glVertex2f(830.0f, 400.0f);
    glVertex2f(780.0f, 400.0f);
    glEnd();

      glBegin(GL_POLYGON);
    //for lift-1 silver-3L
    glColor3ub(192,192,192);
	glVertex2f(780.0f, 400.0f);
    glVertex2f(830.0f,400.0f);
    glVertex2f(780.0f, 700.0f);
    glVertex2f(760.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-1L
    glColor3ub(0,51,0);
    glVertex2f(850.0f, 330.0f);
    glVertex2f(817.0f, 330.0f);
	glVertex2f(837.0f, 180.0f);
    glVertex2f(870.0f,180.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-2L
    glColor3ub(0,51,0);
	glVertex2f(850.0f, 330.0f);
    glVertex2f(817.0f,330.0f);
    glVertex2f(813.0f, 400.0f);
    glVertex2f(825.0f, 400.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 Black-3L
    glColor3ub(0,51,0);
	glVertex2f(813.0f, 400.0f);
    glVertex2f(825.0f,400.0f);
    glVertex2f(778.0f, 700.0f);
    glVertex2f(769.0f, 700.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 silver-4R
    glColor3ub(192,192,192);
	glVertex2f(1060.0f, 270.0f);
    glVertex2f(1100.0f,380.0f);
    glVertex2f(870.0f, 700.0f);
    glVertex2f(870.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-4R
    glColor3ub(192,192,192);
	glVertex2f(890.0f, 670.0f);
    glVertex2f(865.0f,670.0f);
    glVertex2f(870.0f, 700.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for lift-1 silver-5R
    glColor3ub(192,192,192);
	glVertex2f(1060.0f, 270.0f);
    glVertex2f(1180.0f,190.0f);
    glVertex2f(1320.0f, 320.0f);
    glVertex2f(1100.0f, 380.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-6R
    glColor3ub(192,192,192);
	glVertex2f(1180.0f, 190.0f);
    glVertex2f(1250.0f,150.0f);
    glVertex2f(1430.0f, 320.0f);
    glVertex2f(1320.0f, 320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-7R
    glColor3ub(192,192,192);
	glVertex2f(1250.0f, 150.0f);
    glVertex2f(1350.0f,150.0f);
    glVertex2f(1440.0f, 260.0f);
    glVertex2f(1430.0f, 320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-8R
    glColor3ub(192,192,192);
	glVertex2f(1320.0f, 320.0f);
    glVertex2f(1430.0f,320.0f);
    glVertex2f(1140.0f, 390.0f);
    glVertex2f(1100.0f, 380.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 silver-9R
    glColor3ub(192,192,192);
	glVertex2f(1100.0f, 380.0f);
    glVertex2f(1140.0f,390.0f);
    glVertex2f(890.0f, 700.0f);
    glVertex2f(870.0f, 700.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-1R
    glColor3ub(0,51,0);
	glVertex2f(1270.0f, 150.0f);
    glVertex2f(1300.0f,150.0f);
    glVertex2f(1380.0f,260.0f);
    glVertex2f(1350.0f, 260.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-2R
    glColor3ub(0,51,0);
	glVertex2f(1350.0f,260.0f);
    glVertex2f(1380.0f,260.0f);
    glVertex2f(1350.0f,320.0f);
    glVertex2f(1330.0f,320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-3R
    glColor3ub(0,51,0);
	glVertex2f(1330.0f,320.0f);
    glVertex2f(1350.0f,320.0f);
    glVertex2f(1125.0f,382.0f);
    glVertex2f(1110.0f,380.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 Black-2R
    glColor3ub(0,51,0);
	glVertex2f(1125.0f,382.0f);
    glVertex2f(1110.0f,380.0f);
    glVertex2f(875.0f,700.0f);
    glVertex2f(882.0f,700.0f);
    glEnd();



    glBegin(GL_POLYGON);
    //for lift-1 yellow-1
    glColor3ub(255,204,0);
	glVertex2f(830.0f, 670.0f);
    glVertex2f(840.0f,670.0f);
    glVertex2f(970.0f, 270.0f);
    glVertex2f(950.0f, 270.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for lift-1 yellow-2
    glColor3ub(255,204,0);
	glVertex2f(950.0f, 270.0f);
    glVertex2f(970.0f,270.0f);
    glVertex2f(1075.0f, 150.0f);
    glVertex2f(1040.0f, 160.0f);
    glEnd();

          glBegin(GL_POLYGON);
    //for silver floar-2 yellow hide
    glColor3ub(128,128,128);
	glVertex2f(780.0f, 180.0f);
    glVertex2f(780.0f,0.0f);
    glVertex2f(1180.0f,0.0f);
    glVertex2f(1180.0f,190.0f);
    glEnd();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////




            glPushMatrix();
        glTranslatef(liftmanPinkposition5, liftmanyPinkposition5, 0.0f);
        glPushMatrix();
        glScalef(liftmanPinkpositionScaleX5, liftmanPinkpositionScaleY5, 1.0f);


         glBegin(GL_POLYGON);
    //for men-2 g
    glColor3ub(255,255,204);
	glVertex2f(880.0f, 520.0f);
    glVertex2f(900.0f, 520.0f);
    glVertex2f(900.0f,530.0f);
    glVertex2f(880.0f,530.0f);
    glEnd();

    //Men circle
    int j;

	GLfloat x1=890.0f; GLfloat y1=550.0f; GLfloat radius1 =25.0f;
	int triangleAmount1 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glColor3f(1.0f, 0.85f, 0.55f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount1;j++) {
			glVertex2f( x1 + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(j * twicePi1 / triangleAmount1)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-2 s-1
    glColor3ub(255,128,128);
	glVertex2f(865.0f, 520.0f);
    glVertex2f(915.0f, 520.0f);
    glVertex2f(915.0f, 470.0f);
    glVertex2f(865.0f, 470.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 s-2
   glColor3ub(153,153,255);
	glVertex2f(915.0f, 470.0f);
    glVertex2f(865.0f, 470.0f);
    glVertex2f(865.0f,460.0f);
    glVertex2f(915.0f,460.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 p-1
    glColor3ub(153,153,255);
	glVertex2f(865.0f, 460.0f);
    glVertex2f(890.0f, 460.0f);
    glVertex2f(875.0f,410.0f);
    glVertex2f(865.0f,410.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-2 p-1
    glColor3ub(0,128,128);
	glVertex2f(865.0f, 410.0f);
    glVertex2f(875.0f, 410.0f);
    glVertex2f(877.0f, 405.0f);
    glVertex2f(863.0f, 405.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-2 p-2
    glColor3ub(153,153,255);
	glVertex2f(915.0f, 460.0f);
    glVertex2f(890.0f, 460.0f);
    glVertex2f(905.0f,410.0f);
    glVertex2f(915.0f,410.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 p-2
    glColor3ub(0,128,128);
	glVertex2f(905.0f, 410.0f);
    glVertex2f(915.0f, 410.0f);
    glVertex2f(917.0f, 405.0f);
    glVertex2f(903.0f, 405.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-2 s-1-h-1
    glColor3ub(255,128,128);
	glVertex2f(865.0f, 520.0f);
    glVertex2f(865.0f, 490.0f);
    glVertex2f(860.0f, 470.0f);
    glVertex2f(850.0f, 470.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(850.0f, 470.0f);
    glVertex2f(860.0f, 470.0f);
    glVertex2f(859.0f, 465.0f);
    glVertex2f(849.0f, 465.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-2 s-1-h-2
    glColor3ub(255,128,128);
	glVertex2f(915.0f, 520.0f);
    glVertex2f(915.0f, 490.0f);
    glVertex2f(920.0f, 470.0f);
    glVertex2f(930.0f, 470.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-2 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(920.0f, 470.0f);
    glVertex2f(930.0f, 470.0f);
    glVertex2f(931.0f, 465.0f);
    glVertex2f(921.0f, 465.0f);
    glEnd();


        glPopMatrix(); // End scaling
        glPopMatrix(); // End translation

//////////////////////////////////////////////////////////////////////////////////////////////////////////

    glPushMatrix();
        glTranslatef(liftmanyellowposition5, liftmanyyellowposition5, 0.0f);
        glPushMatrix();
        glScalef(liftmanyellowpositionScaleX5, liftmanyellowpositionScaleY5, 1.0f);

     glBegin(GL_POLYGON);
    //for men-1 g
    glColor3ub(255,255,204);
	glVertex2f(940.0f, 270.0f);
    glVertex2f(940.0f, 280.0f);
    glVertex2f(960.0f,280.0f);
    glVertex2f(960.0f,270.0f);
    glEnd();

    //Men circle
    int i;

	GLfloat x=950.0f; GLfloat y=300.0f; GLfloat radius =25.0f;
	int triangleAmount = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3f(1.0f, 0.85f, 0.55f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-1 s-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f,210.0f);
    glVertex2f(925.0f,210.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-2
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 210.0f);
    glVertex2f(975.0f, 210.0f);
    glVertex2f(975.0f,200.0f);
    glVertex2f(925.0f,200.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(204,255,255);
	glVertex2f(925.0f, 200.0f);
    glVertex2f(950.0f, 200.0f);
    glVertex2f(935.0f,150.0f);
    glVertex2f(925.0f,150.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-1
    glColor3ub(51,51,0);
	glVertex2f(925.0f, 150.0f);
    glVertex2f(935.0f, 150.0f);
    glVertex2f(937.0f,145.0f);
    glVertex2f(923.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(204,255,255);
	glVertex2f(950.0f, 200.0f);
    glVertex2f(975.0f, 200.0f);
    glVertex2f(975.0f,150.0f);
    glVertex2f(965.0f,150.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 p-2
    glColor3ub(51,51,0);
	glVertex2f(975.0f, 150.0f);
    glVertex2f(965.0f, 150.0f);
    glVertex2f(963.0f,145.0f);
    glVertex2f(977.0f,145.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,0);
	glVertex2f(925.0f, 270.0f);
    glVertex2f(925.0f, 240.0f);
    glVertex2f(920.0f,215.0f);
    glVertex2f(910.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(920.0f, 215.0f);
    glVertex2f(910.0f, 215.0f);
    glVertex2f(909.0f,210.0f);
    glVertex2f(919.0f,210.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,0);
	glVertex2f(975.0f, 270.0f);
    glVertex2f(975.0f, 240.0f);
    glVertex2f(980.0f,215.0f);
    glVertex2f(990.0f,215.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-1 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(980.0f, 215.0f);
    glVertex2f(990.0f, 215.0f);
    glVertex2f(991.0f,210.0f);
    glVertex2f(981.0f,210.0f);
    glEnd();


        glPopMatrix(); // End scaling
        glPopMatrix(); // End translation





  glPushMatrix();
        glTranslatef(liftmanGreenposition5, liftmanyGreenposition5, 0.0f);
        glPushMatrix();
        glScalef(liftmanGreenpositionScaleX5, liftmanGreenpositionScaleY5, 1.0f);
         glBegin(GL_POLYGON);
    //for men-3 g
    glColor3ub(255,255,204);
	glVertex2f(460.0f, 420.0f);
    glVertex2f(480.0f, 420.0f);
    glVertex2f(480.0f, 405.0f);
    glVertex2f(460.0f, 405.0f);
    glEnd();

    //Men circle
    int k;

	GLfloat x2=470.0f; GLfloat y2=430.0f; GLfloat radius2 =20.0f;
	int triangleAmount2 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glColor3f(1.0f, 0.85f, 0.55f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2); // center of circle
		for(k = 0; k <= triangleAmount2;k++) {
			glVertex2f( x2 + (radius2 * cos(k *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(k * twicePi2 / triangleAmount2)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-3 s-1
    glColor3ub(0,128,128);
	glVertex2f(450.0f, 405.0f);
    glVertex2f(490.0f, 405.0f);
    glVertex2f(490.0f, 365.0f);
    glVertex2f(450.0f, 365.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 s-2
   glColor3ub(128,0,128);
	glVertex2f(450.0f,365.0f);
    glVertex2f(490.0f,365.0f);
    glVertex2f(490.0f,357.0f);
    glVertex2f(450.0f,357.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 p-1
    glColor3ub(128,0,128);
	glVertex2f(450.0f, 357.0f);
    glVertex2f(470.0f, 357.0f);
    glVertex2f(460.0f, 320.0f);
    glVertex2f(450.0f, 320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-3 p-1
    glColor3ub(0,0,128);
	glVertex2f(460.0f, 320.0f);
    glVertex2f(450.0f, 320.0f);
    glVertex2f(449.0f, 315.0f);
    glVertex2f(461.0f, 315.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-3 p-2
   glColor3ub(128,0,128);
	glVertex2f(490.0f, 357.0f);
    glVertex2f(470.0f, 357.0f);
    glVertex2f(480.0f, 320.0f);
    glVertex2f(490.0f, 320.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 p-2
    glColor3ub(0,0,128);
	glVertex2f(490.0f, 320.0f);
    glVertex2f(480.0f, 320.0f);
    glVertex2f(480.0f, 315.0f);
    glVertex2f(490.0f, 315.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-3 s-1-h-1
    glColor3ub(0,128,128);
	glVertex2f(450.0f, 405.0f);
    glVertex2f(450.0f, 380.0f);
    glVertex2f(445.0f, 365.0f);
    glVertex2f(435.0f, 365.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(445.0f, 365.0f);
    glVertex2f(435.0f, 365.0f);
    glVertex2f(434.0f, 361.0f);
    glVertex2f(444.0f, 361.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-3 s-1-h-2
    glColor3ub(0,128,128);
	glVertex2f(490.0f, 405.0f);
    glVertex2f(490.0f, 380.0f);
    glVertex2f(495.0f, 365.0f);
    glVertex2f(505.0f, 365.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-3 s-1-h-2
    glColor3ub(255,255,204);
	glVertex2f(495.0f, 365.0f);
    glVertex2f(505.0f, 365.0f);
    glVertex2f(506.0f, 361.0f);
    glVertex2f(496.0f, 361.0f);
    glEnd();

    glPopMatrix(); // End scaling
    glPopMatrix(); // End translation



         glBegin(GL_POLYGON);
    //for men-4 g
    glColor3ub(255,255,204);
	glVertex2f(666.0f, 450.0f);
    glVertex2f(674.0f, 450.0f);
    glVertex2f(674.0f, 445.0f);
    glVertex2f(666.0f, 445.0f);
    glEnd();

    //Men circle
    int l;

	GLfloat x3=670.0f; GLfloat y3=455.0f; GLfloat radius3 =8.0f;
	int triangleAmount3 = 100; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glColor3ub(204.0f, 255.0f, 255.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3); // center of circle
		for(l = 0; l <= triangleAmount3;l++) {
			glVertex2f( x3 + (radius3 * cos(l *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(l * twicePi3 / triangleAmount3)) );
		}

    glEnd();


    glBegin(GL_POLYGON);
    //for men-4 s-1
    glColor3ub(128,0,0);
	glVertex2f(678.0f, 445.0f);
    glVertex2f(662.0f, 445.0f);
    glVertex2f(662.0f, 430.0f);
    glVertex2f(678.0f, 430.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 s-2
   glColor3ub(0,128,0);
	glVertex2f(662.0f, 430.0f);
    glVertex2f(678.0f, 430.0f);
    glVertex2f(678.0f, 426.0f);
    glVertex2f(662.0f, 426.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 p-1
    glColor3ub(0,128,0);
	glVertex2f(662.0f, 426.0f);
    glVertex2f(670.0f, 426.0f);
    glVertex2f(665.0f, 410.0f);
    glVertex2f(662.0f, 410.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-4 p-1
    glColor3ub(0,0,0);
	glVertex2f(665.0f, 410.0f);
    glVertex2f(662.0f, 410.0f);
    glVertex2f(662.0f, 407.0f);
    glVertex2f(665.0f, 407.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for men-4 p-2
   glColor3ub(0,128,0);
	glVertex2f(678.0f, 426.0f);
    glVertex2f(670.0f, 426.0f);
    glVertex2f(675.0f, 410.0f);
    glVertex2f(678.0f, 410.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 p-2
    glColor3ub(0,0,0);
	glVertex2f(675.0f, 410.0f);
    glVertex2f(678.0f, 410.0f);
    glVertex2f(678.0f, 407.0f);
    glVertex2f(675.0f, 407.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-4 s-1-h-1
    glColor3ub(128,0,0);
	glVertex2f(662.0f, 445.0f);
    glVertex2f(662.0f, 435.0f);
    glVertex2f(660.0f, 430.0f);
    glVertex2f(656.0f, 430.0f);
    glEnd();

     glBegin(GL_POLYGON);
    //for men-4 s-1-h-1
    glColor3ub(255,255,204);
	glVertex2f(660.0f, 430.0f);
    glVertex2f(656.0f, 430.0f);
    glVertex2f(655.0f, 428.0f);
    glVertex2f(659.0f, 428.0f);
    glEnd();


    glBegin(GL_POLYGON);
    //for men-4 s-1-h-2
    glColor3ub(128,0,0);
	glVertex2f(678.0f, 445.0f);
    glVertex2f(678.0f, 435.0f);
    glVertex2f(680.0f, 430.0f);
    glVertex2f(684.0f, 430.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1Black1
    glColor3ub(1,1,1);
	glVertex2f(520.0f, 535.0f);
    glVertex2f(530.0f, 535.0f);
    glVertex2f(530.0f, 545.0f);
    glVertex2f(520.0f, 545.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1Black2
    glColor3ub(1,1,1);
	glVertex2f(575.0f, 535.0f);
    glVertex2f(585.0f, 535.0f);
    glVertex2f(585.0f, 545.0f);
    glVertex2f(575.0f, 545.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1green
    glColor3ub(0,128,0);
	glVertex2f(420.0f, 500.0f);
    glVertex2f(420.0f, 535.0f);
    glVertex2f(685.0f, 535.0f);
    glVertex2f(685.0f, 500.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //for bener-1white
    glColor3ub(255,255,255);
	glVertex2f(423.0f, 503.0f);
    glVertex2f(423.0f, 532.0f);
    glVertex2f(682.0f, 532.0f);
    glVertex2f(682.0f, 503.0f);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    renderBitmapString(435.0f, 510.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, " Welcome to Dhaka Metro");




    glFlush ();
   glutSwapBuffers();
}

void switchToScene0(int value);

void displaySceneCover() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glClear(GL_COLOR_BUFFER_BIT);

    // Title section
    glColor3f(0.0, 0.0, 1.0); // Blue color
    renderBitmapString(500.0f, 650.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh (AIUB)");
    renderBitmapString(580.0f, 620.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Department of Computer Science");
    renderBitmapString(540.0f, 590.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Faculty of Science & Technology (FST)");

    // Project title
    glColor3f(1.0, 0.0, 0.0); // Red color
    renderBitmapString(630.0f, 560.0f, GLUT_BITMAP_TIMES_ROMAN_24, "PROJECT TITLE");
    renderBitmapString(630.0f, 530.0f, GLUT_BITMAP_TIMES_ROMAN_24, "DHAKA METRO RAIL");

    // Semester and section
    glColor3f(0.0, 0.0, 0.0); // Black color
    renderBitmapString(630.0f, 500.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Semester: Fall_24_25");
    renderBitmapString(630.0f, 470.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Section: F");

    // Bold supervisor details
    glColor3f(0.0, 0.0, 0.0); // Black color
    renderBitmapString(630.0f, 440.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Supervised by:");
    renderBitmapString(630.0f, 410.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Mahfujur Rahman");
    renderBitmapString(630.0f, 380.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Assistant professor (AIUB)");

    // Submitted by section
    renderBitmapString(630.0f, 350.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Submission Date: 19th January 2025");
    renderBitmapString(630.0f, 320.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Group No: 3");
    renderBitmapString(630.0f, 290.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Project Submitted By:");


    glColor3f(0.53f, 0.81f, 0.92f);
    glBegin(GL_QUADS);
    glVertex2f(200.0f,240.0);
    glVertex2f(1200.0f, 240.0);
    glVertex2f(1200.0f,  280.0f);
    glVertex2f(200.0f,  280.0f);
    glEnd();

    glColor3f(0.7f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(200.0f,240.0);
     glVertex2f(1200.0f, 240.0);
      glVertex2f(1200.0f, 0.0);
       glVertex2f(200.0f, 0.0);



    glEnd();

    // Table header text
    glColor3f(0.0, 0.0, 0.0); // Black color
    renderBitmapString(240.0f, 250.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Sl");
    renderBitmapString(500.0f, 250.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Student Name");
    renderBitmapString(900.0f, 250.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Student ID");

    // Table content
    float y_offset = 200.0f; // Start below the header
    renderBitmapString(240.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "1");
    renderBitmapString(500.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "Halder, Diamond");
    renderBitmapString(900.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "22-48152-2");

    y_offset -= 40.0f;
    renderBitmapString(240.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "2");
    renderBitmapString(500.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "Farah Mafruha");
    renderBitmapString(900.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "22-48157-2");

    y_offset -= 40.0f;
    renderBitmapString(240.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "3");
    renderBitmapString(500.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "Tahmina Jerin Tinny");
    renderBitmapString(900.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "22-47595-2");

    y_offset -= 40.0f;
    renderBitmapString(240.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "4");
    renderBitmapString(500.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "Bijoy Ahamed");
    renderBitmapString(900.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "22-49373-3");

    y_offset -= 40.0f;
    renderBitmapString(240.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "5");
    renderBitmapString(500.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "Ayon Roy");
    renderBitmapString(900.0f, y_offset, GLUT_BITMAP_TIMES_ROMAN_24, "22-48435-3");

    glFlush();       // Ensure rendering completes
    glutSwapBuffers();
}


void displayScene0() {
       glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(1.0f, 1.0f, 1.0f);  // Set text color to white

    // Instructions from the file
    const char *instructions[] = {
        "Instructions : ",
        "Press->1 To view the first scenario.",
        "Press->2 To view the second scenario.",
        "Press->3 To view the third scenario.",
        "Press->4 To view the fourth scenario.",
        "Press->5 To view the last scenario.",
        "Press-> D/d To view the day view of the 3rd scenario.",
        "Press-> N/n To view the night view of the 3rd scenario.",
        "Press-> Mouse Left Button to view the day view of the 3rd scenario.",
        "Press-> Mouse Right Button to view the night view of the 3rd scenario.",
        "Press->0 To view the instructions."
    };

    // Render each line of instructions
    float startX = 50.0f, startY = 600.0f, lineSpacing = 50.0f; // Text starting position
    for (int i = 0; i < 11; i++) {
        renderBitmapString(startX, startY - i * lineSpacing, GLUT_BITMAP_TIMES_ROMAN_24, instructions[i]);
    }

    glFlush(); // Ensure rendering is complete
    glutSwapBuffers(); // Finish drawing
}

void displaySceneEnd() {
      glClearColor(0.0, 0.0, 1.0, 1.0); // White background
    glClear(GL_COLOR_BUFFER_BIT);

    // Title section
    glColor3f(1.0, 1.0, 1.0); // Blue color
    renderBitmapString(600.0f, 450.0f, GLUT_BITMAP_TIMES_ROMAN_24, "THANKS   EVERYONE");
    renderBitmapString(680.0f, 400.0f, GLUT_BITMAP_TIMES_ROMAN_24, "THE END");




    glFlush();       // Ensure rendering completes
    glutSwapBuffers();
}


void switchToSceneEnd(int value) {
    currentScene = 6; // Assuming 6 corresponds to displaySceneEnd
    glutPostRedisplay(); // Request a redraw
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Set background color based on day/night mode
    if (isDay) {
        glClearColor(0.471f, 0.816f, 0.941f, 1.0f); // Day background
    } else if (isNight) {
        glClearColor(0.05f, 0.05f, 0.2f, 1.0f); // Night background
    }

    // Render the appropriate scene
    if (currentScene == -1) {
        displaySceneCover(); // Display the cover scene
    } else if (currentScene == 0) {
        displayScene0(); // Display Scene 0
    } else if (currentScene == 1) {
        displayScene1(); // Render Scene 1
    } else if (currentScene == 2) {
        displayScene2(); // Render Scene 2
    } else if (currentScene == 3) {
        displayScene3(); // Render Scene 3
    } else if (currentScene == 4) {
        displayScene4(); // Render Scene 4
    } else if (currentScene == 5) {
        displayScene5(); // Render Scene 5
        // Schedule switching to SceneEnd after 10 seconds
        glutTimerFunc(20000, switchToSceneEnd, 0);
    } else if (currentScene == 6) {
        displaySceneEnd(); // Display the end scene
    }

    glFlush();
}


void switchToScene0(int value) {
    currentScene = 0;         // Switch to Scene 0
    glutPostRedisplay();      // Request a redraw
}



// Keyboard function to switch scenes
void keyboard(unsigned char key, int x, int y) {
    if (key == '0') {
        currentScene = 0; // Switch to Scene 0
    } else if (key == '1') {
        currentScene = 1;
    } else if (key == '2') {
        currentScene = 2;
    } else if (key == '3') {
        currentScene = 3;
    } else if (key == '4') {
        currentScene = 4;
    } else if (key == '5') {
        currentScene = 5; // Switch to Scene 5
    } else if (key == 'd' || key == 'D') {
        isDay = true;
        isNight = false;
    } else if (key == 'n' || key == 'N') {
        isDay = false;
        isNight = true;
    }

    //glutPostRedisplay(); // Request redraw
}


void mouseClick(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) { // Check if the mouse button is pressed
        if (button == GLUT_LEFT_BUTTON) {
            isDay = true;
            isNight = false;
        } else if (button == GLUT_RIGHT_BUTTON) {
            isDay = false;
            isNight = true;
        }
    }

    glutPostRedisplay(); // Request a redraw to update the display
}

// Reshape function
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1500.0, 0.0, 700.0); // Viewport size
    glMatrixMode(GL_MODELVIEW);
}

void init (void)
{
//glClear (GL_COLOR_BUFFER_BIT);
glClear(GL_COLOR_BUFFER_BIT);
glClearColor (0.7, 0.7, 0.7, 1.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1500, 0.0, 700.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
    glClear (GL_COLOR_BUFFER_BIT);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (1500, 700);
glutInitWindowPosition (0, 0);
glutCreateWindow ("The Dhaka Metro");
init ();
sound();
  //currentScene = 4;
//glutDisplayFunc(display);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);
      glutMouseFunc(mouseClick); // Register the mouse callback
//0th
 glutTimerFunc(7000, switchToScene0, 0);


//1st
glutTimerFunc(10500, updateliftmanyellow, 0);
glutTimerFunc(10500, updateliftmanPink, 0);
glutTimerFunc(10500, updateliftmanGreen, 0);
//5th
glutTimerFunc(103500, updateliftmanyellow5, 0);
glutTimerFunc(103500, updateliftmanPink5, 0);
glutTimerFunc(103500, updateliftmanGreen5, 0);

//2nd
    glutTimerFunc(22500, update, 0);//for train
 glutTimerFunc(28500, update2, 0);//pass
 glutTimerFunc(28500, update3, 0);//pass
 glutTimerFunc(30500, update4, 0);//door
 glutTimerFunc(30500, update5, 0);//door
glutTimerFunc(29500, update6, 0);//man



//4th
 glutTimerFunc(71000, updatet, 0);//for train4
 glutTimerFunc(79500, updatep1, 0);//pass4
 glutTimerFunc(79500, updatep2, 0);//pass4
 glutTimerFunc(82000, updated1, 0);//door4
 glutTimerFunc(82000, updated2, 0);//door4
 glutTimerFunc(82400, updatem, 0);//man4


     //glutKeyboardFunc(keyboard);
//3rd
    glutTimerFunc(55000, train3update, 0); // Train motion timer
    glutTimerFunc(50000, updateCloud, 0); // Train motion timer
    glutMainLoop();
    return 0;
}
