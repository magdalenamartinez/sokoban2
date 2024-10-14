/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** ncurses.c
*/

#include "../include/my_sokoban.h"

void init_cursor(void)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

void end_cursor(void)
{
    endwin();
}
