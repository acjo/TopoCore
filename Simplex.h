#pragma once
#include <string>
#include <vector>
class Simplex {
private:
  int type;
  std::vector<std::string> value;

public:
  Simplex();
  Simplex(const std::vector<std::string> &val);
  std::vector<std::string> get_val();
  int get_type();
  void set_val(const std::vector<std::string> &val);
};
