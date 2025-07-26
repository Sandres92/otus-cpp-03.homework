#include <iostream>

#include "lib.h"
#include "custom_allocator.h"
#include <map>
#include "utils.cpp"

#define MAP_NUMBER 10

int main(int, char **)
{
  std::cout << "Version: " << version() << std::endl;
  std::cout << "Hello, world!" << std::endl;
  std::map<int, int> m1;
  for (size_t i = 0; i != MAP_NUMBER; ++i)
  {
    m1[i] = otus::utils::factorial(i);
    std::cout << i << " " << m1[i] << "\n";
  }

  std::map<int, int,
           std::less<int>,
           otus::CustomAllocator<std::pair<int, int>, MAP_NUMBER>>
      m2;
  for (size_t i = 0; i != MAP_NUMBER; ++i)
  {
    m2[i] = otus::utils::factorial(i);
    std::cout << i << " " << m2[i] << "\n";
  }

  return 0;
}
