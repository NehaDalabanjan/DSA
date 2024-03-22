#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int phno;
    char name[100];
    char address[100];
    struct node *next;
} node;

node *getnode() {
    return (node *)malloc(sizeof(node));
}

node *read() {
    node *temp = getnode();
    printf("Enter the phone no: ");
    scanf("%d", &(temp->phno));
    printf("Enter the name : ");
    scanf("%s", temp->name);
    printf("Enter the address: ");
    scanf("%s", temp->address);
    return temp;
}

node *insert(node *head) {
    node *newnode = read();
    newnode->next = NULL;
    if (head == NULL) {
        return newnode;
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;
    return head;
}

node *move_to_next(node *head) {
    if (head == NULL || head->next == NULL) {
        printf("No or only one contact present. Cannot move to next.\n");
        return head;
    }
    return head->next;
}

node *Add_specific_contact(node *head) {
    node *newnode = read();
    newnode->next = NULL;
    if (head == NULL) {
        return newnode;
    }

    char name[100];
    printf("Enter contact after which new contact should be added: ");
    scanf("%s", name);

    node *prev = NULL;
    node *cur = head;
    while (cur != NULL && strcmp(cur->name, name) != 0) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Contact with the given namenot found.\n");
        free(newnode);
        return head;
    }

    newnode->next = cur->next;
    cur->next = newnode;

    return head;
}

node *delete_position(node *head) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return NULL;
    }

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    node *temp = head;
    node *prev = NULL;
    int count = 1;
    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position. Deletion not possible.\n");
        return head;
    }

    if (prev != NULL)
        prev->next = temp->next;
    else
        head = temp->next;

    free(temp);
    return head;
}

void display(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        printf("%d : %s : %s\n", temp->phno, temp->name, temp->address);
        temp = temp->next;
    }
}

void write_to_file(node *head, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d %s %s\n", temp->phno, temp->name, temp->address);
        temp = temp->next;
    }

    fclose(fp);
}

int main() {
    node *head = NULL;
    int choice;
    while (1) {
        printf("1-Move tonext\n2-Insert at a position\n3-Delete at a position\n4-Add contact\n5-Display Contacts\n6-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head = move_to_next(head);
            break;
        case 2:
            head = Add_specific_contact(head);
            break;
        case 3:
            head = delete_position(head);
            break;
        case 4:
            head = insert(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            // Save to file
            write_to_file(head, "phonebook.txt");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
