#include <iostream>

#include <map>
#include <forward_list>
#include <vector>
#include <string>

#include "lib.h"
#include "custom_allocator.h"
#include "utils.h"
#include "custom_forward_list.h"
#include "task_1409.h"
#include "task_1877.h"
#include "task_2001.h"

#define MAP_NUMBER 10

void task_1409()
{
  unsigned int harry, larry;
  std::cin >> harry >> larry;
  auto result = otus::task_1409_vt(harry, larry);
  std::cout << std::get<0>(result) << " " << std::get<1>(result) << "\n";
}

void task_1887()
{
  std::string code1Str;
  std::string code2Str;
  std::cin >> code1Str;
  std::cin >> code2Str;

  std::vector<unsigned int> code1(code1Str.size());
  for (char digit : code1Str)
  {
    code1.push_back(digit - '0');
  }

  std::vector<unsigned int> code2(code2Str.size());
  for (char digit : code2Str)
  {
    code2.push_back(digit - '0');
  }

  bool isHack = otus::task_1877(code1, code2);

  std::cout << (isHack ? "yes" : "no") << "\n";
}

void task_2001()
{
  constexpr size_t size = 2;

  std::vector<unsigned int> allMass(size);
  for (size_t i = 0; i != size; ++i)
  {
    std::cin >> allMass[i];
  }

  std::vector<unsigned int> inFirstBasket(size);
  for (size_t i = 0; i != size; ++i)
  {
    std::cin >> inFirstBasket[i];
  }

  std::vector<unsigned int> inSecondBasket(size);
  for (size_t i = 0; i != size; ++i)
  {
    std::cin >> inSecondBasket[i];
  }

  std::vector<unsigned int> result = otus::task_2001(allMass, inFirstBasket, inSecondBasket);
  for (size_t i = 0; i != result.size(); ++i)
  {
    std::cout << result[i] << " ";
  }
  std::cout << "\n";
}

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

  // task_1409();
  // task_1887();
  task_2001();

  return 0;
}
