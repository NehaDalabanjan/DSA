//sll-1.c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int roll;
    int age;
    char name[50];
    struct node *next;
} NODE;

NODE *getnode()
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (!newnode) {
        printf("Memory error\n");
        exit(0);
    }
    return newnode;
}

NODE *read()
{
    NODE *temp;
    temp = getnode();
    printf("enter roll: ");
    scanf("%d", &(temp->roll));
    printf("enter age: ");
    scanf("%d", &(temp->age));
    printf("enter name: ");
    scanf("%s", (temp->name));
    return temp;
}

NODE *ins_end(NODE *head)
{
    NODE *newnode, *cur;
    newnode = read();
    newnode->next = NULL;
    if (head == NULL) {
        return newnode;
    }
    cur = head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newnode;
    return head;
}

NODE *ins_front(NODE *head)
{
    NODE *newnode;
    newnode = read();
    newnode->next = head;
    head = newnode;
    return head;
}

NODE *ins_pos(NODE *head)
{
    NODE *newnode, *cur;
    int pos, i=1, count=1;
    printf("enter position: ");
    scanf("%d", &pos);
    newnode = read();
    newnode->next = NULL;
    cur = head;
    while (i<pos) {
        cur = cur->next;
        i++;
    }
    newnode->next = cur->next;
    cur->next = newnode;return head;
}

void search(NODE *head)
{
    int rno;
    printf("enter roll no to be searched: ");
    scanf("%d", &rno);
    NODE *temp = head;
    while (temp != NULL) {
        if (temp->roll == rno)
            printf("Roll: %d, Age: %d, Name: %s\n", temp->roll, temp->age, temp->name);
        temp = temp->next;
    }
}

NODE *del_end(NODE *head)
{
    NODE *temp = head;
    if (temp->next != NULL){
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

NODE *del_front(NODE *head)
{
    NODE *temp = head;
    if (temp->next != NULL){
        head = head->next;
        free(temp);
    }
    return head;
}

void display(NODE *head)
{
    NODE *temp = head;
    while (temp != NULL) {
        printf("Roll: %d | Age: %d | Name: %s\n", temp->roll, temp->age, temp->name);
        temp = temp->next;
    }
}

void write_file(NODE *head, FILE *fp)
{
    NODE *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d %d %s\n", temp->roll, temp->age, temp->name);
        temp = temp->next;
    }
}

int main()
{
    NODE *head = NULL;
    int choice;
    FILE *fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("Unable to open file\n");
        exit(0);
    }
    while (1) {
        printf("\n1. Insert at end\n2. Insert at front\n3. Insert at position\n4. Delete front\n5. Delete end\n6. Display details\n7. Search element\n8. Write to file\n9. Exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = ins_end(head);
                break;
            case 2:
                head = ins_front(head);
                break;
            case 3:
                head = ins_pos(head);
                break;
            case 4:
                head = del_front(head);
                break;
            case 5:
                head = del_end(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                search(head);
                break;
            case 8:
                write_file(head, fp);
                break;
            case 9:
                printf("thank you");
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
            }
    }
}
