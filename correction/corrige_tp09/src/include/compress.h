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

namespace compression {

/**
 * A (de)compressor class that uses the run-length encoding algorithm.
 */
    class Compressor {
    private:
        /** The threshold value used to activate compression. */
        int threshold_;

        /** The repetition code used to replace bytes in the file. */
        int repetitionCode_;

        /** The compression rate. */
        float rate_;

        /** The input and output stream references. */
        std::fstream *files_;

    public:
        /**
         * Creates a new compressor with the given threshold and repetition
         * code.
         * @param threshold
         * @param repetitionCode
         */
        Compressor(int threshold, int repetitionCode) {
            threshold_ = threshold;
            repetitionCode_ = repetitionCode;
            rate_ = 0.0;
            files_ = new std::fstream[2];
        }

        // accessor member functions.
        int getThreshold() const { return threshold_; }

        int getRepetitionCode() const { return repetitionCode_; }

        float getRate() const { return rate_; }

        void setThreshold(const int threshold) { threshold_ = threshold; }

        void setRepetitionCode(const int repetitionCode) {
            repetitionCode_ = repetitionCode;
        }

        /**
         * Compresses the given input file using the run-length encoding
         * algorithm and saves the compressed data in the output file.
         * @param inputfile
         * @param outputfile
         */
        void compress(const std::string& inputfile,
                      const std::string& outputfile);

        /**
         * Decompresses the given input file using the run-length encoding
         * algorithm and saves the uncompressed data in the output file.
         * @param inputfile
         * @param outputfile
         */
        void decompress(const std::string& inputfile,
                        const std::string& outputfile);

        /** Destructs the compressor. */
        ~Compressor() = default;

        friend std::ostream &operator<<(std::ostream& os, Compressor& compressor);

        friend std::istream &operator>>(std::istream& is, Compressor& compressor);

};

}
#endif
