#include <stdlib.h>
#include <string.h>

#include "dict.h"

/**
 * dict_create - create a dictionary
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly-created dictionary.
 */
dict_t *dict_create(void)
{
	dict_t *dict = calloc(1, sizeof(*dict));

	return (dict);
}

/**
 * dict_delete - delete a dictionary
 *
 * @dict: pointer to the dictionary to delete
 */
void dict_delete(dict_t *dict)
{
	dict_item_t **table = NULL;
	dict_item_t **stop = NULL;
	dict_item_t *item = NULL;
	dict_item_t *temp = NULL;

	if (dict)
	{
		table = dict->table;
		stop = table + DICT_TABLE_SZ;
		while (table < stop)
		{
			item = *table++;
			while ((temp = item))
			{
				item = item->next;
				dict_item_delete(temp);
			}
		}
	}
}

/**
 * dict_set - set an item in a dictionary
 *
 * @dict: pointer to the dict in which to set an item
 * @key: pointer to the item key
 * @value: pointer to the item value
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the item.
 */
dict_item_t *dict_set(dict_t *dict, const char *key, const char *value)
{
	size_t hash = HASH(key);
	dict_item_t *item = dict_get(dict, key);
	char *item_value = NULL;

	if (item)
	{
		item_value = strdup(value);
		if (!item_value)
			return (NULL);
		free(item->value);
		item->value = item_value;
	}
	else
	{
		item = dict_item_create(key, value);
		if (!item)
			return (NULL);
		item->next = dict->table[hash];
		dict->table[hash] = item;
	}
	return (item);
}

/**
 * dict_get - get an item from a dictionary
 *
 * @dict: pointer to the dict from which to get an item
 * @key: pointer to the item key
 *
 * Return: If key is not found in the dictionary, return NULL.
 * Otherwise, return a pointer to the item.
 */
dict_item_t *dict_get(dict_t *dict, const char *key)
{
	size_t hash = HASH(key);
	dict_item_t *item = dict->table[hash];

	while (item && strcasecmp(key, item->key))
		item = item->next;
	return (item);
}

/**
 * dict_discard - discard an item from a dictionary
 *
 * @dict: pointer to the dict from which to discard an item
 * @key: pointer to the item key
 */
void dict_discard(dict_t *dict, const char *key)
{
	size_t hash = HASH(key);
	dict_item_t **row = dict->table + hash;
	dict_item_t *item = *row;

	while (item && strcasecmp(key, item->key))
	{
		row = &item->next;
		item = *row;
	}
	if (item)
	{
		*row = item->next;
		dict_item_delete(item);
	}
}
