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
        int on_circle;
        int** fix;
        int fix_counter;
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
    void print_map(map_t* map);
    void find_player(map_t* map);    
    void init_cursor(void);
    void end_cursor(void);
    void start_game(map_t* map);
    int finish_game(int i);
    void key_pressed(int key, map_t* map);
    void move_player(map_t* map, int new_x, int new_y, int is_circle);
    void change_key(map_t* map, int new_x, int new_y, int move);
    void move_box(map_t* map, int new_x, int new_y, int move);
    void player_on_circle(map_t* map);
    void get_next(int *next_x, int *next_y, int move);
    void add_fix(int next_x, int next_y, map_t* map);
    int find_fix(int next_x, int next_y, map_t* map);
#endif /*MY_SOKOBAN_H_*/