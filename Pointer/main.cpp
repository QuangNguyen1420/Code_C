#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int inputName(int* d){
	printf("\nenter the id in inputName %d", d);
	printf("\nenter the id: %d", &d);
	printf("\nenter the id: %d", *d);
	
}

int main() {
	int *x;
	int a,b,c;
	b = 10;
	printf("enter the id in main: %d", &b);
//	x = &b;
	inputName(&b);
	//printf()
	return 0;
}
