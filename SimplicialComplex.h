#pragma once

#include "Simplex.h"
#include <map>
#include <vector>
class SimplicialComplex {
private:
  std::vector<Simplex> vertices;
  std::vector<Simplex> simplicies;

public:
  SimplicialComplex(std::vector<Simplex> &simplicies);
  void add_simplicies(std::vector<Simplex> &simplicies);
  // std::vector<Simplex> boundary_p_chain_mod_2(int dim);
  // TODO: Add boundary_p_chain computing
  // TODO: Add functionality to dispaly boundary p-chain
};
