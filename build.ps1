if (-not (Test-Path build)) {
    New-Item -ItemType Directory build
}

cmake -S . -B ./build
cmake --build ./build
cmake --build ./build --config Release