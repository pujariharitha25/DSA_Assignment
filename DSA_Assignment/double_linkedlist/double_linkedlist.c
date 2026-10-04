#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void insert(char page[])
{
    struct Node *newNode = malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
        head = current = newNode;
    else
    {
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
}

void forward()
{
    if(current != NULL && current->next != NULL)
        current = current->next;
    else
        printf("Already at the last page\n");

    printf("Current page: %s\n", current->page);
}

void backward()
{
    if(current != NULL && current->prev != NULL)
        current = current->prev;
    else
        printf("Already at the first page\n");

    printf("Current page: %s\n", current->page);
}

void displayForward()
{
    struct Node *temp = head;

    printf("First to last: ");

    while(temp != NULL)
    {
        printf("%s ", temp->page);
        temp = temp->next;
    }

    printf("\n");
}

void displayBackward()
{
    struct Node *temp = current;

    while(temp->next != NULL)
        temp = temp->next;

    printf("Last to first: ");

    while(temp != NULL)
    {
        printf("%s ", temp->page);
        temp = temp->prev;
    }

    printf("\n");
}

void deletePage(char page[])
{
    struct Node *temp = head;

    while(temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Page not found\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(current == temp)
        current = (temp->prev != NULL) ? temp->prev : head;

    free(temp);

    printf("Page deleted\n");
}

int main()
{
    insert("Google");
    insert("YouTube");
    insert("GitHub");

    displayForward();
    displayBackward();

    forward();
    backward();

    deletePage("YouTube");

    displayForward();
    displayBackward();

    return 0;
}