//.b=44
#include <iostream>
#include <cmath>

#include "Distribution.h"

class Simpson {
public:
	double getSimpson(double x, double dof);
private:
	double SimpsonRule();
	double CalculateDiference();
	double x;
	double dof;
	double p;
	double pAux;
	double w;
	int num_seg;
};

//.i
double Simpson::getSimpson(double xVal, double dofVal) {
	this->x = xVal;
	this->dof = dofVal;
	this->p = 0;
	this->pAux = 0;
	this->w = 0;
	this->num_seg = 10;

	return CalculateDiference();

}

//.i
double Simpson::SimpsonRule() {
	double f = 0;
	w = x / num_seg;
	Distribution dist;
	double a;

	f += (w / 3) * dist.Dist(0, dof);

	for (int i = 1; i < num_seg; i++) {
		if (i % 2 == 0) {
			f += (w / 3) * 2.0 * dist.Dist(i * w, dof);
		}
		else {
			f += (w / 3) * 4.0 * dist.Dist(i * w, dof);
		}
	}

	f += (w / 3) * dist.Dist(x, dof);

	return f;
}

//.i
double Simpson::CalculateDiference() {
	pAux = SimpsonRule();

	do {
		p = pAux;
		num_seg *= 2;
		pAux = SimpsonRule();
	} while (p - pAux > 0.0000001);

	return pAux;
}