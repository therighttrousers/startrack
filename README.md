# Star Track

TODO: Write

Satellite constellation simulation, rendering and control

# Initial dev setup

Prerequisites:
- Git
- On Windows: Visual Studio 2026 Build Tools (18.10) `cl`, `cmake`, `ninja`
- On Linux: `g++` or `clang++`, `cmake`, `ninja`

On Windows, launch the x64 Native Tools Command Prompt, to clone/build and to launch VS Code (with `code`).

Steps:
1. Run `git clone --recurse-submodules <repo-url>`
2. In the repo root, run `cmake --workflow --preset <preset>`
   - `<preset>` is `msvc-debug`, `gcc-debug` or `clang-debug`
3. If using VS Code, choose the appropriate CMake preset when asked, and install the recommended extensions 
