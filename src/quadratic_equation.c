#include "quadratic_equation.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static roots_t roots_init(roots_count count)
{
  roots_t result = malloc(sizeof(*result));

  if (!result)
    return NULL; // malloc returned NULL check

  result->roots_count = count;
  if (count == ZERO || count == INF)
  {
    result->roots_values = NULL;
  }
  else
  {
    result->roots_values = malloc(sizeof(double) * count);

    if ((count == ONE || count == TWO) && !result->roots_values)
      return NULL; // malloc returned NULL check
  }

  return result;
}

void roots_free(roots_t roots)
{
  free(
      roots->roots_values); // If roots_values pointer is NULL no action occurs
  free(roots);
}

roots_t solve_equation(double a, double b, double c)
{
  if (a == 0)
  {
    if (b == 0)
      return c == 0 ? roots_init(INF) : roots_init(ZERO);

    roots_t result = roots_init(ONE);
    result->roots_values[0] = -c / b;

    return result;
  }

  double discriminant = b * b - 4 * a * c;

  if (discriminant < 0)
  {
    return roots_init(ZERO);
  }
  else if (discriminant == 0)
  {
    roots_t result = roots_init(ONE);
    result->roots_values[0] = -b / (2 * a);

    return result;
  }
  else
  {
    roots_t result = roots_init(TWO);
    double square_discriminant = sqrt(discriminant);

    result->roots_values[0] = (-b + square_discriminant) / (2 * a);
    result->roots_values[1] = (-b - square_discriminant) / (2 * a);

    return result;
  }
}

bool roots_are_equal(roots_t first, roots_t second)
{
  if (first->roots_count != second->roots_count)
    return false;

  double epsilon =
      0.0001; // Use epsilon delta to compare double precision numbers

  switch (first->roots_count)
  {
  case ZERO:
    return !first->roots_values && !second->roots_values;
  case ONE:
    return fabs(first->roots_values[0] - second->roots_values[0]) < epsilon;
  case TWO:
    return fabs(first->roots_values[0] - second->roots_values[0]) < epsilon &&
           fabs(first->roots_values[1] - second->roots_values[1]) < epsilon;
  case INF:
    return !first->roots_values && !second->roots_values;
  default:
    exit(1);
  }
}

void roots_print(roots_t roots)
{
  switch (roots->roots_count)
  {
  case ZERO:
    printf("No real roots.\n");
    break;
  case ONE:
    printf("Root is: %lf\n", roots->roots_values[0]);
    break;
  case TWO:
    printf("Roots are: %lf and %lf\n", roots->roots_values[0], roots->roots_values[1]);
    break;
  case INF:
    printf("Infinite number of roots.\n");
    break;
  }
}
