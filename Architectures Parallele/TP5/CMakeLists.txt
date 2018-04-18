# Version de cmake demandée.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
 
# Chemin des répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( src/include )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Chemin de recherche des modules pour mettre la main sur TBB.
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "modules/")

# Packages requis.
FIND_PACKAGE( TBB ) 

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11")

# Création des exécutables.
ADD_EXECUTABLE( testPipelinedBubbleSort 
                src/testPipelinedBubbleSort.cpp
                src/Metrics.cpp
)

# Librairies avec lesquelles linker.
TARGET_LINK_LIBRARIES( testPipelinedBubbleSort ${TBB_LIBRARIES} )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )

