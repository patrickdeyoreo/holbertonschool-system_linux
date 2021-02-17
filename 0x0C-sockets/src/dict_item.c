#include <stdlib.h>
#include <string.h>

#include "dict.h"

/**
 * dict_item_create - create a dictionary item
 *
 * @key: key of the item
 * @value: value of the item
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the newly-created item.
 */
dict_item_t *dict_item_create(const char *key, const char *value)
{
	dict_item_t *item = malloc(sizeof(*item));
	char *item_key = strdup(key);
	char *item_value = strdup(value);

	if (item && item_key && item_value)
	{
		item->key = item_key;
		item->value = item_value;
		item->next = NULL;
		return (item);
	}
	free(item);
	free(item_key);
	free(item_value);
	return (NULL);
}

/**
 * dict_item_delete - delete a dictionary item
 *
 * @item: pointer to the item to delete
 */
void dict_item_delete(dict_item_t *item)
{
	if (item)
	{
		free(item->key);
		free(item->value);
		free(item);
	}
}
