#ifndef MATRIX_TEST_HELPERS_H
#define MATRIX_TEST_HELPERS_H

/* Matrix_test_helpers.h
 * Project UID af1f95f547e44c8ea88730dfb185559d
 * Originally written by James Juett at the University of Michigan
 * for project 3 in EECS 280, Winter 2016.
 */

#include "Matrix.h"

// REQUIRES: mat1 points to a valid Matrix
//           mat2 points to a valid Matrix
// EFFECTS:  Returns true if mat1 and mat2 are the same size and
//           contain exactly the same elements. Returns false otherwise.
bool Matrix_equal(const Matrix* mat1, const Matrix* mat2);

// REQUIRES: arr1 and arr2 point to arrays of length n
// EFFECTS:  Returns true if the arrays pointed to by arr1 and arr2
//           contain exactly the same elements. Returns false otherwise.
bool array_equal(const int arr1[], const int arr2[], int n);

#endif // MATRIX_TEST_HELPERS_H
