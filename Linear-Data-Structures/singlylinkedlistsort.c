#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void display(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Node* head) {
    int swapped, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(&(ptr1->data), &(ptr1->next->data));
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;

    insertFront(&head, 4);
    insertFront(&head, 2);
    insertFront(&head, 5);
    insertFront(&head, 1);
    insertFront(&head, 3);

    printf("Original Linked List: ");
    display(head);
    printf("\n");

    sort(head);

    printf("Sorted Linked List: ");
    display(head);

    return 0;
}
