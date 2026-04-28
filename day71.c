#include <stdio.h>
#include <string.h>

#define MAX 100
#define EMPTY -1

int table[MAX];

// Hash function
int hash(int key, int m)
{
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m)
{
    int h = hash(key, m);

    for (int i = 0; i < m; i++)
    {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY)
        {
            table[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using quadratic probing
void search(int key, int m)
{
    int h = hash(key, m);

    for (int i = 0; i < m; i++)
    {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY)
        {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key)
        {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main()
{
    int m, q;
    scanf("%d", &m); // size of hash table
    scanf("%d", &q); // number of operations

    // Initialize table
    for (int i = 0; i < m; i++)
    {
        table[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < q; i++)
    {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0)
        {
            insert(key, m);
        }
        else if (strcmp(operation, "SEARCH") == 0)
        {
            search(key, m);
        }
    }

    return 0;
}