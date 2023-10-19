#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>


using namespace std;

void toUpperCase(std::string& password) {
	for (char& c : password) {
		c = std::toupper(c);
	}
}

void repeatKey(string& inputKey, int passwordLength) {
	while (inputKey.size() < passwordLength) {
		inputKey += inputKey;
	}
	inputKey = inputKey.substr(0, passwordLength);  // Trim to match password length
}

void passwordToIndexes(string& inputPassword, char* alphabet, int* passwordIndexes, int alphabetLength) {
	for (int i = 0; i < alphabetLength; i++) {
		for (int k = 0; k < inputPassword.size(); k++) {
			if (alphabet[i] == inputPassword[k]) {
				passwordIndexes[k] = i;
			}
		}
	}
}

int main() {
	char alphabet[] = { 'A', 'Ą', 'B', 'C', 'Č', 'D', 'E', 'Ę', 'Ė', 'F', 'G', 'H', 'I', 'Į', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'Š', 'T', 'U', 'Ų', 'Ū', 'V', 'Z', 'Ž'};

	string inputPassword;
	string inputKey;

	int passwordIndexes[50];
	int keyIndexes[50];
	int codedPasswordIndexes[50];

	int alphabetLength = sizeof(alphabet);

	cout << "Iveskite pradini teksta" << endl;
	cin >> inputPassword;

	cout << "Iveskite slapta rakta" << endl;
	cin >> inputKey;

	toUpperCase(inputPassword);
	toUpperCase(inputKey);

	repeatKey(inputKey, inputPassword.size());

	passwordToIndexes(inputPassword, alphabet, passwordIndexes, alphabetLength);

	passwordToIndexes(inputKey, alphabet, keyIndexes, alphabetLength);

	for (int i = 0; i < inputPassword.size(); i++) {
		codedPasswordIndexes[i] = (passwordIndexes[i] + keyIndexes[i]) % alphabetLength;
	}

	cout << "Coded Password Indexes: ";
	for (int i = 0; i < inputPassword.size(); i++) {
		cout << codedPasswordIndexes[i] << " ";
	}

	return 0;

}
