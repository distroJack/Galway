#!usr/bin/env python3
# encoding: utf-8

from distutils.core import setup, Extension

setup(name="demo", version="1.0", ext_modules = [Extension("demo", ["demo_module.cpp"])]);
