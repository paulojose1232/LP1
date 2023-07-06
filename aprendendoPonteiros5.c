#include <stdio.h>

int main(void)
{
    char str[10] = "gilson";
    char* p;
    int i;

    printf("p==%p str==%p\n", p, str);
    p = str;
    printf("p==%p str==%p\n", p, str);

    for (i=0; i <10; i++)
        printf("*(p+%d)==%c\n", i, *(p+i)); // *(p+i) == p[i]

    return 0;
}
