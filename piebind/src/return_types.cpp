
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
	std::cout << "Return Tuple" << std::endl;
	return Py_BuildValue("(ii)", 1, 2);
}

PyObject* ReturnList(PyObject *self, PyObject *args)
{
	std::cout << "Return List" << std::endl;
	return Py_BuildValue("[iii]", 1, 2, 3);
}

PyObject* ReturnString(PyObject *self, PyObject *args)
{
	std::cout << "Return String" << std::endl;
	return Py_BuildValue("s", "Hello Buddy");
}
