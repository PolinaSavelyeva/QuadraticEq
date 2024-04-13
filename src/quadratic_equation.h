#pragma once
#include <stdbool.h>

// Stores number of roots of the quadratic equation
// INF states for infinite count of roots
typedef enum { ZERO = 0, ONE, TWO, INF} roots_count;

// Stores roots of the quadratic equation
struct roots {
  double *roots_values;
  roots_count roots_count;
};

// Defines pointer to a roots structure
typedef struct roots *roots_t;

// Frees the memory allocated for roots structure and its associated root values
void roots_free(roots_t roots);

// Solves a quadratic equation given coefficients a, b, and c
roots_t solve_equation(double a, double b, double c);

// Checks whether roots structures are equal
bool roots_are_equal(roots_t first, roots_t second);

// Prints the given roots
void roots_print(roots_t roots);
