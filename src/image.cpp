#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "image.h"

Image::Image(const char *filename)
{
  data = stbi_load(filename, &width, &height, &channels, 0);
  if (data == NULL)
  {
    printf("Error in loading the image\n");
    exit(1);
  }
  size = width * height * channels;
}

Image::Image(const Image &img) : size(img.size), width(img.width), height(img.height), channels(img.channels)
{
  data = new unsigned char[img.size];
  memcpy(data, img.data, size);
}

Image::Image(int width, int height, int channels) : width(width), height(height), channels(channels)
{
  size = width * height * channels;
  data = new unsigned char[size];

  for (int i = 0; i < size; i++)
  {
    data[i] = 0;
  }
}

Image::~Image()
{
  stbi_image_free(data);
}

int Image::write(const char *filename)
{
  FileType type = getFileType(filename);
  int status;
  switch (type)
  {
  case JPG:
    status = stbi_write_jpg(filename, width, height, channels, data, 100);
    break;

  case PNG:
    status = stbi_write_png(filename, width, height, channels, data, width * channels);
    break;
  }
  return status;
}

FileType Image::getFileType(const char *filename)
{
  const char *extension = strrchr(filename, '.');
  if (extension == nullptr)
  {
    printf("File name has no extension\n");
    exit(1);
  }

  if (strcmp(extension, ".jpg") == 0)
  {
    return JPG;
  }
  else if (strcmp(extension, ".png") == 0)
  {
    return PNG;
  }

  printf("File name extension is not supported\n");
  exit(1);
}