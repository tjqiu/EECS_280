// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Matrix.h"

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
    mat->width = width;
    mat->height = height;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
    os << mat->width << " " << mat->height << std::endl;
    for (int i = 0; i < mat->height; ++i) {
        for (int j = 0; j < mat->width; ++j) {
            os << mat->data[i*mat->width + j] << " ";
        }
        os << std::endl;
    }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {
    return mat->width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
    return mat->height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {
    long gap = ptr - mat->data;
    return static_cast<int>(gap / mat->width);
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr) {
    long gap = ptr - mat->data;
    return static_cast<int>(gap % mat->width);
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {
    int* ptr = &(mat->data[row*(mat->width) + column]);
    return ptr;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
    const int* ptr = &(mat->data[row*mat->width + column]);
    return ptr;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
    for (int* ptr = mat->data; ptr < mat->data + mat->height*mat->width; ++ptr){
        *ptr = value;
    }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
    for (int* ptr = mat->data; ptr < mat->data + mat->width; ++ptr){
        *ptr = value;
    }
    int* initPtr = &mat->data[(mat->height - 1) * mat->width];
    int* endPtr = &mat->data[mat->height * mat->width];
    for (int* ptr = initPtr; ptr < endPtr; ++ptr){
        *ptr = value;
    }
    for (int* ptr = mat->data; ptr < &mat->data[mat->height * mat->width]; ptr
         += mat->width){
        *ptr = value;
    }
    for (int* ptr = &mat->data[mat->width - 1];
         ptr < &mat->data[((mat->height + 1) * mat->width - 1)];
         ptr += mat->width) {
        *ptr = value;
    }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
    int maxNum = mat->data[0];
    for (const int* ptr = mat->data;
         ptr < &mat->data[mat->height * mat->width]; ++ptr) {
        if (*ptr > maxNum) {
            maxNum = *ptr;
        }
    }
    return maxNum;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int column_start, int column_end) {
    int minNum = mat->data[row * mat->width + column_start];
    int minColumn = column_start;
    for (const int* ptr = &mat->data[row * mat->width + column_start];
         ptr < &mat->data[row * mat->width + column_end]; ++ptr){
        if (*ptr < minNum){
            minColumn = Matrix_column(mat, ptr);
            minNum = *ptr;
        }
    }
    return minColumn;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int column_start, int column_end) {
    int minNum = mat->data[row * mat->width + column_start];
    for (const int* ptr = &mat->data[row * mat->width + column_start];
         ptr < &mat->data[row * mat->width + column_end]; ++ptr){
        if (*ptr < minNum){
            column_start = Matrix_column(mat, ptr);
            minNum = *ptr;
        }
    }
    return minNum;
}
