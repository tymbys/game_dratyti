cmake_minimum_required(VERSION 3.13)
project(game1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})



add_executable(game1 main.cpp Game.cpp Game.h Map.cpp Map.h Room.cpp Room.h DisplayGL.cpp DisplayGL.h DisplaySDL.cpp DisplaySDL.h Texture.cpp Texture.h IsoEngine.cpp IsoEngine.h)

target_link_libraries(game1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})