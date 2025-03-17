#include "Simplex.h"
#include "SimplicialComplex.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argn, char **argv) {

  std::string fileName;
  if (argn == 2) {
    fileName = static_cast<std::string>(argv[1]);
  } else {
    fileName = "examples/complex_a.csv";
  }

  std::cout << "Reading File: " << fileName << std::endl;
  std::vector<Simplex> simplicies = build_simplices_csv(fileName);

  SimplicialComplex complex = SimplicialComplex(simplicies);

  return 0;
};
