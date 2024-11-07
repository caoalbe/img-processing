#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"

int main(int argc, char **argv)
{
  Image input("input/heather.jpg");

  // Image *output = flipHorizontal(grayScale(&input));
  Image *output = convolution(&input);

  output->write("output/blur-convolve.png");

  return 0;
}