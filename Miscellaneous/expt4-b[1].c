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

void push(char item[])
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory cannot be allocated\n");
        exit(1);
    }
    strncpy(temp->info, item, sizeof(temp->info)); // NEW
    temp->info[strlen(item)] = '\0';               // NEW
    temp->link = top;
    top = temp;
}

void push_char(char c)
{
    char tobepushed[2];
    tobepushed[0]=c;
    tobepushed[1]='\0';
    struct node *tmp;
    if((tmp=(struct node *)malloc(sizeof(struct node)))==NULL)
    {
        printf("NO mem");
        exit(EXIT_FAILURE);
    }
    strncpy(tmp->info, tobepushed, sizeof(tmp->info));
    tmp->info[strlen(tobepushed)]='\0';
    tmp->link=top->link;
    top=tmp;
}

// int stack_count()
// {
//     struct node *p;
//     int count;
//     p = top;
//     while (p != NULL)
//     {
//         count++;
//         p = p->link;
//     }
//     return count;
// }

char str1[100], str2[100]; // NEW
void pop()                 // NEW
{
    if (isEmpty())
    {
        printf("Stack Underflow.\n");
        exit(1); // NEW
    }
    top = top->link;
    strncpy(str1, top->info, sizeof(str1));
    str1[strlen(top->info)] = '\0';
    top = top->link;
    strncpy(str2, top->info, sizeof(str2));
    str2[strlen(top->info)] = '\0';
}

void conv_postfix_to_infix()
{
    char postfix[200], infix[400], symb, tempstr[400];
    printf("\nEnter the postfix array: ");
    scanf("%s", postfix);
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        char symbol[2] = {postfix[i], '\0'};
        switch (postfix[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            // if (stack_count() < 2)
            // {
            //     printf("There are no sufficient terms in the expression\n");
            //     exit(1);
            // }
            pop();
            char open[] = "(";
            char close[] = ")";
            strncpy(tempstr, open, sizeof(tempstr));
            tempstr[strlen(open)] = '\0';
            strncat(tempstr, str2, sizeof(tempstr) - strlen(tempstr) - 1);
            strncat(tempstr, symbol, sizeof(tempstr) - strlen(tempstr) - 1);
            strncat(tempstr, str1, sizeof(tempstr) - strlen(tempstr) - 1);
            strncat(tempstr, close, sizeof(tempstr) - strlen(tempstr) - 1);
            // sprintf(tempstr, "%s %s %s %s %s", "(", b, symbol, a, ")");
            push(tempstr);
            break;
        default:
            push_char(postfix[i]);
            break;
        }
    }
    // if (stack_count() == 1)
    char final[100];
    strncpy(final, top->info, sizeof(final));
    final[strlen(top->info)] = '\0';
    printf("Infix Expression : %s\n", final);
    // else
    //     printf("Error.The user input has too many values.\n");
    // top = NULL;
    // printf("\n");
}

int main()
{
    conv_postfix_to_infix();
    return 0;
}
