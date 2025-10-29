/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:58:01 by hounejja          #+#    #+#             */
/*   Updated: 2025/10/27 21:36:45 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  if (argc != 4)
  {
      std::cout << "there is an invalid number of arguments" << '\n';
      return 1;
  }
  std::string intendedStr = argv[2];
  std::string outfile = argv[1];
  outfile.append(".replace");
  std::string fileName = argv[1];
  std::ifstream inputFile(fileName.c_str());
  std::ofstream outputFile(outfile.c_str());
  if (!inputFile.is_open())
  {
    std::cout << "The file doesn't exist" << '\n';
    return 1;
  }
  std::string input;
  while ((std::getline(inputFile, input)))
  {
    size_t  pos = input.find(intendedStr);
    while (pos != std::string::npos)
    {
      input.erase(pos, intendedStr.length());
      input.insert(pos, argv[3]);
      pos = input.find(intendedStr);
    }
    outputFile << input << '\n';
  }
  inputFile.close();
  outputFile.close();
  return 0;
}


