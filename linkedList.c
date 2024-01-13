#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node in ascending order
void insertSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete the first node of the linked list
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node before a specified position
void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1) {
        printf("Invalid position to delete before.\n");
        return;
    }
    if (position == 2) {
        deleteFront(head);
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < position - 2 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position to delete before.\n");
        return;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to delete a node after a specified position
void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Invalid position to delete after.\n");
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Invalid position to delete after.\n");
        return;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node in ascending order\n");
        printf("4. Delete the first node\n");
        printf("5. Delete a node before a specified position\n");
        printf("6. Delete a node after a specified position\n");
        printf("7. Display the linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert in ascending order: ");
                scanf("%d", &data);
                insertSorted(&head, data);
                break;
            case 4:
                deleteFront(&head);
                break;
            case 5:
                printf("Enter the position before which to delete a node: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position);
                break;
            case 6:
                printf("Enter the position after which to delete a node: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
