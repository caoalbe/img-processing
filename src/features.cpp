#include <string.h>
#include "features.h"

Image *flipHorizontal(Image *src)
{
  Image *output = new Image(src->width, src->height, src->channels);

  int left, right; // indices
  for (int y = 0; y < src->height; y++)
  {
    for (int x = 0; x < src->width / 2; x++)
    {
      for (int c = 0; c < src->channels; c++)
      {
        left = y * src->width * src->channels + x * src->channels + c;
        right = (y + 1) * src->width * src->channels - (x + 1) * src->channels + c;
        output->data[right] = src->data[left];
        output->data[left] = src->data[right];
      }
    }
  }
  return output;
}

Image *flipVertical(Image *src)
{
  Image *output = new Image(src->width, src->height, src->channels);

  for (int y = 0; y < src->height; y++)
  {
    memcpy(&output->data[y * src->width * src->channels],
           &src->data[(src->height - y - 1) * src->width * src->channels],
           src->width * src->channels);
  }
  return output;
}

Image *grayScale(Image *src)
{
  if (src->channels < 3)
  {
    return nullptr;
  }

  Image *output = new Image(src->width, src->height, src->channels);

  unsigned char intensity;
  for (int p = 0; p < src->size; p += src->channels)
  {
    intensity = 0.299 * src->data[p] + 0.587 * src->data[p + 1] + 0.114 * src->data[p + 2];
    for (int c = 0; c < src->channels; c++)
    {
      output->data[p + c] = intensity;
    }
  }

  return output;
}

Image *convolution(Image *src, Kernel *kernel)
{
  Image *output = new Image(src->width, src->height, src->channels);
  unsigned char amount;
  for (int y = 0; y < src->height; y++)
  {
    for (int x = 0; x < src->width; x++)
    {
      for (int c = 0; c < src->channels; c++)
      {
        amount = 0;
        for (int kx = 0; kx < kernel->width; kx++)
        {
          for (int ky = 0; ky < kernel->height; ky++)
          {
            amount += kernel->query(kx, ky) * src->query(x + kx - kernel->halfWidth, y + ky - kernel->halfHeight, c);
          }
        }
        output->data[(x + y * src->width) * src->channels + c] = amount;
      }
    }
  }

  return output;
}