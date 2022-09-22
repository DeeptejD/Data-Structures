#include<stdio.h>
#include<stdlib.h>

struct node{
	float coeff;
	int exp;
	struct node *link;
};

struct node *create(struct node *start){
}

int main(int argc, char const *argv[])
{
	struct node *start1=NULL, *start2=NULL;
	printf("Enter polynomial 1: ");
	start1=create(start1);
	printf("Enter polynomial 2: ");
	start2=create(start2);
	printf("Polynomial 1: ");
	display(start1);
	printf("Polynomial 2: ");
	display(start2);
	return 0;
}
