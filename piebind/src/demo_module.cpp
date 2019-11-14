

#include <Python.h>
#include <iostream>

static PyObject* HelloWorld(PyObject *self, PyObject *args)
{
	
  std::cout << "Hello World" << std::endl;
  Py_RETURN_NONE;
}

static PyObject *
ReturnOne(PyObject *self, PyObject *args)
{
    return Py_BuildValue("i", 1);
}

static PyMethodDef demo_methods[] = {
  {"HelloWorld", (PyCFunction)HelloWorld, METH_NOARGS, "Demo hello world" },
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
