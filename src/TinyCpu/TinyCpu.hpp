#ifndef TINYCPU_H
#define TINYCPU_H

#include <cstdint>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

class Cpu {
private:
    uint8_t A = 0;
    uint8_t B = 0;
    uint8_t PC = 0;
    std::vector<uint8_t> RAM = std::vector<uint8_t>(16, 0);
    bool running = true;

public:
    void loadProgram(const std::vector<uint8_t>& program);
    void run(void);
    std::vector<uint8_t> loadFromFile(const std::string& filename);

private:
    uint8_t fetch(void);
    void execute(uint8_t instruction);
};

#endif