#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

extern bool is_first_time;
extern int prev_mouse_X, prev_mouse_Y;

void mouse_event(int button, int state, int x, int y);
void motion_event (int x, int y);


#endif // MOUSE_EVENT_H
