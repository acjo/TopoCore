#include "Simplex.h"
#include <string>
#include <vector>

std::vector<std::string> parse_file(std::string &fileName) {

  std::vector<std::string> r;
  r.push_back("AA");
  return r;
}
int main(int argn, char *argv[]) {

  // if (argn == 2) {
  //   const std::string fileName = argv[1];
  // } else {
  //   const std::string fileName = "SimplicialComplex.txt";
  // }

  // inFile = std::fopen(fileName, 'r');
  //

  std::string val = "Apple";

  Simplex simp = Simplex(val);

  return 0;
};
