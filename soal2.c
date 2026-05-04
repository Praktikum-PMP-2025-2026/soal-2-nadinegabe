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
        if (list1->data <= list2->data) { // <= penting untuk urutan stabil
            *tail = list1;
            list1 = list1->next;
        } else {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }

    *tail = (list1 != NULL) ? list1 : list2;
    return merged;
}

Node* append(Node* head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
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
        printf("%d", ptr->data);
        if (ptr->next != NULL) printf(" ");
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int N, M, i, x;
    Node *list1 = NULL, *list2 = NULL, *list3 = NULL;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &x);
        list1 = append(list1, x);
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &x);
        list2 = append(list2, x);
    }

    list3 = mergelist(list1, list2);
    printlist(list3);

    return 0;
}
