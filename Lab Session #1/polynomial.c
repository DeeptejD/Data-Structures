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
struct node *multiply(struct node *, struct node *);
void modify(struct node *start);
struct node *addatpos(struct node *, int, int, int);
struct node *del(struct node *, int, int);
struct node *addatend(struct node *, int, int);
struct node *create_using_file(struct node *);

int main()
{
	struct node *p1 = NULL, *p2 = NULL, *p3 = NULL;
	printf("Select mode of input\n1.Manual\n2.From a file\n");
	int mode;
	scanf("%d", &mode);
	switch (mode)
	{
	case 1:
		printf("Polynomial Arithmetic\n");
		printf("Enter the first polynomial\n");
		p1 = create(p1);
		printf("Enter the second polynomial\n");
		p2 = create(p2);
		printf("The first polynomial is: ");
		display(p1);
		printf("The second polynomial is: ");
		display(p2);
		break;
	case 2:
		create_using_file(p1);
		display(p1);
		create_using_file(p2);
		display(p2);
		break;
	default:
		printf("Invalid input entered\n");
		break;
	}
	while (1)
	{
		int choice;
		int select;
		printf("1.Add\n2.Multiply\n3.Modify\n4.Display\n5.Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			p3 = add(p1, p2);
			printf("The sum of the two polynomials is: ");
			display(p3);
			break;
		case 2:
			p3 = multiply(p1, p2);
			printf("The product of the two polynomials is: ");
			display(p3);
			break;
		case 3:
			printf("Which polynomial do you want to modify?\n1.First Polynomial\n2.Second Polynomial\n");
			scanf("%d", &select);
			switch (select)
			{
			case 1:
				modify(p1);
				break;
			case 2:
				modify(p2);
				break;
			default:
				break;
			}
			break;
		case 4:
			display(p1);
			display(p2);
			break;
		case 5:
			exit(1);
		default:
			break;
		}
	}

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

struct node *multiply(struct node *start1, struct node *start2)
{
	struct node *start3, *ptr1 = start1, *ptr2 = start2;
	start3 = NULL;
	if (ptr1 == NULL || ptr2 == NULL)
	{
		printf("The product is 0\n");
		exit(1);
	}
	while (ptr1 != NULL)
	{
		ptr2 = start2;
		while (ptr2 != NULL)
		{
			struct node *tmp = (struct node *)malloc(sizeof(struct node));
			tmp->coeff = ptr1->coeff * ptr2->coeff;
			tmp->exp = ptr1->exp + ptr2->exp;
			tmp->next = NULL;
			if (start3 == NULL)
				start3 = tmp;
			else
			{
				struct node *ptr3 = start3;
				while (ptr3->next != NULL)
					ptr3 = ptr3->next;
				ptr3->next = tmp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return start3;
}

void modify(struct node *start)
{
	struct node *tmp;
	int coeff, exp, pos;
	printf("Select the operation\n1.Enter an element\n2.Delete an element\n3.Return back\n4.Exit\n");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("Enert the coefficient: ");
		scanf("%d", &coeff);
		printf("Enter the exponent: ");
		scanf("%d", &exp);
		printf("Enter the position: ");
		scanf("%d", &pos);
		start = addatpos(start, coeff, exp, pos);
		return;
	case 2:
		printf("Enter the coefficient: ");
		scanf("%d", &coeff);
		printf("Enter the exponent: ");
		scanf("%d", &exp);
		del(start, coeff, exp);
		return;
	case 3:
		return;
	case 4:
		exit(1);
	default:
		break;
	}
}

struct node *addatpos(struct node *start, int coeff, int exp, int pos)
{
	struct node *tmp, *ptr;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coeff = coeff;
	tmp->exp = exp;
	if (pos == 1)
	{
		tmp->next = start;
		start = tmp;
	}
	else
	{
		ptr = start;
		for (int i = 1; i < pos - 1 && ptr != NULL; i++)
			ptr = ptr->next;
		if (ptr == NULL)
			start = addatend(start, coeff, exp);
		else
		{
			tmp->next = ptr->next;
			ptr->next = tmp;
		}
	}
	return start;
}

struct node *del(struct node *start, int coeff, int exp)
{
	struct node *tmp, *p;
	tmp = (struct node *)malloc(sizeof(struct node));
	if (start == NULL)
	{
		printf("Polynomial is empty\n");
		return start;
	}
	if (start->coeff == coeff && start->exp == exp)
	{
		tmp = start;
		start = start->next;
		free(tmp);
		return start;
	}
	p = start;
	while (p->next != NULL)
	{
		if (p->next->coeff == coeff && p->next->exp == exp)
		{
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
			return start;
		}
		p = p->next;
	}
	return start;
}

struct node *addatend(struct node *start, int coeff, int exp)
{
	struct node *p = start;
	while (p->next != NULL)
		p = p->next;
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->coeff = coeff;
	tmp->exp = exp;
	tmp->next = NULL;
	p->next = tmp;
	return start;
}

struct node create_using_file(struct node *start)
{
	struct node *tmp, *ptr;
	int num, i;
	File *fptr;
	if ((fptr = fopen("input.txt", "r")) == NULL)
	{
		printf("The file could not be opened\n");
		exit(1);
	}
	fscanf(fptr, "%d", &num);
	for (i = 0; i < num; i++)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		fscanf(fptr, "%d", &tmp->coeff);
		fscanf(fptr, "%d", &tmp->exp);
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