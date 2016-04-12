
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/AABB_face_graph_triangle_primitive.h>
#include <CGAL/boost/graph/helpers.h>

#include <CGAL/Side_of_triangle_mesh.h>

#include "point_inside_helpers.h"

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_3 Point;
typedef CGAL::Surface_mesh<Point> Mesh;

int main(int argc, char** argv)
{
  const char* filename = (argc > 1) ? argv[1] : "data/elephant.off";
  std::ifstream input(filename);
  Mesh mesh;

  if (!input || !(input >> mesh)){
    std::cerr << "Error: can not read file.";
    return 1;
  }

  std::vector<Point> points;
  std::vector<bool> on_boundary;
  generate_near_boundary(mesh, points, on_boundary);
  test(mesh, points, on_boundary);

  points.clear();
  const int nb_query = (int)1.e4;
  points.reserve(nb_query);
  random_points<Point>(mesh, nb_query, back_inserter(points));
  test(mesh, points);

  //test compilation of constructor from AABB_tree  
  typedef CGAL::AABB_face_graph_triangle_primitive<Mesh> FGTP;
  typedef CGAL::AABB_traits<K, FGTP>    AABB_traits;
  typedef CGAL::AABB_tree<AABB_traits>  AABB_tree;

  AABB_tree tree(faces(mesh).first, faces(mesh).second, mesh);
  CGAL::Side_of_triangle_mesh<Mesh, K> inside_test(tree);

  CGAL::Bounded_side bs = inside_test(CGAL::ORIGIN);
  std::cout << "Origin is " << bs << std::endl;

  return 0;
}
