//ler um arquivo binario com inteiros, exatos 3 inteiros
//no caso, le myfile.bin e imprime os 3 inteiros

#include <stdio.h>

int main(void)
{
	FILE *fp;
	int i, j;
	
	fp = fopen("myfile.bin", "rb");
	
	if (fp != NULL)
	{
		for (i=0;i<3;i++)
		{
			fread(&j, sizeof(int), 1, fp);
			printf("%d\n", j);
		}
	}
	
	return 0;
}	
