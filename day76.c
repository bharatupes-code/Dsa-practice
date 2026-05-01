#include <stdio.h>

int maxLenZeroSum(int arr[], int n)
{
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == 0)
            {
                int len = j - i + 1;
                if (len > max_len)
                {
                    max_len = len;
                }
            }
        }
    }

    return max_len;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSum(arr, n);
    printf("Length of longest subarray with sum 0 = %d", result);

    return 0;
}