//.b = 14
#include <iostream>
using namespace std;

class Regression {
public:
	double BOne(double xySum, double xAvg, double yAvg, double xSumSqrd, int n);
	double BZero(double xAvg, double yAvg, double bOne);
};

//.i
double Regression::BOne(double xySum, double xAvg, double yAvg, double xSumSqrd, int n) {
	double bOne = 0;

	bOne = (xySum - (n * xAvg * yAvg)) / (xSumSqrd - (n * xAvg * xAvg));

	return bOne;
}

//.i
double Regression::BZero(double xAvg, double yAvg, double bOne) {
	double bZero = 0;

	bZero = yAvg - bOne * xAvg;

	return bZero;
}