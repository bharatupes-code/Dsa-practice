#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty()
{
    return (front == -1);
}

// Check full
int isFull()
{
    return (front == 0 && rear == MAX - 1);
}

// Insert at front
void push_front(int value)
{
    if (isFull())
    {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        printf("No space at front\n");
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

// Insert at rear
void push_back(int value)
{
    if (isFull())
    {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        printf("No space at rear\n");
        return;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void pop_front()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// Delete from rear
void pop_back()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

// Get front element
void getFront()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Front: %d\n", deque[front]);
    }
}

// Get rear element
void getBack()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Back: %d\n", deque[rear]);
    }
}

// Display deque
void display()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1.push_front 2.push_back 3.pop_front 4.pop_back\n");
        printf("5.front 6.back 7.display 8.exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push_front(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            push_back(value);
            break;

        case 3:
            pop_front();
            break;

        case 4:
            pop_back();
            break;

        case 5:
            getFront();
            break;

        case 6:
            getBack();
            break;

        case 7:
            display();
            break;

        case 8:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}