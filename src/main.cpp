#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main(int argc, char **argv)
{
  Image test("input/campus.jpg");
  test.blackAndWhite();
  test.write("output/blackandwhite.png");

  return 0;
}