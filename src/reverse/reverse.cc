#include "reverse/reverse.h"

#include <algorithm>

std::string Reverse(std::string s) {
  std::reverse(s.begin(), s.end());
  return s;
}
