#include <iostream>
#include <iomanip> 
using namespace std;

string XORencryptDecrypt(const string& input, char key) {
    string output = input;
    for (size_t i = 0; i < input.size(); i++) {
        output[i] ^= key;
    }
    return output;
}

void printAsHex(const string& input) {
    for (unsigned char c : input) {
        cout << "\\x" << hex << setw(2) << setfill('0') << int(c);
    }
    cout << endl;
}

int main()
{
    string variable = "String to Encrypt\n";
    char key = 'K';

    cout << "Original: " << variable;

    string variableEncrypted = XORencryptDecrypt(variable, key);
    cout << "Encrypted (raw): " << variableEncrypted << endl;

    cout << "Encrypted (hex): ";
    printAsHex(variableEncrypted);

    string variableDecrypted = XORencryptDecrypt(variableEncrypted, key);
    cout << "Decrypted: " << variableDecrypted;

    return 0;
}
