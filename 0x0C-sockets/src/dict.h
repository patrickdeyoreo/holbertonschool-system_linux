#ifndef _DICT_H_
#define _DICT_H_

#include <stddef.h>

#include "hash.h"

#define DICT_TABLE_SZ 127
#define HASH(key) (dbj2(key) % DICT_TABLE_SZ)

/**
 * struct dict_item_s - dictionary item structure
 *
 * @key: item key
 * @value: item value
 * @next: next item in a list
 */
typedef struct dict_item_s
{
	char *key;
	char *value;
	struct dict_item_s *next;
} dict_item_t;

/**
 * struct dict_s - dictionary structure
 *
 * @table: hash table of items
 */
typedef struct dict_s
{
	dict_item_t *table[DICT_TABLE_SZ];
} dict_t;

dict_item_t *dict_item_create(const char *key, const char *value);
void dict_item_delete(dict_item_t *item);

dict_t *dict_create(void);
void dict_delete(dict_t *dict);
dict_item_t *dict_set(dict_t *dict, const char *key, const char *value);
dict_item_t *dict_get(dict_t *dict, const char *key);
void dict_discard(dict_t *dict, const char *key);

#endif /* _DICT_H_ */
