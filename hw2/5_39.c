//
//  n5_39.c
//  VMK
//
//  Created by Екатерина Китова on 03.10.2024.
//

#include <stdio.h>
void left(int arr[], int m, int n)
{
    n = n % m;
    int temp[m];
    for (int i = 0; i < m; i++)
    {
        temp[i] = arr[(i + n) % m];
    }
    for (int i = 0; i < m; i++)
    {
        arr[i] = temp[i];
    }
}
int main(void)
{
    int m, n;
    printf("m:");
    scanf("%d", &m);
    int arr[m];
    if (m <= 0)
    {
        printf("error\n");
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("n:");
    scanf("%d", &n);
    if (n <= 0 || n >= m)
    {
        printf("error\n");
        return 0;
    }
    left(arr, m, n);
    printf("array after left shift by %d positions:\n", n);
    for (int i = 0; i < m; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}
