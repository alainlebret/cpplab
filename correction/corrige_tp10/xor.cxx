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
#include "xor.h"

/**
 * Service de chiffrement utilisant la méthode XOR.
 *
 * @param fichierEntree nom du fichier d'entrée à chiffrer (déchiffrer)
 * @param fichierSortie nom du fichier de sortie chiffré (déchiffré)
 */
void CrypteurXOR::chiffrer(const char *fichierEntree, const char *fichierSortie) {
    int caractere, i = 0;

    flux[0].open(fichierEntree, ios::in | ios::binary);
    flux[1].open(fichierSortie, ios::out | ios::binary);


    while ((caractere = flux[0].get()) != EOF) {
        if (i > clef.size()) i = 0;
        caractere = caractere ^ clef[i++];
        flux[1].put((unsigned char) caractere);
    }

    flux[0].close();
    flux[1].close();
}

void CrypteurXOR::chiffrer(istream &entree, ostream& sortie) {
    int caractere, i = 0;

    while ((caractere = entree.get())) {
        if (i > clef.size()) i = 0;
        caractere = caractere ^ clef[i++];
        sortie.put((unsigned char) caractere);
    }
}

