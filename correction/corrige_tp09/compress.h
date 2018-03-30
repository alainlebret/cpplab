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
#ifndef __COMPRESS_H
#define __COMPRESS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Classe de compression/décompression de fichiers par la méthode RLE.
 */
class Compresseur {
private:
    /** Seuil au delà duquel on compresse. */
    int seuil;

    /** Code de l'octet de répétition. */
    int codeRepetition;

    /** Taux de compression */
    float taux;

    /** Flux de lecture et écriture des fichiers */
    fstream *flux;

public:
    /**
     * Crée un nouvel objet de type Compresseur.
     */
    Compresseur(int unseuil, int uncodeRepetition) {
        seuil = unseuil;
        codeRepetition = uncodeRepetition;
        taux = 0.0;
        flux = new fstream[2];
    }

    // fonctions accesseurs.
    int getSeuil() const { return seuil; }
    int getCodeRepetition() const { return codeRepetition; }
    float getTaux() const { return taux; }
    void setSeuil(const int unseuil) { seuil = unseuil; }
    void setCodeRepetition(const int uncodeRepetition) { codeRepetition = uncodeRepetition; }

    /**
     * Compression par la méthode RLE du fichier en entrée.
     * @param fichierEntree
     * @param fichierSortie
     */
    void compresser(string fichierEntree, string fichierSortie);

    /**
     * Décompression par la méthode RLE du fichier compressé en entrée.
     * @param fichierEntree
     * @param fichierSortie
     */
    void decompresser(string fichierEntree, string fichierSortie);

    /** Destructeur. */
    ~Compresseur() = default;

    /** Gestion du flux de sortie standard. */
    friend ostream &operator<<(ostream &os, Compresseur &unCompresseur);

    /** Gestion du flux d'entrée standard. */
    friend istream &operator>>(istream &is, Compresseur &unCompresseur);

};

#endif
