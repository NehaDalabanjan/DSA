#include <stdio.h>
#include <stdlib.h>

typedef struct letter {
    char name[50];
    int hno;
    char area[50];
    int mob;
    struct letter *next;
} NODE;

NODE *getnode()
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    if (newnode == 0) {
        printf("memory not allocated");
        exit(0);
    }
    newnode->next = newnode;
    return newnode;
}

NODE *read()
{
    NODE *temp;
    temp = getnode();
    printf("enter name: ");
    scanf("%s", temp->name);
    printf("enter house no: ");
    scanf("%d", &temp->hno);
    printf("enter area: ");
    scanf("%s", temp->area);
    printf("enter mobile no: ");
    scanf("%d", &temp->mob);
    return temp;
}

NODE *ins_end(NODE *head)
{
    NODE *newnode, *cur;
    cur = head;
    newnode = read();
    if (head == NULL) {
        newnode->next = newnode;
        return newnode;
    }
    else {
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = newnode;
        newnode->next = head;
        return head;
    }
}

NODE *ins_front(NODE *head)
{
    NODE *newnode, *cur;
    cur = head;
    newnode = read();
    if (head == NULL) {
        return newnode;
    }
    while (cur->next != head) {
        cur = cur->next;
    }
    cur->next = newnode;
    newnode->next = head;
    head = newnode;
    return head;
}

NODE *del_front(NODE *head)
{
    NODE *temp, *cur = head;
    if (head == NULL) {
        printf("list is empty");
        exit(0);
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    while (cur->next != head) {
        cur = cur->next;
    }
    temp = head;
    head = head->next;
    cur->next = head;
    free(temp);
    return head;
}

NODE *del_end(NODE *head)
{
    NODE *temp, *cur = head;
    if (head == NULL) {
        printf("list is empty");
        exit(0);
    }
    while (cur->next != head) {
        cur = cur->next;
    }
    temp = cur->next;
    cur->next = head;
    free(temp);
    return head;
}

void display(NODE *head)
{
    NODE *temp = head;
    if (head != NULL) {
        do {
            printf("%s : %d : %s : %d\n", temp->name, temp->hno, temp->area, temp->mob);
            temp = temp->next;
        } while (temp != head);
    }
}

void write_file(NODE *head)
{
    FILE *fp = fopen("resident-details.txt", "w");
    NODE *temp = head;
    if (head != NULL) {
        do {
            fprintf(fp, "%s %d %s %d\n", temp->name, temp->hno, temp->area, temp->mob);
            temp = temp->next;
        } while (temp != head);
    }
    fclose(fp);
}

int main()
{
    NODE *head = NULL;
    int choice;
    while (1) {
        printf("\n1. Insert at end\n2. Insert at front\n3. Delete front\n4. Delete end\n5. Display details\n6. Write to file\n7. Exit\n");
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
                head = del_front(head);
                break;
            case 4:
                head = del_end(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                write_file(head);
                break;
            case 7:
                printf("thank you");
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
        }
    }
}
