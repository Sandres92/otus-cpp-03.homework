#include <iostream>

#include <map>
#include <forward_list>
#include <vector>
#include <string>

#include "lib.h"
#include "custom_allocator.h"
#include "utils.h"
#include "custom_forward_list.h"

#define MAP_NUMBER 10

int main(int, char **)
{
  std::cout << "Version: " << version() << std::endl;

  std::cout << "std map, std allocator =================\n";

  std::map<int, int> m1;
  for (size_t i = 0; i != MAP_NUMBER; ++i)
  {
    m1[i] = otus::utils::factorial(i);
    std::cout << i << " " << m1[i] << "\n";
  }

  std::cout << "std map, custom allocator =================\n";
  std::map<int, int,
           std::less<>,
           otus::CustomAllocator<std::pair<int, int>, MAP_NUMBER>>
      m2;
  for (size_t i = 0; i != MAP_NUMBER; ++i)
  {
    m2[i] = otus::utils::factorial(i);
    std::cout << i << " " << m2[i] << "\n";
  }

  std::cout << "std forward_list, custom allocator =================\n";
  std::forward_list<int, otus::CustomAllocator<int, MAP_NUMBER>> fl;

  for (size_t i = 0; i != MAP_NUMBER; ++i)
  {
    fl.push_front(i);
  }

  for (int n : fl)
  {
    std::cout << n << "\n";
  }

  std::vector<int> v;
  v.reserve(5);

  std::cout << "custom ForwardList, std allocator =================\n";
  otus::CustomForwardList<int> cfl1;
  for (size_t i = 0; i != MAP_NUMBER; ++i)
  {
    cfl1.push_front(i);
  }

  for (const auto &elem : cfl1)
  {
    std::cout << elem << "\n";
  }

  std::cout << "custom ForwardList,custom allocator =================\n";
  otus::CustomForwardList<int, otus::CustomAllocator<int, MAP_NUMBER>> cfl2;
  for (size_t i = 0; i != MAP_NUMBER; ++i)
  {
    cfl2.push_front(i);
  }

  for (const auto &elem : cfl2)
  {
    std::cout << elem << "\n";
  }

  return 0;
}
