#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int list1;
    struct Node *next;
};

// Program Description. This includes the name of the program, the purpose of the program, and the name of the authors.
// Note that the program is designed only to take integers as input.
void Description()
{
    printf("-------------------------------------------------------------------------------------------\n");
    printf("\t   This program is a simple implementation of a linked list.\n");
    printf("\tIt allows the user to add, delete, and display INTEGERS in the list.\n");
    printf("\t\tThe user can also delete the entire list.\n\n");
    printf("     NOTE: The list is initially empty. Which means that when adding the first\n");
    printf("      item, the head pointer will be initialized to point to the first item.\n");
    printf("   This means that the program can't carry out add item operations for the first element.\n");
    printf("\n\t\tCreated by: Francis Reid Arranguez & Errol James Minguez\n");
    printf("-------------------------------------------------------------------------------------------\n\n");
}

// Function that executes the Add Item operation. This function allows the user to add an item to the list.
void addItem(struct Node **head)
{
    int item, choice, position, count = 1;      // Function Declarations
    system("cls");      // Function that clears the screen to make the program look more organized.
    printf("Please enter the item to be added: ");      // Asks the user to input the item to be added. Stores the input in the variable 'item'.
    scanf("%d", &item);

    // Function that allocates memory for a new node and assigns the value of the item to the list1 field of the new node.
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->list1 = item;
    newNode->next = NULL;

    // Function that checks if the list is empty. If the list is empty, the head pointer will be initialized to point to the new node.
    if (*head == NULL)
    {
        *head = newNode;
    } else {
        // Function that asks the user where to add the item. The user can choose to add the item at the start of the list, at the end of the list, or at a specific position.
        printf("\nWhere to add the item?\n");
        printf("[1] Start of the list\n");
        printf("[2] End of the list\n");
        printf("[3] Specific position\n");
        printf("[0] Cancel\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Switch statement that executes the user's choice.
        switch (choice)
        {
        case 1:     // If the user chooses to add the item at the start of the list, the new node will be added at the start of the list.
            newNode->next = *head;
            *head = newNode;
            printf("\n--[Item added at the start of the list]--\n\n");
            break;
        case 2:     // If the user chooses to add the item at the end of the list, the new node will be added at the end of the list.
        {
            struct Node *last = *head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newNode;
            printf("\n--[Item added at the end of the list]--\n\n");
        }
        break;
        case 3:     // If the user chooses to add the item at a specific position, the user will be asked to input the position where the item will be added.
            printf("Enter the position to add the item: ");
            scanf("%d", &position);

            if (position <= 0)         // If the position is less than or equal to 0, the position is invalid.
            {
                printf("Invalid position!\n");
            } else {             // If the position is valid, the new node will be added at the specified position.
                struct Node *current = *head;
                struct Node *prev = NULL;

                // While loop that traverses the list to find the position where the new node will be added.
                while (current != NULL && count < position)
                {
                    prev = current;
                    current = current->next;
                    count++;
                }

                // If statement that checks if the position is valid. If the position is valid, the new node will be added at the specified position.
                if (count == position)
                {
                    newNode->next = current;

                    if (prev != NULL)
                    {
                        prev->next = newNode;
                    }
                    else
                    {
                        *head = newNode;
                    }

                    printf("\n--[Item added at position %d]--\n\n", position);
                }
                else
                {
                    printf("\n[Invalid position]\n\n");
                }
            }
            break;
        case 0:     // If the user chooses to cancel the operation, the program will display a message that the operation has been cancelled.
            printf("\n--[Operation cancelled]--\n\n");
            break;
        default:
            printf("\n--[Invalid Choice]--\n\n");
        }
    }
}

// Function that deletes the entire list. This function deletes all the nodes in the list.
void deleteList(struct Node **head)
{
    system("cls");
    printf("Deleting List...\n\n");
    // Function that traverses the list and deletes all the nodes in the list.
    struct Node *temp = *head;
    struct Node *next;

    // While loop that traverses the list and deletes all the nodes in the list.
    while (temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL; // Set the head pointer to NULL after deleting all Nodes
    printf("\n[Item List has been deleted.]\n");
}

// Function that deletes an item from the list.
void deleteItem(struct Node **head)
{
    system("cls");
    // Function Declarations and Input
    int n, i, element;
    printf("\nHow many item(s) do you want to delete?");
    printf("\nEnter number: ");
    scanf("%d", &n);

    // For loop that executes the delete item operation n times.
    for (i = 0; i < n; i++)
    {
        int count = 0;
        printf("\nEnter item to be deleted: ");
        scanf("%d", &element);

        struct Node *temp = *head;
        struct Node *previous = NULL;

        while (temp != NULL)
        {
            count++;
            // if the element is found
            if (temp->list1 == element)
            {
                if (previous != NULL)
                {
                    previous->next = temp->next;
                }
                else
                {
                    *head = temp->next;
                }
                free(temp);
                printf("\n[The element %d which is at position %d, has been deleted.]", element, count);
                break;
            }
            previous = temp;
            temp = temp->next;
        }
        if (temp == NULL)       // If the element is not found in the list, displays a message that the element is not found in the list.
        {
            printf("[Item %d not found in the list.]\n", element);
        }
    }
}

// This function displays all the items in the list.
void displayList(struct Node *head)
{
    system("cls");
    printf("Elements: ");
    struct Node *temp = head;

    // If the list is empty, displays a message that there are no items listed.
    if (temp == NULL)
    {
        printf("\n--[There are no items listed]--\n");
    } else {        // If the list is not empty, displays all the items in the list.
        printf("\nHEAD -> ");
        while (temp != NULL)            // While loop that traverses the list and displays all the items in the list.
        {
            printf("%d -> ", temp->list1);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

int main()
{
    Description();
    int choice;
    struct Node *head = NULL;    // Function that initializes the head pointer to NULL.

    // Do-While loop that displays the menu and executes the user's choice.
    do
    {
        printf("\nList Menu\n\n");
        printf("[1] Add Item\n");
        printf("[2] Delete Item\n");
        printf("[3] Display List\n");
        printf("[4] Delete List\n");
        printf("[0] Exit Program\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Exiting program...\n");
            break;
        case 1:
            addItem(&head);
            break;
        case 2:
            deleteItem(&head);
            break;
        case 3:
            displayList(head);
            break;
        case 4:
            deleteList(&head);
            break;
        default:
            printf("\n--[Invalid Choice]--\n\n");
        }
    } while (choice != 0);

    free(head);     // Function that frees the memory allocated for the head pointer.
}
