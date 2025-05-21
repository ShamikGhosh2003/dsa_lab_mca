#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *head2=NULL;

void deleteFirst();
void deleteEnd();
void deleteAfterk(int k);
void deleteAtVal(int val);
void reverse();
void sort();
int search(int val);
void concatenate();
void insertAtEnd(int data);
int isequal();
void merge();
void create2(int n);
void insertAtEnd2(int data);


void create(int n)
{
    int data,i;
    if(head!=NULL)
    {
        printf("\nList already exists!");
        return;
    }
    for(int i=0; i<n; i++)
    {
        printf("\nEnter the data for node %d: ",i+1);
        scanf("%d",&data);
        insertAtEnd(data);
    }
}

void create2(int n)
{
	head2=NULL;
    int data,i;
    if(head2!=NULL)
    {
        printf("\nList already exists!");
		return;
    }
    for(int i=0; i<n; i++)
    {
        printf("\nEnter the data for node %d: ",i+1);
        scanf("%d",&data);
        insertAtEnd2(data);
    }
}

void printList()
{
    struct Node *temp=head;
    if(!temp)
    {
        printf("\nLinked List is empty!");
        return;
    }
    printf("\nThe list is:\n");
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insertAtBeg(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(!newNode)
    {
        printf("\nCannot allocate memory!");
    }
    newNode->data=data;
    newNode->next=head;
    head=newNode;
    printf("\nElement insert at the beginning!");
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp=head;
    if(!newNode)
    {
        printf("\nCannot allocate memory!");
    }
    newNode->data=data;
    newNode->next=NULL;
    if(!head)
    {
        head=newNode;
        return;
    }
    while(temp->next)
        temp=temp->next;

    temp->next=newNode;
}

void insertAtEnd2(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head2;
    if (!newNode) {
        printf("\nCannot allocate memory!");
    }
    newNode->data = data;
    newNode->next = NULL;
    if (!head2) {
        head2 = newNode;
        return;
    }
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void insertAfterk(int k, int data)
{
    int i=0;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp=head;
    if(k<0)
    {
        printf("\nNegtive Index!");
        return;
    }
    if(!head)
    {
        printf("\nLinked List is empty!");
        return;
    }
    while(temp && i<k)
    {
        temp=temp->next;
        i++;
    }
    if(!temp && i==k)
    {
        insertAtEnd(data);
        return;
    }
    if(!temp && i<k)
    {
        printf("\nIndex out of bounds");
        return;
    }
    newNode->data=data;
    newNode->next=temp->next;
    temp->next=newNode;
    printf("\nElement Inserted!");
}

void insertBeforek(int k, int data)
{
    k-=1;
    insertAfterk(k,data);
}

void insertAfterValue(int val, int data)
{
    int idx = search(val);
    if(idx == -1)
    {
        printf("\nElement not found!");
        return;
    }
    insertAfterk(idx,data);
}
void insertBeforeVal(int val, int data)
{
    int idx = search(val);
    if(idx==-1)
    {
        printf("\nElement not found!");
        return;
    }
    insertBeforek(idx,data);
}

void deleteFirst()
{
    if(head==NULL)
    {
        printf("No list exists!");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    printf("First element '%d' is removed!",temp->data);
    free(temp);
}

void deleteEnd()
{
    if(head==NULL)
    {
        printf("No list exists!");
        return;
    }
    if(head->next==NULL){
        deleteFirst();
        return;
    }
    struct Node *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    printf("\n Element '%d' at the end is deleted",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}

void deleteAtk(int k)
{
    int i=0;
    k=k-1;
    if(head==NULL)
    {
        printf("List is empty!");
        return;
    }
    if(k==0)
    {
        deleteFirst();
        return;
    }
    struct Node *temp=head;
    while(i<k-1 && temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    if(i<k && temp->next==NULL)
    {
        printf("\nOut of scope");
        return;
    }
    printf("\nElement '%d' is deleted",temp->next->data);
    struct Node *tbd=temp->next;
    temp->next=temp->next->next;
    free(tbd);    
}
void deleteAtVal(int val)
{
    int idx = search(val);
    if(idx==-1)
    {
        printf("\nElement not found!");
        return;
    }
    deleteAtk(idx+1);
}

void sort()
{
    if(head == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    struct Node *i,*j;
    int temp;
    for(i=head; i!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if(i->data > j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }    
}
void reverse()
{
    struct Node *prev=NULL;
    struct Node *curr=head;
    struct Node *next=NULL;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

int search(int val)
{
    int i=0;
    struct Node *temp=head;
    if(!head)
    {
        printf("\nLinked List is empty!");
        return -1;
    }
    while(temp && temp->data != val)
    {
        temp=temp->next;
        i++;
    }    
    if(!temp)
    {
        printf("\nSearched element not found!");
        return -1;
    }
    return i;
}
void concatenate()
{
    struct Node *temp=head2;
    while(temp!=NULL)
    {
        insertAtEnd(temp->data);
        temp=temp->next;
    }
}

void merge() {
    struct Node *temp1 = head, *temp2 = head2;
    struct Node *merged = NULL;

    while (temp1 && temp2) {
        if (temp1->data < temp2->data) {
            insertAtEnd(temp1->data);
            temp1 = temp1->next;
        } else {
            insertAtEnd(temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp1) {
        insertAtEnd(temp1->data);
        temp1 = temp1->next;
    }

    while (temp2) {
        insertAtEnd(temp2->data);
        temp2 = temp2->next;
    }

    printf("\nLists merged successfully!");
}

int isequal()
{
    // int f=1; //considering list are equal
    struct Node *temp1=head;
    struct Node *temp2=head2;
    while(temp1!=NULL & temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
            return -1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=NULL || temp2!=NULL)
        return -1;
	return 0;
}

int main()
{
    int ch,n,data,k;
    do
    {
        printf("\n\n\n1. Create a linked list.");
        printf("\n2. Print the content of the list.");
        printf("\n3. Insert an element at the front.");
        printf("\n4. Insert an element at the end of the list.");
        printf("\n5. Insert a node after the kth element.");
        printf("\n6. Insert a node after the node (first from the start) containing a given value.");
        printf("\n7. Insert a node before the kth node");
        printf("\n8. Insert Insert a node before the node (first from the start) containing a given value.");
        printf("\n9. Delete the first node.");
        printf("\n10. Delete the last node.");
        printf("\n11. Delete the node after the kth element");
        printf("\n12. Delete the node before the kth node");
        printf("\n13. Delete the kth node.");
        printf("\n14. Delete the node (first from the start) containing a specified value.");
        printf("\n15. Reverse a list physically.");
        printf("\n16. Sort the list.");
        printf("\n17. Search a given element.");
        printf("\n18. Merge two lists; sort in ascending order.");
        printf("\n19. Concatenate two lists.");
        printf("\n20. Find if two lists are equal.");
        printf("\n0. To exit menu.");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                break;
            case 1:
                printf("\nEnter the number of elements you want: ");
                scanf("%d",&n);
                create(n);
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("\nEnter the data: ");
                scanf("%d",&data);
                insertAtBeg(data);
                break;
            case 4:
                printf("\nEnter the data: ");
                scanf("%d",&data);
                insertAtEnd(data);
                printf("\nData inserted at the end!");
                break;
            case 5:
                printf("\nEnter the value of k: ");
                scanf("%d",&k);
                printf("\nEnter the value: ");
                scanf("%d",&data);
                insertAfterk(k,data);
                break;
            case 6:
                printf("\nEnter the value: ");
                scanf("%d",&k);
                printf("\nEnter the data: ");
                scanf("%d",&data);
                insertAfterValue(k,data);
                break;
            case 7:
                printf("\nEnter the value of k: ");
                scanf("%d",&k);
                printf("\nEnter the value: ");
                scanf("%d",&data);
                insertBeforek(k,data);
                break;
            case 8:
                printf("\nEnter the value: ");
                scanf("%d",&k);
                printf("\nEnter the data: ");
                scanf("%d",&data);
                insertBeforeVal(k,data);
                break;
            case 9:
                deleteFirst();
                break;
            case 10:
                deleteEnd();
                break;
            case 11:
                printf("\nEnter the value of k: ");
                scanf("%d",&k);
                deleteAtk(k+1);
                break;
            case 12:
                printf("\nEnter the value of k: ");
                scanf("%d",&k);
                deleteAtk(k-1);
            break;
            case 13:
                printf("\nEnter the value of k: ");
                scanf("%d",&k);
                deleteAtk(k);
                break;
            case 14:
                printf("\nEnter the value: ");
                scanf("%d",&k);
                deleteAtVal(k);
                break;
            case 15:
                reverse();
                break;
            case 16:
                sort();
                printf("\nList Sorted!");
                printList();
                break;
            case 17:
                printf("\nEnter the value: ");
                scanf("%d",&k);
                int idx=search(k);
                if(idx==-1)
                    printf("\nElement not found!");
                else
                    printf("\nElement found at index: %d",idx);
                break;
            case 18:
                printf("\nEnter the number of elements you want: ");
                scanf("%d",&n);
                create2(n);
                merge();
				break;
            case 19:
                printf("\nEnter the number of elements you want: ");
                scanf("%d",&n);
                create2(n);
                printf("\nList Concatenated!");
                concatenate();
                break;
            case 20:
                if(head==NULL){
                    printf("Create a list first before creating another list!");
                    continue;
                }
                head2=NULL;
                printf("\nEnter the number of elements you want: ");
                scanf("%d",&n);
                create2(n);
                printf("List Created!");
                if(isequal()==-1)
                    printf("\nBoth lists are not the same");
                else
                    printf("\nBoth lists are same.");
                break;
            default:
                printf("\nInvalid input!");
                break;
        }
    } while (ch);
    return 0;
}

