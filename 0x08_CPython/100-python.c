#include <stdbool.h>
#include <stdio.h>

#include <Python.h>

/**
 * digits_to_str - render an array of decimal digits as a string
 *
 * @vo: vector of decimal digits
 * @size: the size of the vector
 * @negative: 1 if number is negative
 *
 * Return: If memory allocation fails, return NUll.
 * Otherwise, return a string representation of digits.
 */
static char *digits_to_str(digit *vo, ssize_t size, bool negative)
{
	char *s = NULL;
	char *p = NULL;
	digit factor = 10;
	digit remain = vo[size - 1];
	size_t s_len = (size - 1) * _PyLong_DECIMAL_SHIFT + negative + 1;
	ssize_t i = 0;
	ssize_t j = 0;

	while (factor <= remain)
	{
		factor *= 10;
		++s_len;
	}
	s = calloc(1, s_len + 1);
	if (s)
	{
		p = s + s_len;
		for (i = 0; i < size - 1; ++i)
		{
			remain = vo[i];
			for (j = 0; j < _PyLong_DECIMAL_SHIFT; ++j)
			{
				*--p = '0' + remain % 10;
				remain /= 10;
			}
		}
		remain = vo[i];
		do {
			*--p = '0' + remain % 10;
			remain /= 10;
		} while (remain);
		if (negative)
			*--p = '-';
	}
	return (s);
}

/**
 * long_to_str - renders a python long int as a string
 *
 * @o: pointer to python int object
 *
 * Return: Upon error, return NULL.
 * Otherwise, return a pointer to a dynamically-allocated string.
 */
static char *long_to_str(PyObject *o)
{
	PyLongObject *a = (PyLongObject *) o;
	int d = (33 * _PyLong_DECIMAL_SHIFT) /
		(10 * PyLong_SHIFT - 33 * _PyLong_DECIMAL_SHIFT);
	bool negative = Py_SIZE(a) < 0;
	size_t size_a = Py_SIZE(a) * (negative ? -1 : 1);
	size_t size = 0;
	size_t i = size_a;
	size_t j = 0;
	digit *vo = calloc(sizeof(digit), size_a * (d + 1) / d + 1);
	digit *vi = a->ob_digit;
	twodigits z = 0;
	digit hi = 0;

	if (!vo)
		return (NULL);

	while (--i < size_a)
	{
		hi = vi[i];
		for (j = 0; j < size; ++j)
		{
			z = (twodigits) vo[j] << PyLong_SHIFT | hi;
			hi = (digit) (z / _PyLong_DECIMAL_BASE);
			vo[j] = (digit) (z - (twodigits) hi * _PyLong_DECIMAL_BASE);
		}
		while (hi)
		{
			vo[size++] = hi % _PyLong_DECIMAL_BASE;
			hi /= _PyLong_DECIMAL_BASE;
		}
	}
	if (size == 0)
		vo[size++] = 0;

	return (digits_to_str(vo, size, negative));
}

/**
 * print_python_int - print a Python int object
 *
 * @p: pointer to a Python object
 */
void print_python_int(PyObject *p)
{
	char *s = p && PyLong_Check(p) ? long_to_str(p) : NULL;

	if (s)
	{
		printf("%s\n", s);
		free(s);
	}
}
