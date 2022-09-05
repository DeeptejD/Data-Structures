#include<stdio.h>
#include <stdlib.h>
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
        printf("Enter the accession number: ");
        scanf("%d", &lib->accessionNumber);
        getchar();
        printf("Enter title: ");
        gets(lib->title);
        printf("Enter author: ");
        getchar();
        gets(lib->author);
        printf("Enter price: ");
        scanf("%f", &lib->price);
    }
    printf("%d book(s) added succesfully\n", numberOfBooks);
    *count+=numberOfBooks;
}



int main(int argc, char const *argv[])
{
    int count=0;
    struct Library lib[50];

    printf("===========\nABC Library\n===========\n");
    while(1){
        printf("Enter the number corresponding to the choice of operation\n");
        int choice;
        printf("1. Add book info\n2. Display Book info\n3. List all the books of a given author\n");
        printf("4. List the title of a specified book\n5. List the count of the books\n6. List the books in the order of accession number\n7. exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // add book info
            addBookInfo(lib, &count);
            break;
        
        case 2:
            // display book info
            break;
        
        case 3:
            //list all the books by a gievn author
            break;
        
        case 4:
            //list the title of the specified book
            break;
        
        case 5:
            //list th count of books
            break;
        
        case 6:
            // List the books in the order of accession number
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
