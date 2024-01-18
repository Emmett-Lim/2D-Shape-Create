rem Build the project within visual studio
rmdir /s /q build
mkdir build
cd build
cmake ..
cmake --build .
start CMakeProject_Template_1.sln