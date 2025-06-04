#include "basic_ops.h"
#include "calculator.h"
#include "utils.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b, int *error) {
    *error = CALC_SUCCESS;
    if (b == 0.0) {
        *error = CALC_ERROR_DIVISION_BY_ZERO;
        return 0.0;
    }
    return a / b;
}

double modulo(double a, double b, int *error) {
    *error = CALC_SUCCESS;
    if (b == 0.0) {
        *error = CALC_ERROR_DIVISION_BY_ZERO;
        return 0.0;
    }
    return fmod(a, b);
}

void handle_basic_operations(void) {
    char input[100];
    char operator;
    double num1, num2, result;
    int error = CALC_SUCCESS;
    
    printf("\nBasic Operations Calculator\n");
    printf("Available operators: +, -, *, /, %%\n");
    
    // Get first number
    printf("Enter first number: ");
    if (!get_string_input(input, sizeof(input))) {
        printf("Error reading input.\n");
        return;
    }
    
    num1 = parse_double(input, &error);
    if (error != CALC_SUCCESS) {
        print_error(error);
        return;
    }
    
    // Get operator
    printf("Enter operator (+, -, *, /, %%): ");
    if (!get_string_input(input, sizeof(input))) {
        printf("Error reading input.\n");
        return;
    }
    
    if (strlen(input) != 1) {
        printf("Invalid operator. Please enter a single operator.\n");
        return;
    }
    operator = input[0];
    
    // Get second number
    printf("Enter second number: ");
    if (!get_string_input(input, sizeof(input))) {
        printf("Error reading input.\n");
        return;
    }
    
    num2 = parse_double(input, &error);
    if (error != CALC_SUCCESS) {
        print_error(error);
        return;
    }
    
    // Perform calculation
    switch (operator) {
        case '+':
            result = add(num1, num2);
            printf("Result: %.6f + %.6f = %.6f\n", num1, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("Result: %.6f - %.6f = %.6f\n", num1, num2, result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result: %.6f * %.6f = %.6f\n", num1, num2, result);
            break;
        case '/':
            result = divide(num1, num2, &error);
            if (error == CALC_SUCCESS) {
                printf("Result: %.6f / %.6f = %.6f\n", num1, num2, result);
            } else {
                print_error(error);
            }
            break;
        case '%':
            result = modulo(num1, num2, &error);
            if (error == CALC_SUCCESS) {
                printf("Result: %.6f %% %.6f = %.6f\n", num1, num2, result);
            } else {
                print_error(error);
            }
            break;
        default:
            printf("Invalid operator: %c\n", operator);
            printf("Please use one of: +, -, *, /, %%\n");
            break;
    }
}
