#ifndef _LAPS_H_
#define _LAPS_H_

#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 127

#define HASH(x) ((x) % HASH_TABLE_SIZE)

/**
 * struct s_hash_node_s - a singly-linked and doubly-linked list node
 * @next: the address of the next node in a singly-linked hash table chain
 * @s_next: the address of the next node in a sorted doubly-linked list
 * @s_prev: the address of the prev node in a sorted doubly-linked list
 * @id: the id (key) of the data
 * @value: the value of the data
 */
typedef struct s_hash_node_s
{
	struct s_hash_node_s *next;
	struct s_hash_node_s *s_next;
	struct s_hash_node_s *s_prev;
	int id;
	int value;
} s_hash_node_t;

/**
 * struct s_hash_table_s - a hash table and a sorted doubly-linked list
 * @table: an array of table elements chained for collision resolution
 * @sorted: a pointer to the first item in a sorted doubly-linked list
 */
typedef struct s_hash_table_s
{
	struct s_hash_node_s *table[HASH_TABLE_SIZE];
	struct s_hash_node_s *sorted;
} s_hash_table_t;

void race_state(int *id, size_t size);

#endif /* _LAPS_H_ */
