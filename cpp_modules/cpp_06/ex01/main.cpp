#include "Serializer.hpp"

int main()
{
  Data* ptr = new Data();
  uintptr_t w =  Serializer::serialize(ptr);
  std::cout << w << '\n';
  return 0;
}
