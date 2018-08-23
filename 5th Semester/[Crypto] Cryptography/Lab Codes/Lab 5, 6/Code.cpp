#include <iostream>
#include <string>
using namespace std;

int *generateKey(int *key) {
	int p10_permutation[10] = {	3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
	int p8_permutation[8] = { 6, 3, 7, 4, 8, 5, 10, 9 };
	int P10[10];
	int K[2][8];

	// for(int i = 1; i <= 2; i++) {
	// 	for (int i = 0; i < 10; i++) {
	// 		P10[i] = key[p10_permutation[i] - 1];
	// 	}
	// }
	
	for (int i = 0; i < 10; i++) {
		P10[i] = key[p10_permutation[i] - 1];
	}

	cout << "P10: ";
	for (int i = 0; i < 10; i++) {
		cout << P10[i];
	}
	cout << endl;

	int tmp[2] = { P10[0], P10[5] };
	for (int i = 0; i < 5; i++) {
		if (i == 4) {
			P10[i] = tmp[0];
			P10[i + 5] = tmp[1];
			continue;
		}
		
		P10[i] = P10[i + 1];
		P10[i + 5] = P10[i + 6];
	}

	cout << "P10 shifted: ";
	for (int i = 0; i < 10; i++) {
		cout << P10[i];
	}
	cout << endl;

	return &P10[0];
}

int* sBox(int* P, int Si) {
	int result[2] = {0, 0};
	int S[2][16] = {
		{
			1, 0, 3, 2,
			3, 2, 1, 0,
			0, 2, 1, 3,
			3, 1, 3, 2
		},
		{
			0, 1, 2, 3,
			2, 0, 1, 3,
			3, 0, 1, 0,
			2, 1, 0, 3
		}
	};

	switch(S[Si][4 * (P[0] * 2 + P[3]) + (P[1] * 2 + P[2])]) {
		case 1:
			result[0] = 1;
			break;

		case 2:
			result[1] = 1;
			break;

		case 3:
			result[0] = result[1] = 1;
			break;
	}

	return &result[0];
}

int xOR(int a, int b) {
	return (a + b) % 1;
}

void printer(int* arr, int len) {
	for(int i = 0; i < len; i++) {
		cout<<arr[i];
	}
	cout<<endl;
}

int* F(int* R, int* K, int Ki) {
	// Expansion Permutaton
	int EP_permutation[8] = {4, 1, 2, 3, 2, 3, 4, 1};
	int EP[8];
	for(int i = 0; i < 8; i++) {
		EP[i] = R[EP_permutation[i] - 1];
	}

	// Exclusive OR
	int P[8];
	for(int i = 0; i < 8; i++) {
		P[i] = xOR(EP[i], K[8 * Ki + i]); 
	}

	// S boxes
	int *S[4];
	S[0] = sBox(&P[0], 0);
	S[2] = sBox(&P[0], 1);

	// Fourth Permutation
	int P4_permutation[4] = {2, 4, 3, 1};
	int P4[4];
	for(int i = 0; i < 4; i++) {
		P4[i] = *S[P4_permutation[i] - 1];
	}

	// Exclusive OR (again)
	int *result;
	for(int i = 0; i < 4; i++) {
		result[i] = xOR(K[i], P4[i]);
	}

	return result;
}

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int* encrypt(int* message, int* K) {
	// Initial Permutation
	int IP_permutation[8] = {2, 6, 3, 1, 4, 8, 5, 7};
	int inp[8];
	for(int i = 0; i < 8; i++) {
		inp[i] = message[IP_permutation[i] - 1];
	}
	printer(inp, 8);
	printer(message, 8);

	int *sw = F(inp, K, 0);

	for(int i = 0; i < 4; i++) {
		swap(sw[i], sw[i + 4]);
	}

	int *result = F(sw, K, 1);
	
	// Inverse Permutation
	int IIP_permutation[8] = {4, 1, 3, 5, 7, 2, 8, 6};
	int IIP[8];
	for(int i = 0; i < 8; i++) {
		IIP[i] = result[IIP_permutation[i] - 1];
	}

	return &IIP[0];
}

int main() {
	int message[8] = {1, 0, 0, 1, 0, 1, 1, 0};
	int K[16] = {
		1, 0, 1, 0, 0, 1, 0, 0,
		0, 1, 0, 0, 0, 0, 1, 1
	};

	// For checking
	// for(int i = 0; i < 2; i++) {
	// 	cout<<"K"<<i+1<<": ";
	// 	for(int j = 0; j < 8; j++) {
	// 		cout<<K[8 * i + j];
	// 	}
	// 	cout<<endl;
	// }

	printer(encrypt(&message[0], &K[0]), 8);

	return 0;
}