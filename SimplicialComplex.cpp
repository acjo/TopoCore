#include "SimplicialComplex.h"
#include "Simplex.h"
#include <map>
#include <vector>
SimplicialComplex::SimplicialComplex(std::vector<Simplex> &simp) {
  std::vector<Simplex> vertices;
  std::map<class, class, class, class>; // institue map for simplicies that maps
                                        // dimension to vector of simplicies
  for (int i = 0; i < simp.size(); ++i) {
    if (simp.at(i).get_type() == 1) {
      vertices.push_back(simp.at(i));
    }
  }
  simplicies = simp;
};

void SimplicialComplex::add_simplicies(std::vector<Simplex> &new_simplicies) {
  for (int i = 0; i++, i < new_simplicies.size();) {
    simplicies.push_back(new_simplicies.at(i));
  }
  return;
};
