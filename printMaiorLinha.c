// printar a maior frase
#include <stdio.h>
#include <string.h>

char longest[100];
char line[100];

int mygetline(void);
void copy(void);

int main()
{
    int len; int max;
    max = 0;
    while ((len = mygetline()) > 1)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0) /* there was a line */
        printf("A maior linha e: %s", longest);
    return 0;
}

int mygetline(void)
{
    int i;
    
    printf("Entre uma linha: ");
    fgets(line, 100, stdin);
    i = strlen(line);
    return i;
}

void copy(void)
{
    strcpy(longest, line);
}