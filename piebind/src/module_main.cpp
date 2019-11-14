

#include <Python.h>
#include <iostream>
#include "return_types.h"

static PyMethodDef demo_methods[] = {
  {"ReturnNone", (PyCFunction)ReturnNone, METH_NOARGS, "Demo hello world" },
  {"ReturnOne", (PyCFunction)ReturnOne, METH_NOARGS, "different type" },
  {nullptr, nullptr, 0, nullptr}
};

static PyModuleDef demo_module = {
  PyModuleDef_HEAD_INIT,
  "demo",
  "demonstration module",
  0,
  demo_methods
};

PyMODINIT_FUNC PyInit_demo() {
  Py_Initialize();
  return PyModule_Create(&demo_module);
}