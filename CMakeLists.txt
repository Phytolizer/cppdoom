cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "/home/kyle/.local/share/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(doom)

file(GLOB_RECURSE SOURCES "src/*.cc")
add_executable(doom ${SOURCES})

find_package(SDL2 REQUIRED)

target_link_libraries(doom PRIVATE SDL2 SDL2_image)

find_path(STRTK_INCLUDE_DIRS "strtk.hpp")
target_include_directories(doom SYSTEM PRIVATE ${STRTK_INCLUDE_DIRS})

find_path(BOOST_VARIANT2_INCLUDE_DIRS "boost/variant2/variant.hpp")
target_include_directories(doom SYSTEM PRIVATE ${BOOST_VARIANT2_INCLUDE_DIRS})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(doom PRIVATE fmt::fmt fmt::fmt-header-only)
