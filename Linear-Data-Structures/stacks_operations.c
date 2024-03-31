stack-file.c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;d
};

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("stackInput.txt", "r"); // Open input file in read mode
    if (inputFile == NULL) {
        perror("Error opening input file");
        return -1;
    }

    outputFile = fopen("stackOutput.txt", "w"); // Open output file in write mode
    if (outputFile == NULL) {
        perror("Error opening output file");
        return -1;
    }

    struct Stack stack;
    initializeStack(&stack);

    int value;
    int key;
    int num = 1;
    while (num) {
        printf("enter 1. PUSH / 2. POP / 3. EXIT\n");
        scanf("%d", &key);
        switch(key)
        {
            case 1:
                fscanf(inputFile, "%d", &value);
                push(&stack, value);
                break;
            case 2:
                if (!isEmpty(&stack))
                    stack.top = stack.top - 1;
                fprintf(outputFile, "Stack Contents:\n");
                while (!isEmpty(&stack))
                    fprintf(outputFile, "%d\n", pop(&stack));
                break;
            case 3:
                num = !num;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Stack contents written to stackOutput.txt\n");

    return 0;
}
