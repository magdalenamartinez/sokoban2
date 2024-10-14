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
    int i = 0, j = 0, n = 0;
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
        for (j = 0; j < map->cols[i] + 1; j++) {
            map->map[i][j] = buffer[n++];
        }
        map->map[i][j] = '\0';
        i++;
    }
}

void print_map(map_t* map)
{
    clear();
    for (int i = 0; i < map->rows; i++) {
        mvprintw(i, 0, "%s", map->map[i]); // Imprime cada línea del mapa en la terminal
    }
    refresh();
}