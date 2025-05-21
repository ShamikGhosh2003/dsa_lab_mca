#include <stdio.h>
#include <stdlib.h>

struct CSNode {
    int data;
    struct CSNode *next;
};

struct CSNode* createCSLL(int n) {
    struct CSNode *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++) {
        struct CSNode *newNode = malloc(sizeof(struct CSNode));
        newNode->data = i;
        newNode->next = NULL;
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head;
    return head;
}

int solveWithCSLL(int n, int k) {
    struct CSNode *head = createCSLL(n);
    struct CSNode *ptr = head, *prev = NULL;
    while (ptr->next != ptr) {
        for (int i = 1; i < k; i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        free(ptr);
        ptr = prev->next;
    }
    int result = ptr->data;
    free(ptr);
    return result;
}

struct CDNode {
    int data;
    struct CDNode *prev, *next;
};

struct CDNode* createCDLL(int n) {
    struct CDNode *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++) {
        struct CDNode *newNode = malloc(sizeof(struct CDNode));
        newNode->data = i;
        if (!head) {
            head = tail = newNode;
            newNode->next = newNode->prev = newNode;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }
    return head;
}

int solveWithCDLL(int n, int k) {
    struct CDNode *head = createCDLL(n);
    struct CDNode *ptr = head;
    while (ptr->next != ptr) {
        for (int i = 1; i < k; i++) ptr = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        struct CDNode *del = ptr;
        ptr = ptr->next;
        free(del);
    }
    int result = ptr->data;
    free(ptr);
    return result;
}

int main() {
    int n, k;
    printf("Enter number of people: ");
    scanf("%d", &n);
    printf("Enter skip count (k): ");
    scanf("%d", &k);

    printf("\nSurvivor using Circular Singly Linked List: Person %d\n", solveWithCSLL(n, k));
    printf("Survivor using Circular Doubly Linked List: Person %d\n", solveWithCDLL(n, k));

    return 0;
}

