#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

void display(struct node *);
struct node *create(struct node *);
struct node *multiply(struct node *, struct node *);

int main(int argc, char const *argv[])
{
    struct node *start1, *start2, *prod;
    printf("Enter first polynomial\n");
    start1 = create(start1);
    printf("Enter second polynomial\n");
    start2 = create(start2);
    prod = multiply(start1, start2);
    printf("The first polynomial is: ");
    display(start1);
    printf("The second polynomial is: ");
    display(start2);
    printf("The product of the two polynomials is:");
    display(prod);
    return 0;
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
    struct node *start3, *tmp, *ptr1 = start1, *ptr2 = start2;
    int prod = 1;
    start3 = NULL;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
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
        }
    }
    return start3;
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