/*
** June 2024
** Magdalena Martinez Sanchez
** my_sokoban
** my_sokoban.h
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_
    #include <stdio.h>
    #include <ncurses.h>    
    #include <string.h>    
    #include <stdlib.h>    
    #define BUFFER_SIZE 1024
    typedef struct map {
        char** map;
        int rows;
        int* cols;
        int p_x;
        int p_y;
    } map_t;
    void help_function(void);
    char* open_function(char* file);
    int is_map(char* buffer);
    int is_symbol(char value);
    char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer);
    char* read_file(FILE *fd);
    void count_colrow(char* buffer, map_t* map);
    void fill_struct(char* buffer);
    void resize_cols(map_t* map);
    void free_struct(map_t* map);
    void fill_map(map_t* map, char* buffer);
#endif /*MY_SOKOBAN_H_*/