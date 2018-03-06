#include "keyboard_event.h"
#include  "GL/freeglut.h"
#include "surface_rendering.h"
#include "matrix.h"
#include "vector.h"
#include "transformation.h"

extern Display r;
extern Camera cam1;
extern Object o[3];

int win_x = 1200;
int win_y = 700;

void keyboard_event(unsigned char key,int x,int y)
{

    glClear(GL_COLOR_BUFFER_BIT);
    r.clearZbuffer();

    switch(key)
    {
    case 'a':
    {
        Matrix roty = rotate_yaxis(5);
        for (int i=0; i<3; i++)
        {
            for(unsigned int j=0; j<o[i].total_face; j++)
            {
                o[i].vertices[j].position = roty*o[i].vertices[j].position;
            }
        }
        cam1.render(o, 3);

        break;
    }

    case 'd':
    {
        Matrix roty = rotate_yaxis(-5);
        for (int i=0; i<3; i++)
        {
            for(unsigned int j=0;j<o[i].total_face;j++)
            {
                o[i].vertices[j].position = roty*o[i].vertices[j].position;
            }
        }
        cam1.render(o, 3);
        break;
    }
    case 'w':
    {
        Matrix rotx = rotate_xaxis(5);
        for (int i=0; i<3; i++)
        {
            for(unsigned int j=0; j<o[i].total_face; j++)
            {
                o[i].vertices[j].position = rotx*o[i].vertices[j].position;
            }
        }
        cam1.render(o, 3);
        break;
    }

    case 's':
    {
        Matrix rotx = rotate_xaxis(-5);
        for (int i=0; i<3; i++)
        {
            for(unsigned int j=0; j<o[i].total_face; j++)
            {
                o[i].vertices[j].position = rotx*o[i].vertices[j].position;
            }
        }
        cam1.render(o, 3);
        break;
    }

    default:
        cam1.render(o, 3);
        break;
    }

    glFlush();
    glutSwapBuffers();
}
