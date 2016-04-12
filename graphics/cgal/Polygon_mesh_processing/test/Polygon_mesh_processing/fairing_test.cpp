#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/boost/graph/properties_Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>

#include <CGAL/Polygon_mesh_processing/fair.h>

#include <CGAL/Timer.h>

#include <iostream>
#include <fstream>
#include <iterator>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Polyhedron_3<K> Polyhedron;

typedef K::Point_3 Point;
typedef K::Vector_3 Vector;
typedef boost::graph_traits<Polyhedron>::vertex_descriptor vertex_descriptor;
typedef boost::graph_traits<Polyhedron>::face_descriptor   face_descriptor;

void test(const char* filename)
{
  //run test for a Polyhedron
  Polyhedron poly; // file should contain oriented polyhedron
  std::ifstream input(filename);

  if (!input || !(input >> poly))
  {
    std::cerr << "Error: cannot read Polyhedron : " << filename << "\n";
    assert(!poly.empty());
    assert(false);
    return;
  }

  //try to fair the mesh
  std::size_t nbv =
    std::distance(vertices(poly).first, vertices(poly).second);

  CGAL::Polygon_mesh_processing::fair(poly, vertices(poly));

  std::size_t nbv2 =
    std::distance(vertices(poly).first, vertices(poly).second);

  assert(nbv == nbv2);

  std::ofstream faired_off("faired.off");
  faired_off << poly;
  faired_off.close();
}

int main(int argc, char* argv[])
{
  const char* filename = (argc > 1) ? argv[1] : "data/elephant.off";

  test(filename);

  std::cerr << "All done." << std::endl;

  return 0;
}
