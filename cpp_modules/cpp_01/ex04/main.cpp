
#include <iostream>

#include <fstream>

int main(int argc, char **argv)
{
  if (argc != 4)
  {
      std::cout << "there is an invalid number of arguments" << std::endl;
      return 1;
  }
  std::string outfile = argv[1];
  outfile.append(".replace");
  std::string fileName = argv[1];
  std::ifstream inputFile(fileName.c_str());
  if (!inputFile.is_open())
  {
    std::cout << "The file doesn't exist" << std::endl;
    return 1;
  }
  std::string input;
  while (input.empty())
  {
    std::getline(inputFile, input);
    if (inputFile.eof())
    {
      std::cout << "the file wasn't read from" << std::endl;
      return 1;
    }
  }
  return 0;
}


