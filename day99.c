#include <stdio.h>
#include <stdlib.h>

// Structure for car
struct Car
{
    int position;
    float time;
};

// Comparator: sort by position descending
int compare(const void *a, const void *b)
{
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;
    return c2->position - c1->position;
}

// Function to count fleets
int carFleet(int target, int position[], int speed[], int n)
{
    struct Car cars[n];

    // Step 1: Compute time for each car
    for (int i = 0; i < n; i++)
    {
        cars[i].position = position[i];
        cars[i].time = (float)(target - position[i]) / speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    float maxTime = 0;

    // Step 3: Traverse
    for (int i = 0; i < n; i++)
    {
        if (cars[i].time > maxTime)
        {
            fleets++;               // new fleet
            maxTime = cars[i].time; // update slowest time
        }
        // else joins existing fleet
    }

    return fleets;
}

// Main function
int main()
{
    int n, target;

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}