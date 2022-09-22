#include <stdio.h>
#include <stdlib.h>

struct node
{
	int expo;
	int coeff;
	struct node *link;
};

struct node *create(struct node *);
struct node *insert(struct node *, int, int);
void display(struct node *);
void add(struct node *, struct node *);
void mult(struct node *, struct node *);

int main(int argc, char const *argv[])
{
	struct node *start1 = NULL, *start2 = NULL;
	printf("Enter first polynomial: ");
	start1 = create(start1);
	printf("Enter polynomial 2: ");
	start2 = create(start2);
	printf("Polynomial 1: ");
	display(start1);
	printf("Polynomial 2: ");
	display(start2);
	add(start1, start2);
	mult(start1, start2);
	return 0;
}

struct node *create(struct node *start)
{
	printf("Enter the number of terms: ");
	int n, co, ex;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Enter coefficient for term %d: ");
		scanf("%d", &co);
		printf("Enter exponent for term %d: ");
		scanf("%d", &ex);
		start = insert(start, co, ex);
	}
	return start;
}

struct node *insert(struct node *start, int co, int ex)
{
	if(start==NULL)
	
}

