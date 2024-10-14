/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** player.c
*/

#include "../include/my_sokoban.h"

void find_player(map_t* map)
{
    int found = 0, i = 0;
    map->p_x = 0, map->p_y = 0;

    if (map == NULL || map->map == NULL) {
        free_struct(map);
        exit(EXIT_FAILURE);
    }

    while (i < map->rows  && !found) {
        if (map->map[i] == NULL) {
            free_struct(map);
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < map->cols[i]; j++) {
            if (map->map[i][j] == 'P') {
                found = 1;
                map->p_x = i;
                map->p_y = j;
            }
        }
        i++;
    }
        
    if (!found) {
        free_struct(map);
        exit(EXIT_FAILURE);
    }
}

//SI YA SE PONE X SOBRE CIRCULO NO SE PUEDE VOLVER A MOVER
//SI TOCA ESQUINA ES DECIR UP Y LEFT // UP Y RIGHT // DOWN Y LEFT // DOWN Y RIGHT
//ENTONCES ESA X YA NO SE PUEDE VOLVER A MOVER
//CREAR UNA LISTA CON POSICIONES INAMOVIBLES DE X
//CIRCULOS RESTANTES
//SI NO SE PUEDE MOVER NINGUNA X O BIEN NO QUEDAN CIRCULOS SE ACABA EL JUEGO
 
void player_on_circle(map_t* map)
{
    if (map->on_circle) {
        map->map[map->p_x][map->p_y] = 'O';
    } else {
        map->map[map->p_x][map->p_y] = ' ';
    }
    map->on_circle = 0;
}