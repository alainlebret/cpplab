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
#ifndef __CRYPTEUR_H
#define __CRYPTEUR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Classe de chiffrement/déchiffrement de fichiers utilisant la méthode du XOR.
 */
class Crypteur {
protected:
    /** Clef de chiffrement */
    string clef;

    /** Flux de lecture et écriture des fichiers */
    fstream *flux;

public:
    /**
     * Constructeur logique de la classe Crypteur, permet l'initialisation des
     * données membres de celle-ci.
     */
    Crypteur(string uneclef) {
        clef = uneclef;
        flux = new fstream[2];
    }

    /**
     * Constructeur par défaut de la classe Crypteur, permet l'initialisation
     * des données membres de celle-ci.
     */
    Crypteur();

    /**
     * Retourne la clef de chiffrement.
     */
    string getclef() const { return clef; }

    /**
     * Met à jour la clef de chiffrement.
     */
    void setclef(const string &aclef) { clef = aclef; }

    /**
     * Retourne la longueur de la clef de chiffrement.
     */
    int getlongueurClef() const { return static_cast<int>(clef.size()); }

    /**
     * @brief Service de chiffrement.
     *
     * Chiffrement du fichier d'entrée et enregistrement dans le fichier de
     * sortie. Cette fonction virtuelle pure doit être redéfinie dans toute
     * classe enfant.
     *
     * @param fichierEntree nom du fichier d'entrée à chiffrer (déchiffrer)
     * @param fichierSortie nom du fichier de sortie chiffré (déchiffré)
     */
    virtual void chiffrer(const char *fichierEntree, const char *fichierSortie) = 0;

    /**
     * @brief Service de chiffrement.
     *
     * Chiffrement du flux d'entrée et transfert dans le flux de sortie.
     * Cette fonction virtuelle pure doit être redéfinie dans toute classe
     * enfant.
     *
     * @param entree flux d'entrée à chiffrer (déchiffrer)
     * @param sortie flux de sortie chiffré (déchiffré)
     */
    virtual void chiffrer(istream &entree, ostream &sortie) = 0;

    /** Destructeur. */
    ~Crypteur() {
        clef = nullptr;
        delete[] flux;
    }

    /** @brief Gestion du flux de sortie standard. */
    friend ostream &operator<<(ostream &os, Crypteur &unCrypteur);

    /** @brief Gestion du flux d'entrée standard. */
    friend istream &operator>>(istream &is, Crypteur &unCrypteur);

};

#endif
