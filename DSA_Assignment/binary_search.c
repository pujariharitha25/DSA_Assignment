#include <stdio.h>

int main()
{
    int n, a[100], key;
    int low, high, mid, pos, comparisons;

    printf("Enter number of employee IDs: ");
    scanf("%d", &n);

    printf("Enter %d employee IDs in ascending order:\n", n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    comparisons = 0;
    pos = -1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        comparisons++;

        if(a[mid] == key)
        {
            pos = mid;
            break;
        }
        else if(key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(pos != -1)
        printf("Employee ID %d found at position %d\n", key, pos + 1);
    else
        printf("Employee ID %d is absent\n", key);

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}