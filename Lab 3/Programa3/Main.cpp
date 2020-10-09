//.b=48
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

//.d=2
#include "CalcHelper.h"
#include "Regression.h"
#include "Correlation.h"


using namespace std; 

//.i
int main() {
	//.d=6
	int n = 0; 
	double xk = 0.0; 
	double r; 
	double rSqr; 
	double bZero; 
	double bOne; 
	double yk; 

	double xValues[50];
	double yValues[50];

	CalcHelper helper; 
	Regression reg; 
	Correlation cor; 

	string fileName;
	ifstream myfile;
	string line; 

	cout << "Ingrese el nombre del archivo: ";
	cin >> fileName; 
	myfile.open(fileName);

	if (myfile.is_open()) {
		if (myfile.peek() != std::ifstream::traits_type::eof()) {
			getline(myfile, line);

			//.d=14
			xk = stod(line); 
			if (xk < 0) {
				cout << "Error en valor de xk."; 
				return 0; 
			}

			while (!myfile.eof()) {
				getline(myfile, line);

				xValues[n] = stod(line.substr(0, line.find(',')));
				yValues[n] = stod(line.substr(line.find(',') + 1, line.length()));

				if (xValues[n] < 0 || yValues[n] < 0) {
					cout << "Error en valor de x o y.";
					return 0;
				}
				n++;
			}

			double xySum = helper.XYSum(xValues, yValues, n);
			double xSum = helper.Sum(xValues, n);
			double ySum = helper.Sum(yValues, n);
			double xSumSqr = helper.SumSqrd(xValues, n);
			double ySumSqr = helper.SumSqrd(yValues, n);
			double xAvg = helper.Average(xValues, n);
			double yAvg = helper.Average(yValues, n);

			r = cor.calcCorrelation(xySum, xSum, ySum, xSumSqr, ySumSqr, n);
			bOne = reg.BOne(xySum, xAvg, yAvg, xSumSqr, n);
			bZero = reg.BZero(xAvg, yAvg, bOne);

			yk = bZero + bOne * xk;

			cout << "N = " << n << endl;
			cout << "xk = " << xk << endl;
			printf("r = %.5f \n", r);
			printf("r2 = %.5f \n", r * r);
			printf("b0 = %.5f \n", bZero);
			printf("b1 = %.5f \n", bOne);
			printf("yk = %.5f \n", yk);

			//.d=7
		}
		else {
			cout << "El archivo seleccionado esta vacio. ";
			return 0; 
		}
	} else {
		cout << "El archivo seleccionado no existe." << endl;
	}

	myfile.close();
	return 0; 
}
