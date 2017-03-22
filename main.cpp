#include "earth.hpp"
#include <boost/geometry.hpp>
#include <boost/geometry/algorithms/distance.hpp>
#include <boost/geometry/core/cs.hpp>
#include <iostream>

namespace bg = boost::geometry;
typedef bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree> >
    spherical_point;
typedef bg::model::point<double, 2, bg::cs::geographic<bg::degree> >
    geographic_point;

int main() {
  double earth_radius = 6371000.0;
  point::set_radius(earth_radius);
  /* Assuming earth to be sphere in all these, but this isn't the case*/

  /* distance 268 km.*/
  point delhi(77.1024, 28.7041), jaipur(75.7873, 26.9124);
  spherical_point _delhi(77.1024, 28.7041), _jaipur(75.7873, 26.9124);
  geographic_point __delhi(77.1024, 28.7041), __jaipur(75.7873, 26.9124);
  std::cout << "(1) Distance between Delhi and Jaipur is aproximately "
            << point::distance(delhi, jaipur) / 1000 << " km\n";
  std::cout << "(2) Distance between Delhi and Jaipur is aproximately "
            << (distance(_jaipur, _delhi) * earth_radius) / 1000 << " km\n";
  std::cout << "(3) Distance between Delhi and Jaipur is aproximately "
            << distance(__jaipur, __delhi) / 1000 << " km\n";

  /* distance 11867 km.*/
  point new_york(-74.0059, 40.7128);
  spherical_point _new_york(-74.0059, 40.7128);
  geographic_point __new_york(-74.0059, 40.7128);
  std::cout << "(1) Distance between Jaipur and New York is aproximately "
            << point::distance(jaipur, new_york) / 1000 << " km\n";
  std::cout << "(2) Distance between Jaipur and New York is aproximately "
            << (distance(_jaipur, _new_york) * earth_radius) / 1000 << " km\n";
  std::cout << "(3) Distance between Jaipur and New York is aproximately "
            << distance(__jaipur, __new_york) / 1000
            << " km\n";

  /* distance 6646 km.*/
  point  paris(2.3522, 48.8566), chicago(87.6298, 41.8781);
  spherical_point _paris(2.3522, 48.8566), _chicago(87.6298, 41.8781);
  geographic_point __paris(2.3522, 48.8566), __chicago(87.6298, 41.8781);
  std::cout << "(1) Distance between Paris and Chicago is aproximately "
            << point::distance(paris, chicago) / 1000 << " km\n";
  std::cout << "(2) Distance between Paris and Chicago is aproximately "
            << (distance(_paris, _chicago) * earth_radius) / 1000 << " km\n";
  std::cout << "(3) Distance between Paris and Chicago is aproximately "
            << distance(__paris, __chicago) / 1000 << " km\n";
}
