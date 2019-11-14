
# NOTE: ctypes dynamic load seems to be broken (11/14/19)
# from ctypes import CDLL
# demo = CDLL("./demo.cpython-36m-x86_64-linux-gnu.so")

import demo
demo.HelloWorld()
