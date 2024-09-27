//
//  n5_36.c
//  VMK
//
//  Created by Екатерина Китова on 24.09.2024.
//

#include <stdio.h>

void func(char *str)
{
    int len = 0;
    while (str[len] != '\0') 
    {
        len++;
    }
    char new_str[len + 1];
    int even = 0;
    int odd = (len + 1) / 2;

    for (int i = 0; i < len; i += 2) 
    {
        new_str[even++] = str[i];
    }
    for (int i = 1; i < len; i += 2) 
    {
        new_str[odd++] = str[i];
    }
    new_str[len] = '\0';
    for (int i = 0; i <= len; i++) 
    {
        str[i] = new_str[i];
    }
}

int main(void)
{
    char str[100];
    printf("Write string: ");
    fgets(str, sizeof(str), stdin); //чтение строки
    for (int i = 0; i < 100; i++) //удаляю последний символ
    {
        if (str[i] == '\n')
           {
               str[i] = '\0';
               break;
           }
    }
    func(str);
    printf("New string: %s\n", str);
    return 0;
}
