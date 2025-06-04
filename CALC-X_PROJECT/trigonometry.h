#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

#include <math.h>

// Utility functions for angle conversion
double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);

// Trigonometric functions
double sine(double x, int is_degrees);
double cosine(double x, int is_degrees);
double tangent(double x, int is_degrees, int *error);

// Inverse trigonometric functions
double arcsine(double x, int return_degrees, int *error);
double arccosine(double x, int return_degrees, int *error);
double arctangent(double x, int return_degrees);

#endif // TRIGONOMETRY_H
