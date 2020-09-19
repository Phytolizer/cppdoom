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

find_path(BOOST_LEXICAL_CAST_INCLUDE_DIRS "boost/detail/basic_pointerbuf.hpp")
target_include_directories(doom SYSTEM PRIVATE ${BOOST_LEXICAL_CAST_INCLUDE_DIRS})

find_path(RANG_INCLUDE_DIRS "rang.hpp")
target_include_directories(doom SYSTEM PRIVATE ${RANG_INCLUDE_DIRS})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(doom PRIVATE fmt::fmt fmt::fmt-header-only)

find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(doom PRIVATE Microsoft.GSL::GSL)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(doom PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
