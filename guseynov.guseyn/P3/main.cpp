#include <iostream>
#include <fstream>

#include "cmdprotection.hpp"
#include "matrix.hpp"

int main(int argc, char** argv)
{
  try
  {
    guseynov::cmdProtection(argc, argv);
  }
  catch (const std::logic_error &e)
  {
    std::cerr << e.what();
    return 1;
  }
  size_t m = 0;
  size_t n = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "failed to open file";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "failed to open file";
    return 1;
  }
  input >> n >> m;
  if (!input)
  {
    return 2;
  }
  size_t general = m * n;
  if (general == 0)
  {
    output << "0\n";
    return 0;
  }
  size_t read = 0;
  if (argv[1][0] == '1')
  {
    if (general > 10000)
    {
      return 2;
    }
    int arr[10000];
    if ((!guseynov::inputMtx(input, arr, general, read)) || (read != general))
    {
      return 2;
    }
    output << guseynov::searchNumLocMin(arr, general) << "\n";
  }
  else
  {
    int *arr = nullptr;
    try
    {
      arr = new int[general];
    }
    catch (const std::bad_alloc& e)
    {
      return 2;
    }
    if ((!guseynov::inputMtx(input, arr, general, read)) || (read != general))
    {
      delete[] arr;
      return 2;
    }
    output << guseynov::searchNumLocMin(arr, general) << "\n";
    delete[] arr;
  }
  return 0;
}