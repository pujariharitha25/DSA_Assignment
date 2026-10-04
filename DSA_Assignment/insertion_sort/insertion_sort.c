#include <stdio.h>

int main()
{
    int n, a[100], shifts = 0;
    int key, j;

    printf("Enter number of marks: ");
    scanf("%d", &n);

    printf("Enter %d marks:\n", n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
            shifts++;
        }

        a[j + 1] = key;

        printf("After pass %d: ", i);
        for(int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }

    printf("Final sorted list: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal element shifts: %d\n", shifts);

    return 0;
}