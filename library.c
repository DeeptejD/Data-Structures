#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct Library
{
    int accessionNumber;
    char title[50];
    char author[30];
    float price;
    int flag;
};


void addBookInfo(struct Library lib[], int *count){
    if (*count>=50){
        printf("Library is full!\n");
        return;
    }
    printf("How many books do you want to add?\n");
    int numberOfBooks;
    do
    {
        printf("Enter the number of books you want to add: \n");
        scanf("%d", &numberOfBooks);
    } while (numberOfBooks+(*count)>=50);
    
    for (int i = *count; i < *count+numberOfBooks; i++)
    {
        printf("-------------------------\nEnter the accession number: ");
        scanf("%d", &lib[i].accessionNumber);
        getchar();
        printf("Enter title: ");
        gets(lib[i].title);
        printf("Enter author: ");
        gets(lib[i].author);
        printf("Enter price: ");
        scanf("%f", &lib[i].price);
        printf("Is the books issued?\n");
        do
        {
            printf("Enter '0' for NOT issued or '1' for issued\n");
            scanf("%d", &lib[i].flag);
        } while (lib[i].flag>1 || lib[i].flag<0);
        
    }
    printf("\n%d book(s) added succesfully\n\n", numberOfBooks);
    *count+=numberOfBooks;
}

void displayBookInfo(struct Library lib[], int *count){
    if(count==0){
        printf("The Library is empty\n");
        return;
    }
    for(int i=0;i<(*count);i++){
        printf("-----------------------\nAccession number: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\n", lib[i].accessionNumber, lib[i].title, lib[i].author, lib[i].price);
        if(lib[i].flag){
            printf("The books has been issued\n");
        } else{
            printf("The book has not been issued\n-----------------------\n");
        }
    }
}

void listallauth(struct Library lib[], int *count){
    char auth[30];
    getchar();
    printf("Enter the name of the author: ");
    gets(auth);
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(auth, lib[i].author)==0)     
        {
            printf("-----------------------\nAccession number: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\n", lib[i].accessionNumber, lib[i].title, lib[i].author, lib[i].price);
            if(lib[i].flag){
                printf("The books has been issued\n");
            } else{
                printf("The book has not been issued\n-----------------------\n");
            }
        }
        
    }
    
}

void listTitle(struct Library lib[], int *count){
    int acnum, flag=0;
    printf("Enter the accession number: ");
    scanf("%d", &acnum);
    for(int i=0;i<*count;i++){
        if(lib[i].accessionNumber==acnum){
            printf("\nTitle: %s\n", lib[i].title);
            flag=1;
        }
    }
    if(flag==0)
        printf("No book found with that accession number\n");
}

void listInAccNum(struct Library lib[], int *count){
    for(int i=0;i<*count;i++){
        for(int j=i+1;j<*count;j++){
            if(lib[j].accessionNumber<lib[i].accessionNumber){
                int temp;
                temp=lib[i].accessionNumber;
                lib[i].accessionNumber=lib[j].accessionNumber;
                lib[j].accessionNumber=temp;
            }
        }
    }
    displayBookInfo(lib, count);
}

int main(int argc, char const *argv[])
{
    int count=0;
    struct Library lib[50];

    printf("===========\nABC Library\n===========\n");
    while(1){
        printf("\nEnter the number corresponding to the choice of operation\n");
        int choice;
        printf("1. Add book info\n2. Display Book info\n3. List all the books of a given author\n");
        printf("4. List the title of a specified book\n5. List the count of the books\n6. List the books in the order of accession number\n7. exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // working
            addBookInfo(lib, &count);
            break;
        
        case 2:
            // working
            displayBookInfo(lib, &count);
            break;
        
        case 3:
            // working
            listallauth(lib, &count);
            break;
        
        case 4:
            //working
            listTitle(lib, &count);
            break;
        
        case 5:
            //list the count of books
            printf("There are %d books in the Library\n", count);
            break;
        
        case 6:
            // List the books in the order of accession number
            listInAccNum(lib, &count);
            break;
        
        case 7:
            exit(1);
        
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
