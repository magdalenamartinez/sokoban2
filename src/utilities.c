/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** utilities.c
*/

#include "../include/my_sokoban.h"

int is_symbol(char value)
{
    switch (value)
    {
        case '#':
        case 'P':
        case 'X':
        case 'O':
        case ' ':
        case '\n':
            return EXIT_SUCCESS;
        break;

        default:
            return EXIT_FAILURE;
        break;
    }
    
    return EXIT_SUCCESS;
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