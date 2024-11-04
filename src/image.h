#include <stdint.h>

enum FileType
{
  JPG,
  PNG
};

struct Image
{
  unsigned char *data;
  size_t size = 0; // array size of data
  int width;
  int height;
  int channels;

  Image(const char *filename); // construct from file
  Image(const Image &img);     // copy
  ~Image();                    // destructor

  int write(const char *filename); // write to file location

  FileType getFileType(const char *filename); // get file extension
};