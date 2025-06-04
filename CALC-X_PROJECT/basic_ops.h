#ifndef BASIC_OPS_H
#define BASIC_OPS_H

#include <math.h>

// Basic arithmetic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b, int *error);
double modulo(double a, double b, int *error);

#endif // BASIC_OPS_H
