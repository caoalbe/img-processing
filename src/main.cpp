#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"

int main(int argc, char **argv)
{
  Image input("input/heather.jpg");

  // Image *output = flipHorizontal(grayScale(&input));

  Kernel blur = Kernel();
  Image *output = convolution(&input, &blur);

  output->write("output/blur-convolve.png");

  return 0;
}