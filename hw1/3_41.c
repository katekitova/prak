//
//  n3_41.c
//  VMK
//
//  Created by Екатерина Китова on 24.09.2024.
//

#include <stdio.h>
#include <math.h>

int main(void)
{
    double eps, prev_a = 0.0;
    double a = sqrt(0.5);
    double two_pi = a;
    printf("Eps: ");
    scanf("%lf", &eps);
    while (fabs(a - prev_a) > eps) 
    {
        prev_a = a;
        a = sqrt(0.5 + 0.5 * prev_a);
        two_pi *= a;
    }
    long double pi = 2.0 / two_pi;
    printf("Result: %Lf\n", pi);
    return 0;
}
