
#include <iostream>

int main(int argc, char **argv)
{
  (void)argc;
  int i = 1;
  int j;
  if (argc == 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }
  while (argv[i])
  {
    j = 0;
    while (argv[i][j])
    {
      if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
      {
        argv[i][j] -= 32;
      }
      std::cout << argv[i][j];
      j++;
    }
    i++;
  }
  std::cout << std::endl
  return 0;
}
