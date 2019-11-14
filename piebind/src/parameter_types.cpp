
#include <iostream>
#include "parameter_types.h"

PyObject* AcceptZero(PyObject *self, PyObject *args)
{
  std::cout << "Accept No Parameters" << std::endl;
  Py_RETURN_NONE;
}

PyObject* AcceptOne(PyObject *self, PyObject *args)
{
  int num;
  PyArg_ParseTuple(args, "i", &num);
  std::cout << "Accept One Parameters : (" << num << ")" << std::endl;
  Py_RETURN_NONE;
}

PyObject* AcceptKeyword(PyObject *self, PyObject *args, PyObject* kwargs)
{
  int n;
  char* keywords[] = {"n", NULL};

  PyArg_ParseTupleAndKeywords(args, kwargs, "i", keywords, &n);
  std::cout << "Accept Keyword Parameters : (" << keywords[0] << " : " << n << ")" << std::endl;
  Py_RETURN_NONE;
}
