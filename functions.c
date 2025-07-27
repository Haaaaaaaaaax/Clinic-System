/*
    Here all the functions implementations needed for my project
*/


#include <stdio.h>
#include <stdlib.h> // for malloc and calloc
#include <string.h> // for patient name manipulation
#include "functions.h"
#include "hashtable.h"

#define MAX_TRIES 3
#define PASSWORD 1234

int admin_login() {
    int pwd, tries = 0;
    while (tries < MAX_TRIES) {
        printf("Enter admin password: ");
        if (scanf("%d", &pwd) != 1) exit(0);
        if (pwd == PASSWORD) return 1;
        printf("Incorrect password.\n");
        tries++;
    }
    printf("Too many failed attempts. Exiting.\n");
    exit(0);
    return 0;
}

void add_patient(HashTable *ht) {
    Patient *p = malloc(sizeof(Patient));
    if (!p) { printf("Memory error.\n"); return; }
    printf("ID: "); 
    scanf("%d", &p->id);
    if (hashtable_get(ht, &p->id)) {
        printf("ID already exists.\n");
        free(p);
        return;
    }

    // Read a full line (up to 49 chars) stopping at newline
    printf("Name: ");
    scanf(" %49[^\n]", p->name);

    printf("Age: ");
    scanf("%d", &p->age);

    printf("Gender (M/F): ");
    scanf(" %c", &p->gender);

    p->slot = -1;
    hashtable_add(ht, &p->id, p);
    printf("Patient added.\n");
}

void edit_patient(HashTable *ht) {
    int id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    Patient *p = hashtable_get(ht, &id);
    if (!p) {
        printf("Incorrect ID.\n");
        return;
    }

    printf("Name (%s): ", p->name);
    scanf(" %49[^\n]", p->name);

    printf("Age (%d): ", p->age);
    scanf("%d", &p->age);

    printf("Gender (%c): ", p->gender);
    scanf(" %c", &p->gender);

    printf("Record updated.\n");
}

void reserve_slot(HashTable *ht, int slots[]) {
    int id; printf("Enter patient ID: "); scanf("%d", &id);
    Patient *p = hashtable_get(ht, &id);
    if (!p) { printf("Incorrect ID.\n"); return; }
    printf("Available slots:\n");
    const char *names[] = {"2-2:30","2:30-3","3-3:30","4-4:30","4:30-5"};
    for (int i = 0; i < 5; i++) if (slots[i]==-1) printf("[%d] %s\n", i, names[i]);
    int choice; printf("Choose slot index: "); scanf("%d", &choice);
    if (choice<0||choice>4||slots[choice]!=-1) { printf("Invalid choice.\n"); return; }
    slots[choice] = id; p->slot = choice;
    printf("Reserved %s for %s.\n", names[choice], p->name);
}

void cancel_reservation(HashTable *ht, int slots[]) {
    int id; printf("Enter patient ID: "); scanf("%d", &id);
    Patient *p = hashtable_get(ht, &id);
    if (!p || p->slot<0) { printf("No reservation found.\n"); return; }
    slots[p->slot] = -1; p->slot = -1;
    printf("Reservation canceled.\n");
}

void view_patient(HashTable *ht) {
    int id; printf("Enter patient ID: "); scanf("%d", &id);
    Patient *p = hashtable_get(ht, &id);
    if (!p) { printf("Patient not found.\n"); return; }
    printf("ID:%d Name:%s Age:%d Gender:%c Slot:%d\n",
           p->id, p->name, p->age, p->gender, p->slot);
}

void view_reservations(HashTable *ht, int slots[]) {
    const char *names[] = {"2-2:30","2:30-3","3-3:30","4-4:30","4:30-5"};
    printf("Today's reservations:\n");
    for (int i=0;i<5;i++) {
        if (slots[i] != -1)
            printf("%s: Patient ID %d\n", names[i], slots[i]);
    }
}

size_t hash_int(void *key) {
    return *(int*)key;
}
int compare_int(void *a, void *b) {
    return *(int*)a == *(int*)b;
}
