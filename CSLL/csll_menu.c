#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create();

void display(Node *head);

Node *insertb(Node *head);

Node *inserte(Node *head);

Node *insertpos(Node *head);

Node *deleteb(Node *head);

Node *deletee(Node *head);

Node *deletepos(Node *head);

int count(Node *head);

Node *freeList(Node *head);

int main()
{
    int n;
    Node *head=NULL;

    int running=1,ch;
    while(running)
    {
        printf("=====CSLL Menu=====\n");
        printf("1. Create Circular Singly Linked List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Position\n");
        printf("12. Count Nodes\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                head=freeList(head);
                head=create();
                break;
            case 2:
                display(head);
                break;
            case 3:
                head=insertb(head);
                break;
            case 4:
                head=inserte(head);
                break;
            case 5:
                head=insertpos(head);
                break;
            case 6:
                head=deleteb(head);
                break;
            case 7:
                head=deletee(head);
                break;
            case 8:
                head=deletepos(head);
                break;
            case 12:
                n=count(head);
                printf("Number of nodes: %d\n", n);
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

    if(n<=0)
    {
        printf("Invalid number of nodes\n");
        return NULL;
    }

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

Node *insertb(Node *head)
{
    Node *last=NULL;
    Node *newNode=malloc(sizeof(*newNode));
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter the data: ");
    scanf("%d", &(newNode->data));
    newNode->next=NULL;
    
    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    else
    {
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        last=temp;
        newNode->next=head;
        head=newNode;
        last->next=head;
        return head;
    }
}

Node *inserte(Node *head)
{
    Node *last=NULL;
    Node *temp=head;
    Node *newNode=NULL;
    newNode=malloc(sizeof(*newNode));
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter the data: ");
    scanf("%d", &(newNode->data));
    newNode->next=NULL; 
    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        return head;
    }
}

Node *insertpos(Node *head)
{
    int pos, n;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    n=count(head);
    if(pos<=0 || pos>n+1)
    {
        printf("Invalid position\n");
        return head;
    }
    else
    {
        if(pos==1)
        {
            head=insertb(head);
            return head;
        }
        else if(pos==n+1)
        {
            head=inserte(head);
            return head;
        }
        else
        {
            Node *newNode=NULL;
            newNode=malloc(sizeof(*newNode));
            if(newNode==NULL)
            {
                printf("Memory allocation failed\n");
                return head;
            }
            printf("Enter the new data: ");
            scanf("%d", &(newNode->data));
            newNode->next=NULL;
            Node *temp=head;
            int i=1;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newNode->next=temp->next;
            temp->next=newNode;
            return head;
        }
    }

}

Node *deleteb(Node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if(head->next==head)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node *temp=head;
        Node *last=NULL;
        Node *oldNode=NULL;
        do
        {   
            temp=temp->next;
        }while(temp->next!=head);
        last=temp;
        oldNode=head;
        last->next=head->next;
        head=head->next;
        free(oldNode);
        return head;
    }
}

Node *deletee(Node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if(head->next==head)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node *temp=head;
        Node *prev=NULL;
        Node *oldNode=NULL;
        do
        {
            prev=temp;
            temp=temp->next;
        }while(temp->next!=head);
        oldNode=temp;
        prev->next=head;
        free(oldNode);
        return head;
    }
}

Node *deletepos(Node *head)
{
    int pos,n;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    n=count(head);
    if(pos<1 || pos>n)
    {
        printf("Invalid Position\n");
        return head;
    }
    else
    {
        if(pos==1)
        {
            head=deleteb(head);
            return head;
        }
        else if(pos==n)
        {
            head=deletee(head);
            return head;
        }
        else
        {
            Node *temp=head;
            Node *oldNode=NULL;
            int i=1;
            for(i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            oldNode=temp->next;
            temp->next=oldNode->next;
            free(oldNode);
            oldNode=NULL;
            return head;
        }
    }
}

int count(Node *head)
{
    Node *temp=head;
    int count=0;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        do
        {
            count++;
            temp=temp->next;
        }while(temp!=head);
    }
    return count;
}

Node *freeList(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
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




