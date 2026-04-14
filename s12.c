#include <stdio.h>

struct Address
{
    char city[50];
    int pin;
};

struct Employee
{
    char name[50];
    int id;
    struct Address addr;
};

int main()
{
    struct Employee e;

    printf("Enter name, ID, city, pin:\n");
    scanf("%s %d %s %d", e.name, &e.id, e.addr.city, &e.addr.pin);

    printf("\nEmployee Details:\n");
    printf("%s %d %s %d\n", e.name, e.id, e.addr.city, e.addr.pin);
}