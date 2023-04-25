/*
Exercicio 14 da lista:

Faça um programa em C que simule um cronômetro com horas, minutos e segundos. A simulação 
deverá mostrar no vídeo o cronômetro no seguinte formato HH: MM: SS. Inicialmente o cronômetro será 
zerado ( 00: 00: 00 ), sendo que os segundos começarão a ser incrementados, depois os minutos e 
depois as horas. Lembre-se que a cada 60 segundos os minutos deverão ser incrementados, depois os 
minutos voltarão a zero. Quando as horas estiverem prestes a chegar em 24, o cronômetro deverá 
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
