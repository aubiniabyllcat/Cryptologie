Ce projet implémente trois algorithmes de chiffrement : le chiffrement César, le chiffrement affine et le chiffrement de Garnet Wolseley.

Le chiffrement César(main.cpp) est un chiffrement de substitution simple où chaque lettre du texte brut est décalée d'un certain nombre de positions vers le haut ou vers le bas de l'alphabet.
Le chiffrement affine(affine.cpp) est une technique de chiffrement monoalphabétique utilisant une fonction mathématique linéaire.
Le chiffrement de Garnet Wolseley(garnet.cpp) est une technique de chiffrement par substitution réversible.
# Chiffrement/Déchiffrement César

Ce programme en C++ implémente l'algorithme du chiffrement César pour encrypter et décrypter des messages. 
Le chiffrement César est un chiffrement de substitution simple où chaque lettre dans le texte brut est décalée d'un certain nombre de positions vers le haut ou vers le bas de l'alphabet.

## Utilisation
1. Compiler le Programme
2. Entrer le Message :
Entrez le message que vous souhaitez encrypter ou décrypter lorsqu'on vous le demande.

3. Choisir l'Opération :
Vous serez invité à choisir entre encrypter et décrypter le message.

4. Entrer la Valeur de Décalage :
Entrez la valeur de décalage souhaitée pour le chiffrement César.

5. Voir le Résultat :
Le programme affichera le message encrypté ou décrypté en fonction de votre choix et de votre saisie.
 Exemple message encrypté
Ici on chiffre le mot bonjour![Capture d’écran (77)](https://github.com/aubiniabyllcat/cesarchiffrement/assets/140092517/9eb5007f-db2f-4de9-b9e5-92df1f6d0bf1)
 Exemple message décrypté
![Capture d’écran (78)](https://github.com/aubiniabyllcat/Cryptologie/assets/140092517/56be142e-325a-46fa-86ae-0af531e3a313)

ici on déchiffre erqmrxu qui donne bonjour
Le code fonctionne parfaitement.

7. Fonctions
ChiffrementCesar
string chiffrementCesar(const string& message, int decalage) {
   string resultat = "" ;
    for (char lettre : message) {
        if(isalpha(lettre)) {
            char base = (isupper(lettre)) ? 'A' : 'a';
            resultat += static_cast<char>((lettre-base+decalage)%26 +base);
        } else {
            resultat += lettre ;
        }
    }
    return resultat ;
}
Cette fonction prend un message et une valeur de décalage en entrée et renvoie le message encrypté  en utilisant l'algorithme du chiffrement César.

   

# Chiffrement/Déchiffrement affine

Ce programme en C++ met en œuvre le chiffrement et le déchiffrement affine, une technique de chiffrement monoalphabétique utilisant une fonction mathématique linéaire.

1. Utilisation
2. Saisie du message : Exécutez le programme et entrez le message à chiffrer lorsque vous y êtes invité.

3. Saisie des coefficients a et b : Entrez les coefficients a et b qui définiront la transformation affine.

a doit être non nul et premier entre eux avec 26.
b peut être une valeur entière arbitraire.
Résultats : Le programme affiche le message chiffré et le déchiffre pour vous.
![Capture d’écran (81)](https://github.com/aubiniabyllcat/Cryptologie/assets/140092517/fd0e74f8-ad60-457b-b885-d53078980e9e)

Fonction
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
Cette fonction prend un message et deux entiers a et b en entrée et renvoie le message encrypté en utilisant cet algorithme.

Notes
S'assurer que les coefficients a et b satisfont aux conditions nécessaires pour un chiffrement et un déchiffrement corrects.
Le programme vérifie également que a est non nul et premier entre eux avec 26.

# Chiffrement/Déchiffrement garnet
Explication
Le chiffrement de Garnet Wolseley est une technique de chiffrement par substitution réversible qui tire son nom du général britannique Garnet Joseph Wolseley du XVIIIe siècle. Bien que l'on ne soit pas certain que Wolseley soit l'inventeur de ce chiffre, son utilisation est attestée.

Principe
Suppression d'une lettre de l'alphabet : On commence par supprimer une lettre de l'alphabet. En français, on supprime la lettre "W" (remplacée si nécessaire par deux "V").

Choix d'une clé : Ensuite, on choisit une clé (par exemple, "PARDON").

Création de la table de substitution : On écrit dans l'ordre le reste de l'alphabet sans la lettre supprimée. Ensuite, on écrit cette séquence de lettres mais dans l'ordre inverse pour créer la table de substitution.

Chiffrement : Pour chiffrer, on utilise la table de substitution pour remplacer chaque lettre du message en clair.

Déchiffrement : Pour déchiffrer, on utilise la même table de substitution en sens inverse.
Fonction
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
Cette fonction est utilisée pour déchiffrer le message crypté en premenant en paramètre le message.

Exemple de code:
Entrez la cle : MAISON
Entrez le message en majuscules : SOYONS PATIENTS
Message chiffre :  VUAUT CYNXLTNV
Message dechiffre : SOYONS PATIENTS

##Comment utiliser le code
Compilez et exécutez le programme.
Entrez la clé .
Entrez le message en majuscules).
Le programme affiche le message chiffré et le déchiffre.
S'assurer de respecter les règles du chiffrement de Garnet Wolseley pour obtenir des résultats corrects.

   
   
