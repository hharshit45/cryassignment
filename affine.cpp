#include <iostream>
#include <string>

using namespace std;

string encrypt(string plain_text, int key_a, int key_b) {
    string encrypted_text = "";
    for (char& ch : plain_text) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                encrypted_text += char((key_a * (ch - 'A') + key_b) % 26 + 'A');
            } else {
                encrypted_text += char((key_a * (ch - 'a') + key_b) % 26 + 'a');
            }
        } else {
            encrypted_text += ch;
        }
    }
    return encrypted_text;
}

string decrypt(string cipher_text, int key_a, int key_b) {
    string decrypted_text = "";
    int mod_inverse = 0;
    for (int i = 0; i < 26; i++) {
        if ((key_a * i) % 26 == 1) {
            mod_inverse = i;
            break;
        }
    }
    for (char& ch : cipher_text) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                decrypted_text += char((mod_inverse * (ch - 'A' - key_b + 26)) % 26 + 'A');
            } else {
                decrypted_text += char((mod_inverse * (ch - 'a' - key_b + 26)) % 26 + 'a');
            }
        } else {
            decrypted_text += ch;
        }
    }
    return decrypted_text;
}

int main() {
    string plaintext = "Hello, World!";
    int key_a = 5;  // Multiplicative key (must be coprime with 26)
    int key_b = 8;  // Additive key

    // Encryption
    string encrypted = encrypt(plaintext, key_a, key_b);
    cout << "Encrypted Text: " << encrypted << endl;

    // Decryption
    string decrypted = decrypt(encrypted, key_a, key_b);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
