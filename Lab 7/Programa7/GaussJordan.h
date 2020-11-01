#include <iostream>

using namespace std;

class GaussJordan {
public:
	double getbZero();
	double getbOne(); 
	double getbTwo(); 
	double getbThree();
	void gaussJordanElimination(double values[4][5], int n);
private:
    double bZero; 
    double bOne; 
    double bTwo; 
    double bThree;
};

//.i
void GaussJordan::gaussJordanElimination(double values[4][5], int n) {
    int k = 0, c;
    double aux = 0;
    
    for (int i = 0; i < n; i++) {
        if (values[i][i] == 0) {
            c = 1;
            while ((i + c) < n && values[i + c][i] == 0) {
                c++;
            }
            if ((i + c) == n) {
                break;
            }
            for (int j = i; k <= n; k++) {
                swap(values[j][k], values[j + c][k]);
            }
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double aux = values[j][i] / values[i][i];
                for (k = 0; k <= n; k++) {
                    values[j][k] = values[j][k] - (values[i][k]) * aux;
                }
            }
        }
    }
    

    this->bZero = values[0][n] / values[0][0];
    this->bOne = values[1][n] / values[1][1];
    this->bTwo = values[2][n] / values[2][2];
    this->bThree = values[3][n] / values[3][3];
}

//.i
double GaussJordan::getbZero() {
    return this->bZero;
}

//.i
double GaussJordan::getbOne() {
    return this->bOne;
}

//.i
double GaussJordan::getbTwo() {
    return this->bTwo;
}

//.i
double GaussJordan::getbThree() {
    return this->bThree;
}