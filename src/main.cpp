#include "Assembler/Assembler.hpp"
#include <iostream>
#include "TinyCpu/TinyCpu.hpp"
#include <iomanip>
#include <string>

int main(int argc, char **argv) {
    Cpu cpu;
    std::vector<uint8_t> program;

    if (argc > 2) {
        std::string mode = argv[1];

        if (mode == "--asm") program = assemble(argv[2]);
        else if (mode == "--bin") program = cpu.loadFromFile(argv[2]);
        else if (mode == "--compile") {
            if (argc > 4 && std::string(argv[3]) == "-o") {
                std::string inputAsm = argv[2];
                std::string outputBin = argv[4];

                if (assembleFromFileToBin(inputAsm, outputBin)) {
                    std::cout << "binary generated: " << outputBin << "\n";
                    return 0;
                } else {
                    std::cerr << "error in assembly\n";
                    return 1;
                }
            } else {
                std::cerr << "Usage: --compile input.asm -o output.bin\n";
                return 1;
            }
        }
        else {
            std::cerr << "unknown mode\n";
            return 1;
        }
    } else {
        std::cerr << "Usage: --asm file.asm | --bin file.bin | --compile file.asm -o file.bin\n";
        return 1;
    }

    cpu.loadProgram(program);
    cpu.run();

    return 0;
}
