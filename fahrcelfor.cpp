
#include <stdio.h>
float conversor(float Celsius)
{
    return 1.8*(Celsius) + 32;
}
int main()
{
    float far, i;
    printf("Celsius\t Fahrenheit\n");
    for (i = -10.0; i<= 50.0; i = i + 10.0){
        printf("%f\t%f\n",i, conversor(i));
    }
    return 0;
}
