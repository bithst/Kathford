#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctype.h>

using namespace std;

int main(int argc, char* argv[]) {
	int random_number, prev_pos[2], new_pos[2];
	int iterations = 1000;
	string movement;

	new_pos[0] = new_pos[1] = 0;
	for(int step = 0; step < iterations; step++) {
		random_number = rand() % 100;

		prev_pos[0] = new_pos[0];
		prev_pos[1] = new_pos[1];
		if(random_number > 0 && random_number < 40) {
			movement = "Forward";
			new_pos[1]++;
		} else if(random_number > 40 && random_number < 70) {
			movement = "Backward";
			new_pos[1]--;
		} else if(random_number > 70 && random_number < 85) {
			movement = "Left";
			new_pos[0]--;
		} else if(random_number > 85 && random_number < 100) {
			movement = "Right";
			new_pos[0]++;
		}

		cout<<endl<<"Step: "<<step + 1<<endl;
		cout<<"Current position: ("<<prev_pos[0]<<", "<<prev_pos[1]<<")"<<endl;
		cout<<"Random Number: "<<random_number<<endl;
		cout<<"Movement: "<<movement<<endl;
		cout<<"New position: ("<<new_pos[0]<<", "<<new_pos[1]<<")"<<endl;
	}

}