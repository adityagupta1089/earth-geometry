#include "earth.hpp"
#include <iostream>
#include <math.h>

double haversine(double theta);

double point::radius = 6371000.0;

double point::distance(const point &p1, const point &p2) {
  double h = haversine(p2.longitude - p1.longitude) +
             cos(p2.longitude) * cos(p1.longitude) *
                 haversine(p2.latitude - p1.latitude);
  return 2 * point::radius * asin(sqrt(h));
}

void point::set_radius(const double &_radius) { point::radius = _radius; }

double haversine(double theta) { return pow(sin(theta / 2), 2); }
