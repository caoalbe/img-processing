#include "kernel.h"
#include <string.h>

// basic 3x3 blue kernel
Kernel::Kernel() : width(3), height(3), halfWidth(1), halfHeight(1)
{
  values = new double[9];
  for (int i = 0; i < 9; i++)
  {
    values[i] = 0.11;
  }
}

Kernel::Kernel(int width, int height) : width(width), height(height), halfWidth(width / 2), halfHeight(height / 2)
{
  values = new double[width * height];
  memset(values, 0, width * height * sizeof(double));
}

Kernel::~Kernel()
{
  delete[] values;
}

double Kernel::query(int x, int y)
{
  return values[y * width + x];
}

void Kernel::set(int x, int y, double value)
{
  values[y * width + x] = value;
}
