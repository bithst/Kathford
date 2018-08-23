#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <ctype.h>

using namespace std;

int main() {
	int random_number, prev_pos[2], new_pos[2];
	string movement;
	
	int probablity[4] = {40, 30, 15, 15};
	int iterations = 1000;

	cout<<"Enter probablities"<<endl;
	cout<<"Forward: ";
	cin>>probablity[0]; cin.ignore();
	cout<<"Right: ";
	cin>>probablity[0]; cin.ignore();
	cout<<"Backward: ";
	cin>>probablity[0]; cin.ignore();
	cout<<"Left: ";
	cin>>probablity[0]; cin.ignore();

	cout<<endl<<"Enter the number of iterations: ";
	cin>>iterations; cin.ignore();

	cout<<setw(20)<<"Step";
	cout<<setw(20)<<"Current Position";
	cout<<setw(20)<<"Random Number";
	cout<<setw(20)<<"Movement";
	cout<<setw(20)<<"New Position";
	cout<<endl;

	new_pos[0] = new_pos[1] = 0;
	for(int step = 0; step < iterations; step++) {
		random_number = rand() % 100;

		prev_pos[0] = new_pos[0];
		prev_pos[1] = new_pos[1];
		if(random_number > 0 && random_number < probablity[0]) {
			movement = "Forward";
			new_pos[1]++;
		} else if(random_number > probablity[0] && random_number < probablity[0] + probablity[1]) {
			movement = "Right";
			new_pos[0]++;
		} else if(random_number > probablity[0] + probablity[1] && random_number < probablity[1] + probablity[2]) {
			movement = "Backward";
			new_pos[1]--;
		} else if(random_number > probablity[1] + probablity[2] && random_number < probablity[2] + probablity[3]) {
			movement = "Left";
			new_pos[0]--;
		}

		cout<<setw(20)<<step + 1;
		cout<<setw(20)<<"("<<prev_pos[0]<<", "<<prev_pos[1]<<")";
		cout<<setw(20)<<random_number;
		cout<<setw(20)<<movement;
		cout<<setw(20)<<"("<<new_pos[0]<<", "<<new_pos[1]<<")";
		cout<<endl;
	}
	
	return 0;
}