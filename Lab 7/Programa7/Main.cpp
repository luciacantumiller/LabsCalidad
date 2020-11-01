//.b=67
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "CalcHelper.h"
#include "GaussJordan.h"
//.d=2


using namespace std; 

//.i
int main() {
	int n = 0; 
	double xk = 0.0; 
	//.d=2
	double bZero; 
	double bOne; 
	double bTwo; 
	double bThree;
	double yk; 
	double wk;
	double zk; 

	double wValues[50];
	double xValues[50];
	double yValues[50];
	double zValues[50];

	double values[4][5];

	CalcHelper helper; 
	GaussJordan gauss; 
	//.d=2

	string fileName;
	ifstream myfile;
	string line; 

	cout << "Ingrese el nombre del archivo: ";
	cin >> fileName; 
	myfile.open(fileName);

	if (myfile.is_open()) {
		if (myfile.peek() != std::ifstream::traits_type::eof()) {
			getline(myfile, line);

			wk = stod(line.substr(0, line.find(',')));
			line.erase(0, line.find(',') + 1);
			xk = stod(line.substr(0, line.find(','))); //.m
			line.erase(0, line.find(',') + 1);
			yk = stod(line.substr(0, line.find(',')));

			if (xk < 0) {
				cout << "Error en valor de xk."; 
				return 0; 
			} else if (wk < 0) {
				cout << "Error en valor de wk.";
				return 0;
			} else if (yk < 0) {
				cout << "Error en valor de yk.";
				return 0;
			}

			while (!myfile.eof()) {
				getline(myfile, line);

				wValues[n] = stod(line.substr(0, line.find(',')));
				line.erase(0, line.find(',') + 1);
				xValues[n] = stod(line.substr(0, line.find(',')));
				line.erase(0, line.find(',') + 1);
				yValues[n] = stod(line.substr(0, line.find(',')));
				line.erase(0, line.find(',') + 1);
				zValues[n] = stod(line.substr(0, line.length()));


				if (xValues[n] < 0 || yValues[n] < 0 || wValues[n] < 0 || zValues[n] < 0) { //.m
					cout << "Error en un valor de un cuadruplo."; //.m
					return 0;
				}
				n++;
			}


			//.d=11
			values[0][0] = n; 
			values[0][1] = helper.Sum(wValues, n);
			values[0][2] = helper.Sum(xValues, n);
			values[0][3] = helper.Sum(yValues, n);
			values[0][4] = helper.Sum(zValues, n);

			values[1][0] = helper.Sum(wValues, n);
			values[1][1] = helper.SumSqrd(wValues, n);
			values[1][2] = helper.XYSum(wValues, xValues, n);
			values[1][3] = helper.XYSum(wValues, yValues, n);
			values[1][4] = helper.XYSum(wValues, zValues, n);

			values[2][0] = helper.Sum(xValues, n);
			values[2][1] = helper.XYSum(xValues, wValues, n);
			values[2][2] = helper.SumSqrd(xValues, n);
			values[2][3] = helper.XYSum(xValues, yValues, n);
			values[2][4] = helper.XYSum(xValues, zValues, n);

			values[3][1] = helper.XYSum(yValues, wValues, n);
			values[3][2] = helper.XYSum(yValues, xValues, n);
			values[3][3] = helper.SumSqrd(yValues, n);
			values[3][4] = helper.XYSum(yValues, zValues, n);
			values[3][0] = helper.Sum(yValues, n);
						
			gauss.gaussJordanElimination(values, 4);

			bZero = gauss.getbZero();
			bOne = gauss.getbOne();
			bTwo = gauss.getbTwo(); 
			bThree = gauss.getbThree(); 
			
			zk = bZero + bOne * wk + bTwo * xk + bThree * yk; 

			cout << "N = " << n << endl;
			printf("wk = %.5f \n", wk);
			printf("xk = %.5f \n", xk);
			printf("yk = %.5f \n", yk);
			cout << "------------" << endl; 
			//.d=3
			printf("b0 = %.5f \n", bZero);
			printf("b1 = %.5f \n", bOne);
			printf("b2 = %.5f \n", bTwo);
			printf("b3 = %.5f \n", bThree);
			cout << "------------" << endl; 
			printf("zk = %.5f \n", zk); //.m

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
