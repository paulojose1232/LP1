/*
Exercício 7 da lista:

(Programa está escrito com a turma de 10 alunos, para colocar 50 alunos observe os comentários)

Escreva um programa em C onde, se possa representar os nomes e as notas de alunos de um curso da 
universidade. O programa deverá imprimir os nomes dos cinco alunos que obtiverem as maiores notas 
acima da média da turma. Considerar que a turma tenha 50 alunos. Usar a estrutura multivalorada vista em 
sala de aula. 
*/
#include <stdio.h>
#include <string.h>
typedef 
struct aula
{
    char nome[15];
    float nota;
}
;
int main()
{
    struct aula registro[10]; /* Troque 10 por 50 */
    int cont, perfilaluno, cont1, cont2;
    int flag, continv;
    char outroaux[15];
    float nota, guardar1, nalunos, maioresnotas[10], aux, medianotas; /* Troque 10 por 50 */
    cont1 = 0;
    flag = 1;
    cont2 = 0;
    continv = 9;
    aux = 0;
    nalunos = 10.0; /* Troque 10.0 por 50.0 */
    guardar1 = 0.0;
    while (cont1 < nalunos)
    {
        printf("Aluno de numero %d\n", cont1+1);
        printf("Insira o nome do aluno: ");
        scanf("%s", registro[cont1].nome);
        printf("Insira a nota do aluno: ");
        scanf("%f", &registro[cont1].nota);
        guardar1 = guardar1 + registro[cont1].nota;
        cont1 = cont1+1;
    }
    cont1 = 0;
    medianotas = guardar1/nalunos;
    for (cont1=0;cont1<=9;cont1=cont1+1) /* Troque 9 por 49 */
    {
        for (cont2=cont1+1;cont2<=9;cont2=cont2+1) /*Troque 9 por 49 */
        {
            if (registro[cont1].nota>registro[cont2].nota)
            {
                strcpy(outroaux,registro[cont2].nome);
                strcpy(registro[cont2].nome,registro[cont1].nome);
                strcpy(registro[cont1].nome,outroaux);
                aux = registro[cont2].nota;
                registro[cont2].nota = registro[cont1].nota;
                registro[cont1].nota = aux;
            }
        }
    }
    printf("Notas ordenadas: ");
    for (cont1=0;cont1<=9;cont1=cont1+1) /*Troque 9 por 49 */
    {
        printf("%s, ", registro[cont1].nome);
        printf("%2.2f, ", registro[cont1].nota);
    }
    cont2 = 0;
    printf("\nA media vale: %2.2f", medianotas);
    for (cont1=0;cont1<=9;cont1=cont1+1) /*Troque 9 por 49 */
    {
        if (registro[continv].nota > medianotas)
        {
            maioresnotas[cont2] = registro[continv].nota;
            cont2 = cont2 + 1;
            continv = continv - 1;
            flag = flag+1;
        }
        if (flag == 6)
        {
        break;
        }
    }
    continv = 9; /*Troque 9 por 49 */
    printf("\nOs nomes e notas dos 5 melhores da turma acima da media foram: ");
    for (cont1=0;cont1<=4;cont1=cont1+1)
    {
        if (maioresnotas[cont1] != 0.0)
        {
        printf("Nome%d: %s, Nota: %2.2f; ", cont1+1, registro[continv].nome, maioresnotas[cont1]);
        continv = continv - 1;
        }
    }
    printf("\nAtencao (Menos de 5 notas citadas quer dizer que o restante das notas nao sao maiores que a media)");
    return 0;
}


