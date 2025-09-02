# TinyCppU

A minimalist CPU emulation project with a custom assembler
The project includes : 
 
- A **4-bit CPU** in C++ (`TinyCpu`) capable of executing a limited set of instructions.  
- A **C++ assembler** for generating binaries from ASM files.
 
---

## Project structure

```
src
├── Assembler
│   ├── Assembler.cpp
│   ├── Assembler.hpp
│   └── OpCodes
│       ├── OpCodes.cpp
│       └── OpCodes.h
├── main.cpp
└── TinyCpu
    ├── TinyCpu.cpp
    └── TinyCpu.hpp
````

---

## C++ usage

You can load the program from C++ with (`cpu.loadProgram`) :
```cpp
auto program = cpu.loadProgram({
    0x50,
    0x13,
    ...
    0xF0
});
```
You can also load the program from an external file with (`cpu.loadFromFile`) :
```cpp
auto program = cpu.loadFromFile("filepath.bin");
```
Or load it from an external file in `asm` using (`assemble`) from "Assembler/Assembler.hpp" :
```cpp
auto program = assemble("filepath.asm");
```
To run the program you can use (`cpu.run`) after loading the program.

---
## C++ compilation

The project uses **CMake** to manage compilation

```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
````

The executable will be generated in `releases/main`.

### Launch modes

```bash
./releases/main --asm program.asm
```
```bash
./releases/main --bin bin/program.bin
```
```bash
./releases/main --compile program.asm -o bin/program.bin
```
---

## Notes

* The CPU is a simple 4-bit example with registers A and B and limited RAM.
* The assembler supports comments with `;`.
* Binary files are in single byte per instruction format.

---
