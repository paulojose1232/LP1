//ler um arquivo binario com inteiros
//no caso, le myfile.bin e imprime os inteiros do arquivo até EOF

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int j;

    fp = fopen("myfile.bin", "rb");

    if (fp != NULL)
    {
        while (fread(&j, sizeof(int), 1, fp) == 1)
        // se fread ler um inteiro, retornará o valor 1 e então o while continua,
        // quando ler um EOF retornará 0 e assim sai do while
        {
            printf("%d\n", j);
        }
    }

    fclose(fp);

    return 0;
}