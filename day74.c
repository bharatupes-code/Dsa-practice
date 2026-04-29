#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char names[1000][50];

    // Input names
    for (int i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }

    // Sort names lexicographically
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                char temp[50];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // Count votes
    int maxCount = 1, count = 1;
    char winner[50];
    strcpy(winner, names[0]);

    for (int i = 1; i < n; i++)
    {
        if (strcmp(names[i], names[i - 1]) == 0)
        {
            count++;
        }
        else
        {
            if (count > maxCount)
            {
                maxCount = count;
                strcpy(winner, names[i - 1]);
            }
            count = 1;
        }
    }

    // Check last candidate
    if (count > maxCount)
    {
        maxCount = count;
        strcpy(winner, names[n - 1]);
    }

    // Output result
    printf("%s %d", winner, maxCount);

    return 0;
}