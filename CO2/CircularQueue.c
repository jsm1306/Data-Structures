#include <stdio.h>

int cq[5];
int size = 5;
int front = -1, rear = -1;

int isempty() {
    return (front == -1 && rear == -1) || (front == rear + 1);
}

int isfull() {
    return (front == 0 && rear == size - 1) || (rear == front - 1);
}

void enqueue(int val) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    cq[rear] = val;
}

int dequeue() {
    int val = cq[front];
    front = (front + 1) % size;
    return val;
}

void display() {
    int i;
    for (i = front; i != (rear + 1) % size; i = (i + 1) % size) {
        printf("%d ", cq[i]);
    }
    printf("\n");
}

void createQueue() {
    int i;
    printf("Enter %d values to initialize the queue:\n", size);
    for (i = 0; i < size; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &cq[i]);
        rear = i;
    }
    front = 0;
}

int main() {
    char choice;
    createQueue();
    do {
        int op, val;
        printf("1. Enqueue\n2. Dequeue\n3. Display\nEnter your option: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                if (isfull())
                    printf("Queue is full\n");
                else {
                    printf("Enter the value: ");
                    scanf("%d", &val);
                    enqueue(val);
                }
                break;
            case 2:
                if (isempty())
                    printf("Queue is empty\n");
                else {
                    val = dequeue();
                    printf("Deleted data is %d\n", val);
                }
                break;
            case 3:
                if (isempty())
                    printf("Queue is empty\n");
                else
                    display();
                break;
            default:
                printf("Invalid option\n");
        }
        printf("Enter S/s to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'S' || choice == 's');
    return 0;
}

