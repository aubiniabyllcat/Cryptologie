#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class GarnetWolseleyCipher {
public:
    GarnetWolseleyCipher(const string& key);
    string encrypt(const string& message) const;
    string decrypt(const string& message) const;

private:
    string generateTable(const string& key) const;

    string alphabet;
    string substitutionTable;
};

GarnetWolseleyCipher::GarnetWolseleyCipher(const string& key) {
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    substitutionTable = generateTable(key);
}

string GarnetWolseleyCipher::generateTable(const string& key) const {
    string modifiedKey = key;
    modifiedKey.erase(remove(modifiedKey.begin(), modifiedKey.end(), 'W'), modifiedKey.end());
    string table = key + alphabet;
    sort(table.begin(), table.end(), [&](char a, char b) {
        return key.find(a) < key.find(b);
    });
    return table;
}

string GarnetWolseleyCipher::encrypt(const string& message) const {
    string encryptedMessage = "";
    for (char c : message) {
        if (isalpha(c)) {
            size_t index = alphabet.find(toupper(c));
            char encryptedChar = substitutionTable[index];
            encryptedMessage += islower(c) ? tolower(encryptedChar) : encryptedChar;
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

string GarnetWolseleyCipher::decrypt(const string& message) const {
    string decryptedMessage = "";
    for (char c : message) {
        if (isalpha(c)) {
            size_t index = substitutionTable.find(toupper(c));
            char decryptedChar = alphabet[index];
            decryptedMessage += islower(c) ? tolower(decryptedChar) : decryptedChar;
        } else {
            decryptedMessage += c;
        }
    }
    return decryptedMessage;
}

int main() {
    string key;
    cout << "Entrez la cle : ";
    getline(cin, key);

    GarnetWolseleyCipher garnetWolseley(key);

    string message;
    cout << "Entrez le message en majuscules : ";
    getline(cin, message);

    // Chiffrement
    string encrypted = garnetWolseley.encrypt(message);
    cout << "Message chiffre : " << encrypted << endl;

    // Déchiffrement
    string decrypted = garnetWolseley.decrypt(encrypted);
    cout << "Message dechiffre : " << decrypted << endl;

    return 0;
}
