#include <iostream>


uint32_t bitlen(uint32_t x)
{
  if (x == 0)
    return 0; // Or 1, depending on definition for 0
  uint32_t w = 32 - __builtin_clz(x);
  return w; // For 32-bit unsigned int
}
int hammingWeight(uint32_t n)
{
  int sum = 0;
  int size = bitlen(n);
  return size;
}

int main ()
{
  uint32_t  n = 2147483645;
  int count = hammingWeight(n);
  std::cout << count << "\n";
  return 0;
}
