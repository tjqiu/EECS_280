
/* Image_test_helpers.cpp
 * Project UID af1f95f547e44c8ea88730dfb185559d
 * Originally written by James Juett at the University of Michigan
 * for project 3 in EECS 280, Winter 2016.
 */

#include "Image_test_helpers.h"

bool Pixel_equal(Pixel p1, Pixel p2){
  return p1.r == p2.r && p1.g == p2.g && p1.b == p2.b;
}

bool Image_equal(const Image* img1, const Image* img2){
  if (Image_width(img1) != Image_width(img2)){ return false; }
  if (Image_height(img1) != Image_height(img2)){ return false; }

  for(int r = 0; r < Image_height(img1); ++r){
    for(int c = 0; c < Image_width(img1); ++c){
      if (!Pixel_equal(Image_get_pixel(img1, r, c), Image_get_pixel(img2, r, c))){
        return false;
      }
    }
  }
  
  return true;
}
