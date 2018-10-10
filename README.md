# Build 
g++ -std=c++17 -fPIC -c FunctionExternal.cpp -I/usr/local/halide/include \\
g++ -std=c++17 -fPIC -c CInterface.cpp -I/usr/local/halide/include \\
g++ FunctionExternal.o CInterface.o -std=c++17 -g -fPIC -rdynamic  -O3 -g -L /usr/local/halide/bin -shared -o halideShared.so -lHalide \\
g++ -std=c++17 -fPIC -c Loader.cpp \\
g++ Loader.o -std=c++17 -g -fPIC -O3 -g -ldl -o bin \\

# Run
./bin

# Expected Output
Load object \\
Load function \\
Run Function \\
C_Run \\
Before realization \\
Segmentation fault (core dumped) \\
