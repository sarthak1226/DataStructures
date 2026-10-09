#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextNode;
    struct node *prevNode;
};

struct node *front = NULL;
struct node *head = NULL;

int is_Empty()
{
    return front == NULL;
}

void enque(int val)
{
    
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    if (head == NULL)
    {
        front = newNode;
        head = newNode;
    }
    else
    {
        newNode->prevNode = head;
        head->nextNode = newNode;
        head = newNode;
    }
}

int pop_Beg()
{
    if (is_Empty())
    {
        printf("Already empty");
        return 0;
    }
    struct node *temp = front;
    if (front == head)
    {
        front = head = NULL;
    }
    else
    {
        front = front->nextNode;
        front->prevNode = NULL;
    }
    free(temp);
    return 1;
}

int pop()
{
    if (is_Empty())
    {
        printf("Already empty");
        return 0;
    }
    struct node *temp = head;
    if (head == front)
    {
        head = front = NULL;
    }
    else
    {

        head = head->prevNode;
        head->nextNode = NULL;
    }
    free(temp);
    return 1;
}

int pop_At_Positon(int itt)
{
    struct node *index = front;
    struct node *temp;
    struct node *temp2;

    for (int i = 0; i < itt; i++)
    {
        index = index->nextNode;
    }

    temp = index->prevNode;
    temp2 = index->nextNode;

    if (temp == NULL)
    {
        // deleting first node
        front = temp2;

        if (temp2 != NULL)
            temp2->prevNode = NULL;
        else
            head = NULL;
    }
    else
    {
        temp->nextNode = temp2;

        if (temp2 == NULL)
            head = temp;
        else
            temp2->prevNode = temp;
    }

    free(index);

    return 1;
}

void display()
{
    if (is_Empty())
    {
        printf("queue is empty");
        return;
    }
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->nextNode;
    }
    printf("\n");
}

void menu()
{
    printf("\n--- QUEUE MENU ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Pop from beging\n");
    printf("4. Is Empty\n");
    printf("5. Display\n");
    printf("6. Size\n");
    printf("7. Clear\n");
    printf("8. Exit\n");
}

int main()
{
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    display();
    pop();
    display();
    pop_Beg();

    display();

    return 0;
}