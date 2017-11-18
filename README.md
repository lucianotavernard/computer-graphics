# Computação gráfica #

Este repositório contém o sistema da prova da 3ª unidade de computação gráfica

## Projeto GameBall ##

## Desenvolvimento ##

Git, C++, OpenGL, GLUT

## Siga os passos abaixo para iniciar ##

#### Clone o repositório ####
`git clone https://bitbucket.org/lucianotavernard/computacao_grafica.git`

### Configure o compilador ###

#### CLion ####
`find_package(OpenGL REQUIRED)`
`find_package(GLUT REQUIRED)`

`include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})`

`target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})`

#### CodeBlocks ####

### Instale as bibliotecas xmu e xi ###

#### Linux ####
`sudo apt-get install libxmu-dev libxi-dev`

#### Windows ####
``

## Responsável pelo projeto ##

* Luciano Tavernard
* Danilo Wesley
* Janderson Fonseca
* Laudeine Batista
* Matheus Cadó