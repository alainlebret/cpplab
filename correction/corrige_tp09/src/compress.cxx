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
#include "include/compress.h"

namespace compression {

    void Compressor::compress(const std::string& inputfile,
            const std::string& outputfile) {
        int previousByte;
        int currentByte;
        int numberOfRepetitions;
        float j = 0.0, k = 0.0;

        files_[0].open(inputfile, std::ios::in | std::ios::binary);
        files_[1].open(outputfile, std::ios::out | std::ios::binary);

        numberOfRepetitions = 1;
        previousByte = files_[0].get();

        do {
            currentByte = files_[0].get();
            j += 1;
            if (currentByte == previousByte) {
                numberOfRepetitions++;
            } else {
                if (numberOfRepetitions > threshold_) {
                    files_[1].put(static_cast<char>(repetitionCode_));
                    files_[1].put(static_cast<char>(numberOfRepetitions));
                    files_[1].put(static_cast<char>(previousByte));
                    k += 3;
                } else {
                    if (numberOfRepetitions > 1) {
                        for (int i = 1; i <= numberOfRepetitions; i++) {
                            files_[1].put(static_cast<char>(previousByte));
                            k += 1;
                        }
                    } else {
                        files_[1].put(static_cast<char>(previousByte));
                        k += 1;
                    }
                }
                numberOfRepetitions = 1;
                previousByte = currentByte;
            }
        } while (currentByte != EOF);

        rate_ = (j / k) * 100;

        files_[0].close();
        files_[1].close();
    }

    void Compressor::decompress(const std::string& inputfile,
            const std::string& outputfile) {
        int codeToRepeat;
        int currentByte;
        int numberOfRepetitions;

        files_[0].open(inputfile, std::ios::in | std::ios::binary);
        files_[1].open(outputfile, std::ios::out | std::ios::binary);

        while ((currentByte = files_[0].get()) != EOF) {
            if (currentByte == repetitionCode_) {
                numberOfRepetitions = files_[0].get();
                codeToRepeat = files_[0].get();
                for (int i = 0; i < numberOfRepetitions; i++)
                    files_[1].put(static_cast<char>(codeToRepeat));
            } else {
                files_[1].put(static_cast<char>(currentByte));
            }
        }

        files_[0].close();
        files_[1].close();
    }

    std::ostream &operator<<(std::ostream &os, Compressor &compressor) {
        os << "Valeurs des attributs de l'objet - Classe Compressor" << std::endl;
        os << "seuil : " << compressor.threshold_ << std::endl;
        os << "code de répétition  : " << compressor.repetitionCode_ << std::endl;
        os << "taux de compression : " << compressor.rate_ << " %" << std::endl;
        os << std::endl;
        return os;
    }

    std::istream &operator>>(std::istream &is, Compressor &compressor) {
        std::cout << "Valeurs des attributs de l'objet - Classe Compressor" << std::endl;
        std::cout << "\nEntrez la valeur du seuil : " << std::endl;
        is >> compressor.threshold_;
        std::cout << "\nEntrez la valeur du code de répétition : " << std::endl;
        is >> compressor.repetitionCode_;
        return is;
    }

}
