/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** map.c
*/

#include "../include/my_sokoban.h"

int is_map(char* buffer) 
{
    int i = 0;

    if (buffer == NULL || buffer[0] == '\0') {
        return EXIT_FAILURE;
    }

    while (buffer[i] != '\0') {
        if (is_symbol(buffer[i++]) == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

void fill_map(map_t* map, char* buffer)
{
    int i = 0;
    int j = 0;
    int n = 0;
    map->map = (char**) malloc(sizeof(char*) * map->rows);    
    if (map->map == NULL) {
        free_struct(map);
        exit(EXIT_FAILURE);
    }
    
    while (i < map->rows) {
        map->map[i] = malloc(sizeof(char) * (map->cols[i] + 1));
        if (map->map[i] == NULL) {
            free_struct(map);
            exit(EXIT_FAILURE);
        }
        for (j = 0; j < map->cols[i]; j++) {
            map->map[i][j] = buffer[n++];
        }
        map->map[i][j] = '\0';
        i++;
    }
    
    for (i = 0; i < map->rows; i++) {
        for (j = 0; j < map->cols[i]; j++) {
            printf("%c", map->map[i][j]);
        }
    }
}