## Dependencies

* [Boost Python][]

### Installing dependencies

Install the development header files for python and boost python: 

    sudo apt-get install python-dev libboost-python-dev


## Building

###Eclipse CDT

Create new shared library project with the name **intro**. Include the repository header and implementation files.

Right click the Project -> Properties -> C/C++ Build -> Settings

Under tab Tool Settings: 

1. GCC C++ Compiler -> Includes: Add path /usr/include/python2.7
2. GCC C++ Compiler -> Miscellaneous: Check Position independent code
3. GCC C++ Linker -> Libraries: Add boost_python and python2.7

When using boost python the .so file must have the same name as 
the boost python module. To make sure no prefix is added to the output name set the Output prefix in Build Artifact tab to an empty string.

Build the project in Eclipse, start a console window navigate to the build folder (Debug by default) and start an interactive python console: 

    $ cd Debug
    $ python

Import the intro module and test the module function:

    >>> import intro
    >>> intro.type_info("test")


[Boost Python]: http://www.boost.org/
