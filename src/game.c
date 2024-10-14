/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** game.c
*/

#include "../include/my_sokoban.h"

void start_game(map_t* map)
{
    int i = 0;
    int key = 0;
    map->on_circle = 0;
    
    init_cursor();
    print_map(map);
    
    while (!finish_game(i)) {
        key = getch();
        key_pressed(key, map);
    }

}

int finish_game(int i)
{
    if (i == 10) {
        return 1;
    }
    return 0;
}