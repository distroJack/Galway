
#include <iostream>
#include "return_types.h"

PyObject* ReturnNone(PyObject *self, PyObject *args)
{
	std::cout << "Return No Parameters" << std::endl;
  Py_RETURN_NONE;
}

PyObject* ReturnOne(PyObject *self, PyObject *args)
{
	std::cout << "Return One Parameter" << std::endl;
	return Py_BuildValue("i", 1);
}
