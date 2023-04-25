/******************************************************************************
Exercicio 6 da lista:

odometro = distancia percorrida em quilometros.
6) Um motorista acaba de retornar de um feriado prolongado. Em cada parada de reabastecimento ele
registrou a leitura de seu odômetro, a quantidade de gasolina comprada (suponha que ele tenha enchido o
tanque cada vez) e o preço pago. Além disso, suponha também que ele tenha enchido o tanque antes de
partir e imediatamente após retornar. Escreva um programa em C para ler, em primeiro lugar, o número total
de reabastecimentos feitos (incluindo o primeiro e o último) e, a seguir, os dados relativos à compra de
gasolina e calcular :
a) a quilometragem obtida por litro de gasolina entre cada par de paradas de reabastecimento;
b) a quilometragem obtida por litro de gasolina em toda a viagem
c) custo do combustível por quilometro rodado em toda a viagem

PLano: 
*******************************************************************************/
#include <stdio.h>
typedef
struct viagem
{
    int abastecimento;
    float quilometros;
    float litros;
    float preco;
}
;
int main()
{
    struct viagem registro[10];
    float preco, precoporkm, kmporltotal, kmporl, guardar2, guardar1, guardar3, reabas;
    float quilometros, litros, abastecimento;
    int cont;
    cont = 0;
    guardar1 = 0;
    guardar2 = 0;
    guardar3 = 0;
    printf("Insira o numero de abastecimentos (máximo de 10): ");
    scanf("%f", &reabas);
    while (cont < reabas)
    {
        registro[cont].abastecimento = cont+1;
        
        printf("Abastecimento %d\n", registro[cont].abastecimento);
        printf("Insira o valor do odometro em quilometros: ");
        scanf("%f", &registro[cont].quilometros);
        printf("Insira a quantidade de gasolina para encher o tanque em litros: ");
        scanf("%f", &registro[cont].litros);
        printf("Insira o preço pago para encher o tanque em reais: ");
        scanf("%f", &registro[cont].preco);
        kmporl = registro[cont].quilometros/registro[cont].litros;
        printf("Neste abastecimento o veículo realizou %2.3f quilometros por litro.\n", kmporl);
        guardar1 = guardar1+registro[cont].quilometros;
        guardar2 = guardar2+registro[cont].litros;
        guardar3 = guardar3+registro[cont].preco;
        
        cont = cont+1;
    }
    kmporltotal = guardar1/guardar2;
    precoporkm = guardar3/guardar1;
    printf("Durante toda a viagem, o carro fez %2.3f quilometros por litro.\n", kmporltotal);
    printf("O custo do combustível por quilometro foi de %2.2f reais.", precoporkm);
    return 0;
}




