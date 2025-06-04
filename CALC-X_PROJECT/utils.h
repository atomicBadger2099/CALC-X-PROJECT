#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Input/output utility functions
int get_string_input(char *buffer, size_t size);
int validate_menu_choice(const char *input);
double parse_double(const char *str, int *error);
void print_error(int error_code);
void clear_input_buffer(void);

#endif // UTILS_H
