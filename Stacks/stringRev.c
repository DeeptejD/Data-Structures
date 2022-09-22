#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
char stack[MAX], expression[MAX];
int top=-1;
void reverse()
{   
    for(int i=0;i<strlen(expression);i++)
        stack[++top]=expression[i];
    printf("Reverse: ");
    while(top!=-2)
        printf("%c", stack[top--]);
    printf("\n");
}

void pallindrome()
{
    for(int i=0;i<strlen(expression);i++)
        stack[++top]=expression[i];
    int i=0;
    while(top!=-2 && i<strlen(expression)){
        if(stack[top]!=expression[i]){
            printf("Not pallindrome\n");
            return;
        }
        top--;
        i++;
    }
    printf("Pallindrome\n");
    return;
}
int main(int argc, char const *argv[])
{
    printf("Enter expression: ");
    gets(expression);
    expression[strlen(expression)+1]='\0';
    while (1)
    {
        printf("1. Reverse\n2. Check pallindrome\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            reverse();
            break;
        case 2:
            pallindrome();
            break;
        case 3:
            exit(1);
        default:
            printf("Inavlid expression\n");
        }
    }
    
    return 0;
}
