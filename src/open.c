/*
** October 2024
** Magdalena Martinez Sanchez
** sokoban
** open.c
*/
#include "../include/my_sokoban.h"

char* open_function(char* filename)
{
    FILE *fd = fopen(filename, "r");
    if (fd == NULL) {
        exit(EXIT_FAILURE);
    }

    char* final_buffer = read_file(fd);

    fclose(fd);

    return final_buffer;
}

char* read_file(FILE *fd)
{
    ssize_t read;
    size_t len = 0;
    char* buffer = NULL;
    size_t final_buffer_size = BUFFER_SIZE;
    
    char* final_buffer = malloc(final_buffer_size);
    if (final_buffer == NULL) {
        exit(EXIT_FAILURE);
    }
    final_buffer[0] = '\0';

    while ((read = getline(&buffer, &len, fd)) != -1) {
        final_buffer = resize_buffer(final_buffer, &final_buffer_size, buffer);
        if (final_buffer == NULL) {
            free(buffer);
            fclose(fd);
            exit(EXIT_FAILURE);
        }
        strcat(final_buffer, buffer);
    }

    if (buffer) {
        free(buffer);
    }
    return final_buffer;
}

char* resize_buffer(char* final_buffer, size_t* final_buffer_size, char* buffer) 
{
    if (strlen(final_buffer) + strlen(buffer) + 1 > *final_buffer_size) {
            *final_buffer_size += strlen(buffer) + BUFFER_SIZE;
            final_buffer = realloc(final_buffer, *final_buffer_size);
    }
    return final_buffer;
} 
