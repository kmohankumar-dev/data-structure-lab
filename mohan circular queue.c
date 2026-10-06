#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert();
void delete();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Display \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
}

void insert()
{
    int add_item;


    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }

    printf("Inset the element in queue : ");
    scanf("%d", &add_item);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }

    queue_array[rear] = add_item;
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow \n");
        return;
    }

    printf("Element deleted from queue is : %d\n", queue_array[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty \n");
        return;
    }

    printf("Queue is : \n");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
    }
    else
    {

        for (i = front; i < MAX; i++)
            printf("%d ", queue_array[i]);


        for (i = 0; i <= rear; i++)
            printf("%d ", queue_array[i]);
    }
    printf("\n");
}
