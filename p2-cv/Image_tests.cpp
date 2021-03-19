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

TEST(test_init_basic1) {
    Image* img = new Image;
    Image_init(img, 3, 2);
    ASSERT_EQUAL(Image_width(img), 3);
    ASSERT_EQUAL(Image_height(img), 2)
    delete img;
}

TEST(test_init_basic2) {
    Image* img = new Image;
    
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};

    Image_init(img, 2, 2);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 1, 0, blue);
    Image_set_pixel(img, 1, 1, white);
    
    string inputPPM = "P3\n2 2\n255\n255 0 0 0 255 0 \n0 0 255 255 255 255 \n";
    
    Image* img0 = new Image;
    std::istringstream ss_input(inputPPM);
    Image_init(img0, ss_input);
    
    ASSERT_TRUE(Image_equal(img, img0))
    
    delete img0;
    delete img;
}

TEST(test_init_edge) {
    Image* img = new Image;
    
    const Pixel red = {255, 0, 0};

    Image_init(img, 1, 1);
    Image_set_pixel(img, 0, 0, red);
    
    string inputPPM = "P3\n1 1\n255\n255 0 0 \n";
    
    Image* img0 = new Image;
    std::istringstream ss_input(inputPPM);
    Image_init(img0, ss_input);
    
    ASSERT_TRUE(Image_equal(img, img0))
    
    delete img0;
    delete img;
}

TEST(test_print_edge) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};

  Image_init(img, 1, 1);
  Image_set_pixel(img, 0, 0, red);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n1 1\n255\n";
  correct << "255 0 0 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_get_set_pixel_basic) {
    Pixel* pix = new Pixel;
    Image* img = new Image;
    
    Image_init(img, 3, 3);
    
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};
    
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 2, green);
    Image_set_pixel(img, 1, 1, blue);
    Image_set_pixel(img, 2, 2, white);
    
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 2), green));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 1), blue));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 2), white));
    
    delete pix;
    delete img;
}

TEST(test_fill) {
    Image* img = new Image;
    const Pixel red = {255, 0, 0};
    
    Image_init(img, 2, 2);
    Image_fill(img, red);
    
    Image* img0 = new Image;
    Image_init(img0, 2, 2);
    Image_set_pixel(img0, 0, 0, red);
    Image_set_pixel(img0, 0, 1, red);
    Image_set_pixel(img0, 1, 0, red);
    Image_set_pixel(img0, 1, 1, red);
    ASSERT_TRUE(Image_equal(img, img0));
    delete img;
    delete img0;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
