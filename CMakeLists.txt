# CMakeList.txt : CMake project for Limon, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project("Limon" VERSION 1.0)

#glfw3
add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/glfw/)
#glfw3

#gl
find_package(OpenGL REQUIRED)
#gl
 
file(GLOB LIMON_SOURCES
    src/Limon/*.h
    src/Limon/*.cpp
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} ${LIMON_SOURCES} )

target_include_directories(${PROJECT_NAME} 
	PUBLIC ${PROJECT_SOURCE_DIR}/Dependencies/stb/
	PUBLIC ${PROJECT_SOURCE_DIR}/Dependencies/glfw/include/
	)

target_link_Libraries(${PROJECT_NAME} 
	glfw
	OpenGL::GL
	)

target_link_directories(${PROJECT_NAME} 
	PRIVATE Dependencies/glfw/src
	)
