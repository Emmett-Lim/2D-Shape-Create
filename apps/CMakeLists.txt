cmake_minimum_required(VERSION 3.8)

project(
	MyApp
	VERSION 0.0.1
	DESCRIPTION "CMake Project Template ver. 1 for future projects"
	LANGUAGES CXX)

add_executable(${PROJECT_NAME}
	"src/main.cpp"
	"src/application.cpp"
	"src/application.h")

target_compile_features(MyApp PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} core)