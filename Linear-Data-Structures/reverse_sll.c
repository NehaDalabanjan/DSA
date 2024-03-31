//sll-reverse.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void display(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev, *cur, *nextNode;
    prev = NULL;
    cur = head;
    while (cur != NULL) {
        nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    return prev;
}

int main() {
    struct Node* head = NULL;

    for (int i = 5; i > 0; i--)
        insertFront(&head, i);

    printf("Original Linked List: ");
    display(head);

    head = reverseList(head);

    printf("Reversed Linked List: ");
    display(head);

    return 0;
}
