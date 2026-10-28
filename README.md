# Multicurve bootstrapping

C++ project for the course "Software Engineering and C++ for Quantitative Analysis and Algorithmic
Trading". Topic: **multicurve bootstrapping**, i.e. building an OIS discount curve and a 3M forward
curve from market quotes (deposits, FRAs, swaps).

**Version 0.1 is a simplified placeholder.** The program converts deposit rates into discount
factors with `P = 1 / (1 + r * T)` and prints them. The real two-curve algorithm will replace it step by step with the development of the project.

**Documentation:** https://skindori24.github.io/multicurve/

## Build and run

One needs CMake 3.20 or newer, a C++20 compiler and Git. On the first one should configure, CMake downloads
GoogleTest and Google Benchmark.

Linux, macOS or Git Bash:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build          # unit tests
./build/multicurve              # program
./build/multicurve_bench        # benchmark
doxygen Doxyfile                # documentation -> docs/html/index.html
```

Windows with the Visual Studio compiler (PowerShell):

```powershell
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release
.\build\Release\multicurve.exe
.\build\Release\multicurve_bench.exe
```

## Project structure

```text
src/                 code: curve.hpp, curve.cpp (library) and main.cpp (program)
tests/               unit tests (GoogleTest)
bench/               benchmark (Google Benchmark)
.github/workflows/   CI/CD: ci.yml (build, tests, benchmark), docs.yml (docs to GitHub Pages)
Doxyfile             Doxygen settings
AGENTS.md            settings for the AI coding agent (CLAUDE.md refers to it)
```


