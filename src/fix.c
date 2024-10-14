/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** fix.c
*/

#include "../include/my_sokoban.h"

int find_fix(int next_x, int next_y, map_t* map)
{
    int i = 0;
    if (map->fix_counter != 0) {
        while (i < map->fix_counter) {
            if (map->fix[i][0] == next_x && map->fix[i][1] == next_y) {
                return 1;
            }
            i++;
        }
    }
    return 0;
}

void add_fix(int next_x, int next_y, map_t* map)
{
    int** aux = realloc(map->fix, (map->fix_counter + 1) * sizeof(int*));
    if (aux == NULL) {
        free_struct(map);
        exit(EXIT_FAILURE);
    } 
    map->fix = aux;

    map->fix[map->fix_counter] = malloc(sizeof(int) * 2);
    if (map->fix[map->fix_counter] == NULL) {
        free_struct(map);
        exit(EXIT_FAILURE);
    }
    map->fix[map->fix_counter][0] = next_x;
    map->fix[map->fix_counter][1] = next_y;

    map->fix_counter++;
}
