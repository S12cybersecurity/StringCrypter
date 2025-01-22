#include <iostream>

using namespace std;

string XORencryptDecrypt(const string& input, char key) {
    string output = input;
    for (size_t i = 0; i < input.size(); i++) {
        output[i] ^= key;
    }
    return output;
}

int main()
{
    std::cout << "Hello World!\n";
    string encrpyted = "\x18\x3f\x39\x22\x25\x2c\x6b\x3f\x24\x6b\x0e\x25\x28\x39\x32\x3b\x3f\x41";
    cout << "Decrypted: " << XORencryptDecrypt(encrpyted, 'K');
}
