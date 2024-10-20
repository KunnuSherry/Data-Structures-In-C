//Program to insert at the end, delete a particular element, traversing and searching a particular element in a linear linked list.


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Insert at end
struct node* insert(struct node* head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode; // New head if the list is empty
    }

    struct node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newnode; // Link the last node to the new node
    return head; // Return the unchanged head pointer
}

// Delete a particular data
struct node* delete(struct node* head, int data) {
    struct node* ptr = head;
    struct node* ptr2 = NULL;

    if (head == NULL) {
        printf("No Data in the Linked List!\n");
        return head;
    }

    // Handle case where head needs to be deleted
    if (ptr->data == data) {
        head = ptr->next; 
        free(ptr);
        return head; // Return new head
    }

    while (ptr->next != NULL && ptr->next->data != data) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        printf("Data not found in the list!\n");
        return head;
    }

    ptr2 = ptr->next;
    ptr->next = ptr->next->next;
    free(ptr2);
    return head; // Return the unchanged head pointer
}

// For traversing
void traverse(struct node* head) {
    struct node* ptr = head;
    if (ptr == NULL) {
        printf("No Element in Linked List!\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Searching
void search(struct node* head, int element) {
    struct node* ptr = head;
    int i = 0; // Start index from 0

    if (ptr == NULL) {
        printf("No element in the Linked List\n");
        return;
    }

    while (ptr != NULL) {
        if (ptr->data == element) {
            printf("The Element %d is found at index %d\n", element, i);
            return; // Exit the function if found
        }
        ptr = ptr->next;
        i++;
    }
    printf("The Element %d is not found in the list\n", element);
}

int main() {
    struct node* head = NULL;

    while (1) {
        int choice, data;
        printf("Enter Choice: 1.Insert 2. Delete 3.Traverse 4.Search 5.Quit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insert(head, data); // Update head
                break;
            case 2: // Delete
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = delete(head, data); // Update head
                break;
            case 3: // Traverse
                traverse(head);
                break;
            case 4: // Search
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 5: // Quit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
