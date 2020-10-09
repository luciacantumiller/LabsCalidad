//.b=48
#include <iostream>
#include "Simpson.h"

//.d=4

using namespace std;

//.i
int main() {
	//.d=39
	double x, dof, p; 
	Simpson simp; 

	cout << "Ingresar valor de x: ";
	cin >> x;

	cout << "Ingresar valor de dof: ";
	cin >> dof; 
	
	if (x > 0 && dof > 0) {
		p = simp.getSimpson(x, dof);

		printf("x = %.5f \n", x);
		cout << "dof = " << dof << endl;
		printf("p = %.10f \n", p);
	} else {
		cout << endl << "Existe uno o mas errores en los valores ingresados. "; 
	}
	
	
	return 0;
}