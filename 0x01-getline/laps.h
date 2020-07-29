#ifndef _LAPS_H_
#define _LAPS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TABLE_SIZE 127

#define HASH(x) ((x) % TABLE_SIZE)

#define MESSAGE_ADDED_ID(x) ("Car " (x) " joined the race")
#define MESSAGE_ID_LAPS(x, y) ("Car " (x) " [" (y) " laps]")

#define PUTS(s) write(STDOUT_FILENO, (s), _strlen(s))

/**
 * struct s_hash_node_s - a list node for two separate singly-linked lists
 * @next: the address of the next node in a singly-linked hash table chain
 * @s_next: the address of the next node in a sorted doubly-linked list
 * @id: the id (key) of the element
 * @value: the value of the element
 */
typedef struct s_hash_node_s
{
	struct s_hash_node_s *next;
	struct s_hash_node_s *s_next;
	int id;
	int value;
} s_hash_node_t;

/**
 * struct s_hash_table_s - a hash table and a sorted singly-linked list
 * @table: an array of tabledoubly elements chained for collision resolution
 * @sorted: a pointer to the first item in a sorted singly-linked list
 */
typedef struct s_hash_table_s
{
	struct s_hash_node_s *table[TABLE_SIZE];
	struct s_hash_node_s *sorted;
} s_hash_table_t;

void race_state(int *id, size_t size);

#endif /* _LAPS_H_ */
