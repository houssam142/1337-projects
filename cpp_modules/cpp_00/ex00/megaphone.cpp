
#include <iostream>

int main(int argc, char **argv)
{
  int i = 1;
  int j;
  if (argc == 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 1;
  }
  while (argv[i])
  {
    j = 0;
    while (argv[i][j])
    {
      if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
        argv[i][j] -= 32;
      std::cout << argv[i][j];
      j++;
    }
    i++;
  }
  std::cout << '\n';
  return 0;
}
