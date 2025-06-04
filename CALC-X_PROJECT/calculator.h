#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

// Error codes
#define CALC_SUCCESS 0
#define CALC_ERROR_INVALID_INPUT -1
#define CALC_ERROR_DIVISION_BY_ZERO -2
#define CALC_ERROR_DOMAIN -3
#define CALC_ERROR_OVERFLOW -4

// Function prototypes for main calculator operations
void handle_basic_operations(void);
void handle_advanced_operations(void);
void handle_trigonometric_operations(void);

// Utility function prototypes
int get_string_input(char *buffer, size_t size);
int validate_menu_choice(const char *input);
double parse_double(const char *str, int *error);
void print_error(int error_code);
void clear_input_buffer(void);

#endif // CALCULATOR_H
