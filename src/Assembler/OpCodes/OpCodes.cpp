#include "OpCodes.h"

const std::unordered_map<std::string, uint8_t> OPCODES = {
    {"nop", 0x0},
    {"lia", 0x1},
    {"lib", 0x2},
    {"add", 0x3},
    {"sub", 0x4},
    {"sta", 0x5},
    {"jmp", 0x6},
    {"jz", 0x7},
    {"and", 0x8},
    {"or", 0x9},
    {"xor", 0xA},
    {"inc", 0xB},
    {"dec", 0xC},
    {"lda", 0xD},
    {"ldb", 0xE},
    {"halt", 0xF}
};
