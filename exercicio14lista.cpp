/*
Exercicio 14 da lista:

Fa�a um programa em C que simule um cron�metro com horas, minutos e segundos. A simula��o 
dever� mostrar no v�deo o cron�metro no seguinte formato HH: MM: SS. Inicialmente o cron�metro ser� 
zerado ( 00: 00: 00 ), sendo que os segundos come�ar�o a ser incrementados, depois os minutos e 
depois as horas. Lembre-se que a cada 60 segundos os minutos dever�o ser incrementados, depois os 
minutos voltar�o a zero. Quando as horas estiverem prestes a chegar em 24, o cron�metro dever� 
voltar a zero ( 00: 00: 00 ). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
int main()
{
    int s,m,h;
    int c, d;
    system("cls");
    for (h=0;h<=23;h=h+1)
    {
        for (m=0;m<=59;m=m+1)
        {
            for (s=0;s<=59;s=s+1)
            {
                printf("\n%d:%d:%d",h,m,s);
                Sleep(1000);
                system("cls");
            }
            printf("\n%d:%d:%d",h,m,s);
            system("cls");
        }
        printf("\n%d:%d:%d", h,m,s);
        system("cls");
    }
    getch();
}
