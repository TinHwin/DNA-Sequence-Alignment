// "Copyright [2023] <Truong-Thinh Huynh, Preston Luie>"
#include <string>
#include <algorithm>

#pragma once

class EDistance {
 public:
  EDistance(std::string, std::string);

  static int penalty(char a, char b);
  static int min(int a, int b, int c);

  int optDistance();

  std::string alignment();

  void clearMatrix();

  int eCOptDistance();

 private:
  std::string stringRow;
  std::string stringCol;

  int stringRowSize;
  int stringColSize;

  int** optMatrix;

  std::string stringOptimalAlignment;
};

