// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_image_init_basic) {
    Image *img = new Image;
    
    const int width = 1;
    const int height = 8;
    Image_init(img, width, height);
    ASSERT_EQUAL(Image_width(img), width);
    ASSERT_EQUAL(Image_height(img), height);
    
    delete img;
}

// Create a hardcoded PPM image, and test whether
// Image_int could initialize the image properly
TEST(test_image_init) {
    Image *img = new Image;
    
    // A hardcoded PPM image
    string input = "P3\n2 1\n255\n163 73 164 0 255 0 \n";
    
    // Use istringstream for simulated input
    istringstream ss_input(input);
    Image_init(img, ss_input);
    
    ASSERT_EQUAL(Image_width(img), 2);
    ASSERT_EQUAL(Image_height(img), 1);
    Pixel purple = {163, 73, 164};
    Pixel green = {0, 255, 0};
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), purple));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), green));
    
    delete img;
}

// Create a hardcoded PPM image, and test whether Image_print
// can print it properly
TEST(test_image_from_and_to_stream) {
    Image *img = new Image;
    
    // A hardcoded PPM image
    string input = "P3\n2 4\n255\n255 0 0 0 0 0 \n0 255 0 0 0 255 \n";
    input += "124 63 63 101 151 183 \n255 255 255 163 73 164 \n";
    
    // Use istringstream for simulated input
    istringstream ss_input(input);
    Image_init(img, ss_input);
    
    // Capture output in ostringstream
    string output_correct = input;
    ostringstream ss_output;
    Image_print(img, ss_output);
    string actual = ss_output.str();
    cout << actual << endl;
    ASSERT_EQUAL(actual, output_correct);
    
    delete img;
}

// Create a 100x399 image and check its width and height
TEST(test_image_width_and_height) {
    Image *img = new Image;
    
    const int width = 78;
    const int height = 96;
    Image_init(img, width, height);
    ASSERT_EQUAL(Image_width(img), width);
    ASSERT_EQUAL(Image_height(img), height);
    
    delete img;
}

// Create a 2x4 image and test whether Image_get_pixel
// could get the correct pixel
TEST(test_image_get_pixel) {
    Image *img = new Image;
    
    // A hardcoded PPM image
    string input = "P3\n2 4\n255\n255 0 0 0 0 0 \n0 255 0 0 0 255 \n";
    input += "124 63 63 101 151 183 \n255 255 255 163 73 164 \n";
    
    // Use istringstream for simulated input
    istringstream ss_input(input);
    Image_init(img, ss_input);
    
    Pixel test_black = Image_get_pixel(img, 0, 1);
    Pixel test_blue = Image_get_pixel(img, 1, 1);
    Pixel test_brown = Image_get_pixel(img, 2, 0);
    Pixel blue = {0, 0, 255};
    Pixel black = {0, 0, 0};
    Pixel brown = {124, 63, 63};
    ASSERT_TRUE(Pixel_equal(test_black, black));
    ASSERT_TRUE(Pixel_equal(test_blue, blue));
    ASSERT_TRUE(Pixel_equal(test_brown, brown));
    
    delete img;
}

// Create a 6x6 image and fill it with dark_blue color
// change the pixel at the last row and column to white
// and test whether Image_set_pixel works properly
TEST(test_image_set_pixel) {
    Image *img = new Image;
    
    const int width = 6;
    const int height = 6;
    Image_init(img, width, height);
    Pixel dark_blue = {101, 151, 183};
    Pixel white = {255, 255, 255};
    
    Image_fill(img, dark_blue);
    Image_set_pixel(img, 5, 5, white);
    Pixel pixel_test = Image_get_pixel(img, 5, 5);
    
    ASSERT_TRUE(Pixel_equal(pixel_test, white));
    
    delete img;
}

// Create a 3x2 Image and test whether Image_fill
// could fill the Image's each pixel with grey color
TEST(test_image_fill) {
    Image *img = new Image;
    
    const int width = 3;
    const int height = 2;
    Image_init(img, width, height);
    Pixel grey = {100, 100, 100};
    
    Image_fill(img, grey);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, i, j), grey));
        }
    }
    
    Image_print(img, cout);
    delete img;
}
// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
