#include "Simplex.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> parse_csv(std::string &fileName) {

  std::fstream inputFile(fileName);

  if (!inputFile.is_open()) {
    std::cout << "Error opening file!" << std::endl;
    std::vector<std::string> error_vector(1, "Error");
    return error_vector;
  }

  std::string line;
  while (std::getline(inputFile, line)) {
    std::cout << line << std::endl;
  }

  std::vector<std::string> normal_execution(1, "Complete");
  return normal_execution;
}

int main(int argn, char *argv[]) {

  // if (argn == 2) {
  //   const std::string fileName = argv[1];
  // } else {
  //   const std::string fileName = "SimplicialComplex.txt";
  // }

  // inFile = std::fopen(fileName, 'r');
  //

  std::string fileName = "examples/complex_a.csv";
  std::vector<std::string> output = parse_csv(fileName);

  return 0;
};
