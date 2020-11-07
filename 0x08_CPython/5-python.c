#include <stdbool.h>
#include <stdio.h>

#include <Python.h>

/**
 * print_python_int - print basic info about a Python int object
 *
 * @p: pointer to a Python object
 */
void print_python_int(PyObject *p)
{
	unsigned long int value = 0;
	unsigned long int total = 0;
	bool negative = false;
	size_t size = 0;
	size_t shift = 0;
	size_t index = 0;

	printf("[.] int object info\n");
	if (!p || !PyLong_Check(p))
	{
		printf("  [ERROR] Invalid Int Object\n");
		return;
	}
	negative = ((PyVarObject *) p)->ob_size < 0;
	if (negative)
		size = ((PyVarObject *) p)->ob_size * -1;
	else
		size = ((PyVarObject *) p)->ob_size;
	switch (size)
	{
	case 3:
		if (((PyLongObject *) p)->ob_digit[2] < 0x10)
			break;
	default: /* fall through */
		if (size < 3)
			break;
		printf("C unsigned long int overflow\n");
		return;
	}
	for (; index < size; index += 1, shift += PyLong_SHIFT, total += value)
		value = (1UL << shift) * ((PyLongObject *) p)->ob_digit[index];
	if (negative)
		printf("-");
	printf("%lu\n", total);
	fflush(stdout);
}
