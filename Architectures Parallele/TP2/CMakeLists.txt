# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/include )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11 ")

# OpenMP
set(CMAKE_C_COMPILER clang-omp CACHE STRING "C compiler" FORCE)
set(CMAKE_CXX_COMPILER clang-omp++ CACHE STRING "C++ compiler" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -I/usr/local/opt/llvm/include")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/opt/llvm/lib")

# Création des exécutables.
ADD_EXECUTABLE( testForEach src/testForEach.cpp
                            src/Metrics.cpp
)
ADD_EXECUTABLE( testCountIf src/testCountIf.cpp
                            src/Metrics.cpp
)

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )
