rem Build the project within visual studio
rmdir /s /q build
mkdir build
cd build
cmake ..
cmake --build .
rem start 2D-Shape-Create.sln