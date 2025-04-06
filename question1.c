#include <stdio.h>
#include <stdlib.h>

void create(int **,int *);
void display(int *,int);
void count(int);
void reverse(int *,int);
void index_of_element(int *,int);
void element_at_index(int *,int);
void insert_at_pos(int **,int *);
void delete_at_pos(int **,int *);
void merge(int **,int *);
void split(int *,int);
void sort(int *,int);

int main()
{
	int ch,*arr,n=0;
	do {
		printf("\n----------------MENU---------------");
		printf("\n1. Create\n2. Display the list\n3. Count (number of elements in the list)\n4. Reverse the list\n5. Index of a given element\n6. Indexed element\n7. Insert\n8. Delete\n9. Merge\n10. Split\n11. Sort\n0. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				create(&arr,&n);
				break;
			case 2:
				display(arr,n);
				break;
			case 3:
				count(n);
				break;
			case 4:
				reverse(arr,n);
				break;
			case 5:
				index_of_element(arr,n);
				break;
			case 6:
				element_at_index(arr,n);
				break;
			case 7:
				insert_at_pos(&arr,&n);
				break;
			case 8:
				delete_at_pos(&arr,&n);
				break;
			case 9:
				merge(&arr,&n);
				break;
			case 10:
				split(arr,n);
				break;
			case 11:
				sort(arr,n);
				break;
			case 0:
				break;
			default:
				printf("\nInvalid Input");
				break;
		}

	}while(ch);

	return 0;
}

void create(int **arr, int *n)
{
	int i;
	printf("Enter the size: ");
	scanf("%d",n);
	*arr=(int*)malloc((*n)*sizeof(int));
	
	if(*arr == NULL){
		printf("\nMemory allocation failed");
		exit(0);
	}

	printf("\nEnter the elements:\n");
	for(i=0;i<*n;i++)
	{
		printf("[%d]: ",i+1);
		scanf("%d",&(*arr)[i]);
	}
	printf("\nArray Created!");
}

void display(int *arr,int n)
{
	int i;
	printf("\nThe array is: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

void count(int n)
{
	printf("\nCount: %d",n);
}

void reverse(int *arr,int n)
{
	int i,temp;
	for(i=0;i<(n/2);i++)
	{
		temp=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=temp;
	}
	printf("\nArray reversed!");
}

void index_of_element(int *arr,int n)
{
	int i,ele,flag=0;
	printf("\nEnter the element: ");
	scanf("%d",&ele);
	printf("\nIndex of the element (if present): ");
	for(i=0;i<n;i++)
		if(arr[i]==ele)
		{
			printf("%d ",i+1);
			flag=1;
		}
	if(!flag)
		printf("\nElement not found!");
}

void element_at_index(int *arr,int n)
{
	int pos,i;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	if(pos<0||pos>=n)
	{
		printf("\nIndex out of bounds!");
		return;
	}
	printf("\nElement at position '%d' is: %d",pos,arr[pos]);
}

void insert_at_pos(int **arr,int *n)
{
	int i,pos,ele;

	do{
		printf("\nEnter the position [0-%d]: ",*n-1);
		scanf("%d",&pos);
		if(pos<0 || pos>=*n)
			continue;
		else
		{
			printf("\nEnter the element: ");
			scanf("%d",&ele);
			break;
		}
	}while(1);

	*arr=(int*)realloc(*arr,(*n+1)*sizeof(int));
	(*n)+=1;
	for(i=*n-1;i>=pos;i--)
		(*arr)[i]=(*arr)[i-1];
	(*arr)[pos] = ele;
	printf("\nElement inserted!");
}

void delete_at_pos(int **arr,int *n)
{
	int i,pos;

	do{
		printf("\nEnter the position [0-%d]: ",*n-1);
		scanf("%d",&pos);
		if(pos<0 || pos>=*n)
			continue;
		else
			break;
	}while(1);

	printf("\nElement at position '%d': value '%d' deleted!",pos,(*arr)[pos]);
	for(i=pos;i<*n-1;i++)
		(*arr)[i]=(*arr)[i+1];
	*arr=(int*)realloc(*arr,(*n-1)*sizeof(int));
	(*n)-=1;
}

void merge(int **arr,int *n)
{
	int	i,*arr2,m;
	printf("\nEnter the size of the new array: ");
	scanf("%d",&m);
	arr2=(int*)malloc(m*sizeof(int));
	
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<m;i++)
	{
		printf("[%d]: ",i+1);
		scanf("%d",&arr2[i]);
	}

	*arr=(int*)realloc(*arr,(*n+m)*sizeof(int));
	
	for(i=*n;i<(*n+m);i++)
		(*arr)[i]=arr2[i-*n];

	*n=*n+m;
	printf("Arrays merged!");
}

void split(int *arr,int n)
{
	int *arr1,*arr2,i,pos;
	do {
		printf("\nEnter the position [0-%d]: ",n-1);
		scanf("%d",&pos);
		if(pos<0 || pos>=n)
			continue;
		else
			break;
	}while (1);

	arr1=(int*)malloc(pos*sizeof(int));
	arr2=(int *)malloc((n-pos)*sizeof(int));

	for(i=0;i<pos;i++)
		arr1[i]=arr[i];
	for(i=pos;i<n;i++)
		arr2[i-pos]=arr[i];

	printf("\nArrays split are:\n");
	printf("Array1 is: ");
	for(i=0;i<pos;i++)
		printf("%d ",arr1[i]);
	printf("\nArray2 is: ");
	for(i=0;i<(n-pos);i++)
		printf("%d ",arr2[i]);
}

void sort(int *arr,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nArray is sorted!");
}
