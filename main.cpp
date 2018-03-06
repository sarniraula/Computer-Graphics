#include <iostream>
#include  "GL/freeglut.h"
#include "obj_parser.h"
#include "surface_rendering.h"
#include "light.h"
#include "matrix.h"
#include "camera.h"
#include "transformation.h"
#include "mouse_event.h"
#include "keyboard_event.h"
#include "shadow.h"

using namespace std;

#define WINDOW_X 1200
#define WINDOW_Y 700

using namespace std;

Object table, plate, susan;
Object o[3];
int objects = 3; //specify number of objects in the scene

Vector_3d look_from;
Display r;

Vector_3d lookfrom_point(1,-1,1);
Vector_3d lookat_point(-10,0,0);
Vector_3d lookup_vector(0,1,0);

bool rendering=false; //specify whether an object is rendering or not

Camera cam1(lookfrom_point, lookat_point, lookup_vector);

Light bulb(Vector_3d(120,30,41), Vector_3d(0,0,0), .5);

bool is_first_time = true;
int prev_mouse_X, prev_mouse_Y;

void display(){}

void keyboard_event(unsigned char key,int x,int y);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (WINDOW_X,WINDOW_Y);
    glutInitWindowPosition (90,0);
    glutCreateWindow ("Table Stuff");
    glClearColor (0.7, 0.6, 0.8, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WINDOW_X/2, WINDOW_X/2, -WINDOW_Y/2, WINDOW_Y/2, -WINDOW_X/2, WINDOW_X/2);
//    glOrtho(-WINDOW_X/2, WINDOW_X/2, -WINDOW_Y/2, WINDOW_Y/2, -1, 1);
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(1);

    table.load_obj_file("/home/sandesh/project/graphics/Graphics_final/assets/table_f.obj");
    plate.load_obj_file("/home/sandesh/project/graphics/Graphics_final/assets/plate.obj");
    susan.load_obj_file("/home/sandesh/project/graphics/Graphics_final/assets/monkey.obj");

    table.mtl.color = Color(1,.5,0);
    table.mtl.reflecion_param = 1;
    table.mtl.specular_coeff = 0;
    susan.mtl.color = Color(.8,.8,.8);
    susan.mtl.specular_coeff = 1;
    susan.mtl.reflecion_param = 200;
    plate.mtl.color = Color(.7,.7,.7);


    o[0]=table;
    o[1]=susan;
    o[2]=plate;

    r.clearZbuffer();

    cam1.render(o, 3);

    glEnd();
    glFlush ();
    glutSwapBuffers();
    glutKeyboardFunc(keyboard_event);

    glutMouseFunc(mouse_event);
    glutMotionFunc(motion_event);


    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
