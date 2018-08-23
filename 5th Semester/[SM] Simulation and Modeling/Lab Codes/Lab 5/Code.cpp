#include <cstdlib>
#include <math.h>
#include <ctime>
#include <iostream>
using namespace std;

double monteCarloPI(double);
 
int main() {
	double throws;
	cout << "Enter number of throws: ";
	cin >> throws;

	cout<< "Estimated value of PI: " << monteCarloPI(throws) << endl;

	return 0;
}

double monteCarloPI(double throws) {
	double x, y;
	double pi;
	srand(time(NULL));

	int insideCircle = 0;

	for(int i = 0; i < throws; i++) {
		x = (double)rand() / (RAND_MAX);
		y = (double)rand() / (RAND_MAX);
		
		if(sqrt(x * x + y * y) <= 1)
			insideCircle++;
	}
	pi = (double)(4 * insideCircle) / throws;

	return pi;
}