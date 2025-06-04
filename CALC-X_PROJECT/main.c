#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "calculator.h"
#include "basic_ops.h"
#include "advanced_ops.h"
#include "trigonometry.h"
#include "utils.h"

void print_usage(const char* program_name) {
    printf("Usage: %s [OPTIONS]\n", program_name);
    printf("Options:\n");
    printf("  -h, --help     Show this help message\n");
    printf("  -v, --version  Show version information\n");
    printf("  -d, --debug    Enable debug mode\n");
}

void print_version(void) {
    printf("Enhanced Calculator v1.0\n");
    printf("Compiled with GNU C99 standard\n");
}

void print_welcome(void) {
    printf("\n");
    printf("========================================\n");
    printf("    Enhanced Calculator v1.0\n");
    printf("    GNU C99 Compliant Implementation\n");
    printf("========================================\n");
}

void show_menu(void) {
    printf("\nAvailable Operations:\n");
    printf("1. Basic Operations (+, -, *, /, %%)\n");
    printf("2. Advanced Operations (^, sqrt, log, ln)\n");
    printf("3. Trigonometric Functions (sin, cos, tan)\n");
    printf("4. Exit\n");
}

int main(int argc, char *argv[]) {
    int opt;
    int debug_mode = 0;
    
    // Command line argument parsing
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"debug", no_argument, 0, 'd'},
        {0, 0, 0, 0}
    };
    
    while ((opt = getopt_long(argc, argv, "hvd", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                print_usage(argv[0]);
                return EXIT_SUCCESS;
            case 'v':
                print_version();
                return EXIT_SUCCESS;
            case 'd':
                debug_mode = 1;
                break;
            default:
                print_usage(argv[0]);
                return EXIT_FAILURE;
        }
    }
    
    if (debug_mode) {
        printf("Debug mode enabled\n");
    }
    
    print_welcome();
    
    int continue_calc = 1;
    char choice[10];
    
    while (continue_calc) {
        show_menu();
        printf("\nSelect operation type (1-4): ");
        
        if (!get_string_input(choice, sizeof(choice))) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
        
        int operation = validate_menu_choice(choice);
        if (operation == -1) {
            printf("Invalid choice. Please select 1-4.\n");
            continue;
        }
        
        switch (operation) {
            case 1:
                handle_basic_operations();
                break;
            case 2:
                handle_advanced_operations();
                break;
            case 3:
                handle_trigonometric_operations();
                break;
            case 4:
                printf("\nThank you for using Enhanced Calculator. Goodbye!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid operation selected.\n");
                continue;
        }
        
        // Ask if user wants to continue
        printf("\nWould you like to perform another calculation? (y/n): ");
        if (!get_string_input(choice, sizeof(choice))) {
            printf("Error reading input. Exiting...\n");
            break;
        }
        
        if (choice[0] != 'y' && choice[0] != 'Y') {
            printf("\nCalculation session ended by user choice. Goodbye!\n");
            continue_calc = 0;
        }
    }
    
    return EXIT_SUCCESS;
}
