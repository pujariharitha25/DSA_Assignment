#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }

    printf("\n");
}

void insertBeginning(int roll)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int roll)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->roll = roll;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void search(int roll)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        if(temp->roll == roll)
        {
            printf("Roll number %d found\n", roll);
            return;
        }

        temp = temp->next;
    }

    printf("Roll number %d not found\n", roll);
}

void deleteNode(int roll)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while(temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Roll number %d not found\n", roll);
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Roll number %d deleted\n", roll);
}

int main()
{
    int n, roll, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &roll);
        insertEnd(roll);
    }

    printf("Initial list: ");
    display();

    printf("Enter roll number to insert at beginning: ");
    scanf("%d", &roll);
    insertBeginning(roll);
    display();

    printf("Enter roll number to insert at end: ");
    scanf("%d", &roll);
    insertEnd(roll);
    display();

    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    search(roll);

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    deleteNode(roll);
    display();

    return 0;
}