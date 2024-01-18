cmake_minimum_required(VERSION 3.8)

project(
	CMakeProject_Template_1
	VERSION 0.0.2
	DESCRIPTION "CMake Project Template ver. 1 for future projects"
	LANGUAGES CXX)

# Library code
add_subdirectory(core)

# Executable(s)
add_subdirectory(apps)