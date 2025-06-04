#include "trigonometry.h"
#include "calculator.h"
#include "utils.h"

#define PI 3.14159265358979323846

double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
}

double radians_to_degrees(double radians) {
    return radians * 180.0 / PI;
}

double sine(double x, int is_degrees) {
    if (is_degrees) {
        x = degrees_to_radians(x);
    }
    return sin(x);
}

double cosine(double x, int is_degrees) {
    if (is_degrees) {
        x = degrees_to_radians(x);
    }
    return cos(x);
}

double tangent(double x, int is_degrees, int *error) {
    *error = CALC_SUCCESS;
    
    if (is_degrees) {
        x = degrees_to_radians(x);
    }
    
    // Check for values where tangent is undefined (cos(x) = 0)
    double cos_x = cos(x);
    if (fabs(cos_x) < 1e-15) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    return tan(x);
}

double arcsine(double x, int return_degrees, int *error) {
    *error = CALC_SUCCESS;
    
    if (x < -1.0 || x > 1.0) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    double result = asin(x);
    if (return_degrees) {
        result = radians_to_degrees(result);
    }
    
    return result;
}

double arccosine(double x, int return_degrees, int *error) {
    *error = CALC_SUCCESS;
    
    if (x < -1.0 || x > 1.0) {
        *error = CALC_ERROR_DOMAIN;
        return 0.0;
    }
    
    double result = acos(x);
    if (return_degrees) {
        result = radians_to_degrees(result);
    }
    
    return result;
}

double arctangent(double x, int return_degrees) {
    double result = atan(x);
    if (return_degrees) {
        result = radians_to_degrees(result);
    }
    
    return result;
}

void handle_trigonometric_operations(void) {
    char input[100];
    char operation[20];
    char unit_choice[10];
    double num, result;
    int error = CALC_SUCCESS;
    int use_degrees = 1;
    
    printf("\nTrigonometric Functions Calculator\n");
    printf("Available functions: sin, cos, tan, asin, acos, atan\n");
    
    printf("Enter function (sin/cos/tan/asin/acos/atan): ");
    if (!get_string_input(operation, sizeof(operation))) {
        printf("Error reading input.\n");
        return;
    }
    
    // For inverse functions, ask about output unit
    if (strcmp(operation, "asin") == 0 || strcmp(operation, "acos") == 0 || strcmp(operation, "atan") == 0) {
        printf("Return result in degrees or radians? (d/r): ");
        if (!get_string_input(unit_choice, sizeof(unit_choice))) {
            printf("Error reading input.\n");
            return;
        }
        use_degrees = (unit_choice[0] == 'd' || unit_choice[0] == 'D');
    } else {
        // For regular trig functions, ask about input unit
        printf("Input angle in degrees or radians? (d/r): ");
        if (!get_string_input(unit_choice, sizeof(unit_choice))) {
            printf("Error reading input.\n");
            return;
        }
        use_degrees = (unit_choice[0] == 'd' || unit_choice[0] == 'D');
    }
    
    if (strcmp(operation, "sin") == 0) {
        printf("Enter angle: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = sine(num, use_degrees);
        printf("Result: sin(%.6f%s) = %.6f\n", num, use_degrees ? "°" : " rad", result);
    }
    else if (strcmp(operation, "cos") == 0) {
        printf("Enter angle: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = cosine(num, use_degrees);
        printf("Result: cos(%.6f%s) = %.6f\n", num, use_degrees ? "°" : " rad", result);
    }
    else if (strcmp(operation, "tan") == 0) {
        printf("Enter angle: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = tangent(num, use_degrees, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: tan(%.6f%s) = %.6f\n", num, use_degrees ? "°" : " rad", result);
        } else {
            print_error(error);
        }
    }
    else if (strcmp(operation, "asin") == 0) {
        printf("Enter value (-1 to 1): ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = arcsine(num, use_degrees, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: asin(%.6f) = %.6f%s\n", num, result, use_degrees ? "°" : " rad");
        } else {
            print_error(error);
        }
    }
    else if (strcmp(operation, "acos") == 0) {
        printf("Enter value (-1 to 1): ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = arccosine(num, use_degrees, &error);
        if (error == CALC_SUCCESS) {
            printf("Result: acos(%.6f) = %.6f%s\n", num, result, use_degrees ? "°" : " rad");
        } else {
            print_error(error);
        }
    }
    else if (strcmp(operation, "atan") == 0) {
        printf("Enter value: ");
        if (!get_string_input(input, sizeof(input))) {
            printf("Error reading input.\n");
            return;
        }
        num = parse_double(input, &error);
        if (error != CALC_SUCCESS) {
            print_error(error);
            return;
        }
        
        result = arctangent(num, use_degrees);
        printf("Result: atan(%.6f) = %.6f%s\n", num, result, use_degrees ? "°" : " rad");
    }
    else {
        printf("Invalid function: %s\n", operation);
        printf("Available functions: sin, cos, tan, asin, acos, atan\n");
    }
}
