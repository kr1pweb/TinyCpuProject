#include "Assembler.hpp"

std::vector<uint8_t> assemble(const std::string& asmFile) {
    std::vector<uint8_t> program;
    std::ifstream file(asmFile);
    if (!file) return {};

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string instr;
        int operand = 0;

        if (!(iss >> instr)) continue;

        if (!(iss >> operand)) operand = 0;

        auto it = OPCODES.find(instr);
        if (it == OPCODES.end()) {
            std::cerr << "unknown opcode\n";
            continue;
        }

        uint8_t byte = (it->second << 4) | (operand & 0xF);
        program.push_back(byte);
    }

    return program;
}
bool assembleFromFileToBin(const std::string& asmFile, const std::string& binFile) {
    std::ifstream file(asmFile);
    if (!file) return false;

    std::vector<uint8_t> program;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string instr;
        int operand = 0;

        if (!(iss >> instr)) continue;

        if (!(iss >> operand)) operand = 0;

        auto it = OPCODES.find(instr);
        if (it == OPCODES.end()) {
            std::cerr << "unknown opcode\n";
            continue;
        }

        uint8_t byte = (it->second << 4) | (operand & 0xF);
        program.push_back(byte);
    }

    std::ofstream out(binFile, std::ios::binary);
    if (!out) return false;

    out.write(reinterpret_cast<const char*>(program.data()), program.size());
    return true;
}
