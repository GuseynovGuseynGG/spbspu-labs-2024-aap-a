#include "resize.hpp"
#include <exception>

char* asafov::resize(char* string, size_t length)
{
  size_t i = 0;
  char* oldString = string;
  char* newString = nullptr;
  try
  {
    newString = new char[length + 8];
  }
  catch (const std::bad_alloc)
  {
    return oldString;
  }
  while (i < length)
  {
    newString[i] = oldString[i];
  }
  while (i < length + 8)
  {
    newString[i] = '\0';
  }
  delete[] oldString;
  return newString;
}
