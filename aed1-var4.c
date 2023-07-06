//Escreva uma função que recebe um vetor L de caracteres, um inteiro N,  e 
//retorne um valor lógico indicando se a cadeia formada pelos N primeiros 
//elementos de L é um palíndromo.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool Palindromo(char L[], int N) {
    int inicio = 0;
    int fim = N - 1;
    while (inicio < fim) {
        if (L[inicio] != L[fim]) {
            return false;
        }
        inicio++;
        fim--;
    }
    return true;
}

// Funcao principal para teste
int main() {
    char L[] = "radarmovel";
    int N = 5;
    bool ehpalindromo = Palindromo(L, N);
    if (ehpalindromo) {
        printf("Os primeiros %d elementos formam um palíndromo.\n", N);
    } else {
        printf("Os primeiros %d elementos não formam um palíndromo.\n", N);
    }
    return 0;
}
