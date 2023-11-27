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
 Exemple message encrypté![Capture d’écran (77)](https://github.com/aubiniabyllcat/cesarchiffrement/assets/140092517/9eb5007f-db2f-4de9-b9e5-92df1f6d0bf1)
 Exemple message décrypté![Capture d’écran (78)](https://github.com/aubiniabyllcat/cesarchiffrement/assets/140092517/f527cb59-7fa5-4d27-917d-ce204d382a52)

7. Fonctions
ChiffrementCesar
Cette fonction prend un message et une valeur de décalage en entrée et renvoie le message encrypté ou décrypté en utilisant l'algorithme du chiffrement César.

string chiffrementCesar(const string& message, int decalage);
   


   
   
