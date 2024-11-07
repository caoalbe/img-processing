#include "kernel.h"
#include <string.h>

// basic 5x5 blur kernel
Kernel::Kernel() : width(5), height(5), halfWidth(2), halfHeight(2)
{
  values = new double[25];
  for (int i = 0; i < 25; i++)
  {
    values[i] = 0.04;
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
