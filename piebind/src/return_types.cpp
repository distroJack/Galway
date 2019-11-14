
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

PyObject* ReturnNumber(PyObject *self, PyObject *args)
{
	std::cout << "Return Number Parameter" << std::endl;
	return Py_BuildValue("i", 1);
}

PyObject* ReturnTuple(PyObject *self, PyObject *args)
{
	std::cout << "Return Two Parameter" << std::endl;
	auto a = Py_BuildValue("i", 1);
	auto b = Py_BuildValue("i", 2);
	return PyTuple_Pack(2, a, b);
}
