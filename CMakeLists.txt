cmake_minimum_required(VERSION 3.8)

project(
	2D-Shape-Create
	VERSION 0.0.2
	DESCRIPTION "CMake Project Template ver. 1 for future projects"
	LANGUAGES CXX)

# Library code
add_subdirectory(core)

# Executable(s)
add_subdirectory(apps)