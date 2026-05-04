/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : Nadine Gabe Ulina Sianturi
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Nadine Gabe Ulina Sianturi (13224005)
 *   Nama File           : soal2.c
 *   Deskripsi           : Menggabungkan dua linked list terurut naik. Dengan aturan Kedua list sudah terurut non-menurun, Hasil juga harus non-menurun,
 * Semua elemen dari kedua list harus tetap muncul, Duplicates boleh ada. (PLS BISA AYO)
 * 
 */

// source : https://www.geeksforgeeks.org/dsa/merge-two-sorted-linked-lists/, https://stackoverflow.com/questions/18646190/if-else-statement-shortcut-in-c


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* mergelist(Node* list1, Node* list2) {
    Node* merged = NULL;
    Node** tail = &merged;

    while (list1 && list2) {
        if ((*list1).data <= (*list2).data) { 
            *tail = list1;
            list1 = (*list1).next;
        } else {
            *tail = list2;
            list2 = (*list2).next;
        }
        tail = &((*(*tail)).next);
    }

    *tail = (list1 != NULL) ? list1 : list2;
    return merged;
}

Node* insertfirst(Node* head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    (*newNode).data = data;
    (*newNode).next = NULL;

    if (head == NULL) return newNode;

    Node* temp = head;
    while ((*temp).next != NULL) temp = (*temp).next;
    (*temp).next = newNode;
    return head;
}

void printlist(Node* head) {
    if (head == NULL) {
        printf("MERGED EMPTY\n");
        return;
    }

    printf("MERGED ");
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d", (*ptr).data);
        if ((*ptr).next != NULL) printf(" ");
        ptr = (*ptr).next;
    }
    printf("\n");
}

int main() {
    int N, M, i, x;
    Node *list1 = NULL, *list2 = NULL, *list3 = NULL;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &x);
        list1 = insertfirst(list1, x);
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &x);
        list2 = insertfirst(list2, x);
    }

    list3 = mergelist(list1, list2);
    printlist(list3);

    return 0;
}
