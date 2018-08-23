#include <iostream>
#include <string>
using namespace std;

string PlayfairCipher(string message, string key, bool encrypt) {
	string key_matrix[5];
	string temp_key;
	bool exists;
	
	temp_key = key;
	for(char i = 'a'; i <= 'z'; i++) {
		if(i == 'i') {
			temp_key.push_back('i');
			i++;
		} else {
			temp_key.push_back(i);
		}
	}

	key = "";
	for(int i = 0; i < temp_key.length(); i++) {
		exists = false;
		for(int j = 0; j < key.length(); j++) {
			if(temp_key[i] == key[j]) {
				exists = true;
			}
		}
		if(!exists) {
			key.push_back(temp_key[i]);
		}
	}

	int j = 0;
	for(int i = 0; i < 5; i++) {
		key_matrix[i] = key.substr(i*5, 5);
		cout<<key_matrix[i]<<endl;
	}

	for(int i = 0; i < message.length(); i++) {
		if(message[i] == message[i+1]) {
			message.insert(i+1, "x");
			message.insert(i+3, "o");
		}
		message[i] = tolower(message[i]);
	}
	if(message.length() % 2 != 0) {
		message.push_back('x');
	}

	cout<<message;
	cout<<"\n--------------\n";

	string result = "";
	int ft[2], st[2];
	int tmp;
	for(int i = 0 ; i < message.length(); i += 2) {
		for(int j = 0; j < 5; j++) {


			for(int k = 0; k < 5; k++) {
				if(message[i] == key_matrix[j][k]) {
					ft[0] = j;
					ft[1] = k;
				}
				if(message[i+1] == key_matrix[j][k]) {
					st[0] = j;
					st[1] = k;
				}
			}
		}
		
		if(ft[0] == st[0]) {
			ft[1] = (ft[1] + 1) % 5;
			st[1] = (st[1] + 1) % 5;
		} else if(ft[1] == st[1]) {
			ft[0] = (ft[0] + 1) % 5;
			st[0] = (st[0] + 1) % 5;
		} else {
			tmp = ft[1];
			ft[1] = st[1];
			st[1] = tmp;
		}

		result.push_back(key_matrix[ft[0]][ft[1]]);
		result.push_back(key_matrix[st[0]][st[1]]);

	}

	cout<<result<<endl;

}

int main() {
	PlayfairCipher("hello", "hello", true);
	
	return 0;
}
