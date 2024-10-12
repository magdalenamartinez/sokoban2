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
    map->cols = (int*) malloc(sizeof(int));
    map->cols[map->rows] = 0;
    if (map == NULL || map->cols == NULL) {
        exit(EXIT_FAILURE);
    }
    //contar filas y columnas
    count_colrow(buffer, map);
    //rellenar el mapa ahora
    fill_map(map, buffer);
    
    free_struct(map);
}

void count_colrow(char* buffer, map_t* map)
{
    int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i++] == '\n') {
            map->rows++;
            resize_cols(map);
        } else {
            map->cols[map->rows]++;
        }
    }
}

void resize_cols(map_t* map)
{
    int *temp = realloc(map->cols, (map->rows + 1) * sizeof(int));
    if (temp == NULL) {
        free_struct(map);
        exit(EXIT_FAILURE);
    }
    map->cols = temp;
    map->cols[map->rows] = 0;
}

void free_struct(map_t* map)
{
    if (map->cols != NULL) {
        free(map->cols);
    }
    
    if (map->map != NULL) {
        for (int i = 0; i < map->rows; i++) {
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