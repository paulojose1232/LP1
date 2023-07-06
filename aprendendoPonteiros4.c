#include <stdio.h>
/*
void strcpy(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void strcpy(char *s, char *t)
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}
*/
void strcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}
/*
void strcpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}
*/
int main(void)
{
    char str1[10] = "gilson";
    char str2[10] = "maria";

    printf("str1=='%s' str2=='%s'\n", str1, str2);
    strcpy(str1, str2);
    printf("str1=='%s' str2=='%s'\n", str1, str2);

    return 0;
}

