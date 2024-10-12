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
