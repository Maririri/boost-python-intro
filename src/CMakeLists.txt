cmake_minimum_required (VERSION 2.8)

project(intro CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")


# Find dependencies
find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(Python_ADDITIONAL_VERSIONS "2.7")
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})


# Python wrapper
add_library(intro SHARED 
    intro.cpp 
    functions.cpp)

set_target_properties(intro PROPERTIES
    PREFIX ""
    SUFFIX ".so"
)

target_link_libraries(intro
        ${Boost_LIBRARIES}
        ${PYTHON_LIBRARIES}
)