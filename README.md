
# Encrypting Strings to Evade Static Detection

Welcome to this repository! This project demonstrates a straightforward technique to bypass malicious string detection mechanisms employed by most security products, such as antivirus (AV) software and endpoint detection and response (EDR) tools. It uses a simple XOR encryption method to obfuscate strings in your code, making them harder to detect. While this method suffices for most cases, remember that it can still be reversed by malware analysts.

## Features
- XOR encryption and decryption for obfuscating strings
- Example implementations in C++
- Visualization of encrypted strings in hexadecimal format
- Decryption demonstration to restore the original string

---

## Project Overview

### XOR Encryption Basics
The XOR operation is a symmetric encryption method where the same key is used for both encryption and decryption. While it's not secure against advanced analysis, it can effectively evade basic static detection mechanisms.

### Alternatives to XOR Encryption
- **Base64 Encoding:** Simple obfuscation method but easily reversible.
- **AES (Advanced Encryption Standard):** Stronger encryption, harder to crack but detectable by advanced systems.
- **RC4:** A faster stream cipher with moderate security.
- **Polymorphic Encryption:** Dynamic encryption methods to further evade detection at the cost of complexity.

---

## Example Code

### Crypter Implementation
```cpp
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
        cout << "\x" << hex << setw(2) << setfill('0') << int(c);
    }
    cout << endl;
}

int main() {
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
```

This implementation shows how XOR can encrypt and decrypt strings. The output includes both the raw and hexadecimal representations of the encrypted data.

### Decryptor Implementation
```cpp
#include <iostream>

using namespace std;

string XORencryptDecrypt(const string& input, char key) {
    string output = input;
    for (size_t i = 0; i < input.size(); i++) {
        output[i] ^= key;
    }
    return output;
}

int main() {
    string encrypted = "\x18\x3f\x39\x22\x25\x2c\x6b\x3f\x24\x6b\x0e\x25\x28\x39\x32\x3b\x3f\x41";
    cout << "Decrypted: " << XORencryptDecrypt(encrypted, 'K');
}
```

The decryptor demonstrates how to reverse the XOR encryption using the same key and outputs the original plaintext.

---

## Detection and Analysis
The encryptor and decryptor themselves are not inherently malicious but could be flagged by certain security engines. Testing with sandboxes like LitterBox and ThreatCheck can help understand detection behaviors.

---

## Limitations
While XOR encryption can obfuscate strings effectively, it is not robust against:
- Known keys or predictable patterns
- Advanced analysis tools that can identify XOR operations

For stronger protection, consider using AES or polymorphic encryption.

---

## Contributions
Feel free to contribute by:
- Adding more encryption methods
- Enhancing detection testing
- Providing real-world scenarios and use cases

---

## License
This project is licensed under the MIT License.

---

## Disclaimer
This repository is for educational purposes only. The techniques demonstrated here are meant to illustrate how encryption works and should not be used for malicious activities.
