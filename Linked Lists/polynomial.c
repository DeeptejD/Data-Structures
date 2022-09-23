// polynomial addition using linked lists
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int coeff;
	int exp;
	struct node *next;
};
struct node *create(struct node *);
struct node *add(struct node *, struct node *);
void display(struct node *);
int main()
{
	struct node *p1 = NULL, *p2 = NULL, *p3 = NULL;
	printf("Enter the first polynomial: ");
	p1 = create(p1);
	printf("Enter the second polynomial: ");
	p2 = create(p2);
	p3 = add(p1, p2);
	printf("The first polynomial is: ");
	display(p1);
	printf("The second polynomial is: ");
	display(p2);
	printf("The sum of the two polynomials is: ");
	display(p3);
	return 0;
}
struct node *create(struct node *start)
{
	struct node *new_node, *ptr;
	int num, i;
	printf("Enter the number of terms: ");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("Enter the coefficient: ");
		scanf("%d", &new_node->coeff);
		printf("Enter the exponent: ");
		scanf("%d", &new_node->exp);
		new_node->next = NULL;
		if (start == NULL)
			start = new_node;
		else
		{
			ptr = start;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new_node;
		}
	}
	return start;
}
struct node *add(struct node *p1, struct node *p2)
{
	struct node *start3, *new_node, *ptr;
	int sum;
	start3 = NULL;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->exp == p2->exp)
		{
			sum = p1->coeff + p2->coeff;
			if (sum != 0)
			{
				new_node = (struct node *)malloc(sizeof(struct node));
				new_node->coeff = sum;
				new_node->exp = p1->exp;
				new_node->next = NULL;
				if (start3 == NULL)
					start3 = new_node;
				else
				{
					ptr = start3;
					while (ptr->next != NULL)
						ptr = ptr->next;
					ptr->next = new_node;
				}
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exp > p2->exp)
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->coeff = p1->coeff;
			new_node->exp = p1->exp;
			new_node->next = NULL;
			if (start3 == NULL)
				start3 = new_node;
			else
			{
				ptr = start3;
				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = new_node;
			}
			p1 = p1->next;
		}
		else
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			new_node->coeff = p2->coeff;
			new_node->exp = p2->exp;
			new_node->next = NULL;
			if (start3 == NULL)
				start3 = new_node;
			else
			{
				ptr = start3;
				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = new_node;
			}
			p2 = p2->next;
		}
	}
	while (p1 != NULL)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->coeff = p1->coeff;
		new_node->exp = p1->exp;
		new_node->next = NULL;
		if (start3 == NULL)
			start3 = new_node;
		else
		{
			ptr = start3;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new_node;
		}
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->coeff = p2->coeff;
		new_node->exp = p2->exp;
		new_node->next = NULL;
		if (start3 == NULL)
			start3 = new_node;
		else
		{
			ptr = start3;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new_node;
		}
		p2 = p2->next;
	}
	return start3;
}
void display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while (ptr != NULL)
	{
		printf("%dx^%d", ptr->coeff, ptr->exp);
		ptr = ptr->next;
		if (ptr != NULL)
			printf(" + ");
	}
	printf("\n");
}
