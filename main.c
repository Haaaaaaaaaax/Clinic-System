/*
    Here is the main file for the project
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "functions.h"

int main() {
    // initialize hash table
    HashTable *ht = hashtable_initialize(10, 2, 5, hash_int, compare_int);
    int slots[5] = {-1, -1, -1, -1, -1};
    int choice;

    while (1) {
        printf("1) Admin Mode\n2) User Mode\n0) Exit\nChoice: ");
        if (scanf("%d", &choice)!=1) break;
        if (choice==0) break;
        if (choice==1) {
            if (admin_login()) {
                do {
                    printf("\nAdmin:\n1) Add\n2) Edit\n3) Reserve\n4) Cancel\n0) Back\nChoice: ");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1: add_patient(ht); break;
                        case 2: edit_patient(ht); break;
                        case 3: reserve_slot(ht, slots); break;
                        case 4: cancel_reservation(ht, slots); break;
                    }
                } while (choice);
            }
        } else if (choice==2) {
            do {
                printf("\nUser:\n1) View Patient\n2) View Reservations\n0) Back\nChoice: ");
                scanf("%d", &choice);
                switch(choice) {
                    case 1: view_patient(ht); break;
                    case 2: view_reservations(ht, slots); break;
                }
            } while (choice);
        } else {
            printf("Wrong number. Please try again\n");
        }
    }

    hashtable_destroy(ht);
    return 0;
}
