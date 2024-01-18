# C++ CMake Project Starter Template

This is a small and simple project template for C++ projects utilizing CMake. The `core/` contains user defined files
and external sources which is then built into a static library to be used for multiple applications. The `apps/`
folder contains files intended to be built into an executable that uses the static library created
from `core/`. `core/external/` directory is used for 3rd-party sources and `cmake/` folder should contain `.cmake` files. 

## Using Project Template

1. Clone the repository or use this template on Github to setup own repository using this template
2. Modify the files to liking.
3. Make sure to have cmake installed
4. To build the project, for visual studio run `build.bat` on the command line; otherwise, use `build.sh`
