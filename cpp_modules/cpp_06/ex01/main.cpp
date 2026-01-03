#include "Serializer.hpp"

int main()
{
  Data* ptr = new Data();
  uintptr_t w = Serializer::serialize(ptr);
  std::cout << ptr << '\n';
  std::cout << w << '\n';
  delete ptr;
  return 0;
}
