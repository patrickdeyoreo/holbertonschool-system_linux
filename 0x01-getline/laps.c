#include <string.h>
#include "laps.h"

/**
 * race_state - track the number of laps made by several cars in a race
 * @id: an array of intrepresenting the “identifier” of each car
 * @size: the size of the id array
 *
 * Description: Each car identifier is considered to unique. If an identifier
 * is unknown, a car is created with the number of laps completed set to 0,
 * and "Car X joined the race" is printed to stdout, where X is the identifier.
 * Each time the function is called, the number of laps of each car in listed
 * in id is incremented by 1 and the state of the race is printed as follows:
 * "Race state" followed by a new line, then "Car X [Y laps]", for each car,
 * sorted by id, where X is the id and Y is the number of laps completed. If
 * this function is called with size = 0, it will free all allocated memory.
 */
void race_state(int *id __attribute__((unused)), size_t size)
{
	static s_hash_table_t state = {0};
	s_hash_node_t *tmp = NULL;

	if (size == 0)
	{
		while ((tmp = state.sorted))
		{
			state.sorted = tmp->next;
			free(tmp);
		}
	}
}
