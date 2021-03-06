Introduction to building a C++ library with [Boost Python][] and using it from Python in Ubuntu.

## Continuous integration

[![Build Status](https://travis-ci.org/oscarlorentzon/boost_python_intro.svg)](https://travis-ci.org/oscarlorentzon/boost_python_intro)

## Dependencies

* Install the development header files for Python and [Boost Python][]: 

        sudo apt-get install python-dev libboost-python-dev

* Install the [g++][] compiler:

        sudo apt-get install g++

## Building

#### Command line

Create a g++ output directory and navigate to it:

    mkdir gpp_build
    cd gpp_build

Compile the source files:

    g++ -I/usr/include/python2.7 -c -fPIC -o "functions.o" "../src/functions.cpp"
    g++ -I/usr/include/python2.7 -c -fPIC -o "intro.o" "../src/intro.cpp"

Link the targets (intro.so will be placed in the gpp_build directory):

    g++ -shared -Wl,-soname,intro.so -o "intro.so" ./functions.o ./intro.o -lboost_python -lpython2.7

#### Distutils

[Distutils][] is part of the Python standard library so no installation is required.

Build the module with:

    python setup.py build

Navigate to the build output folder (build/lib.linux...).

#### CMake

Install [CMake][] with:

    sudo apt-get install cmake 

Create a [CMake][] output directory and navigate to it:

    mkdir cmake_build
    cd cmake_build

Build from the output directory (intro.so will be placed in the cmake_build directory):

    cmake ../src
    make

#### Eclipse CDT

Install [Eclipse CDT][]:

    sudo apt-get install eclipse eclipse-cdt 

Create new shared library project with the name **intro**. Include the repository header and implementation files.

Right click the Project -> Properties -> C/C++ Build -> Settings

Under tab Tool Settings: 

1. GCC C++ Compiler -> Includes: Add path /usr/include/python2.7
2. GCC C++ Compiler -> Miscellaneous: Check Position independent code
3. GCC C++ Linker -> Libraries: Add boost_python and python2.7

When using boost python the .so file must have the same name as 
the boost python module. To make sure no prefix is added to the output name set the Output prefix in Build Artifact tab to an empty string.

Build the project in Eclipse, start a terminal and navigate to the build output folder (Debug by default).

## Using

Start an interactive python console from one of the build output folders above: 

    $ python

Import the intro module and call the module function:

    >>> import intro
    >>> intro.type_info("test")

[Boost Python]: http://www.boost.org/
[g++]: https://gcc.gnu.org/
[Distutils]: https://docs.python.org/2/library/distutils.html
[Eclipse CDT]: https://eclipse.org/cdt/
[CMake]: http://www.cmake.org/
