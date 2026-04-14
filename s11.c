#include <stdio.h>

struct Book
{
    char title[50];
    char author[50];
    float price;
};

int main()
{
    struct Book b[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter Book %d details:\n", i + 1);
        scanf("%s %s %f", b[i].title, b[i].author, &b[i].price);
    }

    printf("\nBook Details:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %.2f\n", b[i].title, b[i].author, b[i].price);
    }
}