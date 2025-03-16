
class SimplicialComplex {
  SimplicialComplex();
  void add_simplices(std::vector<Simplex> simplices);
  std::set<Simplex, Simplex, Simplex> simplices;
};
