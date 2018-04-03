# TP C++ n<sup>o</sup> 10

## Chiffrement XOR
### Objectif
Réaliser une classe `CrypteurXOR` qui hérite de `Crypteur` et répondant à l'algorithme de chiffrement/déchiffrement mettant en oeuvre la méthode du OU Exclusif (en anglais XOR).

## Pré-requis
- TP n<sup>o</sup> 7
- le [chiffrement XOR](tp10/xor.md)

### Travail demandé

On désire créer une classe `CrypteurXOR` déclarée dans le fichier `xor.h` et implémentée dans le fichier `xor.cxx`. Cette classe héritera de la classe abstraite `Crypteur` (fichiers `crypteur.h` et `crypteur.cxx`). Le diagramme de classes UML est le suivant (`fstream` est une classe déclarée dans `<fstream>` et permet de gérer les fichiers de données) :

![Diagramme de classes](tp10/classes.png)

La fonction membre `chiffrer` doit répondre au prototype suivant :

```void chiffrer(const string fichierEntree, const string fichierSortie);```

#### 1. Algorithmes
Donner en pseudolangage l'algorithme de la fonction `chiffrer`. Justifier le type des variables choisies.

#### 2. Implémentation de la classe 
Implémenter en C++ les classes `Crypteur` et `CrypteurXOR`.

#### 3. Test de la classe
Valider la classe en chiffrant le fichier [texte.txt](tp10/texte.txt). Le fichier destination sera nommé `texte.$$$`. Éditer le fichier chiffré à l'aide d'un éditeur hexadécimal et vérifier son intégrité par rapport à l'algorithme XOR. Vérifier la fonction inverse en déchiffrant `texte.$$$` en `texte.ok`.


### Conditions
*   Compilateur GNU C++
*   Système d'exploitation Linux, Mac OS X ou Ms-Windows

### Critères d'évaluation
*   Qualité et organisation des documents rendus (codes sources, fichier LISEZMOI, etc.)
*   Autonomie
