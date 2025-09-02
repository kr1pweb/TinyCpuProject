#include "TinyCpu.hpp"

void Cpu::loadProgram(const std::vector<uint8_t>& program) { for (size_t i = 0; i < program.size() && i < RAM.size(); i++) RAM[i] = program[i]; }
uint8_t Cpu::fetch(void) { return RAM[PC++]; }
void Cpu::execute(uint8_t instruction) {
    uint8_t opcode = instruction >> 4;
    uint8_t operand = instruction & 0xF;

    switch (opcode) {
        case 0x0: break;
        case 0x1: A = operand; break;
        case 0x2: B = operand; break;
        case 0x3: if (operand == 0) A = (A + B) & 0xF; else B = (A + B) & 0xF; break;
        case 0x4: if (operand == 0) A = (A - B) & 0xF; else B = (B - A) & 0xF; break;
        case 0x5: RAM[operand] = A; break;
        case 0x6: PC = operand - 1; break;
        case 0x7: if (A == 0) PC = operand - 1; break;
        case 0x8: A = A & B; break;
        case 0x9: A = A | B; break;
        case 0xA: A = A ^ B; break;
        case 0xB: if (operand == 0) A = (A + 1) & 0xF; else B = (B + 1) & 0xF; break;
        case 0xC: if (operand == 0) A = (A - 1) & 0xF; else B = (B - 1) & 0xF; break;
        case 0xD: A = RAM[operand]; break; 
        case 0xE: B = RAM[operand]; break;
        case 0xF: running = false; break;
        default: std::cout << "unknown opcode\n";
    }
}
void Cpu::run(void) {
    while (running && PC < RAM.size()) {
        uint8_t instruction = fetch();
        execute(instruction);

        std::cout << "PC:" << int(PC-1) << " A:" << int(A) << " B:" << int(B) << " RAM:[";
        for (auto v : RAM) std::cout << std::hex << int(v) << " "; std::cout << "]\n";
    }
}
std::vector<uint8_t> Cpu::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) return {};

    std::vector<uint8_t> program((std::istreambuf_iterator<char>(file)),
                                 std::istreambuf_iterator<char>());

    return program;
}
