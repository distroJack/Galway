

#include <Python.h>
#include <iostream>

#include "return_types.h"
#include "parameter_types.h"
#include "error_handling.h"

static PyMethodDef demo_methods[] = {
  // RETURN TYPES
  {"ReturnNone", (PyCFunction)ReturnNone, METH_NOARGS, "Return no parameters" },
  {"ReturnOne", (PyCFunction)ReturnOne, METH_NOARGS, "Return one parameter" },
  {"ReturnNumber", (PyCFunction)ReturnNumber, METH_NOARGS, "Return a number" },
  {"ReturnTuple", (PyCFunction)ReturnTuple, METH_NOARGS, "Return a tuple" },
  {"ReturnList", (PyCFunction)ReturnList, METH_NOARGS, "Return a list" },
  {"ReturnString", (PyCFunction)ReturnString, METH_NOARGS, "Return a string" },
  // PARAMETER TYPES
  {"AcceptZero", (PyCFunction)AcceptZero, METH_NOARGS, "Accept zero parameters" },
  {"AcceptOne", (PyCFunction)AcceptOne, METH_VARARGS, "Accept one parameter" },
  {"AcceptKeyword", (PyCFunction)AcceptKeyword, METH_VARARGS | METH_KEYWORDS, "Accept one parameter" },
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
