//.b=48
#include <iostream>
#include <cmath>
#include "Simpson.h"

using namespace std;

//.i
int main() {
	double x = 1, dof, pt, p, pAux, d = 0.5; //m
	char dir;
	Simpson simp;
	int i = 1;

	cout << "Ingresar valor de p: "; //m
	cin >> pt; //m

	cout << "Ingresar valor de dof: ";
	cin >> dof;

	if (pt > 0 && pt < 0.5 && dof > 0) {
		pAux = simp.getSimpson(x, dof); //m

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

		printf("p = %.5f \n", pt); //m
		cout << "dof = " << dof << endl;
		printf("x = %.5f \n", x);
	}
	else {
		cout << endl << "Existe uno o mas errores en los valores ingresados. ";
	}

	return 0;
}