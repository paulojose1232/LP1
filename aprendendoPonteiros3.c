#include <stdio.h>
#include <string.h>

/*
 atoi: convert s to integer
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}
*/

int atoi(char *s)
{
    int i, n;
    n = 0;
    for (i = 0; *(s+i) >= '0' && *(s+i) <= '9'; ++i)
    {
        n = 10 * n + (*(s+i) - '0');
    }

    return n;
}

int main(void)
{
    char str[10] = "1234b";
    int n, i;

    printf("Quem é str %p\n", str);
    printf("Quem é *str? %c\n", *str);
    printf("Quem é str+1 %p\n", str+1);
    printf("Quem é *(str+1)? %c\n", *(str+1));
    /*
    printf("str é: %s\n", str); // str == &str[0]
    i = 1;
    printf("O caracter str[%d] é: %c\n", i, str[i]); // str[0] == *str
    */
    n = atoi(str);
    printf("O valor inteiro é: %d\n", n);

    return 0;
}
