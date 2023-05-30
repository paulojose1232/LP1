//puts.c
#include <stdio.h>

int main()
{
    char str[20];
    int i;



    for (i=0; i<=20; i++)
    {
        printf("%d", str[i]);

    }

        printf("\n");

        fgets(str, 20, stdin);

        for (i=0; i<20; i++)
        {
            printf("%d", str[i]);
        }
        printf("\n");

        puts(str);


    return 0;

}