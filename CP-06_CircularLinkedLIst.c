// Create circular linked list having information about a college and perform Insertion at front perform 
// Deletion at end.
#include <stdio.h>
#include <stdlib.h>

struct cll {
    int collegeID;
    int numSt;
    char grade;
    struct cll *next;
};

struct cll* show(struct cll* top) {
    if (top == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct cll* ptr = top;
    printf("College ID: %d\n", ptr->collegeID);
    printf("Number of Students: %d\n", ptr->numSt);
    printf("College Grade: %c\n", ptr->grade);
    ptr = ptr->next;
    while (ptr != top) {
        printf("College ID: %d\n", ptr->collegeID);
        printf("Number of Students: %d\n", ptr->numSt);
        printf("College Grade: %c\n", ptr->grade);
        ptr = ptr->next;
    }
    printf("\n");
    return top;
}



struct cll* insertAtBeginning(struct cll* top, int collegeID, int numSt, char grade) {
    struct cll* ptr = (struct cll*)malloc(sizeof(struct cll));
    ptr->collegeID = collegeID;
    ptr->numSt = numSt;
    ptr->grade = grade;
    if (top == NULL) {
        top = ptr;
        top->next = top;
    } else {
        ptr->next = top;
        struct cll* temp = top;
        while (temp->next != top) {
            temp = temp->next;
        }
        temp->next = ptr;
        top = ptr;
    }
    return top;
}


struct cll* deleteAtEnd(struct cll* top) {
    if (top == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (top->next == NULL) {
        free(top);
        return NULL;
    }
    struct cll* ptr = top;
    while (ptr->next->next!= top) {
        ptr = ptr->next;
    }
    ptr->next->next = NULL;
    ptr->next =top;
    return top;
}



int main() {
    struct cll* top = NULL;
    int choice, collegeID, numSt;
    char grade;

    while (1) {
        printf("1. Insert at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Show List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter college ID to insert: ");
                scanf("%d", &collegeID);
                printf("Enter Number of college Students to insert: ");
                scanf("%d", &numSt);
                printf("Enter college grade to insert: ");
                scanf("%s", &grade);
                top = insertAtBeginning(top, collegeID, numSt, grade);
                break;
            case 2:
                top = deleteAtEnd(top);
                break;
            case 3:
                top = show(top);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
