#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
printf("%d\n", sizeof(int));
printf("%d\n", sizeof(void));
printf("%d\n", sizeof(double));
 return 0;
}
*/
/*
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
*/
void copy(char *to, char *from)
{
    int i;
    i = 0;
    while ((*(to+i) = *(from+i)) != '\0')
        ++i; // i++ também funciona
}

int main(void)
{
    char str1[10] = "gilson";
    char str2[10] = "maria";

    printf("str1 == %s, str2 == %s\n", str1, str2); // poderia usar &str[0] invés de str1, dá no mesmo
    copy(str2, str1);
    printf("str1 == %s, str2 == %s\n", str1, str2);


    return 0;
}
