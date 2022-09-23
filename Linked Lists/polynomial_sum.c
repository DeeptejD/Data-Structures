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
	printf("Enter the first polynomial\n");
	p1 = create(p1);
	printf("Enter the second polynomial\n");
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
	struct node *tmp, *ptr;
	int num, i;
	printf("Enter the number of terms: ");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		printf("Enter the coefficient: ");
		scanf("%d", &tmp->coeff);
		printf("Enter the exponent: ");
		scanf("%d", &tmp->exp);
		tmp->next = NULL;
		if (start == NULL)
			start = tmp;
		else
		{
			ptr = start;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = tmp;
		}
	}
	return start;
}
struct node *add(struct node *p1, struct node *p2)
{
	struct node *start3, *tmp, *ptr;
	int sum;
	start3 = NULL;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->exp == p2->exp)
		{
			sum = p1->coeff + p2->coeff;
			if (sum != 0)
			{
				tmp = (struct node *)malloc(sizeof(struct node));
				tmp->coeff = sum;
				tmp->exp = p1->exp;
				tmp->next = NULL;
				if (start3 == NULL)
					start3 = tmp;
				else
				{
					ptr = start3;
					while (ptr->next != NULL)
						ptr = ptr->next;
					ptr->next = tmp;
				}
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exp > p2->exp)
		{
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->coeff = p1->coeff;
			tmp->exp = p1->exp;
			tmp->next = NULL;
			if (start3 == NULL)
				start3 = tmp;
			else
			{
				ptr = start3;
				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = tmp;
			}
			p1 = p1->next;
		}
		else
		{
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->coeff = p2->coeff;
			tmp->exp = p2->exp;
			tmp->next = NULL;
			if (start3 == NULL)
				start3 = tmp;
			else
			{
				ptr = start3;
				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = tmp;
			}
			p2 = p2->next;
		}
	}
	while (p1 != NULL)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->coeff = p1->coeff;
		tmp->exp = p1->exp;
		tmp->next = NULL;
		if (start3 == NULL)
			start3 = tmp;
		else
		{
			ptr = start3;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = tmp;
		}
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->coeff = p2->coeff;
		tmp->exp = p2->exp;
		tmp->next = NULL;
		if (start3 == NULL)
			start3 = tmp;
		else
		{
			ptr = start3;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = tmp;
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
