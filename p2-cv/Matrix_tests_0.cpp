// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// Create a 1x1 Matrix with a value and checks
// that Matrix_width returns the width of the Matrix
// that Matrix_height returns the height of the Matrix
// Matrix_print prints the width and height for the Matrix
TEST(test_init_basic) {
    Matrix *mat = new Matrix;
    
    int width = 1;
    int height = 1;
    int value = 20;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    
    ASSERT_EQUAL(Matrix_width(mat), width);
    ASSERT_EQUAL(Matrix_height(mat), height);

    delete mat;
}

// Create a 20x26 Matrix with a value and checks
// that Matrix_width returns the width of the Matrix
// that Matrix_height returns the height of the Matrix
// Matrix_print prints the width and height for the Matrix
TEST(test_init_basic_large) {
    Matrix *mat = new Matrix;
    
    int width = 20;
    int height = 26;
    int value = 31;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    
    ASSERT_EQUAL(Matrix_width(mat), width);
    ASSERT_EQUAL(Matrix_height(mat), height);

    delete mat;
}

// Create a 3x6 Matrix with same values,
// makes ptr points to one element, and checks whether
// Matrix_row and Matrix_column returns the row and column of the
// element pointed to by ptr
TEST(test_matrix_row_and_column) {
    Matrix *mat = new Matrix;
    
    const int width = 3;
    const int height = 6;
    int value = 1000;
    int change_value = 208;

    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *(Matrix_at(mat, 5, 2)) = change_value;
    int *ptr = Matrix_at(mat, 5, 2);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 5);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 2);
    
    delete mat;
}

// Create a 2x2 Matrix with same values,
// makes ptr points to one elemennt, and checks whether
// Matrix_row and Matrix_column returns the row and column of the
// element pointed to by ptr
TEST(test_matrix_row_and_column_edge_2) {
    Matrix *mat = new Matrix;
    
    const int width = 2;
    const int height = 2;
    int value = 0;

    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    int *ptr = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 0);
    
    delete mat;
}

// Create a 5x5 Matrix with same values,
// makes ptr points to one elemennt, and checks whether
// Matrix_row and Matrix_column returns the row and column of the
// element pointed to by ptr
TEST(test_matrix_row_and_column_edge_3) {
    Matrix *mat = new Matrix;
    
    const int width = 5;
    const int height = 5;
    int value = 2;

    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    int *ptr = Matrix_at(mat, 3, 4);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 3);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 4);
    
    delete mat;
}

// Create a 1x1 Matrix with same values,
// makes ptr points to one elemennt, and checks whether
// Matrix_row and Matrix_column returns the row and column of the
// element pointed to by ptr
TEST(test_matrix_row_and_column_edge_4) {
    Matrix *mat = new Matrix;
    
    const int width = 1;
    const int height = 1;
    int value = 25;

    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    int *ptr = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 0);
    
    delete mat;
}

// Create a 28x40 Matrix with same values,
// makes ptr points to one elemennt, and checks whether
// Matrix_row and Matrix_column returns the row and column of the
// element pointed to by ptr
TEST(test_matrix_row_and_column_edge_5) {
    Matrix *mat = new Matrix;
    
    const int width = 28;
    const int height = 40;
    int value = 5;

    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    int *ptr = Matrix_at(mat, 30, 27);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 30);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 27);
    
    delete mat;
}

// Create a 2x3 Matrix with different values, print out
// the information of the Matrix
TEST(test_matrix_print) {
    Matrix *mat = new Matrix;
    
    const int width = 2;
    const int height = 3;
    
    Matrix_init(mat, width, height);
    *(Matrix_at(mat, 0, 0)) = 12;
    *(Matrix_at(mat, 0, 1)) = 16;
    *(Matrix_at(mat, 1, 0)) = 62;
    *(Matrix_at(mat, 1, 1)) = 89;
    *(Matrix_at(mat, 2, 0)) = 3;
    *(Matrix_at(mat, 2, 1)) = 0;
    
    ostringstream expected;
    expected << "2 3\n"
             << "12 16 \n"
             << "62 89 \n"
             << "3 0 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());
    
    delete mat;
}


// Create a 6x10 Matrix with a value, changes
// the element on the 3rd row and 4th column to another
// value, and checks whether int* Matrix_at returns value
// for the element
TEST(test_matrix_at) {
    Matrix *mat = new Matrix;
    
    const int width = 6;
    const int height = 10;
    int value = 1;
    int change_value = 4;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *(Matrix_at(mat, 9, 5)) = change_value;
    ASSERT_EQUAL(*(Matrix_at(mat, 9, 5)), change_value);
    
    delete mat;
}

// Create a 5x8 Matrix with a value, changes
// the element on the 1st row and 1st column to another
// value, and checks whether int* Matrix_at returns value
// for the element
TEST(test_matrix_at_edge_case_1) {
    Matrix *mat = new Matrix;
    
    const int width = 5;
    const int height = 8;
    int value = 3;
    int change_value = 79;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *(Matrix_at(mat, 0, 0)) = change_value;
    ASSERT_EQUAL(*(Matrix_at(mat, 0, 0)), change_value);
    
    delete mat;
}

// Create a 1x1 Matrix with a value, changes
// the element on the last row and last column to another
// value, and checks whether int* Matrix_at returns value
// for the element
TEST(test_matrix_at_edge_case_2) {
    Matrix *mat = new Matrix;
    
    const int width = 1;
    const int height = 1;
    int value = 9;
    int change_value = 56;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *(Matrix_at(mat, 0, 0)) = change_value;
    ASSERT_EQUAL(*(Matrix_at(mat, 0, 0)), change_value);
    
    delete mat;
}

// Create a 3x3 Matrix with a value, changes
// the element on the last row and last column to another
// value, and checks whether int* Matrix_at returns value
// for the element
TEST(test_matrix_at_edge_case_3) {
    Matrix *mat = new Matrix;
    
    const int width = 3;
    const int height = 14;
    int value = 19;
    int change_value = 23;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *(Matrix_at(mat, 13, 2)) = change_value;
    ASSERT_EQUAL(*(Matrix_at(mat, 13, 2)), change_value);
    
    delete mat;
}

// Create a 2x2 Matrix with a value and checks whether
// Matrix_fill_border fills the border of matrix with another value
TEST(test_matrix_fill_border) {
    Matrix *mat = new Matrix;
    
    const int width = 2;
    const int height = 2;
    int value = 70;
    int border_value = 1;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    Matrix_fill_border(mat, border_value);
    

    Matrix *mat_test = new Matrix;
    Matrix_init(mat_test, width, height);
    Matrix_fill(mat_test, border_value);
    
    ASSERT_TRUE(Matrix_equal(mat, mat_test));
    
    delete mat;
    delete mat_test;
}

// Create a 1x1 Matrix with a value and checks whether
// Matrix_fill_border fills the border of matrix with another value
TEST(test_matrix_fill_border_edge_case_1) {
    Matrix *mat = new Matrix;
    
    const int width = 1;
    const int height = 1;
    int value = 6;
    int border_value = 2;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    Matrix_fill_border(mat, border_value);
    
    Matrix *mat_test = new Matrix;
    Matrix_init(mat_test, width, height);
    Matrix_fill(mat_test, border_value);
    
    ASSERT_TRUE(Matrix_equal(mat, mat_test));

    delete mat;
    delete mat_test;
}

// Create a 4x5 Matrix with a value and checks whether
// Matrix_fill_border fills the border of matrix with another value
TEST(test_matrix_fill_border_edge_case_2) {
    Matrix *mat = new Matrix;
    
    const int width = 24;
    const int height = 25;
    int value = 8;
    int border_value = 3;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    Matrix_fill_border(mat, border_value);
    
    
    for (int i = 0; i < width; ++i) {
        if (i == 0 || i == width - 1) {
            for (int j = 0; j < height; ++j) {
                ASSERT_EQUAL(*(Matrix_at(mat, j, i)),
                             border_value);
            }
        }
    }
    
    for (int i = 0; i < height; ++i) {
        if (i == 0 || i == height - 1) {
            for (int j = 0; j < width; ++j) {
                ASSERT_EQUAL(*(Matrix_at(mat, i, j)),
                             border_value);
            }
        }
    }
    
    delete mat;
}

// Create a 1x1 Matrix with a value and checks
// whether Matrix_maxreturns the value of the maximum element
// in the Matrix
TEST(test_matrix_max) {
    Matrix *mat = new Matrix;
    
    const int width = 1;
    const int height = 1;
    int value = 70;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    
    ASSERT_EQUAL(Matrix_max(mat), value);
    
    delete mat;
}

// Create a 9x10 Matrix with a value, changes an element's value
// to a larger one than the rest of elements, and checks
// whether Matrix_max returns the value of the maximum element
// in the Matrix
TEST(test_matrix_max_edge_case_1) {
    Matrix *mat = new Matrix;
    
    const int width = 9;
    const int height = 10;
    int value = 99;
    int change_value = 1040;
    
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    *(Matrix_at(mat, 6, 5)) = change_value;
    
    ASSERT_EQUAL(Matrix_max(mat), change_value);
    
    delete mat;
}

// Create a 5x2 matrix with different values,v and checks
// whether Matrix_max returns the value of the maximum element
// in the Matrix
TEST(test_matrix_max_edge_case_2) {
    Matrix *mat = new Matrix;
    
    const int width = 5;
    const int height = 2;
    Matrix_init(mat, width, height);
    *(Matrix_at(mat, 0, 0)) = 7;
    *(Matrix_at(mat, 0, 1)) = 3;
    *(Matrix_at(mat, 0, 2)) = 22;
    *(Matrix_at(mat, 0, 3)) = 34;
    *(Matrix_at(mat, 0, 4)) = 5;
    *(Matrix_at(mat, 1, 0)) = 0;
    *(Matrix_at(mat, 1, 1)) = 78;
    *(Matrix_at(mat, 1, 2)) = 82;
    *(Matrix_at(mat, 1, 3)) = 9;
    *(Matrix_at(mat, 1, 4)) = 100;
    
    ASSERT_EQUAL(Matrix_max(mat), 100);
    
    delete mat;
}

// Create a 3x4 matrix with different values, and checks whether
// Matrix_column_of_min_value_in_row returns
// the column of the element with the minimal value
TEST(test_matrix_column_of_min_value_in_row) {
    Matrix *mat = new Matrix;
    
    const int width = 3;
    const int height = 4;
    Matrix_init(mat, width, height);
    *(Matrix_at(mat, 0, 0)) = 100;
    *(Matrix_at(mat, 0, 1)) = 2;
    *(Matrix_at(mat, 0, 2)) = 2;
    *(Matrix_at(mat, 1, 0)) = 6;
    *(Matrix_at(mat, 1, 1)) = 5;
    *(Matrix_at(mat, 1, 2)) = 7;
    *(Matrix_at(mat, 2, 0)) = 7;
    *(Matrix_at(mat, 2, 1)) = 8;
    *(Matrix_at(mat, 2, 2)) = 9;
    *(Matrix_at(mat, 3, 0)) = 10;
    *(Matrix_at(mat, 3, 1)) = 10;
    *(Matrix_at(mat, 3, 2)) = 10;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                0, 0, 1), 0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 0, 0, 3), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                1, 0, 3), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                3, 0, 3), 0);
    delete mat;
}

// Create a 1x1 matrix with a value, and returns whether
// Matrix_column_of_min_value_in_row returns
// the column of the element with the minimal value
TEST(test_matrix_column_of_min_value_in_row_edge_1) {
    Matrix *mat = new Matrix;
    const int width = 1;
    const int height = 1;
    int value = 10;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                0, 0, 1), 0);
    
    delete mat;
}

// Create a 4x3 matrix with a value, and checks whether
// Matrix_column_of_min_value_in_row returns
// the column of the element with the minimal value
TEST(test_matrix_column_of_min_value_in_row_edge_2) {
    Matrix *mat = new Matrix;
    
    const int width = 4;
    const int height = 3;
    Matrix_init(mat, width, height);
    *(Matrix_at(mat, 0, 0)) = 4;
    *(Matrix_at(mat, 0, 1)) = 5;
    *(Matrix_at(mat, 0, 2)) = 4;
    *(Matrix_at(mat, 0, 3)) = 3;
    *(Matrix_at(mat, 1, 0)) = 6;
    *(Matrix_at(mat, 1, 1)) = 6;
    *(Matrix_at(mat, 1, 2)) = 6;
    *(Matrix_at(mat, 1, 3)) = 5;
    *(Matrix_at(mat, 2, 0)) = 0;
    *(Matrix_at(mat, 2, 1)) = 1;
    *(Matrix_at(mat, 2, 2)) = 2;
    *(Matrix_at(mat, 2, 3)) = 1;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 0, 0, 3), 0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 0, 0, 4), 3);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 0, 1, 2), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 1, 0, 4), 3);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 1, 0, 3), 0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 2, 1, 4), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,
                 2, 0, 4), 0);
    delete mat;
}

// Create a 3x4 matrix with different values, and checks whether
// Matrix_min_value_in_row returns the element
// with the minimal value
TEST(test_matrix_min_value_in_row) {
    Matrix *mat = new Matrix;
    
    const int width = 3;
    const int height = 4;
    Matrix_init(mat, width, height);
    *(Matrix_at(mat, 0, 0)) = 100;
    *(Matrix_at(mat, 0, 1)) = 2;
    *(Matrix_at(mat, 0, 2)) = 2;
    *(Matrix_at(mat, 1, 0)) = 6;
    *(Matrix_at(mat, 1, 1)) = 5;
    *(Matrix_at(mat, 1, 2)) = 7;
    *(Matrix_at(mat, 2, 0)) = 7;
    *(Matrix_at(mat, 2, 1)) = 8;
    *(Matrix_at(mat, 2, 2)) = 9;
    *(Matrix_at(mat, 3, 0)) = 10;
    *(Matrix_at(mat, 3, 1)) = 10;
    *(Matrix_at(mat, 3, 2)) = 10;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 100);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                 0, 0, 3), 2);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                1, 0, 3), 5);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                3, 0, 3), 10);
    delete mat;
}

// Create a 1x1 matrix with a value, and checks whether
// Matrix_min_value_in_row returns the element
// with the minimal value
TEST(test_matrix_min_value_in_row_edge_1) {
    Matrix *mat = new Matrix;
    const int width = 1;
    const int height = 1;
    int value = 10;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 10);
    
    delete mat;
}

// Create a 4x3 matrix with a value, and checks whether
// Matrix_column_of_min_value_in_row returns
// the column of the element with the minimal value
TEST(test_matrix_min_value_in_row_edge_2) {
    Matrix *mat = new Matrix;
    
    const int width = 4;
    const int height = 3;
    Matrix_init(mat, width, height);
    *(Matrix_at(mat, 0, 0)) = 4;
    *(Matrix_at(mat, 0, 1)) = 5;
    *(Matrix_at(mat, 0, 2)) = 4;
    *(Matrix_at(mat, 0, 3)) = 3;
    *(Matrix_at(mat, 1, 0)) = 6;
    *(Matrix_at(mat, 1, 1)) = 6;
    *(Matrix_at(mat, 1, 2)) = 6;
    *(Matrix_at(mat, 1, 3)) = 5;
    *(Matrix_at(mat, 2, 0)) = 0;
    *(Matrix_at(mat, 2, 1)) = 1;
    *(Matrix_at(mat, 2, 2)) = 2;
    *(Matrix_at(mat, 2, 3)) = 1;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 3), 4);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                 0, 1, 2), 5);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                 0, 1, 4), 3);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                 1, 0, 3), 6);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                 1, 0, 4), 5);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                 2, 0, 4), 0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,
                 2, 1, 4), 1);
    
    delete mat;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
