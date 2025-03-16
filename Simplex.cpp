#include "Simplex.h"

Simplex::Simplex() {}
Simplex::Simplex(const std::string &val) {
  // Constructor with value;
  value = val;
}
std::string Simplex::get_val() { return value; }
void Simplex::set_val(const std::string &val) { value = val; }
