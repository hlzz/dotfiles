#include <iostream>
#include <fstream>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/Polygon_mesh_processing/self_intersections.h>
#include <CGAL/IO/Polyhedron_iostream.h>

#include <CGAL/Timer.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Polyhedron_3<K> Polyhedron;
typedef boost::graph_traits<Polyhedron>::face_descriptor face_descriptor;


int main(int argc, char** argv)
{
  const char* filename = (argc > 1) ? argv[1] : "data/elephant.off";
  std::ifstream input(filename);
  Polyhedron poly;

  if ( !input || !(input >> poly) ){
    std::cerr << "Error: can not read file.";
    return 1;
  }
  
  CGAL::Timer timer;
  timer.start();

  std::vector<std::pair<face_descriptor, face_descriptor> > intersected_tris;
  CGAL::Polygon_mesh_processing::self_intersections
    (poly,
     std::back_inserter(intersected_tris),
     CGAL::Polygon_mesh_processing::parameters::vertex_index_map(get(CGAL::vertex_point, poly)));
  bool intersecting_1 = !intersected_tris.empty();
  assert(!intersecting_1);

  std::cerr << "Self-intersection test took " << timer.time() << " sec." << std::endl;
  std::cerr << intersected_tris.size() << " pairs of triangles intersect." << std::endl;

  timer.reset();
  bool intersecting_2 =
    CGAL::Polygon_mesh_processing::does_self_intersect(poly,
      CGAL::Polygon_mesh_processing::parameters::vertex_index_map(get(CGAL::vertex_point, poly)));

  assert(intersecting_1 == intersecting_2);

  std::cerr << "does_self_intersect test took " << timer.time() << " sec." << std::endl;
  std::cerr
    << (intersecting_2 ? "There is a self-intersection." : "There are no self-intersections.")
    << std::endl;

  return 0;
}
