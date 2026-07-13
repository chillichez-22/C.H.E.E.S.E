
Create the CMake build folder, with ninja and MinGw, using the GCC C++ Compiler:
    >> cmake -S . -B build -G Ninja -D CMAKE_C_COMPILER=gcc -D CMAKE_CXX_COMPILER=g++


Create the testing build executable:
    >> cmake --build build --target cheese-testing

Create the main build executable:
    >> cmake --build build --target cheese-main
    
