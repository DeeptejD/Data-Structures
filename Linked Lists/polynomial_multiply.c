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
    
    return 0;
}

struct node *create(struct node *start){
    struct node *tmp, *ptr;
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    for(i=0;i<num;i++){
        tmp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient: ");
        scanf("%d", &tmp->coeff);
        printf("Enter the exponent: ");
        scanf("%d", &tmp->exp);
        tmp->next=NULL;
        if(start==NULL)
            start=tmp;
        else{
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=tmp;
        }
    }
    return start;
}

void display(struct node *start)
{
    {
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
    }
}

struct node *multiply(struct node *start1, struct node *start2){
    struct node *start3, *tmp, *ptr;
}