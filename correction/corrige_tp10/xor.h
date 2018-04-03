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
#ifndef __XOR_H
#define __XOR_H

#include "crypteur.h"

class CrypteurXOR : public Crypteur {
public:
    /**
     * Constructeur logique de la classe Crypteur, permet l'initialisation des données membres de celle-ci.
     */
    CrypteurXOR(string uneclef): Crypteur(uneclef) {}

    /**
	 * @brief Service de chiffrement.
	 *
	 * @param fichierEntree nom du fichier d'entrée à chiffrer (déchiffrer)
	 * @param fichierSortie nom du fichier de sortie chiffré (déchiffré)
	 */
    void chiffrer(const char *fichierEntree, const char *fichierSortie);

    /**
     * @brief Service de chiffrement.
     *
     * @param entree flux d'entrée à chiffrer (déchiffrer)
     * @param sortie flux de sortie chiffré (déchiffré)
     */
    void chiffrer(istream &entree, ostream &sortie);

    /** Destructeur. */
    //~CrypteurXOR():~Crypteur() {}

};

#endif
