#include <stdio.h>
#include <stdlib.h>


typedef struct Students{
	int math;
	char name[30];
	struct node *next;
} Students; 

Students *head;
Students *tail;

void EnterData(char *a , int *b)
{
	fflush(stdin);
	printf("enter the name: ");
//    gets(a);
	scanf("%[^\n]s",a);
    printf("enter the math scores: ");
    scanf("%d",b);
   
    
}
// them mot node vao dau danh sach
void AddToHead()
{
	Students *NewStudent= (Students*)malloc(sizeof(Students));
	EnterData(NewStudent->name,&(NewStudent->math));
	if(head == NULL)
	{
		head = NewStudent;
		NewStudent->next = tail;
	}
	NewStudent->next = head;
	head = NewStudent ;
}


void PrintList()
{
	Students *cur;
	cur = head;
	while(cur->next != tail)
	{
		printf("Name: %s \t", cur->name);
		printf("id: %d\n",cur->math);
	
		cur = cur->next;
	}	
	fflush(stdin);
}

struct Students *swap(struct Students *a, struct Students *b){
	struct Node* tmp = b->next;
    b->next = a;
    a->next = tmp;
    return b;
}

// sap xep theo diem toan
void sortMathOfStudent(){
	Students *x;
	Students *temp;
	Students *prev;
	temp = head->next;
	prev = head;
	if(prev->math > temp->math){
		swap(prev,temp);
		x = prev;
		prev = temp;
		temp = x;
		head = prev; 
	}
	printf("Diem:%d\n",temp->math);
	while(temp->next == tail)
	{
		printf("diem toan%d\n",prev->math);
		if(prev->math > temp->math){
			swap(prev,temp);
			x = prev;
			prev = temp;
			temp = x;
		}
		prev = temp;	
		temp = temp->next;
	
	}

}

int main() {
	char check = 'y';
	tail = (Students*)malloc(sizeof(Students));
	head = (Students*)malloc(sizeof(Students));
	tail->next = NULL;
	head->next = tail;
	do
	{
		AddToHead();
		printf("do you want to add a new student:y/n?");
		fflush(stdin);
		scanf("%c",&check);
	}while(check != 'n');
//	switch (q)
//	{
//		case 'y':
//		
//		case 'n':
//			PrintList();
//			break;
//		default:
//			printf("error!");
//			break;
//		
//	}

	PrintList();
	sortStudentList();
	PrintList();
	Students *del;// Free bo nho cap phat
	del = head;
	while (del != NULL)
	{
	head = head->next;
	free(del);
	del = head;
	}
	
	
	return 0;
}
