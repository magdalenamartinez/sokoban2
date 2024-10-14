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
        //comprobado los simbolos del mapa
        //mapa relleno con buffer
        //memoria reservada y liberada
        //filas y columnas segun filas contadas
        //encontramos posicion del jugador

        //ahora tenemos que poner el raton
        //en la posicion del jugador
        //y hacer que se mueva la P
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

     

     
          
