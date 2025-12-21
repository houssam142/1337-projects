#include "Serializer.hpp"

int main()
{
  int a = 97;

  int* p = &a;
  char* w = reinterpret_cast<char*>(p);
  std::cout << *w << '\n';
  // Data* ptr = new Data();
  // uintptr_t w =  Serializer::serialize(ptr);
  // std::cout << w << '\n';
  // delete ptr;
  return 0;
}
