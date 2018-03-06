#include "mouse_event.h"
#include  "GL/freeglut.h"
#include "surface_rendering.h"
#include "matrix.h"
#include "vector.h"
#include "transformation.h"

extern Display r;
extern Camera cam1;
extern Object o[3];

void mouse_event(int button, int state, int x, int y)
{
    glClear(GL_COLOR_BUFFER_BIT);
    r.clearZbuffer();
    // Wheel reports as button 3(scroll up) and button 4(scroll down)
       if (button == 3) // It's a wheel event
       {
           // Each wheel event reports like a button click, GLUT_DOWN then GLUT_UP
           if (state == GLUT_UP) return; // Disregard redundant GLUT_UP events
           Matrix scl = scale(Vector_3d(1.5,1.5,1.5));

           for (int i=0; i<3; i++)
           {
               for(unsigned int j=0; j<o[i].total_face; j++)
               {
                   o[i].vertices[j].position = scl*o[i].vertices[j].position;
               }
           }
           cam1.render(o, 3);

       }
       else if (button == 4)
       {
           // Each wheel event reports like a button click, GLUT_DOWN then GLUT_UP
           Matrix scl = scale(Vector_3d(.5,.5,.5));
           for (int i=0; i<3; i++)
           {
               for(unsigned int j=0; j<o[i].total_face; j++)
               {
                   o[i].vertices[j].position = scl*o[i].vertices[j].position;
               }
           }
           cam1.render(o, 3);

       }
       else if (button == 1)
       {

       }
       else
       {
           cam1.render(o, 3);
       }
       glFlush();
       glutSwapBuffers();
}

void motion_event (int x, int y)
{
    glClear(GL_COLOR_BUFFER_BIT);
    r.clearZbuffer();
    if (is_first_time) {
          is_first_time = false;
          prev_mouse_X = x;
          prev_mouse_Y = y;
          return;
      }
      GLfloat deltaX = prev_mouse_X - x;
      GLfloat deltaY = prev_mouse_Y - y;

      if ( deltaX > 1.0f )
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

      }
      if ( deltaX <  -1.0f )
      {
          Matrix roty = rotate_yaxis(-5);
          for (int i=0; i<3; i++)
          {
              for(unsigned int j=0; j<o[i].total_face; j++)
              {
                  o[i].vertices[j].position = roty*o[i].vertices[j].position;
              }
          }
          cam1.render(o, 3);
      }
      if ( deltaY > 1.0f )
      {
          Matrix rotz = rotate_zaxis(-5);
          for (int i=0; i<3; i++)
          {
              for(unsigned int j=0; j<o[i].total_face; j++)
              {
                  o[i].vertices[j].position = rotz*o[i].vertices[j].position;
              }
          }
          cam1.render(o, 3);
      }

      if ( deltaY < -1.0f )
      {
          Matrix rotz = rotate_zaxis(5);
          for (int i=0; i<3; i++)
          {
              for(unsigned int j=0; j<o[i].total_face; j++)
              {
                  o[i].vertices[j].position = rotz*o[i].vertices[j].position;
              }
          }
          cam1.render(o, 3);
      }

      prev_mouse_X = x;
      prev_mouse_Y = y;
      glFlush();
//      glutSwapBuffers();
}
