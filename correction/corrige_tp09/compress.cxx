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
#include "compress.h"

// Services de la classe Compresseur

/*
 * compresser
 * Paramètres : 'fichier' = nom du fichier à compresser
 *              'fichier_compresse' = nom du fichier resultat
 * Description : Compression du fichier de nom 'fichier' à l'aide de la
 *               méthode RLE. Le fichier obtenu après compression est appelé
 *              'fichier_compresse'.
 */
void Compresseur::compresser(const string fichierEntree, const string fichierSortie) {
    int octetPrecedent;     // octet précédent.
    int octetCourant;       // octet courant.
    int nombreRepetitions;  // nombre de répétitions d'un octet.
    float j = 0.0, k = 0.0;

    flux[0].open(fichierEntree, ios::in | ios::binary);   // ouverture du fichierEntree à compresser.
    flux[1].open(fichierSortie, ios::out | ios::binary);  // ouverture du fichierEntree compressé.

    nombreRepetitions = 1;            // un octet lu est répété au moins une fois.
    octetPrecedent = flux[0].get();   // lecture du premier octet.

    do {
        octetCourant = flux[0].get();
        j += 1;
        // si les octets 'précédent' et 'courant' sont les mêmes :
        if (octetCourant == octetPrecedent) {
            nombreRepetitions++; // on incrémente le nombre de répétitions de celui-ci.

            // si l'octet 'courant' est différent du 'précédent' :
        } else {
            // si le nombre de répétitions de l'octet est supérieur au seuil.
            if (nombreRepetitions > seuil) {
                flux[1].put(static_cast<char>(codeRepetition));       // écriture de l'octet de répétition.
                flux[1].put(static_cast<char>(nombreRepetitions));    // écriture du nombre de répétitions.
                flux[1].put(static_cast<char>(octetPrecedent));       // écriture de l'octet récalcitrant.
                k += 3;
            } else {
                // si le nombre de répétitions de l'octet est inférieur au seuil
                // et si le nombre de répétitions est compris entre 1 et 'seuil' :
                if (nombreRepetitions > 1) {
                    // alors on écrit celui-ci 'nombreRepetitions' fois.
                    for (int i = 1; i <= nombreRepetitions; i++) {
                        flux[1].put(static_cast<char>(octetPrecedent));
                        k += 1;
                    }
                    // si l'octet n'a qu'une occurrence, on l'écrit.
                } else {
                    flux[1].put(static_cast<char>(octetPrecedent));
                    k += 1;
                }
            }
            nombreRepetitions = 1;          // on repositionne nombreRepetitions à 1.
            octetPrecedent = octetCourant;  // mise de côté de l'octet que
            // l'on vient de traiter.
        }
    } while (octetCourant != EOF);

    taux = (j / k) * 100;

    flux[0].close();  // fermeture des flux
    flux[1].close();
}


/*
 * decompresser
 * Paramètres : 'fichier_compresse' = nom du fichier à décompresser
 *              'fichier' = nom du fichier résultat
 * Description : Décompression du fichier d'entrée à l'aide
 *               de la méthode RLE.
 */
void Compresseur::decompresser(const string fichierEntree, const string fichierSortie) {
    int codeARepeter;       // octet à répéter.
    int octetCourant;       // octet courant.
    int nombreRepetitions;  // nombre de répétitions d'un octet.

    flux[0].open(fichierEntree, ios::in | ios::binary);  // ouverture du fichierSortie à décompresser.
    flux[1].open(fichierSortie, ios::out | ios::binary); // ouverture du fichierSortie décompressé.

    // boucle de lecture des octets tant que la fin de fichierSortie n'est pas
    // atteinte.
    while ((octetCourant = flux[0].get()) != EOF) {
        // si l'octet courant correspond au code de répétition, il nous
        // faut traiter les deux octets suivants :
        if (octetCourant == codeRepetition) {
            nombreRepetitions = flux[0].get();    // on regarde le nombre d'occurrences
            codeARepeter = flux[0].get();         // on lit l'octet à répéter
            for (int i = 0; i < nombreRepetitions; i++)  // puis on écrit 'nombreRepetitions' fois cet octet
                flux[1].put(static_cast<char>(codeARepeter));       // dans le flux de sortie.
        } else {
            // sinon on l'envoie directement vers le flux de sortie.
            flux[1].put(static_cast<char>(octetCourant));
        }
    }

    flux[0].close();           // fermeture des flots.
    flux[1].close();
}

ostream &operator<<(ostream &os, Compresseur &unCompresseur) {
    os << "Valeurs des attributs de l'objet - Classe Compresseur" << endl;
    os << "seuil : " << unCompresseur.seuil << endl;
    os << "code de répétition  : " << unCompresseur.codeRepetition << endl;
    os << "taux de compression : " << unCompresseur.taux << " %" << endl;
    os << endl;
    return os;
}

istream &operator>>(istream &is, Compresseur &unCompresseur) {
    cout << "Valeurs des attributs de l'objet - Classe Compresseur" << endl;
    cout << "\nEntrez la valeur du seuil : " << endl;
    is >> unCompresseur.seuil;
    cout << "\nEntrez la valeur du code de répétition : " << endl;
    is >> unCompresseur.codeRepetition;
    return is;
}
