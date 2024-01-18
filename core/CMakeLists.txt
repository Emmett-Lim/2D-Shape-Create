cmake_minimum_required(VERSION 3.8)

project(
	MyCore
	VERSION 0.0.2
	DESCRIPTION "CMake Project Template ver. 1 for future projects"
	LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Source Files
set(CORE_SOURCE_FILES
	src/core.cpp)

# Header Files
set(CORE_HEADER_FILES
	include/core/core.h)

# By default this is already a static library
add_library(core ${CORE_SOURCE_FILES} ${CORE_HEADER_FILES})

target_include_directories(core
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
		# ${CMAKE_CURRENT_SOURCE_DIR}/include/core
		${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
)

target_compile_features(core PRIVATE cxx_std_20)

target_link_libraries(core
    PRIVATE
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)