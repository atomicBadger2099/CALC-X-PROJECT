#include "utils.h"
#include "calculator.h"

int get_string_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        return 0;  // Error reading input
    }
    
    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    
    return 1;  // Success
}

int validate_menu_choice(const char *input) {
    char *endptr;
    long choice = strtol(input, &endptr, 10);
    
    // Check if conversion was successful and entire string was consumed
    if (*endptr != '\0' || endptr == input) {
        return -1;  // Invalid input
    }
    
    // Check if choice is in valid range
    if (choice < 1 || choice > 4) {
        return -1;  // Out of range
    }
    
    return (int)choice;
}

double parse_double(const char *str, int *error) {
    *error = CALC_SUCCESS;
    char *endptr;
    
    // Clear errno before conversion
    errno = 0;
    
    double result = strtod(str, &endptr);
    
    // Check for conversion errors
    if (endptr == str || *endptr != '\0') {
        *error = CALC_ERROR_INVALID_INPUT;
        return 0.0;
    }
    
    // Check for overflow/underflow
    if (errno == ERANGE) {
        if (result == HUGE_VAL || result == -HUGE_VAL) {
            *error = CALC_ERROR_OVERFLOW;
        } else {
            *error = CALC_ERROR_INVALID_INPUT;
        }
        return 0.0;
    }
    
    return result;
}

void print_error(int error_code) {
    switch (error_code) {
        case CALC_ERROR_INVALID_INPUT:
            printf("Error: Invalid input. Please enter a valid number.\n");
            break;
        case CALC_ERROR_DIVISION_BY_ZERO:
            printf("Error: Division by zero is not allowed.\n");
            break;
        case CALC_ERROR_DOMAIN:
            printf("Error: Input is outside the valid domain for this operation.\n");
            break;
        case CALC_ERROR_OVERFLOW:
            printf("Error: Result is too large to represent (overflow).\n");
            break;
        default:
            printf("Error: Unknown error occurred.\n");
            break;
    }
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Clear the input buffer
    }
}
