/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** key.c
*/

#include "../include/my_sokoban.h"


void key_pressed(int key, map_t* map)
{
    int new_x = map->p_x;
    int new_y = map->p_y;
    int move = 0;
    switch (key)
    {
        case KEY_UP:
            new_x = map->p_x - 1;
            move = 1;
            break;
        case KEY_DOWN:
            new_x = map->p_x + 1;
            move = 2;
            break;
        case KEY_LEFT:
            new_y = map->p_y - 1;
            move = 3;
            break;
        case KEY_RIGHT:
            new_y = map->p_y + 1;
            move = 4;
            break;
        default:
            return;
    }
    change_key(map, new_x, new_y, move);
}

void change_key(map_t* map, int new_x, int new_y, int move)
{
    switch (map->map[new_x][new_y])
    {
        case ' ':
            move_player(map, new_x, new_y, 0);
            break;
        case 'O':
            move_player(map, new_x, new_y, 1);
            break;
        case 'X':
            move_box(map, new_x, new_y, move);
            break;
    }
}