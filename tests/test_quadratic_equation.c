#include "minunit.h"
#include "quadratic_equation.h"

MU_TEST(test_solve_two_roots) {
  roots_t actual = solve_equation(1, -3, 2);
  double expected_values[] = {2.0, 1.0};
  struct roots expected = {.roots_count = TWO, .roots_values = expected_values};

  mu_check(roots_are_equal(actual, &expected));
  roots_free(actual);
}

MU_TEST(test_solve_one_root) {
  roots_t actual = solve_equation(1, -2, 1);
  double expected_values = 1.0;
  struct roots expected = {.roots_count = ONE,
                           .roots_values = &expected_values};

  mu_check(roots_are_equal(actual, &expected));
  roots_free(actual);
}

MU_TEST(test_solve_no_roots) {
  roots_t actual = solve_equation(1, 0, 1);  // x^2 + 1 = 0
  struct roots expected = {.roots_count = ZERO, .roots_values = NULL};

  mu_check(roots_are_equal(actual, &expected));
  roots_free(actual);
}

MU_TEST(test_solve_infinite_roots) {
  roots_t actual = solve_equation(0, 0, 0);
  struct roots expected = {.roots_count = INF, .roots_values = NULL};

  mu_check(roots_are_equal(actual, &expected));
  roots_free(actual);
}

MU_TEST(test_solve_linear_equation) {
  roots_t actual =
      solve_equation(0, 1, -5);  // Linear equation 0*x^2 + x - 5 = 0
  double expected_values = 5.0;
  struct roots expected = {.roots_count = ONE,
                           .roots_values = &expected_values};

  mu_check(roots_are_equal(actual, &expected));
  roots_free(actual);
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_solve_two_roots);
  MU_RUN_TEST(test_solve_one_root);
  MU_RUN_TEST(test_solve_no_roots);
  MU_RUN_TEST(test_solve_infinite_roots);
  MU_RUN_TEST(test_solve_linear_equation);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  roots_t roots = solve_equation(2, -4, 2);
  roots_print(roots);
  return MU_EXIT_CODE;
}
