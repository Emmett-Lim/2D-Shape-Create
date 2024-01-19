cmake_minimum_required(VERSION 3.8)

project(
	MyCore
	VERSION 0.0.1
	DESCRIPTION "CMake Project Template ver. 1 for future projects"
	LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Source Files
set(CORE_SOURCE_FILES
	"src/shapecreate2d.cpp"
	"src/plane2D.cpp")

# Header Files
set(CORE_HEADER_FILES
	"include/core/shapecreate2d.h"
	"include/core/shapecreate2d_utilities.h"
	"include/core/utilities.h"
	"include/core/plane2D.h")

# By default this is already a static library
add_library(core STATIC ${CORE_SOURCE_FILES} ${CORE_HEADER_FILES})

target_include_directories(core
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
		${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/include
		# ${CMAKE_CURRENT_SOURCE_DIR}/include/core
)

target_compile_features(core PRIVATE cxx_std_20)

target_link_libraries(core
    PRIVATE
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)

install(TARGETS core DESTINATION lib)