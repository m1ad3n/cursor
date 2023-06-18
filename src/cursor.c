#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "cursor.h"

void clrscr() {
    system("clear");
}

void goto_xy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void goto_x(int x) {
    int y, tmp;

    get_pos(&tmp, &y);
    goto_xy(x, y);
}

void goto_y(int y) {
    int x, tmp;
    
    get_pos(&x, &tmp);
    goto_xy(x, y);
}

int get_pos(int *x, int *y) {

    char buf[30] = {0};
    int ret, i, pow;
    char ch;

    *x = 0; *y = 0;

    struct termios term, restore;

    tcgetattr(0, &term);
    tcgetattr(0, &restore);
    term.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(0, TCSANOW, &term);

    write(1, "\033[6n", 4);

    for( i = 0, ch = 0; ch != 'R'; i++ )
    {
        ret = read(0, &ch, 1);
        if ( !ret ) {
           tcsetattr(0, TCSANOW, &restore);
           return 1;
        }
        buf[i] = ch;
    }

    if (i < 2) {
        tcsetattr(0, TCSANOW, &restore);
        printf("i < 2\n");
        return 1;
    }

    for( i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
        *x = *x + ( buf[i] - '0' ) * pow;

    for( i-- , pow = 1; buf[i] != '['; i--, pow *= 10)
        *y = *y + ( buf[i] - '0' ) * pow;

    tcsetattr(0, TCSANOW, &restore);
    return 0;
}

int get_x(int *x) {
    int y;
    return get_pos(&y, x);
}

int get_y(int *y) {
    int x;
    return get_pos(y, &x);
}