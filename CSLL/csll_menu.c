#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create();

void display(Node *head);

Node *freeList(Node *head);

int main()
{
    Node *head=NULL;

    int running=1,ch;
    while(running)
    {
        printf("=====CSLL Menu=====\n");
        printf("1. Create Circular Singly Linked List\n");
        printf("2. Display List\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                head=create();
                break;
            case 2:
                display(head);
                break;
            case 14:
                running=0;
                head=freeList(head);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    head=NULL;

    return 0;
}

Node *create()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    Node *head=NULL;
    Node *temp=NULL;
    Node *newNode=NULL;

    for(int i=0;i<n;i++)
    {
        newNode=malloc(sizeof(*newNode));
        if(newNode==NULL)
        {
            printf("Memory allocation failed\n");
            return NULL;
        }
        printf("Enter the data: ");
        scanf("%d", &(newNode->data));
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            temp=head;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }
    }
    temp->next=head;
    return head;
}

void display(Node *head)
{
    Node *temp=head;

    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        do
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        while(temp!=head);
        printf("NULL");
        printf("\n");
    }
}

Node *freeList(Node *head)
{
    Node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    temp=head;
    while(temp!=NULL)
    {
        Node *nextNode=temp->next;
        free(temp);
        temp=nextNode;
    };
    return NULL;
}




