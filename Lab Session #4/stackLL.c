#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char postfix[MAX], infix[MAX];
struct node{
    char string[MAX]
    struct node *link;
}*top=NULL;

struct node *push(char c[]){
    struct node *tmp;
    if((tmp=(struct node *)malloc(sizeof(struct node)))==NULL){
        printf("overflow\n");
        exit(1);
    }
    strcpy(tmp->string, c);
    tmp->link=top->link;
    top=tmp;
    return top;
}

char *pop(){
    struct node *tmp;
    tmp=top;
    char arr[MAX];
    strcpy(arr, top->string);
    top=top->link;
    free(tmp);
    return arr;
}

void display(){
    if(top==NULL){
        printf("Ltack is empty\n");
        return;
    }
    struct node *p=top;
    print("Stack is: ");
    while(p!=NULL){
        printf("%d, ", p->info);
    }
}

isOperand(char c){
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return 0;
    return 1;
        break;
    
    default:
        break;
    }
}

void toInfix(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            push(postfix[i]);
        } else {
            char c1[MAX] = pop();
            char c2[MAX]=pop();
            char tmp[MAX];
            strcat(tmp, '(');
            strcat(tmp, c1);
            strcat(tmp, postfix[i]);
            strcat(tmp, c2);
            strcat(tmp, ')');
            push(tmp);
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the postfix expression: ");
    gets(postfix);
    toInfix(postfix);
    printf("\n%s\n", pop());
    return 0;
}
