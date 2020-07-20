#include "option.h"

/**
 * options - initialize and access a static table of options indexed by name
 *
 * Return: a pointer to the static option table
 */
option_table_t *options(void)
{
	static option_table_t option_table = {{0}};
	static option_t option_table_init[] = OPTION_TABLE_INIT;
	static option_t *opt = option_table_init;
	size_t index = 0;

	while ((index = opt->name))
		option_table[index] = *opt++;

	return (&option_table);
}

/**
 * option_is_defined - check if an option exists in the option table
 * @c: single-character option identifier
 *
 * Return: true if the option c exists, otherwise false
 */
bool option_is_defined(int c)
{
	return (c < OPTION_TABLE_SIZE && (*options())[c].name);
}

/**
 * option_is_enabled - check if an option is enabled in the option table
 * @c: single-character option identifier
 *
 * Return: true if the option c is enabled, otherwise false
 */
bool option_is_enabled(int c)
{
	return (c < OPTION_TABLE_SIZE && (*options())[c].enabled);
}
