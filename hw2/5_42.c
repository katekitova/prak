//
//  n5_42.c
//  VMK
//
//  Created by Екатерина Китова on 03.10.2024.
//

#include <stdio.h>
void f(unsigned int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        unsigned char up_b = (arr[i] >> 24) & 0xFF;
        if ((up_b >= 'A' && up_b <= 'Z') || (up_b >= 'a' && up_b <= 'z'))
        {
            arr[i] &= 0x00FFFFFF;
        }
    }
}
int main(void)
{
    int n;
    printf("len of arr: ");
    scanf("%d", &n);
    unsigned int arr[n];
    printf("write elements with format 0x41FFFFFF:\n");
    for (int i = 0; i < n; i++)
    {
        printf("element %d: ", i + 1);
        scanf("%x", &arr[i]);
    }
    printf("before:\n");
    for (int i = 0; i < n; i++)
    {
        printf("0x%x\n", arr[i]);
    }
    f(arr, n);
    printf("\nafter:\n");
    for (int i = 0; i < n; i++)
    {
        printf("0x%x\n", arr[i]);
    }
    return 0;
}
//очень ОЧЕНЬ странно работает, иногда и не работает(((((
