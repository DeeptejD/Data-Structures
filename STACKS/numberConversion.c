#include <stdio.h>
#define MAX 100
char stack[MAX];
int top = -1;

int isFull()
{
    // returns 1 if stack is full
    if (top == MAX - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    // returns 1 if stack is empty
    if (top == -1)
        return 1;
    return 0;
}

void toBinary(int n){
        top=-1;
        while (n>0)
        {
            stack[++top]=n%2;
            n/=2;
        }
        
}

void toHex(int n){
    top=-1;
    while (n>0)
    {
        if(n%16>9)
            stack[++top]=(n%16+55);
        if(n%16<10)
            stack[++top]=n%16+48;
        n/=16;
    }
    
}

void display()
{
    if(!isEmpty){
        printf("Stack underflow\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%1C", stack[i]);
    }
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        printf("\nEnter the operation\n1. Decimal to binary\n2. Decimal to hexadecimal\n3. display\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:{
            int n;
            printf("Enter the number in decimal: ");
            scanf("%d", &n);
            toBinary(n);
            printf("%d is binary is: ", n);
            display();
            top=-1;
            break;
            }
        
        case 2:{
            int n;
            printf("Enter the number in decimal: ");
            scanf("%d", &n);
            toHex(n);
            display();
            top=-1;
            break;
        }
        }
    
}
return 0;
}
