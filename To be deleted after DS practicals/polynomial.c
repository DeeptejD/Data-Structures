// Polynomial Arithmetic

#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x);
#define sfl(x) scanf("%f", &x);
struct node
{
    int exp;
    float coeff;
    struct node *next;
};

struct node *addatend(struct node *start, int exp, float coeff)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)), *ptr = start;
    temp->exp = exp, temp->coeff = coeff, temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        return start;
    }
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return start;
}

struct node *create(int degree)
{
    float coeff;
    struct node *poly = NULL;
    for (int i = degree; i >= 0; i--)
    {
        printf("Enter the coefficient for degree %d: ", i);
        scanf("%f", &coeff);
        poly = addatend(poly, i, coeff);
    }
    return poly;
}

void display(struct node *poly)
{
    if (poly == NULL)
    {
        printf("0x^0 = 0\n");
        return;
    }
    struct node *ptr = poly;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
            printf("%.1fx^%d = 0\n", ptr->coeff, ptr->exp);
        else
            printf("%.1fx^%d + ", ptr->coeff, ptr->exp);
        ptr = ptr->next;
    }
}

struct node *poly_add(struct node *poly1, struct node *poly2)
{
    struct node *result = NULL, *ptr1 = poly1, *ptr2 = poly2;
    while (ptr1 != NULL || ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            result = addatend(result, ptr1->exp, ptr1->coeff + ptr2->coeff);
            ptr1 = ptr1->next, ptr2 = ptr2->next;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            result = addatend(result, ptr1->exp, ptr1->coeff);
            ptr1 = ptr1->next;
        }
        else if (ptr2->exp > ptr1->exp)
        {
            result = addatend(result, ptr2->exp, ptr2->coeff);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        result = addatend(result, ptr1->exp, ptr1->coeff);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        result = addatend(result, ptr2->exp, ptr2->coeff);
        ptr2 = ptr2->next;
    }
    return result;
}

struct node *multiply(struct node *poly1, struct node *poly2)
{
    if (poly1 == NULL || poly2 == NULL)
        return NULL;
    struct node *finalresult = NULL;
    struct node *result = NULL, *ptr1 = poly1, *ptr2 = poly2;
    while (ptr1 != NULL)
    {
        ptr2 = poly2;
        while (ptr2 != NULL)
        {
            result = addatend(result, ptr1->exp + ptr2->exp, ptr1->coeff * ptr2->coeff);
            ptr2 = ptr2->next;
        }
        finalresult = poly_add(finalresult, result);
        result = NULL;
        ptr1 = ptr1->next;
    }
    return finalresult;
}

struct node *addatpos(struct node *poly, float coeff, int exp, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)), *ptr = poly;
    temp->exp = exp, temp->coeff = coeff;
    if (pos == 1)
    {
        temp->next = poly;
        poly = temp;
    }
    else
    {
        for (int i = 0; ptr != NULL && i < pos - 1; i++)
            ptr = ptr->next;
        if (ptr == NULL)
        {
            temp->next = poly;
            poly = temp;
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    return poly;
}

struct node *insertterm(struct node *poly)
{
    float coeff;
    int exp;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter coeff: ");
    sfl(coeff);
    printf("Enter expo: ");
    sint(exp);
    temp->coeff = coeff, temp->exp = exp;
    int pos;
    sint(pos);
    poly = addatpos(poly, coeff, exp, pos);
    return poly;
}

struct node *delterm(struct node *poly)
{
    int exp;
    float coeff;
    printf("Enter the exponent: ");
    sint(exp);
    printf("Enter the coeff: ");
    sfl(coeff);
    struct node *ptr = poly;
    if (poly->exp == exp && poly->coeff == coeff)
    {
        struct node *temp = poly;
        poly = poly->next;
        free(temp);
        return poly;
    }
    else
    {
        while (ptr->next != NULL)
        {
            if (ptr->next->exp == exp && ptr->next->coeff == coeff)
            {
                struct node *temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                return poly;
            }
        }
    }
    printf("The term is not present\n");
    return poly;
}

struct node *modify(struct node *poly)
{
    int choice;
    printf("1. Add term\n2. Del term\n3. Display\n4. Exit\n");
    while (1)
    {
        sint(choice);
        switch (choice)
        {
        case 1:
        {
            poly = insertterm(poly);
        }
        break;
        case 2:
        {
            poly = delterm(poly);
            break;
        }
        case 3:
            display(poly);
            break;
        case 4:
            return poly;

        default:
            printf("Invalid\n");
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int deg1, deg2;
    struct node *poly1 = NULL, *poly2 = NULL;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &deg1);
    poly1 = create(deg1);
    printf("Enter the degree for the second polynomial: ");
    scanf("%d", &deg2);
    poly2 = create(deg2);
    printf("The first polynomial is: ");
    display(poly1);
    printf("The second polynomial is: ");
    display(poly2);
    struct node *result = poly_add(poly1, poly2);
    printf("The sum of the two polynomials is: ");
    display(result);
    // printf("Product of the multiplication of the two polynomials is: ");
    // struct node *prod = multiply(poly1, poly2);
    // display(prod);
    modify(poly1);
    display(poly1);
    modify(poly1);
    display(poly1);
    return 0;
}
