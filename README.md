```markdown
# TinyCpuProject

Un projet d’émulation de CPU minimaliste avec un assembleur personnalisé.  
Le projet inclut :  

- Un **CPU 4-bit** en C++ (`TinyCpu`) capable d’exécuter un ensemble limité d’instructions.  
- Un **assembleur en C++** et un équivalent en Python pour générer des fichiers binaires à partir de fichiers ASM.  
- Une structure de projet claire avec CMake pour la compilation et un répertoire Python pour les scripts auxiliaires.  

---

## Structure du projet

```

D#/
├── src/                       # Code source C++
│   ├── main.cpp
│   ├── TinyCpu/
│   │   ├── TinyCpu.cpp
│   │   └── TinyCpu.hpp
│   └── Assembler/
│       ├── Assembler.cpp
│       └── OpCodes/
│           ├── OpCodes.cpp
│           └── OpCodes.h
├── python/                     # Scripts Python (assembleur)
├── bin/                        # Binaries générés par Python
├── releases/                   # Exécutables compilés C++
├── build/                      # Fichiers CMake générés
├── program.asm                 # Exemple de programme ASM
├── output.bin                  # Exemple de binaire généré
└── CMakeLists.txt              # Build configuration

````

---

## Compilation C++

Le projet utilise **CMake** pour gérer la compilation.  

```bash
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
````

L’exécutable sera généré dans `releases/main`.

### Modes de lancement

```bash
# Charger un fichier ASM, assembler et exécuter
./releases/main --asm program.asm

# Charger un fichier binaire existant et exécuter
./releases/main --bin output.bin

# Compiler un fichier ASM en binaire
./releases/main --compile program.asm -o output.bin
```

---

## Assembleur Python (optionnel)

Le projet contient également un assembleur Python pour générer des fichiers binaires `.bin` depuis un `.asm`.

```bash
cd python
python3 main.py
```

Le binaire généré sera dans `bin/program.bin`.

---

## Contribuer

1. Ajouter ou modifier des instructions dans `OpCodes.h` / `Opcodes.py`.
2. Écrire des programmes ASM dans `program.asm`.
3. Compiler le CPU avec CMake et tester les programmes.

---

## Notes

* Le CPU est un simple exemple 4-bit avec registre A, B et une RAM limitée.
* L’assembleur supporte des commentaires avec `;`.
* Les fichiers binaires sont au format simple byte par instruction.

```

---

Si tu veux, je peux te pondre **une version encore plus “pro” avec badges CMake, build status et instructions Python + C++ combinées**, façon repo GitHub prêt à cloner.  

Veux que je fasse ça ?
```