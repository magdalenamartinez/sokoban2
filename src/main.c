/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** main.c
*/

#include "../include/my_sokoban.h"

int main(int argc, char** argv) 
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1]=='h')
        {
            help_function();
            return EXIT_SUCCESS;
        } 
        char* buffer = open_function(argv[1]);
        if (is_map(buffer) == EXIT_SUCCESS) {
            fill_struct(buffer);
        } else {
            return EXIT_FAILURE;
        }
        //Ya hemos comprobado que el mapa tiene simbolos correctos
        //ahora pasamos al siguiente paso
        //primero rellenamos el mapa con el buffer
        //contamos filas
        //contamos columnas segun cada fila (el mapa no tiene q ser cuadrado)
        //encontramos posicion del jugador
    }
    return EXIT_SUCCESS;
}

void help_function(void)
{
    printf("USAGE\n");
    printf("./my_sokoban map\n");
    printf("DESCRIPTION\n");
    printf("map  file representing the warehouse map, containing ‘#’ for walls,\n");
    printf("‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.\n");
}

     

     
          
