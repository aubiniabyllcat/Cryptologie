#include <iostream>
#include <string>

using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

string chiffrementAffine(const string &message, int a, int b) {
    string cipherText = "";

    for (char c : message) {
        if (isalpha(c)) {
            char encryptedChar;
            if (isupper(c)) {
                encryptedChar = (a * (c - 'A') + b) % 26 + 'A';
            } else {
                encryptedChar = (a * (c - 'a') + b) % 26 + 'a';
            }
            cipherText += encryptedChar;
        } else {
            cipherText += c;
        }
    }

    return cipherText;
}

string dechiffrementAffine(const string &cipherText, int a, int b) {
    string decryptedText = "";

    int aInverse = modInverse(a, 26);

    if (aInverse != -1) {
        for (char c : cipherText) {
            if (isalpha(c)) {
                char decryptedChar;
                if (isupper(c)) {
                    decryptedChar = (aInverse * (c - 'A' - b + 26)) % 26 + 'A';
                } else {
                    decryptedChar = (aInverse * (c - 'a' - b + 26)) % 26 + 'a';
                }
                decryptedText += decryptedChar;
            } else {
                decryptedText += c;
            }
        }
    } else {
        cout << "Impossible de dechiffrer"<< a<< "n'a pas d'inverse modulaire." << endl;
    }

    return decryptedText;
}

int main() {
    string message;
    int a, b;
    int choix;

    // Saisie du message
    cout << "Entrez le message : ";
    getline(cin, message);

    // Saisie des coefficients a et b
    cout << "Entrez la valeur de a : ";
    cin >> a;

    cout << "Entrez la valeur de b : ";
    cin >> b;

    // Choix entre chiffrement et déchiffrement
    cout << "Choisissez l'operation : \n";
    cout << "1. Chiffrement\n";
    cout << "2. Dechiffrement\n";
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
        case 1: {
            // Chiffrement du message
            string cipherText = chiffrementAffine(message, a, b);
            cout << "Message chiffre : " << cipherText << endl;
            break;
        }
        case 2: {
            // Déchiffrement du message
            string decryptedText = dechiffrementAffine(message, a, b);
            cout << "Message dechiffre : " << decryptedText << endl;
            break;
        }
        default:
            cout << "Choix invalide.\n";
    }

    return 0;
}
