/*
    Here is implementation for all of the protoypes in HASHTABLE.h
*/


#include <stdlib.h> // for malloc and calloc
#include <string.h> // for patient name manipulation
#include <stdio.h>
#include "hashtable.h"

static void ensure_capacity(HashTable *ht) {
    if (ht->count < ht->maxCollisions * ht->size) return;
    size_t new_size = ht->size + ht->growthFactor;
    Item **old_buckets = ht->buckets;
    size_t old_size = ht->size;

    ht->buckets = calloc(new_size, sizeof(Item*));
    ht->size = new_size;
    ht->count = 0;

    for (size_t i = 0; i < old_size; ++i) {
        Item *cur = old_buckets[i];
        while (cur) {
            hashtable_add(ht, cur->key, cur->value);
            Item *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(old_buckets);
}

HT hashtable_initialize(size_t initial_size, size_t max_collisions,
                        size_t growth_factor, hash_function hf,
                        compare_equal eq) {
    HashTable *ht = malloc(sizeof(HashTable));
    if (!ht) return NULL;
    ht->size = initial_size;
    ht->count = 0;
    ht->maxCollisions = max_collisions;
    ht->growthFactor = growth_factor;
    ht->hf = hf;
    ht->eq = eq;
    ht->buckets = calloc(initial_size, sizeof(Item*));
    if (!ht->buckets) { free(ht); return NULL; }
    return ht;
}

void hashtable_destroy(HT ht) {
    if (!ht) return;
    for (size_t i = 0; i < ht->size; ++i) {
        Item *cur = ht->buckets[i];
        while (cur) {
            Item *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(ht->buckets);
    free(ht);
}

int hashtable_add(HT ht, void *key, void *value) {
    ensure_capacity(ht);
    size_t idx = ht->hf(key) % ht->size;
    Item *cur = ht->buckets[idx];
    while (cur) {
        if (ht->eq(cur->key, key)) {
            cur->value = value;
            return 1;
        }
        cur = cur->next;
    }
    Item *node = malloc(sizeof(Item));
    if (!node) return 0;
    node->key = key;
    node->value = value;
    node->next = ht->buckets[idx];
    ht->buckets[idx] = node;
    ht->count++;
    return 1;
}

int hashtable_remove(HT ht, void *key) {
    size_t idx = ht->hf(key) % ht->size;
    Item *cur = ht->buckets[idx];
    Item *prev = NULL;
    while (cur) {
        if (ht->eq(cur->key, key)) {
            if (prev) prev->next = cur->next;
            else       ht->buckets[idx] = cur->next;
            free(cur);
            ht->count--;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

void *hashtable_get(HT ht, void *key) {
    size_t idx = ht->hf(key) % ht->size;
    Item *cur = ht->buckets[idx];
    while (cur) {
        if (ht->eq(cur->key, key)) return cur->value;
        cur = cur->next;
    }
    return NULL;
}
