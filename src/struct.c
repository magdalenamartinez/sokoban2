/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** struct.c
*/

#include "../include/my_sokoban.h"

void fill_struct(char* buffer)
{
    map_t* map = (map_t*) malloc(sizeof(map_t));
    map->rows = 0;
    map->fix_counter = 0;
    map->fix = NULL;
    map->cols = (int*) malloc(sizeof(int));
    map->cols[map->rows] = 0;
    if (map == NULL || map->cols == NULL) {
        exit(EXIT_FAILURE);
    }

    count_colrow(buffer, map);
    fill_map(map, buffer);
    find_player(map);
    start_game(map);
    free_struct(map);
}

void free_struct(map_t* map)
{
    if (map->cols != NULL) {
        free(map->cols);
    }
    
    if (map->fix != NULL) {
        for (int i = 0; i < map->fix_counter && map->fix[i]; i++) {
            if (map->fix[i] != NULL) {
                free(map->fix[i]);
            }
        }
        free(map->fix);
    }
    
    if (map->map != NULL) {
        for (int i = 0; i < map->rows && map->map[i]; i++) {
            if (map->map[i] != NULL) {
                free(map->map[i]);
            }
        }
        free(map->map);
    }

    if (map != NULL) {
        free(map);
    }

}