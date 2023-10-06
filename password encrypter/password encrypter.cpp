#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    char alphabet[] = { 'A', 'Ą', 'B', 'C', 'Č', 'D', 'E', 'Ę', 'Ė', 'F', 'G', 'H', 'I', 'Į', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'Š', 'T', 'U', 'Ų', 'Ū', 'V', 'Y', 'Z' };
    string inputPassword;
    string inputKey;

    int alphabetLength = sizeof(alphabet) / sizeof(alphabet[0]);

    cout << "Iveskite pradini teksta" << endl;
    cin >> inputPassword;

    cout << "Iveskite slapta rakta" << endl;
    cin >> inputKey;

    const int inputPasswordLength = inputPassword.length();
    char* passwordArray = new char[inputPasswordLength + 1];
    strcpy(passwordArray, inputPassword.c_str());

    for (int i = 0; i < inputPasswordLength; i++)
    {
        std::cout << passwordArray[i];
    }


    
}
