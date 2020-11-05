#include <stdio.h>

#include <Python.h>

#define MIN(m, n) ((m) < (n) ? (m) : (n))

/**
 * print_python_float - print basic info about a Python float object
 *
 * @p: pointer to a Python object
 */
void print_python_float(PyObject *p)
{
	char *s = NULL;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");
	if (p && PyFloat_Check(p))
	{
		s = PyOS_double_to_string(
			((PyFloatObject *) p)->ob_fval, 'g', 16,
			Py_DTSF_ADD_DOT_0, NULL);
		printf("  value: %s\n", s);
		PyMem_Free(s);
	}
	else
	{
		printf("  [ERROR] Invalid Float Object\n");
	}
}

/**
 * print_python_bytes - print basic info about a Python bytes object
 *
 * @p: pointer to a Python object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t i = 0;
	Py_ssize_t n = p ? ((PyVarObject *) p)->ob_size : 0;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (p && PyBytes_Check(p))
	{
		printf("  size: %ld\n", n);
		printf("  trying string: %s\n",
			((PyBytesObject *) p)->ob_sval);
		n = MIN(n + 1, 10);
		printf("  first %ld bytes: ", n);
		for (i = 0; i < n; i += 1)
			printf("%02hhx%c",
				((PyBytesObject *) p)->ob_sval[i],
				i + 1 < n ? ' ' : '\n');
	}
	else
	{
		printf("  [ERROR] Invalid Bytes Object\n");
	}
}

/**
 * print_python_list - print basic info about a Python list object
 *
 * @p: pointer to a Python object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i = 0;
	Py_ssize_t n = p ? ((PyVarObject *) p)->ob_size : 0;
	PyObject *o = NULL;

	setbuf(stdout, NULL);
	if (p && PyList_Check(p))
	{
		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %ld\n", n);
		printf("[*] Allocated = %ld\n",
			((PyListObject *) p)->allocated);
		for (i = 0; i < n; i += 1)
		{
			o = ((PyListObject *) p)->ob_item[i];
			printf("Element %ld: %s\n", i, o->ob_type->tp_name);
			if (PyBytes_Check(o))
				print_python_bytes(o);
			if (PyFloat_Check(o))
				print_python_float(o);
		}
	}
	else
	{
		printf("  [ERROR] Invalid List Object\n");
	}
}
