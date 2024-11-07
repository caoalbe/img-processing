
struct Kernel
{
  double *values;
  int width;
  int height;
  int halfWidth;
  int halfHeight;

  Kernel();
  Kernel(int width, int height);
  ~Kernel();

  double query(int x, int y);
  void set(int x, int y, double value);
};