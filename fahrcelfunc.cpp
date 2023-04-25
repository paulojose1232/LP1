#include <stdio.h>
float converte(float x)
{
    return 1.8*x+32.0;
}
int main()
{
    printf("Celsius\tFahrenheit\n");
    printf("%f\t%f\n",-10.0,converte(-10.0));
    printf("%f\t%f\n",0.0,converte(0.0));
    printf("%f\t%f\n",10.0,converte(10.0));
    printf("%f\t%f\n",20.0,converte(20.0));
    printf("%f\t%f\n",30.0,converte(30.0));
    printf("%f\t%f\n",40.0,converte(40.0));
    printf("%f\t%f\n",50.0,converte(50.0));
    printf("%f\t%f\n",60.0,converte(60.0));
}
