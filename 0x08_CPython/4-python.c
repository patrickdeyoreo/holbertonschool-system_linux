#include <stdio.h>

#include <Python.h>

/**
 * print_python_string - print basic info about a Python string object
 *
 * @p: pointer to a Python object
 */
void print_python_string(PyObject *p)
{
	wprintf(L"[.] string object info\n");
	if (p && PyUnicode_Check(p))
	{
		if (((PyASCIIObject *) p)->state.ascii)
			wprintf(L"  type: compact ascii\n");
		else
			wprintf(L"  type: compact unicode object\n");
		PyUnicode_READY(p);
		wprintf(L"  length: %ld\n", PyUnicode_GET_LENGTH(p));
		wprintf(L"  value: %ls\n", PyUnicode_AS_UNICODE(p));
	}
	else
	{
		wprintf(L"  [ERROR] Invalid String Object\n");
	}
}

