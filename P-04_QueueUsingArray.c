#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int* arr;
};

int isFull(struct queue* q) {
    if (q->rear == q->size - 1 && q->rear != q->front) {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue* q) {
    if (q->rear == q->front) {
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
    }
    else {
        q->rear = q->rear + 1;
        q->arr[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue(struct queue* q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
    }
    else {
        q->front = q->front + 1;
        a = q->arr[q->front];
        printf("Dequeued: %d\n", a);
    }
    return a;
}

void traverse(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements: ");
        for (int i = q->front + 1; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    q.rear = -1;
    q.front = -1;
    q.size = 10;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int choice, value;
    while (1) {
        printf("\nChoose an option: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverse(&q);
                break;
            case 4:
                printf("Exiting...\n");
                free(q.arr);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
