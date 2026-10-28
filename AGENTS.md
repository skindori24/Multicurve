# AGENTS.md

Instructions for AI coding agents working in this repository.

## Purpose

C++ project on multicurve bootstrapping: build an OIS discount curve and a 3M forward curve from
market quotes. Version 0.1 is a simplified placeholder that turns deposit rates into discount
factors.

## Structure

- `src/`: library code (`curve.hpp`, `curve.cpp`) and the program (`main.cpp`)
- `tests/`: unit tests (GoogleTest)
- `bench/`: benchmark (Google Benchmark)
- `.github/workflows/`: CI/CD. `ci.yml` builds, tests and benchmarks; `docs.yml` publishes the
  Doxygen documentation.

## Commands

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release   # configure
cmake --build build                              # build
ctest --test-dir build --output-on-failure       # run unit tests
./build/multicurve_bench                         # run benchmark
./build/multicurve                               # run program
doxygen Doxyfile                                 # documentation -> docs/html
```

## Code style

- C++20, 4-space indentation, lines up to 100 characters.
- Structs and classes in `PascalCase`, functions and variables in `snake_case`.
- All code lives in the `multicurve` namespace.
- Every public function has a Doxygen comment.
- Rates are decimals (0.15 = 15%); times are in years.

## Rules for the agent

- Before finishing a task, build the project and run the tests.
- Do not change CI/CD (`.github/workflows/`) unless asked.
- Do not add new libraries without asking.
- Add a unit test for every new function.
- Never commit `build/` or `docs/`.
