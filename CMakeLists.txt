cmake_minimum_required(VERSION 3.20)
project(MemeGenerator)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_library(memer src/memer.cpp)
target_link_libraries(memer sfml-graphics sfml-audio)

add_executable (MemeGenerator src/memeify.cpp)
target_link_libraries(MemeGenerator memer sfml-graphics sfml-audio)