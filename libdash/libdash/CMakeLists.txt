cmake_minimum_required(VERSION 3.0)

find_package(LibXml2 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(CURL REQUIRED)

include_directories(include)
include_directories(${LIBXML2_INCLUDE_DIR})
include_directories(${ZLIB_INCLUDE_DIRS})
include_directories(${CURL_INCLUDE_DIRS})

file(GLOB_RECURSE libdash_source *.cpp)

add_library(dash SHARED ${libdash_source})
target_link_libraries(dash ${CURL_LIBRARIES} ${ZLIB_LIBRARIES} ${LIBXML2_LIBRARIES})
