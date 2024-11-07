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

// blur kernel
double kernel[3][3] = {
    {0.11, 0.11, 0.11},
    {0.11, 0.11, 0.11},
    {0.11, 0.11, 0.11},
};

Image *convolution(Image *src)
{
  Image *output = new Image(src->width, src->height, src->channels);

  for (int y = 1; y < src->height - 1; y++)
  {
    for (int x = 1; x < src->width - 1; x++)
    {
      for (int c = 0; c < src->channels; c++)
      {
        output->data[(y * src->width + x) * src->channels + c] =
            kernel[0][0] * src->data[((y - 1) * src->width + (x - 1)) * src->channels + c] +
            kernel[0][1] * src->data[((y - 1) * src->width + (x)) * src->channels + c] +
            kernel[0][2] * src->data[((y - 1) * src->width + (x + 1)) * src->channels + c] +
            kernel[1][0] * src->data[((y)*src->width + (x - 1)) * src->channels + c] +
            kernel[1][1] * src->data[((y)*src->width + (x)) * src->channels + c] +
            kernel[1][2] * src->data[((y)*src->width + (x + 1)) * src->channels + c] +
            kernel[2][0] * src->data[((y + 1) * src->width + (x - 1)) * src->channels + c] +
            kernel[2][1] * src->data[((y + 1) * src->width + (x)) * src->channels + c] +
            kernel[2][2] * src->data[((y + 1) * src->width + (x + 1)) * src->channels + c];
      }
    }
  }

  return output;
}