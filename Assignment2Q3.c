#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev, *next;
};

struct DNode *head = NULL;

void printList() {
    struct DNode *temp = head;
    if (!temp) {
        printf("\nList is empty!");
        return;
    }
    printf("\nThe list is: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertAtBeg(int data) {
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
    printf("\nElement inserted at the beginning!");
}

void insertAtEnd(int data) {
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    if (!head) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct DNode *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterK(int k, int data) {
    struct DNode *temp = head;
    for (int i = 1; i < k && temp; i++)
        temp = temp->next;
    if (!temp) {
        printf("\nPosition out of bounds!");
        return;
    }
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void insertBeforeK(int k, int data) {
    if (k <= 1) {
        insertAtBeg(data);
        return;
    }
    insertAfterK(k - 1, data);
}

void insertAfterValue(int val, int data) {
    struct DNode *temp = head;
    while (temp && temp->data != val)
        temp = temp->next;
    if (!temp) {
        printf("\nValue not found!");
        return;
    }
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void insertBeforeValue(int val, int data) {
    struct DNode *temp = head;
    while (temp && temp->data != val)
        temp = temp->next;
    if (!temp) {
        printf("\nValue not found!");
        return;
    }
    if (temp == head) {
        insertAtBeg(data);
        return;
    }
    struct DNode *newNode = (struct DNode *)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteFirst() {
    if (!head) {
        printf("\nList is empty!");
        return;
    }
    struct DNode *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    printf("\nDeleted first element: %d", temp->data);
    free(temp);
}

void deleteEnd() {
    if (!head) {
        printf("\nList is empty!");
        return;
    }
    struct DNode *temp = head;
    if (!temp->next) {
        deleteFirst();
        return;
    }
    while (temp->next)
        temp = temp->next;
    printf("\nDeleted last element: %d", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

void deleteKth(int k) {
    if (k < 1 || !head) {
        printf("\nInvalid position!");
        return;
    }
    struct DNode *temp = head;
    for (int i = 1; i < k && temp; i++)
        temp = temp->next;
    if (!temp) {
        printf("\nPosition out of bounds!");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    printf("\nDeleted element at position %d: %d", k, temp->data);
    free(temp);
}

void deleteAfterK(int k) {
    struct DNode *temp = head;
    for (int i = 1; i < k && temp; i++)
        temp = temp->next;
    if (!temp || !temp->next) {
        printf("\nNo node exists after the given position!");
        return;
    }
    struct DNode *del = temp->next;
    temp->next = del->next;
    if (del->next)
        del->next->prev = temp;
    printf("\nDeleted element after position %d: %d", k, del->data);
    free(del);
}

void deleteBeforeK(int k) {
    if (k <= 1 || !head || !head->next) {
        printf("\nNo node exists before the given position!");
        return;
    }
    deleteKth(k - 1);
}

void deleteByValue(int val) {
    struct DNode *temp = head;
    while (temp && temp->data != val)
        temp = temp->next;
    if (!temp) {
        printf("\nValue not found!");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    printf("\nDeleted node with value: %d", temp->data);
    free(temp);
}

void reverse() {
    struct DNode *curr = head, *temp = NULL;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp)
        head = temp->prev;
}

void sort() {
    struct DNode *i, *j;
    int t;
    for (i = head; i && i->next; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}

int search(int val) {
    struct DNode *temp = head;
    int i = 0;
    while (temp) {
        if (temp->data == val)
            return i;
        temp = temp->next;
        i++;
    }
    return -1;
}

void create(int n) {
    int data;
    if (head != NULL) {
        printf("\nList already exists!");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("\nEnter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
}

int main() {
    int ch, n, data, k;
    do {
        printf("\n\n--- Doubly Linked List Menu ---");
        printf("\n1. Create list");
        printf("\n2. Print list");
        printf("\n3. Insert at beginning");
        printf("\n4. Insert at end");
        printf("\n5. Insert after kth node");
        printf("\n6. Insert after node with value");
        printf("\n7. Insert before kth node");
        printf("\n8. Insert before node with value");
        printf("\n9. Delete first node");
        printf("\n10. Delete last node");
        printf("\n11. Delete after kth node");
        printf("\n12. Delete before kth node");
        printf("\n13. Delete kth node");
        printf("\n14. Delete node with value");
        printf("\n15. Reverse list");
        printf("\n16. Sort list");
        printf("\n17. Search element");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);
                create(n);
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtBeg(data);
                break;
            case 4:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("\nEnter k: ");
                scanf("%d", &k);
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAfterK(k, data);
                break;
            case 6:
                printf("\nEnter value: ");
                scanf("%d", &k);
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAfterValue(k, data);
                break;
            case 7:
                printf("\nEnter k: ");
                scanf("%d", &k);
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertBeforeK(k, data);
                break;
            case 8:
                printf("\nEnter value: ");
                scanf("%d", &k);
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertBeforeValue(k, data);
                break;
            case 9:
                deleteFirst();
                break;
            case 10:
                deleteEnd();
                break;
            case 11:
                printf("\nEnter k: ");
                scanf("%d", &k);
                deleteAfterK(k);
                break;
            case 12:
                printf("\nEnter k: ");
                scanf("%d", &k);
                deleteBeforeK(k);
                break;
            case 13:
                printf("\nEnter k: ");
                scanf("%d", &k);
                deleteKth(k);
                break;
            case 14:
                printf("\nEnter value: ");
                scanf("%d", &data);
                deleteByValue(data);
                break;
            case 15:
                reverse();
                printf("\nList reversed!");
                break;
            case 16:
                sort();
                printf("\nList sorted!");
                break;
            case 17:
                printf("\nEnter element to search: ");
                scanf("%d", &data);
                k = search(data);
                if (k == -1)
                    printf("\nElement not found!");
                else
                    printf("\nElement found at index: %d", k);
                break;
            case 0:
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (ch != 0);
    return 0;
}

