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

int main(int argc, char *argv[]) {
    compression::Compressor compressor(3, 255);

    std::cout << compressor << std::endl;
    std::cout << "--------- COMPRESSION -----------" << std::endl;
    compressor.compress("image.xpm", "image_.xpm");
    std::cout << compressor << std::endl;
    std::cout << "-------- DECOMPRESSION ----------" << std::endl;
    compressor.decompress("image_.xpm", "image2.xpm");

    return EXIT_SUCCESS;
}
