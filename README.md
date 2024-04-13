# QuadraticEq
C module for solving quadratic equations

## Main Features

- `solve_equation`: Solves the quadratic equation given coefficients a, b, and c. Returns a pointer to a structure containing the roots and their count (zero, one, two, or infinite solutions).
- `roots_are_equal`: Checks whether the given roots structure are equal.
- `roots_print`: Prints the given roots.

## Building

To build the QuadraticEq, follow these steps:

1. Clone the repository:

```
git clone https://github.com/PolinaSavelyeva/QuadraticEq.git
```

2. Navigate to the QuadraticEq directory:

```
cd QuadraticEq
```

3. Build the module using CMake:

```
cmake .
make
```

## Build Requirements

- CMake (version 3.10 or higher)
- A C compiler supporting the C99 standard (e.g., GCC, Clang)
- Optionally, valgrind for memory leak checks if tests are included

## Usage

After building the project, you can use the executable to test the functionality or include the library in other projects to utilize the quadratic equation solving capabilities.

### Test

To test builded project use commands as follows:

```
make test
```
    
or

```
make check
```

### Example

Suppose you have a quadratic equation `2x^2 - 4x + 2 = 0`. The following code solve it and prints the result:

```c
#include "quadratic_equation.h"

int main() {
    roots_t roots = solve_equation(2, -4, 2);
    roots_print(roots);
    roots_free(roots);

    return 0;
}
```
