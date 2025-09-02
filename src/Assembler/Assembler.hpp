#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>
#include "OpCodes/OpCodes.h"

std::vector<uint8_t> assemble(const std::string& asmFile);
bool assembleFromFileToBin(const std::string& asmFile, const std::string& binFile);

#endif