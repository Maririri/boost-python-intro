from distutils.core import setup
from distutils.extension import Extension
 
setup(
    name="intro",
    ext_modules=[
        Extension(
            "intro", 
            ["src/intro.cpp", "src/functions.cpp"],
            libraries = ["boost_python"])
    ])
