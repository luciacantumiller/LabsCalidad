//.b = 28
#include <iostream>
#include <cmath>
#include "Simpson.h"

using namespace std;

class CalcHelper {
public:
	double XYSum(double* xValues, double* yValues, double n);
	double Average(double* values, double n);
	double Sum(double* values, double n);
	double SumSqrd(double* values, double n);
	double SumTwoNumbersSqrd(double* values, double n, double average);
	double GetX(double p, double dof);
	double StandardDeviation(double* xValues, double* yValues, double bZero, double bOne, double n);
};

//.i
double CalcHelper::XYSum(double* xValues, double* yValues, double n) {

	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += xValues[i] * yValues[i];
	}

	return sum;
}

//.i
double CalcHelper::Average(double* values, double n) {
	double avg = 0;

	for (int i = 0; i < n; i++) {
		avg += values[i];
	}

	return avg / n;
}

//.i
double CalcHelper::Sum(double* values, double n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += values[i];
	}

	return sum;
}

//.i
double CalcHelper::SumSqrd(double* values, double n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += values[i] * values[i];
	}

	return sum;
}

//.i 
double CalcHelper::SumTwoNumbersSqrd(double* values, double n, double average) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += pow(values[i] - average, 2);
	}

	return sum;
}

//.i 
double CalcHelper::GetX(double pt, double dof) {
	double x = 1, p, pAux, d = 0.5;
	char dir;
	Simpson simp;
	double i = 1;

	if (pt > 0 && pt < 0.5 && dof > 0) {
		pAux = simp.getSimpson(x, dof);

		if (pAux <= pt) {
			dir = 'r';
			x += d;
		}
		else {
			dir = 'l';
			x -= d;
		}

		do {
			p = pAux;
			pAux = simp.getSimpson(x, dof);
			if (pAux < pt) {
				if (dir == 'l') {
					d /= 2;
				}
				dir = 'r';

			}
			else if (pAux > pt) {
				if (dir == 'r') {
					d /= 2;
				}
				dir = 'l';
			}

			if (pAux < pt) {
				x += d;
			}
			else {
				x -= d;
			}

		} while (abs(p - pAux) > 0.00000001);
	}
	else {
		cout << endl << "Existe uno o mas errores en los valores ingresados. "; 
	}

	return x; 
}

//.i
double CalcHelper::StandardDeviation(double* xValues, double* yValues, double bZero, double bOne, double n) {
	double dev = 0; 
	for (int i = 0; i < n; i++) {
		dev += pow(yValues[i] - bZero - bOne*xValues[i] ,2);
	}

	dev *= (1 / (n - 2));

	dev = sqrt(dev);

	return dev; 
}

