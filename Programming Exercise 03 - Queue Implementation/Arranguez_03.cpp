#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Structure for Customer Information
struct customer {
    char sname[25];
    float data;
};

// Queue structure
struct node { 
    struct customer data;
    struct node *next;
}*front=NULL, *rear=NULL;

// Function prototypes
void enqueue(struct customer data);
void dequeue();
void Front();
bool empty();
int menu(int choice);
void free_queue();
void choices(int choice, struct customer *data);

// Function that carries out the enqueue operation
void enqueue(struct customer data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));      // Allocates memory for the new node.
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL) {             // If the front is NULL, the new node will be the front.
        front = newNode;
    } else {                        // Otherwise, the new node will be the rear.
        rear->next = newNode;
    }
    rear = newNode;
}

// Function that carries out the dequeue operation
void dequeue() {
    if(front == NULL) {             // If the front is NULL, displays a message that the queue is empty and there are no orders to serve.
        printf("The QUEUE is EMPTY. No order to serve.\n\n");
    } else {                      // Otherwise, the front will be the next node.
        struct node *temp = front;
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

// Function that displays the front item of the queue
void Front() {
    if(front == NULL) {            // If the front is NULL, displays a message that the queue is empty and there are no orders to serve.
        printf("\nThe QUEUE is EMPTY. No order to serve.\n\n");
    } else {                    // Otherwise, displays the next order to be served.
        printf("\nNext order: For [%s] with total amount payable of PhP [%.4f].\n\n", front->data.sname, front->data.data);
    }
}

// Function that returns true if queue Q is empty, otherwise, returns false
bool empty() {
    if(front == NULL) {         // If the front is NULL, returns true.
        return true;
    } else {
        return false;           // Otherwise, returns false.
    }
}

// Function that shows the menu and returns the choice of the user
int menu(int choice) {
    printf("ESENAR Membership Shopping: Counter 1\n\n");
    printf("Welcome to ESENAR Membership Shopping!\n");
    printf("Please select an option:\n");
    printf("[1] Fall in Line\n");
    printf("[2] Serve Customer\n");
    printf("[3] Next Customer\n");
    printf("[4] Closing Time\n");
    printf("[0] Exit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function that frees the queue
void free_queue() {
    struct node *temp = front;      // Temporarily stores the front.
    while(temp != NULL) {           // While loop that frees the queue.
        front = front->next;
        free(temp);
        temp = front;
    }
    front = NULL;               // Sets the front to NULL.
    rear = NULL;                // Sets the rear to NULL.
}

// Function that carries out the user's choice
void choices(int choice, struct customer *data) {
    switch (choice)
    {
        case 1:             // If the user chooses 1, the program will ask for the customer's surname and total amount payable.
            printf("\nEnter customer surname: ");
            scanf("%s", data->sname);           // Stores the customer's surname.
            printf("Enter total amount payable: ");
            scanf("%f", &data->data);           // Stores the total amount payable.
            enqueue(*data);
            printf("-------------------------------------------------------------------------\n\n");
            break;
        case 2:         // If the user chooses 2, the program will serve the customer.
            if (empty()) {          // If the queue is empty, the program will display a message that there are no orders to serve.
                printf("The QUEUE is EMPTY. No order to serve.\n\n");
            } else {                // Otherwise, the program will display the customer's surname and total amount payable.
                printf("Serving order: For [%s] with total amount payable of PhP [%.4f].\n\n", front->data.sname, front->data.data);
                dequeue();
            }
				printf("-------------------------------------------------------------------------\n\n");
            break;
        case 3:         // If the user chooses 3, the program will display the next customer to be served.
            Front();        // Calls the front function.
            printf("-------------------------------------------------------------------------\n\n");
            break;
        case 4:
            system("cls");          // Clears the screen.
            if (empty()) {          // If the queue is empty, the program will display a message that there are no more customers to serve.
                printf("\n--[The QUEUE is EMPTY. No customer/s to serve!]--\n\n");
                break;
            } else {
            while (!empty()) {      // While loop that displays all customers and serves them.
                printf("Serving order: For [%s] with total amount payable of PhP [%.4f].\n", front->data.sname, front->data.data);
                sleep(1);           // Delays the program for 1 second.
                dequeue();          
            }
            printf("\n[ALL CUSTOMERS HAS BEEN SERVED!]\n\n");            // Displays a message that all customers have been served.
            free_queue();           // Frees the queue.
            }
            printf("-------------------------------------------------------------------------\n\n");
            break;
        default:        // If the user chooses an invalid choice, the program will display a message that the choice is invalid.
            printf("\nInvalid choice. Please try again.\n");
			printf("-------------------------------------------------------------------------\n\n");
            break;
    }
}

// Main function
int main() {
    int choice;
    struct customer data;       // Structure for customer information.
    choice = menu(choice);      // Displays the menu.
    while (choice!= 0) {        // While loop that executes the user's choice.
        if(choice == 1) {
            choices(choice, &data);
        } else {
            choices(choice, NULL);
        }
        choice = menu(choice);
    }
    return 0;
}