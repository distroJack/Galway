

#include <Python.h>
#include <iostream>

static PyObject* HelloWorld(PyObject *self, PyObject *args)
{
  std::cout << "Hello World" << std::endl;
  Py_RETURN_NONE;
}

static PyMethodDef demo_methods[] = {
  {"HelloWorld", (PyCFunction)HelloWorld, METH_VARARGS, "Demo hello world" },
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
