project(melkor)
cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c99 -O3")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
file(GLOB SOURCES
    "src/main.c"
    "src/melkor/**/*.c"
)
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories("src/melkor")
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} glfw)
