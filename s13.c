#include <stdio.h>

union Data
{
    float temp;
    int humidity;
};

int main()
{
    union Data d;

    d.temp = 36.5;
    printf("Temperature: %.2f\n", d.temp);

    d.humidity = 80;
    printf("Humidity: %d\n", d.humidity);

    printf("Temperature after humidity stored: %.2f\n", d.temp);
}