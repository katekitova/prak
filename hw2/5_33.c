//
//  n5_33.c
//  VMK
//
//  Created by Екатерина Китова on 03.10.2024.
//

#include <stdio.h>
#include <string.h>
#define N 256
void f(char *s, int n, char *res, int *cnt)
{
    int cnt_str[N] = {0};
    int min_cnt = n + 1;
    char min_char = '\0';
    
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            cnt_str[(unsigned char)s[i]]++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (cnt_str[i] > 0 && cnt_str[i] < min_cnt)
        {
            min_cnt = cnt_str[i];
            min_char = (char)i;
        }
        else if (cnt_str[i] == min_cnt && (char)i < min_char)
        {
            min_char = (char)i;
        }
    }
    *res = min_char;
    *cnt = min_cnt;
}
int main(void)
{
    char str[] = "aaaaaccbb";
    char res;
    int cnt;
    size_t n = strlen(str);
    f(str, (int)n, &res, &cnt);
    if (res != '\0')
    {
        printf("'%c': %d\n", res, cnt);
    }
    else
    {
        printf("error \n");
    }
    return 0;
}
