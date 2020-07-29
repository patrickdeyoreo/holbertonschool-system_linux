#include "laps.h"

/**
 * _strlen - measure the length of a string
 * @s: the string to measure
 * Return: the length of the string
 */
static size_t _strlen(const char *s)
{
	size_t len = 0;

	if (s)
	{
		while (*s++)
			len += 1;
	}
	return (len);
}

/**
 * printint - write an integer to stdout
 * @n: the integer
 */
static void printint(int n)
{
	char chr = '0' + (n < 0 ? -1 : 1) * (n % 10);

	if (n < 0)
		write(STDOUT_FILENO, "-", 1);
	if (n / 10)
		printint((n < 0 ? -1 : 1) * (n / 10));

	write(STDOUT_FILENO, &chr, 1);
}

/**
 * print_race_state - print the number of laps each car has completed
 * @head: a pointer to the head of a list of cars
 */
static void print_race_state(const s_hash_node_t *head)
{
	if (head)
	{
		PUTS("Race state\n");
		do {
			PUTS("Car ");
			printint(head->id);
			PUTS(" [");
			printint(head->value);
			PUTS(" laps]\n");
		} while ((head = head->s_next));
	}
}

/**
 * free_race_state - free memory allocated for the race state
 * @state: a pointer to the race state
 */
static void free_race_state(s_hash_table_t *state)
{
	s_hash_node_t *tmp = NULL;
	size_t index = 0;

	if (state)
	{
		while ((tmp = state->sorted))
		{
			state->sorted = tmp->s_next;
			free(tmp);
		}
		while (index < TABLE_SIZE)
		{
			state->table[index++] = NULL;
		}
	}
}

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
void race_state(int *id, size_t size)
{
	static s_hash_table_t state = {0};
	s_hash_node_t **ref = NULL, *tmp = NULL;
	int *stop = NULL;

	if (size)
	{
		for (stop = id + size; id < stop; id += 1)
		{
			ref = &state.table[HASH(*id)];
			while (*ref && (*ref)->id != *id)
				ref = &(*ref)->next;
			if (*ref)
			{
				(*ref)->value += 1;
			}
			else
			{
				PUTS("Car ");
				printint(*id);
				PUTS(" joined the race\n");
				tmp = *ref = malloc(sizeof(*tmp));
				if (tmp)
				{
					tmp->next = NULL;
					tmp->id = *id;
					tmp->value = 0;
				}
				ref = &state.sorted;
				while (*ref && (*ref)->id < tmp->id)
					ref = &(*ref)->s_next;
				tmp->s_next = *ref;
				*ref = tmp;
			}
		}
		print_race_state(state.sorted);
	}
	else
	{
		free_race_state(&state);
	}
}
