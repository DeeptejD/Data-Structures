#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char info[100];
    struct node *link;
} *top = NULL;

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push(char *item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory cannot be allocated\n");
        exit(1);
    }
    strcpy(temp->info, item);
    temp->link = top;
    top = temp;
}

int stack_count()
{
    struct node *p;
    int count;
    p = top;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}

char *pop()
{
    struct node *temp;
    char *s = malloc(100);
    if (isEmpty())
    {
        printf("Stack Underflow.\n");
        exit(1); //changed the return stmt here from return; to exit(1)
    }
    temp = top;
    top = top->link;
    strcpy(s, temp->info);
    free(temp);
    return s;
}

void display()
{
    struct node *p;
    p = top;
    printf("The elements of the stack are : ");
    while (p != NULL)
    {
        printf("%s ", p->info);
        p = p->link;
    }
    printf("\n");
}

void conv_postfix_to_infix()
{
    char postfix[200], infix[400], symbol[2], symb, a[200], b[200], tempstr[400] = "";
    printf("\nEnter the postfix array: ");
    scanf("%s", postfix);
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        char symbol[2] = {postfix[i], '\0'};
        symb = postfix[i];
        switch (symb)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            if (stack_count() < 2)
            {
                printf("There are no sufficient terms in the expression\n");
                exit(1);
            }
            strcpy(a, pop());
            strcpy(b, pop());
            sprintf(tempstr, "%s %s %s %s %s", "(", b, symbol, a, ")");
            push(tempstr);
            break;
        default:
            push(symbol);
        }
    }
    if (stack_count() == 1)
        printf("Infix Expression : %s\n", pop());
    else
        printf("Error.The user input has too many values.\n");
    top = NULL;
    printf("\n");
}

int main()
{
    int choice, cr;
    while (1)
    {
        printf("Enter 1 to push an element.\n");
        printf("Enter 2 to pop an element.\n");
        printf("Enter 3 to display elements in stack.\n");
        printf("Enter 4 to convert postfix to infix.\n");
        printf("Enter 5 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the character to be inserted.\n");
            cr=getchar(); // getchar shud be assigned 
            scanf("%c", &cr);
            push(&cr);
            break;
        case 2:
            printf("Enter 2 to delete an element.\n");
            printf("The deleted element was %c\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            top = NULL;
            conv_postfix_to_infix();
            break;
        case 5:
            exit(1);
        }
    }
}
