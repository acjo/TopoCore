#include "Simplex.h"
#include <vector>

Simplex::Simplex() {}
Simplex::Simplex(const std::vector<std::string> &val) {
  value = val;
  type = value.size();
}
std::vector<std::string> Simplex::get_val() { return value; }
int Simplex::get_type() { return type; }
void Simplex::set_val(const std::vector<std::string> &val) {
  value = val;
  type = value.size();
}
