#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#define KEY_LENGTH 64
#define HTAB_SIZE 4096

/* Our hash table uses a key/value pair to store entries in the table.
The key is a string which is hashed into an integer using the htab_hash
function. The resulting index is used as an address in the array of key/value
pairs to store a specific pair. When looking up a pair using the key, the
key is again hashed, and the resulting index is used to retrieve the desired pair
from the array. This operation has O(1) complexity.*/

typedef struct
{
	char* key;
	int value;
} htable_node;

typedef struct
{
	int num_nodes;
	htable_node* nodes[HTAB_SIZE];
} hash_table;

hash_table* create_htab();
void destroy_htab(hash_table* htab);

// Add a key/value pair to the hash table
inline int htab_add(hash_table* htab, char* key, int value);

// Find a key/value pair in the hash table, using the key
inline int htab_find(hash_table* htab, char* key);

// This is the hashing function used to create an index from a key
inline unsigned int htab_hash(char* key);

#endif
