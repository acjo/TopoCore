#include "Simplex.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// split strings by a delimiter
std::vector<std::string> split(std::string &line, char delimiter);
// parse csv.
std::vector<Simplex> build_simplices_csv(std::string &fileName);
bool is_vertex(int length_token);
bool is_line(int length_token);
bool is_triangle(int length_token);

std::vector<Simplex> build_simplices_csv(std::string &fileName) {

  std::fstream inputFile(fileName);

  if (!inputFile.is_open()) {
    std::cout << "Error opening file!" << std::endl;
    throw std::invalid_argument("Invalid file name: " + fileName);
  }

  std::vector<Simplex> simplicies;
  std::string line;
  char delimiter = ',';
  while (std::getline(inputFile, line)) {
    std::vector<std::string> tokens = split(line, delimiter);
    std::cout << tokens.size() << std::endl;
    for (int i = 0; ++i, i < tokens.size();) {
      std::cout << tokens.at(i) << std::endl;
    }
    Simplex simplex = Simplex(tokens);
    simplicies.push_back(simplex);
  }
  return simplicies;
}

std::vector<std::string> split(std::string &line, char delimiter) {

  // Fix split function, is incorrect.
  std::istringstream iss(line);
  std::vector<std::string> tokens;

  std::string token;
  while (std::getline(iss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

bool is_vertex(int length_token) { return length_token == 1; };
bool is_line(int length_token) { return length_token == 2; };
bool is_triangle(int length_token) { return length_token == 3; };
