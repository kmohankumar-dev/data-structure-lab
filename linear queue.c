
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert();
void dequeue();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void insert()
{
    int add_item;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
        {

            front = 0;
        }
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);

        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        printf("Deleted Element is: %d\n", queue_array[front]);
        front = front + 1;

        /* Reset queue indexes if it becomes empty to optimize space usage */
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}
