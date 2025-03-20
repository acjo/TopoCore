#include "Simplex.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// build simplices from CSV
std::vector<Simplex> build_simplices_csv(std::string &fileName);
// split strings by a delimiter
std::vector<std::string> split(std::string &line, char delimiter);
// removes new line and empty spaces from a string
std::string strip(const std::string &line);
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
    for (int i = 0; i < tokens.size(); ++i) {
      tokens.at(i) = strip(tokens.at(i));
    }
    std::cout << "line: " << line << std::endl;
    std::cout << "Tokens Size: " << tokens.size() << std::endl;
    std::cout << "All Tokens:" << std::endl;
    for (int i = 0; i < tokens.size(); ++i) {
      std::cout << tokens.at(i) << std::endl;
    }
    Simplex simplex = Simplex(tokens);
    simplicies.push_back(simplex);
  }
  return simplicies;
}

std::string strip(const std::string &str) {
  std::string result = str;

  // Remove spaces and newlines from the beginning
  result.erase(0, result.find_first_not_of(" \n\r\t"));

  // Remove spaces and newlines from the end
  size_t last = result.find_last_not_of(" \n\r\t");
  if (last != std::string::npos)
    result.erase(last + 1);

  return result;
}

std::vector<std::string> split(std::string &line, char delimiter) {

  std::vector<std::string> tokens;
  std::string current_line;
  size_t idx = line.find(delimiter);
  if (idx == std::string::npos) {
    tokens.push_back(line);
    return tokens;
  }

  std::string new_token = "";
  for (int i = 0; i < line.size(); ++i) {
    if (line.at(i) == delimiter) {
      tokens.push_back(new_token);
      new_token.clear();
      continue;
    }
    new_token += line.at(i);
  }

  return tokens;
}

bool is_vertex(int length_token) { return length_token == 1; };
bool is_line(int length_token) { return length_token == 2; };
bool is_triangle(int length_token) { return length_token == 3; };
