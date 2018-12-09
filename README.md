# Computer Graphics

This repository contains the system of proof of the 3rd unit of computer graphics

## GameBall Project

## Stack of Development

Git, C++, OpenGL, GLUT

## Follow the steps below to start

#### Clone the repository
`git clone https://github.com/ltavernard/computer-graphics.git`

### Configure the compiler

#### CLion
`find_package(OpenGL REQUIRED)`
`find_package(GLUT REQUIRED)`

`include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})`

`target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})`

### Install the xmu and xi libraries

#### Linux
`sudo apt-get install libxmu-dev libxi-dev`

## Project Managers

* Luciano Tavernard
* Danilo Wesley
* Janderson Fonseca
* Laudeine Batista
* Matheus Cadó