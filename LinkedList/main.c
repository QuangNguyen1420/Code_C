#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Node 
{
	int data;
	struct Node *next;
}Node;
void showData_Of_Current_Element(int data){
	printf("Data = %d\n",data);
}
int main() {
 	Node* head;
	Node* second = NULL;
	Node* third = NULL;
	
	// Cap phat bo nho 
	head = (Node*)malloc(sizeof(Node));
	second = (Node*)malloc(sizeof(Node));
	third = (Node*)malloc(sizeof(Node));
	printf("kich thuoc %lu\n",sizeof(Node));
	
	// gan du lieu
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	Node* cur;
	for(cur = head; cur != NULL; cur = cur->next){
			showData_Of_Current_Element(cur->data);
			printf("kich thuoc %d %lu\n",cur->data,sizeof(cur->data));
	}
		
	
	return head->data;
}
