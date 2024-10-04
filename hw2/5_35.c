//
//  n5_35.c
//  VMK
//
//  Created by Екатерина Китова on 03.10.2024.
//

#include <stdio.h>
#define n_x 25
#define n_y 40
void G(double mas[], int n, double *min, double *max)
{
    *min = mas[0];
    *max = mas[0];
    for (int i = 1; i < n; i++)
    {
        if (mas[i] < *min)
        {
            *min = mas[i];
        }
        if (mas[i] > *max)
        {
            *max = mas[i];
        }
    }
}
int main(void)
{
    double x[n_x],y[n_y];
    double min_x,max_x;
    double min_y,max_y;
    printf("x:\n");
    for (int i = 0; i < n_x; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }
    printf("\n y:\n");
    for (int i = 0; i < n_y; i++)
    {
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
    G(x, n_x, &min_x, &max_x);
    printf("For x:\n");
    printf("min: %lf\n", min_x);
    printf("max: %lf\n", max_x);
    G(y, n_y, &min_y, &max_y);
    printf("For y:\n");
    printf("min: %lf\n", min_y);
    printf("max: %lf\n", max_y);
    return 0;
}
