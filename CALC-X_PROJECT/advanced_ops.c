#include "advanced_ops.h"
#include "calculator.h"
#include "utils.h"

double power(double base, double exponent, int *error) {
    *error = CALC_SUCCESS;
    
    // Handle special cases
    if (base == 0.0 && exponent < 0.0) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    if (base < 0.0 && exponent != floor(exponent)) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    double result = pow(base, exponent);
    
    // Check for overflow
    if (isinf(result) || isnan(result)) {
        *error = CALC_ERROR_OVERFLOW;
        return 0.0;
    }
    
    return result;
}

double square_root(double x, int *error) {
    *error = CALC_SUCCESS;
    
    if (x < 0.0) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    return sqrt(x);
}

double logarithm_10(double x, int *error) {
    *error = CALC_SUCCESS;
    
    if (x <= 0.0) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    return log10(x);
}

double natural_log(double x, int *error) {
    *error = CALC_SUCCESS;
    
    if (x <= 0.0) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    return log(x);
}

double exponential(double x, int *error) {
    *error = CALC_SUCCESS;
    
    double result = exp(x);
    
    if (isinf(result)) {
        *error = CALC_ERROR_OVERFLOW;
        return 0.0;
    }
    
    return result;
}

void handle_advanced_operations(void) {
    char input[100];
    char operation[20];
    double num, result;
    int error = CALC_SUCCESS;
    
    printf("\nAdvanced Operations Calculator\n");
    printf("Available operations: power, sqrt, log, ln, exp\n");
    
    printf("Enter operation (power/sqrt/log/ln/exp): ");
    if (!get_string_input(operation, sizeof(operation))) {
        printf("Error reading input.\n");
        return;
    }
    
    if (strcmp(operation, "power") == 0) {
        double base, exponent;
        
        printf("Enter base: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        base = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        printf("Enter exponent: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        exponent = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = power(base, exponent, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: %.6f ^ %.6f = %.6f\n", base, exponent, result);
        } else {
            print_error(error);
        }
    }
    else if (strcmp(operation, "sqrt") == 0) {
        printf("Enter number: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = square_root(num, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: sqrt(%.6f) = %.6f\n", num, result);
        } else {
            print_error(error);
        }
    }
    else if (strcmp(operation, "log") == 0) {
        printf("Enter number: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = logarithm_10(num, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: log10(%.6f) = %.6f\n", num, result);
        } else {
            print_error(error);
        }
    }
    else if (strcmp(operation, "ln") == 0) {
        printf("Enter number: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = natural_log(num, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: ln(%.6f) = %.6f\n", num, result);
        } else {
            print_error(error);
        }
    }
    else if (strcmp(operation, "exp") == 0) {
        printf("Enter number: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = exponential(num, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: exp(%.6f) = %.6f\n", num, result);
        } else {
            print_error(error);
        }
    }
    else {
        printf("Invalid operation: %s\n", operation);
        printf("Available operations: power, sqrt, log, ln, exp\n");
    }
}
