#include <stdio.h>
int main()
{
    int x,y,z,a,cont;
    y=0;
    z=0;
    a= -99999;
    for(cont=1;cont<=3;cont=cont+1)
    {
        scanf("%d", &x);
        if ((x%2)==0)
        {
            y = x;
            if (y>=a)
            {
                a = y;
            }
        }
    }
    if (a != -99999)
    {
        printf("O maior numero par lido e %d",a);
    }
    else
    {
        printf("Nenhum numero inserido e par");
    }
    return 0;
}
