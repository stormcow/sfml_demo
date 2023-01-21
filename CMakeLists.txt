cmake_minimum_required(VERSION 3.11)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall )

if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULES_PATH})

    set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})

endif(UNIX)

if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )

    set ( SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)


find_package(SFML 2 COMPONENTS graphics audio REQUIRED)


add_executable(game "Source/main.cpp" "Source/Game.cpp" "Header/Game.h" "Header/Player.h" "Header/Level.h"  "Header/Map.h" "Source/Map.cpp" "Source/Player.cpp" "Source/Tile.cpp" "Source/Level.cpp" "Header/Loader.h" "Source/Loader.cpp" "Header/Tile.h" "Header/Aquamentus.h" "Header/BladeTrap.h" "Header/Enemy.h"
"Header/Entity.h" "Header/Goriya.h" "Header/Keese.h" "Header/Stalfos.h" "Header/Wallmaster.h")
target_link_libraries(game sfml-graphics sfml-audio sfml-window sfml-graphics)
