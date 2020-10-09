#include <iostream>
#include <cmath>
using namespace std; 

class Correlation {
public:
	double calcCorrelation(double xySum, double xSum, double ySum, double xSumSqr, double ySumSqr, int n); 
};

//.i
double Correlation::calcCorrelation(double xySum, double xSum, double ySum, double xSumSqr, double ySumSqr, int n) {
	double r = 0; 

	r = (n * xySum - xSum * ySum) / sqrt((n*xSumSqr - (xSum*xSum)) * (n * ySumSqr - (ySum * ySum)));

	return r;
}