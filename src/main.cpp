#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "features.h"

int main(int argc, char **argv)
{
  Image input("input/campus.jpg");

  Image *output = flipHorizontal(grayScale(&input));

  output->write("output/chained.png");

  return 0;
}