@echo off
cd /d "%~dp0.."

rmdir /s /q build

cmake -S . -B build -G Ninja -D CMAKE_C_COMPILER=gcc -D CMAKE_CXX_COMPILER=g++ -D CMAKE_PREFIX_PATH="external\googletest" -DIS_TESTING=OFF

cmake --build build

PAUSE