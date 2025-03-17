#include "SimplicialComplex.h"
#include "Simplex.h"
#include <vector>
SimplicialComplex::SimplicialComplex(){};
SimplicialComplex::SimplicialComplex(std::vector<Simplex> &simplicies) {
  this->simplicies = simplicies;
};

void SimplicialComplex::add_simplicies(std::vector<Simplex> &new_simplicies) {
  for (int i = 0; i++, i < new_simplicies.size();) {
    simplicies.push_back(new_simplicies.at(i));
  }
  return;
};
