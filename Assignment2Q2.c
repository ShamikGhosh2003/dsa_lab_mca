#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void appendTerm(struct Node** head, int coeff, int power) {
    if (coeff == 0) return;
    struct Node* newNode = createNode(coeff, power);
    if (!(*head)) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void displayPoly(struct Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    while (head) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while (p1 && p2) {
        if (p1->power > p2->power) {
            appendTerm(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            appendTerm(&result, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            appendTerm(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        appendTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2) {
        appendTerm(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}

struct Node* subtractPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while (p1 && p2) {
        if (p1->power > p2->power) {
            appendTerm(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            appendTerm(&result, -p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            appendTerm(&result, p1->coeff - p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        appendTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2) {
        appendTerm(&result, -p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}

struct Node* multiplyPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    for (struct Node* i = p1; i; i = i->next) {
        for (struct Node* j = p2; j; j = j->next) {
            int coeff = i->coeff * j->coeff;
            int power = i->power + j->power;

            struct Node* temp = result;
            struct Node* prev = NULL;
            while (temp && temp->power > power) {
                prev = temp;
                temp = temp->next;
            }
            if (temp && temp->power == power) {
                temp->coeff += coeff;
            } else {
                struct Node* newNode = createNode(coeff, power);
                if (!prev) {
                    newNode->next = result;
                    result = newNode;
                } else {
                    newNode->next = temp;
                    prev->next = newNode;
                }
            }
        }
    }
    return result;
}

void freePoly(struct Node* poly) {
    while (poly) {
        struct Node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, power;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter terms (coeff power) in descending order of powers: ");
    for (int i = 0; i < n; i++) {
        scanf("%dx^%d", &coeff, &power);
        appendTerm(&poly1, coeff, power);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter terms (coeff power) in descending order of powers:");
    for (int i = 0; i < n; i++) {
        scanf("%dx^%d", &coeff, &power);
        appendTerm(&poly2, coeff, power);
    }

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    result = addPoly(poly1, poly2);
    printf("Addition: ");
    displayPoly(result);
    freePoly(result);

    result = subtractPoly(poly1, poly2);
    printf("Subtraction: ");
    displayPoly(result);
    freePoly(result);

    result = multiplyPoly(poly1, poly2);
    printf("Multiplication: ");
    displayPoly(result);
    freePoly(result);

    freePoly(poly1);
    freePoly(poly2);

    return 0;
}

