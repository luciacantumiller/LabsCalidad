#include <iostream>

using namespace std; 

class CalcHelper {
public:
	double XYSum(double* xValues, double* yValues, int n);
	double Average(double* values, int n);
	double Sum(double* values, int n);
	double SumSqrd(double* values, int n);
};

//.i
double CalcHelper::XYSum(double* xValues, double* yValues, int n) {

	double sum = 0; 

	for (int i = 0; i < n; i++) {
		sum += xValues[i] * yValues[i];
	}

	return sum;
}

//.i
double CalcHelper::Average(double* values, int n) {
	double avg = 0;

	for (int i = 0; i < n; i++) {
		avg += values[i];
	}

	return avg/n;
}

//.i
double CalcHelper::Sum(double* values, int n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += values[i];
	}

	return sum;
}

//.i
double CalcHelper::SumSqrd(double* values, int n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += values[i]* values[i];
	}

	return sum;
}
