//Crio um arquivo chamado myfile.bin e gravo nele 3 inteiros

#include <stdio.h>

int main(void)
{
    FILE * pF;
    int vInt[]={11, 21, 31};
    pF = fopen ("myfile.bin", "wb"); //wb = Write Binary - Abro para escrever em modo binário
    fwrite (vInt, sizeof(int), 3, pF);
    fflush(pF);
    fclose(pF);
    return 0;
}