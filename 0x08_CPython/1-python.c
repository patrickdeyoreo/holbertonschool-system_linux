#include <stdio.h>

#include <Python.h>

/**
 * print_python_list - print basic info about a Python list object
 *
 * @p: pointer to a Python list object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i = 0, n = PyList_Size(p);
	PyObject *o = NULL;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", n);
	printf("[*] Allocated = %ld\n", ((PyListObject *) p)->allocated);
	while (i < n)
	{
		o = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i++, Py_TYPE(o)->tp_name);
	}
}
