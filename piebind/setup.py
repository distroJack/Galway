#!usr/bin/env python3
# encoding: utf-8

from distutils.core import setup, Extension
import glob

sources = [
	"src/return_types.cpp",
	"src/parameter_types.cpp",
	"src/module_main.cpp"
]

setup(name="demo", version="1.0", ext_modules = [Extension("demo", sources)]);
