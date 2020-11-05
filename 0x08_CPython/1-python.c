#include <stdio.h>

#include <Python.h>

#include "python.h"

/**
 * print_python_list - print basic info about a Python list object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i = 0;
	Py_ssize_t n = 0;
	PyObject *o = NULL;

	if (p)
	{
		n = PyList_Size(p);
		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %ld\n", n);
		printf("[*] Allocated = %ld\n", Py_SIZE(p));
		while (i < n)
		{
			o = PyList_GetItem(p, i);
			printf("Element %ld: %s\n", i++, Py_TYPE(o)->tp_name);
		}
	}
}
