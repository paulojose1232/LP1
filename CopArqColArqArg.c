//Ler um arquivo txt, copia o texto e depois
//cria um novo arquivo txt e cola o texto nele
//rodar com argumento ou seja
//exemplo: ./arquivo teste.txt teste2.txt

#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, char *argv[])
{
   FILE *fp1, *fp2;
   int ind;
    if (argc == 1) /* no args; copy standard input */
    filecopy(stdin, stdout);
    else
    {
        for (ind=1; ind < argc; ind++)
        {
            if ((fp1 = fopen(argv[1], "r")) == NULL)
            {
                printf("cat: can't open %s\n", argv[ind]);
                return 1;
            }
            else 
            {
                (fp2 = fopen(argv[2], "w"));
                filecopy(fp1, fp2);
                fflush(fp2);
                fclose(fp1);
                fclose(fp2);
            }
        }
    }
    return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c, stop = 0;
    while (stop!=1)
    {
        c = getc(ifp);
        if (c == EOF)
            stop = 1;
        else 
        {
            putc(c, ofp); 
            if (c == '\n')
                stop = 1; 
        }
    }
}