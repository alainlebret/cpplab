/*
 * C++ programming laboratory work.
 *
 * Copyright (C) 1995-2018 Alain Lebret (alain.lebret@ensicaen.fr)
 * ENSICAEN
 * 6 Bd Maréchal Juin
 * 14000 Caen, France
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
 * or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef __CRYPTEUR_H    //Requis pour la classe courante
#define __CRYPTEUR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Crypteur {
private:
    /** Clef de chiffrement */
    string clef;

    /** Flux de lecture et écriture */
    fstream *flux;

public:
    /**
     * Constructeur de la classe Crypteur, permet l'initialisation des données membres de celle-ci.
     */
    Crypteur(string uneclef) {
        clef = uneclef;
        flux = new fstream[2];
    }

    // services permettant l'accès au données privées.
    string getclef() const { return clef; }
    void setclef(const string aclef) { clef = aclef; }
    int getlongueurClef() const { return clef.size(); }

    /**
     * Service de chiffrement.
     *
     * @param fichierEntree nom du fichier d'entrée à chiffrer (déchiffrer)
     * @param fichierSortie nom du fichier de sortie chiffré (déchiffré)
     */
    void crypter(const char *fichierEntree, const char *fichierSortie);

    /** Destructeur. */
    ~Crypteur() { clef = nullptr; delete[] flux; }

    /** Gestion du flux de sortie standard. */
    friend ostream &operator<<(ostream &os, Crypteur &unCrypteur);

    /** Gestion du flux d'entrée standard. */
    friend istream &operator>>(istream &is, Crypteur &unCrypteur);

};

#endif
