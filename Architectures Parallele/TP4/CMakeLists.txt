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

# Option du compilateur pour supporter C 2011.
SET( CMAKE_C_FLAGS "-std=c11")

# # Création des exécutables.
# ADD_EXECUTABLE( dry_run       src/bench.c src/matvec.c       )
# ADD_EXECUTABLE( bench        src/bench.c src/matvec.c        )
# ADD_EXECUTABLE( bench_r4     src/bench.c src/matvec_r4.c     )
# ADD_EXECUTABLE( bench_sse_r4 src/bench.c src/matvec_sse_r4.c )
#
# # Symboles pré-processeur nécessaires à la génération des exécutables.
# TARGET_COMPILE_DEFINITIONS( dry_run      PRIVATE RAW PRIVATE DRY_RUN )
# TARGET_COMPILE_DEFINITIONS( bench        PRIVATE RAW                 )
# TARGET_COMPILE_DEFINITIONS( bench_r4     PRIVATE R4                  )
# TARGET_COMPILE_DEFINITIONS( bench_sse_r4 PRIVATE SSE_R4              )

# Création des exécutables.
ADD_EXECUTABLE( testParallelHybridRecursiveMerge
                src/Metrics.cpp
		src/testParallelHybridRecursiveMerge.cpp
)
ADD_EXECUTABLE( testParallelStableMerge
                src/Metrics.cpp
		src/testParallelStableMerge.cpp
)

# Librairies avec lesquelles linker.
TARGET_LINK_LIBRARIES( testParallelHybridRecursiveMerge ${TBB_LIBRARIES} )
TARGET_LINK_LIBRARIES( testParallelStableMerge ${TBB_LIBRARIES} )

# Faire parler le make.
set( CMAKE_VERBOSE_MAKEFILE off )
