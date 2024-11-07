#include "image.h"
#include "kernel.h"

Image *flipHorizontal(Image *src);
Image *flipVertical(Image *src);
Image *grayScale(Image *src);
Image *convolution(Image *src, Kernel *kernel);