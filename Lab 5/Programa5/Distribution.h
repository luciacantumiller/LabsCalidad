//.b=19
#include <iostream>
#include <cmath>

class Distribution {
public:
	double Dist(double x, double dof);
private:
	double f;
	double Gamma(double x);
};

//.i
double Distribution::Dist(double x, double dof) {
	f = (Gamma((dof + 1.0) / 2.0) / (pow(dof * (2 * acos(0.0)), 0.5) * Gamma(dof / 2.0))) * (pow((1.0 + (pow(x, 2) / dof)), (dof + 1.0) / -2.0));
	return f;
}

//.i
double Distribution::Gamma(double x) {
	double g = 1;
	x--;

	while (x > 0) {
		g *= x;
		x--;

		if (x > 0 && x < 1) {
			g *= sqrt(2 * acos(0.0));
		}
	}

	return g;
}