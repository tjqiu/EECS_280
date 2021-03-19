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
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_init_small) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);
    ASSERT_EQUAL(Matrix_width(mat), 1);
    ASSERT_EQUAL(Matrix_height(mat), 1);
    delete mat;
}

TEST(test_init_large1) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 400, 499);
    ASSERT_EQUAL(Matrix_width(mat), 400);
    ASSERT_EQUAL(Matrix_height(mat), 499);
    delete mat;
}

TEST(test_init_large2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, MAX_MATRIX_WIDTH, MAX_MATRIX_HEIGHT);
    ASSERT_EQUAL(Matrix_width(mat), MAX_MATRIX_WIDTH);
    ASSERT_EQUAL(Matrix_height(mat), MAX_MATRIX_HEIGHT);
    delete mat;
}

TEST(test_print_basic) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 2);

    *Matrix_at(mat, 0, 0) = 0;
    *Matrix_at(mat, 0, 1) = 1;
    *Matrix_at(mat, 0, 2) = 2;
    *Matrix_at(mat, 1, 0) = 3;
    *Matrix_at(mat, 1, 1) = 4;
    *Matrix_at(mat, 1, 2) = 5;
    ostringstream expected;
    expected << "3 2\n"
             << "0 1 2 \n"
    << "3 4 5 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());
    delete mat;
}

TEST(test_row_basic1) {
    Matrix* mat = new Matrix;
    Matrix_init(mat,3,3);
    const int* ptr = Matrix_at(mat, 1, 1);
    ASSERT_EQUAL(Matrix_row(mat,ptr), 1);
    delete mat;
}

TEST(test_row_baisc2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);
    const int* ptr = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
    delete mat;
}

TEST(test_row_edge1) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    const int* ptr = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
    delete mat;
}

TEST(test_row_edge2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat,3,3);
    const int* ptr = Matrix_at(mat, 2, 2);
    ASSERT_EQUAL(Matrix_row(mat,ptr), 2);
    delete mat;
}

TEST(test_row_edge3) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);
    const int* ptr = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
    delete mat;
}

TEST(test_row_edge4) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, MAX_MATRIX_HEIGHT);
    const int* ptr = Matrix_at(mat, MAX_MATRIX_HEIGHT - 1, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr), MAX_MATRIX_HEIGHT - 1);
    delete mat;
}

TEST(test_column_basic) {
    Matrix* mat = new Matrix;
    Matrix_init(mat,2,3);
    const int* ptr = Matrix_at(mat, 1, 1);
    ASSERT_EQUAL(Matrix_column(mat,ptr), 1);
    delete mat;
}

TEST(test_column_edge1) {
    Matrix* mat = new Matrix;
    Matrix_init(mat,1,1);
    const int* ptr = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(Matrix_column(mat,ptr), 0);
    delete mat;
}

TEST(test_column_edge2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat,2,3);
    const int* ptr = Matrix_at(mat, 2, 1);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 1);
    delete mat;
}

TEST(test_column_edge3) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    const int* ptr = Matrix_at(mat, 2, 2);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 2);
    delete mat;
}

TEST(test_column_edge4) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, MAX_MATRIX_WIDTH, 1);
    const int* ptr = Matrix_at(mat, 0, MAX_MATRIX_WIDTH - 1);
    ASSERT_EQUAL(Matrix_column(mat, ptr), MAX_MATRIX_WIDTH - 1);
    delete mat;
}

TEST(test_fill_edge) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 10;
  const int height = 10;
  const int value = -1;
  Matrix_init(mat, 10, 10);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_fill_boarder_basic) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 4, 3);
    Matrix_fill(mat, -3);
    *Matrix_at(mat, 0, 0) = 3;
    *Matrix_at(mat, 0, 1) = 3;
    *Matrix_at(mat, 0, 2) = 3;
    *Matrix_at(mat, 0, 3) = 3;
    *Matrix_at(mat, 1, 0) = 3;
    *Matrix_at(mat, 1, 3) = 3;
    *Matrix_at(mat, 2, 0) = 3;
    *Matrix_at(mat, 2, 1) = 3;
    *Matrix_at(mat, 2, 2) = 3;
    *Matrix_at(mat, 2, 3) = 3;
    Matrix* mat0 = new Matrix;
    Matrix_init(mat0, 4, 3);
    Matrix_fill(mat0, -3);
    Matrix_fill_border(mat0,3);
    ASSERT_TRUE(Matrix_equal(mat, mat0));
    delete mat0;
    delete mat;
}

TEST(test_fill_boarder_edge1) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);
    Matrix_fill(mat, 3);
    Matrix* mat0 = new Matrix;
    Matrix_init(mat0, 1, 1);
    Matrix_fill(mat0, -3);
    Matrix_fill_border(mat0,3);
    ASSERT_TRUE(Matrix_equal(mat, mat0));
    delete mat0;
    delete mat;
}

TEST(test_fill_boarder_edge2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    Matrix_fill(mat, 3);
    Matrix* mat0 = new Matrix;
    Matrix_init(mat0, 2, 2);
    Matrix_fill(mat0, -3);
    Matrix_fill_border(mat0,3);
    ASSERT_TRUE(Matrix_equal(mat, mat0));
    delete mat0;
    delete mat;
}

TEST(test_fill_boarder_edge3) {
    Matrix* mat = new Matrix;

    const int width = MAX_MATRIX_WIDTH;
    const int height = MAX_MATRIX_HEIGHT;
    const int value = -1;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);

    for (int r = 0; r < MAX_MATRIX_HEIGHT; ++r) {
        for (int c = 0; c < MAX_MATRIX_WIDTH; ++c) {
            ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
        }
    }

    delete mat;
}

TEST(test_max_basic) {
    Matrix* mat = new Matrix;
    Matrix_init(mat,3,3);
    Matrix_fill(mat, 3);
    Matrix_fill_border(mat, -3);
    ASSERT_EQUAL(Matrix_max(mat), 3)
    delete mat;
}

TEST(test_max_edge1) {
    Matrix* mat = new Matrix;
    Matrix_init(mat,1,1);
    Matrix_fill(mat, 3);
    ASSERT_EQUAL(Matrix_max(mat), 3)
    delete mat;
}

TEST(test_max_edge2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    *Matrix_at(mat, 0, 0) = 3;
    *Matrix_at(mat, 0, 1) = 2;
    *Matrix_at(mat, 1, 0) = 1;
    *Matrix_at(mat, 1, 1) = 3;
    ASSERT_EQUAL(Matrix_max(mat), 3)
    delete mat;
}

TEST(test_column_min_basic) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    *Matrix_at(mat, 0, 0) = 3;
    *Matrix_at(mat, 0, 1) = 2;
    *Matrix_at(mat, 1, 0) = 1;
    *Matrix_at(mat, 1, 1) = 3;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 2), 1)
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 2), 0)
    delete mat;
}

TEST(test_column_min_edge) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    *Matrix_at(mat, 0, 0) = 2;
    *Matrix_at(mat, 0, 1) = 2;
    *Matrix_at(mat, 0, 2) = 2;
    *Matrix_at(mat, 1, 0) = 1;
    *Matrix_at(mat, 1, 1) = 1;
    *Matrix_at(mat, 1, 2) = 1;
    *Matrix_at(mat, 2, 0) = 1;
    *Matrix_at(mat, 2, 1) = 3;
    *Matrix_at(mat, 2, 2) = 0;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 3), 0)
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 1, 3), 1)
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 1, 3), 2)
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 2, 3), 2)
    delete mat;
}

TEST(test_min_in_row_basic) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    *Matrix_at(mat, 0, 0) = 3;
    *Matrix_at(mat, 0, 1) = 2;
    *Matrix_at(mat, 1, 0) = 1;
    *Matrix_at(mat, 1, 1) = 3;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 2), 2)
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 2), 1)
    delete mat;
}

TEST(test_min_in_row_edge) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    *Matrix_at(mat, 0, 0) = 2;
    *Matrix_at(mat, 0, 1) = 2;
    *Matrix_at(mat, 0, 2) = 2;
    *Matrix_at(mat, 1, 0) = 1;
    *Matrix_at(mat, 1, 1) = 1;
    *Matrix_at(mat, 1, 2) = 1;
    *Matrix_at(mat, 2, 0) = 1;
    *Matrix_at(mat, 2, 1) = 3;
    *Matrix_at(mat, 2, 2) = 0;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 3), 2)
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 0, 3), 0)
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 0, 2), 1)
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 0, 1), 1)
    delete mat;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
