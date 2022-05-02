#include<stdio.h>
#include <string.h>
#include<stdlib.h>
//defining a structure
struct stock
{
    char book_name[50];
    char first_author_name[50];
    int book_id; //4 digits
    int pages;
    char book_type[2]; //fx,ex,sx,jx for f-fiction, e-engineering, s-science and j-journal OR fe for f-fiction and e-engineering together
    char book_category[100]; //first 4 digits for book-id + book type + first 2 char of book_name
    //Ex: 1001 + "fi + en" + ma for the book "maths for engineers" = 1001fienma
};

int main()
{
    int n; // number of books
    printf("\nEnter number of books: ");
    scanf("%d", &n); //taking total number of books
    struct stock bookStock[n]; //defining array of book stock

    for(int i=0; i<n; i++)
    {
        //taking input for books
        printf("Enter book name for book_%d: ",i+1);
        scanf("%s", &bookStock[i].book_name);       //taking input for book name
        printf("Enter 4 digit book ID for book_%d: ",i+1);
        scanf("%d", &bookStock[i].book_id);         //taking input for book ID
        printf("Enter number of pages for book_%d: ",i+1);
        scanf("%d", &bookStock[i].pages);           //taking input for book pages
        printf("Enter type for book_%d (fx,ex,sx,jx only!!): ",i+1);
        scanf("%s", &bookStock[i].book_type);       //taking input for book typpe
        printf("\n");
    }
    //calling assign category
    assignBookCategory(bookStock,n);
    //calling listBooks for display
    listBooks(bookStock,n);
    return 0;
}

void assignBookCategory(struct stock *bookStock, int n)
{
    for(int i=0; i<n; i++)
    {
        char bookId[4]; //array for book id
        int id = bookStock[i].book_id; // getting book id
        itoa(id, bookId, 10); //converting int book id to string

        strcat(bookStock[i].book_category, bookId); //concatinating bookId to book_category
        strcat(bookStock[i].book_category, bookStock[i].book_type); //concatinating book_type to book_category
        strncat(bookStock[i].book_category,bookStock[i].book_name, 2); //concatinating book_name to book_category
    }

}
void listBooks(struct stock *bookStock, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\n%d", bookStock[i].book_id);
        printf("\n%s", bookStock[i].book_type);
        printf("\n%s", bookStock[i].book_category);

    }
}
