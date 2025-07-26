#include <iostream>

#include "lib.h"
#include "custom_allocator.h"
#include <map>

int main(int, char **)
{
  std::cout << "Version: " << version() << std::endl;
  std::cout << "Hello, world!" << std::endl;
  std::map<int, int> m1;

  std::map<int, int,
           std::less<>,
           otus::CustomAllocator<std::pair<int, int>, 10>>
      m2;

  return 0;
}
