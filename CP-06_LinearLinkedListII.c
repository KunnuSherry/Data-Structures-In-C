//Program to perform Linked List operations such as insertion in between and rest


#include <stdio.h>
#include <stdlib.h>

struct node {
    int rollno;
    struct node* next;
};

// Insert in between
struct node* insert(struct node* head, int data, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    int i=1;
    struct node* ptr = head;
    struct node* ptr2 = NULL;
    newnode->rollno = data;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode; // New head if the list is empty
    }
    while (i!=position-1) {
        ptr = ptr->next;
        i++;
    }
    ptr2 = ptr->next;
    ptr->next = newnode; // Link the last node to the new node
    newnode->next = ptr2;
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
    if (ptr->rollno == data) {
        head = ptr->next; 
        free(ptr);
        return head; // Return new head
    }

    while (ptr->next != NULL && ptr->next->rollno != data) {
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
        printf("%d ", ptr->rollno);
        ptr = ptr->next;
    }
    printf("\n");
}

//Reversing the List
void reverse(struct node* head) {
    if (head == NULL) {
        return; // Base case: if the list is empty, return
    }
    reverse(head->next); // Recursive call
    printf("%d ", head->rollno); // Print data after returning from recursion
}

int main() {
    struct node* head = NULL;

    while (1) {
        int choice, data, position;
        printf("\nEnter Choice: 1.Insert 2. Delete 3.Traverse 4.Reverse 5.Quit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter rollno to insert: ");
                scanf("%d", &data);
                printf("Enter Position to insert: ");
                scanf("%d", &position);
                head = insert(head, data, position); // Update head
                break;
            case 2: // Delete
                printf("Enter rollno to delete: ");
                scanf("%d", &data);
                head = delete(head, data); // Update head
                break;
            case 3: // Traverse
                traverse(head);
                break;
            case 4: // Reverse
                reverse(head);
                break;
            case 5: // Quit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
