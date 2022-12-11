#include <stdio.h>

struct node
{
    int info;
    struct node *link;
} *start = NULL;

int large_dig(struct node *start)
{
    struct node *p = start;
    int largest = 0, n_largest = 0;
    while (p != NULL)
    {
        if (p->info > largest)
            largest = p->info;
        p = p->link;
    }
    while (largest != 0)
    {
        n_largest++;
        largest /= 10;
    }
    return n_largest;
}

int digit(int number, int k)
{
    int dig = 0;
    for (int i = 1; i <= k; i++)
    {
        dig = number % 10;
        number /= 10;
    }
    return dig;
}

void radix_sort()
{
    int dig, l_sig, m_sig;
    l_sig = 1;
    struct node *p, *rear[10], *front[10];
    m_sig = large_dig(start);
    int k;
    for (k = l_sig; k <= m_sig; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            rear[i] = NULL, front[i] = NULL;
        }
        for (p = start; p != NULL; p = p->link)
        {
            dig = digit(p->info, k);
            if (front[dig] == NULL)
                front[dig] = p;
            else
                rear[dig]->link = p;
            rear[dig] = p;
        }
        int i = 0;
        while (front[i] == NULL)
            i++;
        start = front[i];
        while (i < 9)
        {
            if (rear[i + 1] != NULL)
                rear[i]->link = front[i + 1];
            else
                rear[i + 1] = rear[i];
            i++;
        }
        rear[9]->link == NULL;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int info;
        printf("Enter the number: ");
        scanf("%d", &info);
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = info;
        temp->link = NULL;
        if (start = NULL)
            start = temp;
        else
        {
            struct node *p = start;
            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
    radix_sort();
    // display
    return 0;
}
