/*
    Here is all the functions protoypes needed for the project
*/


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "hashtable.h"

typedef struct {
    int id;
    char name[50];
    int age;
    char gender; // 'M' or 'F'
    int slot;    // -1 if no reservation, 0-4 slots
} Patient;

// Admin operations
int admin_login();
void add_patient(HashTable *ht);
void edit_patient(HashTable *ht);
void reserve_slot(HashTable *ht, int slots[]);
void cancel_reservation(HashTable *ht, int slots[]);

// User operations
void view_patient(HashTable *ht);
void view_reservations(HashTable *ht, int slots[]);

// Utility
size_t hash_int(void *key);
int compare_int(void *a, void *b);

#endif /* FUNCTIONS_H */