#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* enqueue(struct node* f, struct node* r, int value) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("No more memory can be allocated!\n");
        return f;
    }
    n->value = value;
    n->next = NULL;

    if (f == NULL) {
        f = r = n;
    } else {
        r->next = n;
        r = n;
    }
    return f;
}

struct node* dequeue(struct node* f, struct node** r) {
    if (f == NULL) {
        printf("Queue Underflow!\n");
        return f;
    } else {
        struct node* ptr = f;
        int value = ptr->value;
        f = ptr->next;
        if (f == NULL) {
            *r = NULL;  // Set rear to NULL when the queue is empty
        }
        free(ptr);
    }
    return f;
}

void traverse(struct node* f) {
    if (f == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        while (f != NULL) {
            printf("%d ", f->value);
            f = f->next;
        }
        printf("\n");
    }
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    int choice, value;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                front = enqueue(front, rear, value);
                if (rear == NULL) {
                    rear = front; // Set rear if queue is empty
                }
                break;
            case 2:
                front = dequeue(front, &rear);
                break;
            case 3:
                traverse(front);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
