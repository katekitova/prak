//
//  n3_50a.c
//  VMK
//
//  Created by Екатерина Китова on 24.09.2024.
//

#include <stdio.h>
int main(void)
{
    printf("Write sequence which ends with '$':\n");
    char c;
    int cnt = 0;
    int flag = 0;
    char buf[100];
    int i = 0;
    while ((c = getchar()) != '$')
    {
        if (c >= '0' && c <= '9')
        {
            if (flag)
            {
                cnt++;
                if (cnt > 2)
                {
                    continue;
                }
            }
            else
            {
                cnt = 1;
            }
        }
        else
        {
            flag = 0;
            cnt = 0;
        }
        if (c == '.')
        {
            flag = 1;
        }
        buf[i++] = c;
    }
    buf[i] = '\0';
    printf("New sequence: %s\n", buf);
    return 0;
}
