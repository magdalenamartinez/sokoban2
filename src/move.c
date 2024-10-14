/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** move.c
*/

#include "../include/my_sokoban.h"


void move_player(map_t* map, int new_x, int new_y, int is_circle)
{
    if (map->on_circle) {
        map->map[map->p_x][map->p_y] = 'O';
    } else {
        map->map[map->p_x][map->p_y] = ' ';
    }
    map->p_x = new_x;
    map->p_y = new_y;
    map->map[new_x][new_y] = 'P';
    print_map(map);
    map->on_circle = is_circle;
}

void move_box(map_t* map, int new_x, int new_y, int move)
{
    int next_x = new_x;
    int next_y = new_y;
    get_next(&next_x, &next_y, move);
 
    if (!find_fix(new_x, new_y, map) && (map->map[next_x][next_y] == ' ' || map->map[next_x][next_y] == 'O')) {
        if (map->map[next_x][next_y] == 'O') {
            add_fix(next_x, next_y, map);
        }
        map->map[next_x][next_y] = 'X';
        map->map[new_x][new_y] = 'P';
        player_on_circle(map);
        map->p_x = new_x;
        map->p_y = new_y;
        print_map(map);
    } 
}

void get_next(int *next_x, int *next_y, int move)
{
    switch (move)
    {
       case 1:
        (*next_x)--;
        break;
       case 2:
        (*next_x)++;
        break;
       case 3:
        (*next_y)--;
        break;
       case 4:
        (*next_y)++;
        break; 
    }
}

