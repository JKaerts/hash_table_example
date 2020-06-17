#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

/*!
 * \brief constructor for an entry in the hash table
 * \param k The key for the entry.
 * \param k The value for the entry.
 * \return A pointer to the new entry.
 */
static ht_item* ht_new_item(const char* k, const char* v) {
	ht_item* i = malloc(sizeof(ht_item));
	char* keyptr = malloc(strlen(k)+1);
	char* valptr = malloc(strlen(v)+1);
	strcpy(keyptr, k);
	strcpy(valptr, v);

	i->key = keyptr;
	i->value = valptr;
	return i;
}

/*!
 * \brief constructor for a hash table
 * \return A pointer to the new table
 *
 * The table has room for 53 elements and is empty
 */
ht_hash_table* ht_new() {
	ht_hash_table* ht = malloc(sizeof(ht_hash_table));
	
	ht->size = 53;
	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
	return ht;
}

static void ht_del_item(ht_item* i) {
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}
