#ifndef EARTH_HPP
#define EARTH_HPP

#include <math.h>

class point {
	double longitude;
	double latitude;
	static double radius;
public:
	point(double _longitude, double _latitude) {
		longitude = _longitude * M_PI / 180.0;
		latitude = _latitude * M_PI / 180.0;
	}

	static double distance(const point&, const point&);
	static void set_radius(const double&);

	double get_latitude_degrees() const {
		return latitude * 180.0 / M_PI;
	}

	double get_longitude_degrees() const {
		return longitude * 180.0 / M_PI;
	}

	double get_latitude_radians() const {
		return latitude;
	}

	double get_longitude_radians() const {
		return longitude;
	}
};

#endif /*EARTH_HPP*/
