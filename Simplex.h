#pragma once
#include <string>
class Simplex {
private:
  std::string value;

public:
  Simplex();
  Simplex(const std::string &val);
  std::string get_val();
  void set_val(const std::string &val);
};
