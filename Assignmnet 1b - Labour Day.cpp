/*
===============================================================================
ASSIGNMENT 1B – SECV2213 FUNDAMENTAL OF COMPUTER GRAPHICS
SEMESTER II 2024/2025

STUDENT NAME : ALICE LEE HUI MEE
MATRIC NO    : A23CS0040
SECTION      : 01
LECTURER NAME : TS. DR. GOH EG SU
===============================================================================

DESCRIPTION:
------------
This program creates a simple 2D construction scene with OpenGL for a
Labour Day themed assignment. The scene is built using basic geometric primitives
such as rectangles, triangles, circles, and lines.

The elements included in the scene are:
    1. A wall
    2. A ground with a brick-like pattern
    3. A construction crane with hanging a hook
    4. A builiding with windows and a door
    5. Traffic cones for safety indication
    6. A wooden ladder
    7. Construction worker

*/


#include <GL/glut.h> // Include the GLUT header file for OpenGL functionality
#include <math.h> // Include math.h for trigonometic functions (sin, cos)

//===============================================================================
// Initialization function
//===============================================================================-

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set black background (RGBA)
    glMatrixMode(GL_PROJECTION);      // Set projection matrix mode
    glLoadIdentity();                 // Reset projection matrix
    gluOrtho2D(-400.0, 400.0, -300.0, 300.0); // Set up a two-dimensional orthographic viewing region
}

//===============================================================================
// Background Drawing Functions
//===============================================================================

// ----------------------------------- WALL -----------------------------------
void drawWall() {
    glColor3f(0.97, 0.85, 0.67); //Light orange color

    // Draw wall as a rectangle
    glBegin(GL_QUADS);
    glVertex2f(-400.0, -100.0); // Bottom-left
    glVertex2f(400.0, -100.0);  // Bottom-right
    glVertex2f(400.0, 300.0);   // Top-right
    glVertex2f(-400.0, 300.0);  // Top-left
    glEnd();
}

// ----------------------------------- GROUND -----------------------------------
void drawGround() {
    glColor3f(0.55, 0.27, 0.07); // Dark brown color

    //Draw ground as a rectangle
    glBegin(GL_QUADS);
    glVertex2f(-400.0, -300.0); // Bottom-left
    glVertex2f(400.0, -300.0);  // Bottom-right
    glVertex2f(400.0, -100.0);  // Top-right
    glVertex2f(-400.0, -100.0); // Top-left
    glEnd();
}

// ----------------------------------- BRICK PATTERN ---------------------------------
void drawBricks() {
    glColor3f(0.4, 0.2, 0.05); //Darker brown color
    glLineWidth(2.0); //Set line width

    // Horizontal brick lines
    glBegin(GL_LINES);
    for (int y = -290; y <= -110; y += 30) {
        glVertex2f(-400, y);
        glVertex2f(400.0, y);
        }
    glEnd();

     // Vertical brick lines
    glBegin(GL_LINES);
    for (int x = -400; x <= 400; x += 80) {
        glVertex2f(x, -300.0);  // Start from bottom of ground
        glVertex2f(x, -100.0);  // Go up to the top of the ground
    }
    glEnd();
}

//===============================================================================
// Structure Drawing Functions
//===============================================================================

// ----------------------------------- CRANE ----------------------------------
void drawCrane() {
    // Vertical line (tower)
    glColor3f(0.1, 0.1, 0.1); // Dark gray
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2f(-300.0, -100.0); // Bottom
    glVertex2f(-300.0, 150.0);  // Top
    glEnd();

    // Horizontal line (arm)
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(-380.0, 120.0);  // Left end
    glVertex2f(-200.0, 120.0);  // Right end
    glEnd();

    // Support line
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-300.0, 150.0);  // Top of tower
    glVertex2f(-230.0, 120.0);  // Middle of arm
    glEnd();

    // Hanging line
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex2f(-250.0, 120.0);  // From arm
    glVertex2f(-250.0, 30.0);   // Hanging down
    glEnd();

    // Hook (small rectangle)
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-265.0, 30.0); // Bottom-left
    glVertex2f(-235.0, 30.0); // Bottom-right
    glVertex2f(-235.0, 10.0); // Top-right
    glVertex2f(-265.0, 10.0); // Top-left
    glEnd();
}

// ---------------------------------- BUILDING-----------------------------------
void drawBuilding() {
    // Main building structure (Rectangle)
    glColor3f(0.7, 0.7, 0.7); // Gray color
    glBegin(GL_QUADS);
    glVertex2f(-200.0, -100.0); // Bottom-left
    glVertex2f(-50.0, -100.0);  // Bottom-right
    glVertex2f(-50.0, 100.0);   // Top-right
    glVertex2f(-200.0, 100.0);  // Top-left
    glEnd();
    
    // Door
    glColor3f(0.4, 0.2, 0.1); // Brown color
    glBegin(GL_QUADS);
    glVertex2f(-140.0, -100.0); // Bottom-left
    glVertex2f(-110.0, -100.0); // Bottom-right
    glVertex2f(-110.0, -40.0);  // Top-right
    glVertex2f(-140.0, -40.0);  // Top-left
    glEnd();
    
    // Windows (2 simple squares)
    glColor3f(0.8, 0.9, 1.0); // Light blue color
    
    // Left window
    glBegin(GL_QUADS);
    glVertex2f(-180.0, 0.0);
    glVertex2f(-150.0, 0.0);
    glVertex2f(-150.0, 40.0);
    glVertex2f(-180.0, 40.0);
    glEnd();
    
    // Right window
    glBegin(GL_QUADS);
    glVertex2f(-100.0, 0.0);
    glVertex2f(-70.0, 0.0);
    glVertex2f(-70.0, 40.0);
    glVertex2f(-100.0, 40.0);
    glEnd();
}

// ----------------------------------- TRAFFIC CONE -----------------------------------
void drawTrafficCone(float x, float y) {
    // Cone body (triangle)
    glColor3f(1.0, 0.5, 0.0); // Orange color
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 10.0, y - 35.0); // Bottom left
    glVertex2f(x + 10.0, y - 35.0); // Bottom right
    glVertex2f(x, y);              // Top
    glEnd();

    // White stripes (Two small rectangles)
    glColor3f(1.0, 1.0, 1.0); // White color

    // Bottom stripe
    glBegin(GL_QUADS);
    glVertex2f(x - 8.0, y - 30.0);
    glVertex2f(x + 8.0, y - 30.0);
    glVertex2f(x + 7.0, y - 25.0);
    glVertex2f(x - 7.0, y - 25.0);
    glEnd();

    // Top stripe
    glBegin(GL_QUADS);
    glVertex2f(x - 5.0, y - 15.0);
    glVertex2f(x + 5.0, y - 15.0);
    glVertex2f(x + 4.0, y - 10.0);
    glVertex2f(x - 4.0, y - 10.0);
    glEnd();
}

// ----------------------------------- LADDER -----------------------------------
void drawLadder(float x, float y, float height) {
    // Vertical rails
    glColor3f(0.9, 0.6, 0.2); // Brown color
    glLineWidth(3.0);

    // Left rail
    glBegin(GL_LINES);
    glVertex2f(x - 10.0, y);
    glVertex2f(x - 10.0, y + height);
    glEnd();

    // Right rail
    glBegin(GL_LINES);
    glVertex2f(x + 10.0, y);
    glVertex2f(x + 10.0, y + height);
    glEnd();

    // Rungs
    for (int i = 0; i < height / 15; i++) {
        glBegin(GL_LINES);
        glVertex2f(x - 10.0, y + (i * 15) + 7.5);
        glVertex2f(x + 10.0, y + (i * 15) + 7.5);
        glEnd();
    }
}

// ---------------------------------- CONSTRUCTION WORKER -----------------------------------
void drawWorker(float x, float y) {
    // Head with helmet
    glColor3f(1.0, 0.7, 0.0); // Yellow color

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y + 22.0); // Center point
    for (int i = 0; i <= 360; i += 30) {
        float angle = i * 3.14159 / 180.0;
        glVertex2f(x + 12.0 * cos(angle), (y + 22.0) + 12.0 * sin(angle));
    }
    glEnd();

    // Body (rectangle)
    glColor3f(0.0, 0.0, 0.7); // Dark blue color
    glBegin(GL_QUADS);
    glVertex2f(x - 10.0, y + 10.0);
    glVertex2f(x + 10.0, y + 10.0);
    glVertex2f(x + 10.0, y - 20.0);
    glVertex2f(x - 10.0, y - 20.0);
    glEnd();

    // Vest (line)
    glColor3f(1.0, 0.5, 0.0); // Orange color
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(x - 10.0, y);
    glVertex2f(x + 10.0, y);
    glEnd();

    // Arms (lines)
    glColor3f(0.0, 0.0, 0.7); // Dark blue color
    glLineWidth(4.0);
    glBegin(GL_LINES);

    // Left arm
    glVertex2f(x - 10.0, y);
    glVertex2f(x - 20.0, y - 10.0);

    // Right arm
    glVertex2f(x + 10.0, y);
    glVertex2f(x + 20.0, y - 10.0);
    glEnd();

    // Legs (lines)
    glLineWidth(4.0);
    glBegin(GL_LINES);

    // Left leg
    glVertex2f(x - 6.0, y - 20.0);
    glVertex2f(x - 6.0, y - 45.0);

    // Right leg
    glVertex2f(x + 6.0, y - 20.0);
    glVertex2f(x + 6.0, y - 45.0);
    glEnd();
}

// ---------------------------------- TEXT -----------------------------------
void displayText(float x, float y, const char* text, void* font = GLUT_BITMAP_HELVETICA_18) {
    glColor3f(1.0, 1.0, 1.0); // White color
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(font, *text);
        ++text;
    }
}

//===============================================================================
// Main Display Fnction - draws the entire scene
//===============================================================================

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Call all the functions to draw objects
    drawWall();
    drawGround();
    drawBricks();
    drawCrane();
    drawBuilding();

    drawTrafficCone(-350.0, -65.0);
    drawTrafficCone(-100.0, -65.0);
    drawTrafficCone(-60.0, -65.0);
    drawTrafficCone(150.0, -65.0);
    drawTrafficCone(380.0, -65.0);

    drawLadder(120.0, -100.0, 170.0);

    drawWorker(-200.0, -55.0);
    drawWorker(300.0,-55.0);
    drawWorker(200.0,-55.0);
    drawWorker(60.0,-55.0);
 

    displayText(-190.0, 200.0, "HAPPY INTERNATIONAL LABOUR DAY!");

    glFlush(); // Update window
}

//===============================================================================
// Main Function -initializes window and enters main loop
//===============================================================================

int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode - Single buffer, RGB color
    glutInitWindowSize(800, 600);                 // Set window size - (width, height)
    glutInitWindowPosition(0, 0);                 // Set window position on screen
    glutCreateWindow("Construction Scene - Labour Day Theme");       // Window title

    init();                                       // Call initialization function
    glutDisplayFunc(display);                     // Register display callback
    glutMainLoop();                               // Enter GLUT event loop

    return 0;
}