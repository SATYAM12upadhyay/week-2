#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create()
{
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertBeginning()
{
    int value;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd()
{
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertPosition()
{
    int value, position, i;
    struct Node *newNode, *temp;

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if(position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;

    for(i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd()
{
    struct Node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deletePosition()
{
    int position, i;
    struct Node *temp, *deleteNode;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &position);

    if(position == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    for(i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
}

void search()
{
    int value, position = 1, found = 0;
    struct Node *temp = head;

    printf("Enter value to search: ");
    scanf("%d", &value);

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            printf("Element found at position %d\n", position);
            found = 1;
            break;
        }

        temp = temp->next;
        position++;
    }

    if(found == 0)
    {
        printf("Element not found\n");
    }
}

void countNodes()
{
    int count = 0;
    struct Node *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes = %d\n", count);
}

void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("List reversed successfully\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Search\n");
        printf("10. Count Nodes\n");
        printf("11. Reverse\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insertBeginning();
                break;

            case 4:
                insertEnd();
                break;

            case 5:
                insertPosition();
                break;

            case 6:
                deleteBeginning();
                break;

            case 7:
                deleteEnd();
                break;

            case 8:
                deletePosition();
                break;

            case 9:
                search();
                break;

            case 10:
                countNodes();
                break;

            case 11:
                reverse();
                break;

            case 12:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}