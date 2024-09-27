//
//  n3_27.c
//  VMK
//
//  Created by Екатерина Китова on 24.09.2024.
//

#include <stdio.h>

int main(void)
{
    int n;
    int k = 0;
    int m = 1;
    scanf("%d", &n);
    while(n!=0)
    {
        if (((n%10) != 0) && ((n%10) != 5))
        {
            k += (n%10)*m;
            m *= 10;
        }
        n /= 10;
    }
    printf("new number: %d \n", k);
    return 0;
}
