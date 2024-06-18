#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10          // Maximum size of the stack

// Implementation of Linked List
struct Node {
    char data[100];
    struct Node* next;
};

// Implementation of Stack
struct Stack {
    int top;
    struct Node* next;
};

// Function that displays the description of the program
void description(){
    printf("---------------------------------------------------------------\n");
    printf("This program emulates a kitchenware washing machine.\n");
    printf("The user can add kitchenware, wash kitchenware, check\nthe top kitchenware, and wash all kitchenware.\n");
    printf("The maximum size of the stack is 10.\n\n");
    printf("Program created: Francis Reid Arranguez & Errol James Minguez\n");
    printf("---------------------------------------------------------------\n\n");
}

// Function that displays the menu
int menu(int choice) {
    printf("[1] Add kitchenware\n[2] Wash Kitchenware\n[3] Check Top Kitchenware\n[4] Wash all\n[0] Exit\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function that pushes the kitchenware to the stack
void push(struct Stack* stack, char data[100]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));       // Allocates memory for the new node.
    if (newNode == NULL) {      // If the new node is NULL, displays a message that the stack is full and cannot add kitchenware.
        printf("STACK is FULL. Cannot add kitchenware.\n");
        return;
    }
    if (stack->top == MAX - 1) {                // If the stack is full, displays a message that the stack is full and cannot add kitchenware.
        printf("STACK is FULL. Cannot add kitchenware\n");
        return;
    }
    strcpy(newNode->data, data);                // Copies the data to the new node.
    newNode->next = stack->next;
    stack->next = newNode;
    stack->top++;
    printf("\n");
}

// Function that pops the kitchenware from the stack
void pop(struct Stack* stack) {
    if (stack->top == -1) {             // If the stack is empty, displays a message that there are no more kitchenware to wash.
        printf("STACK is EMPTY. No more kitchenware to wash.\n");
        return;
    }
    struct Node* temp = stack->next;            // Temporarily stores the next node.
    stack->next = stack->next->next;            //  Points the next node to the next node.
    stack->top--;                               // Decrements the top.
    free(temp);
    printf("\n");
}

// Function that checks if the stack is full
int isFull(struct Stack* stack) {
    if (stack->top == MAX - 1) {            // If the top is equal to the maximum size of the stack, returns 1.
        return 1;
    } else {
        return 0;                           // Otherwise, returns 0.
    }
}

// Function that checks if the stack is empty
int isEmpty(struct Stack* stack) {
    if (stack->top == -1) {             // If the value of top is still -1, returns 1.
        return 1;
    } else {
        return 0;                       // Otherwise, returns 0.
    }
}

// Function that returns the top of the stack
char* top(struct Stack* stack) {     
    if (isEmpty(stack)) {               // If the stack is empty, returns an empty string.
        return "";
    } else {
        return stack->next->data;       // Otherwise, returns the data of the next node.
    }
}

// Function that carry out the operation of each cases
void choices(int choice, struct Stack* stack) {
    char data[100];
    int a;
    switch (choice)
    {
        case 1:             // If the user chooses to add kitchenware, the program will prompt the user to input the kitchenware.
        	a = isFull(stack);
        	if (a == 0){                        // If the stack is not full, the kitchenware will be added to the stack.
            printf("\nEnter kitchenware: ");
            scanf("%s", data);
            push(stack, data);
            printf("[%s] is added.\n\n", data);
			} else {                                                        // If the stack is full, the program will display a 
				printf("The STACK is FULL. Cannot add kitchenware.\n\n");   // message that the stack is full and cannot add kitchenware.
			}
            break;
        case 2:             // If the user chooses to wash kitchenware, the program will display the kitchenware that is being washed.
            if (stack->top != -1) {         // If the stack is not empty, the program will display the kitchenware that is being washed.
                printf("\n[%s] is being washed.\n", top(stack));
                pop(stack);          // The kitchenware will be removed from the stack.
            } else {                       // If the stack is empty, the program will display a message that there are no more kitchenware to wash.
                printf("\nThe STACK is EMPTY. No kitchenware to wash.\n\n");     
            }
            break;

        case 3:     // If the user chooses to check the top kitchenware, the program will display the kitchenware that is next to be washed.
            if (stack->top != -1) {         // If the stack is not empty, the program will display the kitchenware that is next to be washed.
                printf("\n[%s] is next to be washed.\n\n", top(stack));
            } else {        // If the stack is empty, the program will display a message that there are no more kitchenware to wash.
                printf("\nThe STACK is EMPTY. No kitchenware to wash.\n\n");
            }
            break;

        case 4:     // If the user chooses to wash all kitchenware, the program will display all kitchenware that is being washed.
        	system("cls");          // Clears the screen.
            while (stack->top != -1) {      // While loop that displays all kitchenware that is being washed.
                printf("\n[%s] is being washed.", top(stack));
                pop(stack);             // The kitchenware will be removed from the stack.
            }
            printf("\n--[All kitchenwares has been washed!]--\n\n");            // Displays a message that all kitchenware has been washed.
            break;

        case 0:         // If the user chooses to exit the program, the program will display a message that the program has been terminated.
            break;

        default:            // If the user chooses an invalid choice, the program will display a message that the choice is invalid.
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}

int main() {
    description();
    int choice;
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));      // Allocates memory for the stack.
    stack->top = -1;                // Initializes the top of the stack to -1.
    stack->next = NULL;             // Initializes the next of the stack to NULL.
    choice = menu(choice);          // Displays the menu.
    while (choice != 0) {           // While loop that executes the user's choice.
        choices(choice, stack);
        choice = menu(choice);
    }
    free(stack);                    // Frees the memory allocated for the stack.
    return 0;
}
