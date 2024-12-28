

#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
	struct node *prev;
};

struct node * head, *tail;

void ftraversal()
{
    struct node * t = head;
        if(head==NULL)
        {
            printf("\nList empty");
            return;
        }
        while(t!=NULL)
        {
            printf("%d -> ", t->value);
            t=t->next;
        }
}

void btraversal()
{
    struct node * t = tail;
        if(tail==NULL)
        {
            printf("\nList empty");
            return;
        }
        while(t!=NULL)
        {
            printf("%d -> ", t->value);
            t=t->prev;
        }
}

void insertFirst(int val)
{
    struct node*newNode = (struct node*) malloc( sizeof(struct node));
    newNode->value = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        {
         head->prev = newNode;
    }
    else
    {
        tail =  newNode;
    }
    head = newNode ;
}

void insertLast( int val )
{
    struct node*newNode = (struct node*) malloc (sizeof(struct node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        {
        tail->next = newNode;
    }
    else
    {
     head = newNode;
    }
    tail =  newNode;
}

void insertAfter(int val,int afterVal)
{
    struct node *current = head;
    while (current != NULL && current->value !=  afterVal)
        {
        current = current->next;
    }

    if (current != NULL)
        {
        struct node*newNode = (struct node *) malloc(sizeof (struct node));
        newNode->value = val;
        newNode ->next  = current->next;
        newNode->prev = current;

        if (current->next != NULL)
            {
            current->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }

        current->next = newNode;
    }
    else
        {
        printf("Value %d not found in the list\n",afterVal);
    }
}

void insertAtPosition(int val,int pos)
{
    if (pos == 1)
        {
        insertFirst(val);

        return;
    }

    struct node*current = head;

    for(int i =1;i <pos-1 && current!= NULL;i++)
        {
        current = current->next;
    }

    if (current != NULL)
        {
        struct node*newNode = (struct node*) malloc( sizeof(struct node));
        newNode->value= val;
        newNode->next= current->next;
        newNode->prev= current;

        if (current ->next != NULL)
            {
            current->next->prev = newNode;
        }
        else
            {
            tail =newNode;
        }

        current->next = newNode;
    }
    else
        {
        printf("Position %d is out of range\n",pos);
    }
}

void deleteValue(int val)
{
    struct node*current = head;

    while(current != NULL &&current->value != val)
        {
        current = current->next;
    }

    if (current !=NULL)
        {
        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }
    else
        {
            head = current->next;
        }

        if (current->next != NULL)
            {
            current->next->prev = current->prev;
        } else
        {
            tail = current->prev;
        }

        free(current);
    }
   else
    {
        printf("Value %d not found in the list.\n",val);
    }
}

void  searchValue( int val)
{
    struct node *current = head;

    int pos = 1;

    while (current != NULL && current->value !=val)
        {
        current= current->next;

         pos++;
    }

    if (current != NULL)
        {
        printf("Value %d found at position %d.\n",val,pos);
    }

    else
        {
        printf("Value %d not found in the list.\n",val);
    }
}

int main()
{
    head=NULL;
    tail=NULL;
    int val,choice,pos,afterVal;

while(1)
{
    printf("\n1. F Traversal \n2. B Traversal \n3. Insert First \n4. Insert Last \n5. Insert After a val \n6. Insert at a middle pos \n7. Delete \n8. Search \n9. Your custom function!  \n10.EXIT\nEnter choice:");
    scanf("%d", &choice);

    if(choice==1)
    {
        ftraversal();
    }
    else if(choice==2)
    {
         btraversal();
    }
    else if(choice==3)
    {
        printf("Enter valueto insert at the beginning:");
        scanf("%d",&val);
        insertFirst(val);
    }
    else if(choice==4)
    {
        printf("Enter value to insert at the  end:");
        scanf("%d",&val);
        insertLast(val);
    }
    else if(choice==5)
    {
          printf("Enter value to insert: ");
          scanf("%d",&val);
          printf("Enter value to inset after:");
          scanf("%d",&afterVal);

          insertAfter(val,afterVal);
    }
    else if(choice==6)
    {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter position to insert at:");
            scanf("%d", &pos);
            insertAtPosition(val,pos);
    }
    else if(choice==7)
    {
          printf("Enter value to delete:");
         scanf("%d", &val);
          deleteValue(val);
    }
    else if(choice==8)
    {
            printf("Enter value to search: ");
            scanf("%d", &val);
            searchValue(val);
    }
    else if(choice==9)
    {
         //WRITE APPROPRIATE CODE HERE
    }

    else if(choice==10)
        break;

    else
    {
        printf("Wrong choice, enter again");
    }

}

}
