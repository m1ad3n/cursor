#ifndef __CURSOR_H
#define __CURSOR_H

void clrscr();

void goto_xy(int x, int y);
void goto_x(int x);
void goto_y(int y);

int get_pos(int *x, int *y);
int get_x(int *x);
int get_y(int *y);

#endif