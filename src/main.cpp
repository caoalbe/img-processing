#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main(int argc, char **argv)
{
  Image test("input/campus.jpg");
  test.flipVertical();
  test.write("output/vertical-flip.png");

  // Image copy(test);
  // for (int i = 0; i < 2 * copy.width * copy.channels; i++)
  // {
  //   copy.data[i] = 255;
  // }
  // copy.write("output/whiteRow.jpg");

  // Image blank(100, 100, 3);
  // blank.write("output/blank.jpg");

  return 0;
}