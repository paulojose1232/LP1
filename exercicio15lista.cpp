/******************************************************************************
Exerc�cio 15 da lista:

O Departamento de tr�nsito do estado anotou dados de acidentes de tr�nsito no �ltimo ano. Para cada 
motorista envolvido no acidente, tem-se as seguintes informa��es: 
- Ano de nascimento; 
- Sexo (M - Masculino, F - Feminino) 
- Proced�ncia ( 0 - Capital, 1 - Interior, 2 - Outro estado); 
Fa�a um programa em C que : 
a) Calcule a porcentagem de motoristas com menos de 21 anos; 
b) Calcule quantas mulheres s�o da capital; 
c) Calcule quantos motoristas do interior do estado tem idade maior que 60 anos; 
d) Verifique se existe alguma mulher com idade maior que 60 anos; 
*******************************************************************************/
#include <stdio.h>
typedef

struct departamento
{
    int ano;
    char sexo;
    int local;
};

int main()
{
    struct departamento dados[5];
    int cont1, cont2, aux, guardar2, guardar3, guardar4;
    float porcent, guardar1;
    cont1 = 0;
    guardar3 = 0;
    guardar1 = 0.0;
    guardar2 = 0;
    guardar4 = 0;
    while (cont1 <= 4)
    {
        printf("Motorista de numero %d.\n", cont1+1);
        printf("Ano de nascimento: ");
        scanf("%d", &dados[cont1].ano);
        printf("G�nero (M para masculino e F para feminino): ");
        scanf("%s", &dados[cont1].sexo);
        printf("Procedencia(0 para Capital, 1 para interior e 2 para outro estado): ");
        scanf("%d", &dados[cont1].local);
        cont1 = cont1 + 1;
    }
    
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        if (dados[cont1].local == 1 && dados[cont1].ano < 1963)
        {
            guardar3 = guardar3 + 1;
        }
        if (dados[cont1].local == 0 && dados[cont1].sexo == 'F')
        {
            guardar2 = guardar2 + 1;
        }
        if (dados[cont1].sexo == 'F' && dados[cont1].ano < 1963)
        {
            guardar4 = guardar4 + 1;
        }
        if (dados[cont1].ano > 2001)
        {
            guardar1 = guardar1 + 1;
        }
    }
    porcent = (guardar1/5)*100;
    printf("\nN�mero de mulheres da capital: %d\n", guardar2);
    printf("N�mero de motoristas do interior com mais de 60 anos: %d\n", guardar3);
    printf("N�mero de mulheres com mais de 60 anos: %d\n", guardar4);
    printf("Porcentagem de motoristas com menos de 21 anos: %f porcento.\n", porcent);
}
