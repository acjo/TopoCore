#include "Simplex.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// split strings by a delimiter
std::vector<std::string> split(std::string &line, std::string delimiter);
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
  std::string delimiter = ",";
  while (std::getline(inputFile, line)) {
    std::vector<std::string> tokens = split(line, delimiter);
    std::cout << "line: " << line << std::endl;
    std::cout << "Tokens Size: " << tokens.size() << std::endl;
    for (int i = 0; i < tokens.size(); ++i) {
      std::cout << tokens.at(i) << std::endl;
    }
    Simplex simplex = Simplex(tokens);
    simplicies.push_back(simplex);
  }
  return simplicies;
}

std::vector<std::string> split(std::string &line, std::string delimiter) {

  // TODO: remove space from string

  std::vector<std::string> tokens;
  std::string current_line;
  size_t idx = line.find(delimiter);
  if (idx == std::string::npos) {
    tokens.push_back(line);
    return tokens;
  }

  std::string pre = "";
  std::string suff = "";
  for (int i = 0; i < line.size(); i++) {
    if (i < idx) {
      pre += line[i];
    } else if (i == idx) {
      continue;
    } else {
      suff += line[i];
    }
  }
  tokens.push_back(pre);

  std::vector<std::string> suff_tokens = split(suff, delimiter);
  for (int i = 0; i < suff_tokens.size(); i++) {
    if (suff_tokens.at(i) == "") {
      continue;
    }
    tokens.push_back(suff_tokens.at(i));
  }

  return tokens;
}

bool is_vertex(int length_token) { return length_token == 1; };
bool is_line(int length_token) { return length_token == 2; };
bool is_triangle(int length_token) { return length_token == 3; };
