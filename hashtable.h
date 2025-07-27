/*
    This is the HASHTABLE header file that contains all prototypes of the needed functions

    HASHTABLE_H
*/



#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h> // for size_t

// Function pointer types
typedef size_t (*hash_function)(void *key);
typedef int    (*compare_equal)(void *a, void *b);


typedef struct Item {
    void *key;
    void *value;
    struct Item *next;
} Item;


typedef struct HashTable {
    size_t size;
    size_t count;
    size_t maxCollisions;
    size_t growthFactor;
    Item **buckets;
    hash_function hf;
    compare_equal eq;
} HashTable;


// Create a new hash table
typedef HashTable *HT;
HT hashtable_initialize(size_t initial_size, size_t max_collisions, size_t growth_factor,
                        hash_function hf, compare_equal eq);


// Free entire table and items
void hashtable_destroy(HT ht);


// Insert or replace key/value
int  hashtable_add(HT ht, void *key, void *value);


// Remove by key
int  hashtable_remove(HT ht, void *key);


// Lookup by key
void *hashtable_get(HT ht, void *key);

#endif /* HASHTABLE_H */
