//Escreva uma função que recebe um vetor L de inteiros, um inteiro N,  um inteiro x, e retorne um valor lógico indicando se x ocorre entre os primeiros N elementos de L.
//Respostas em C:
#include <stdio.h>
#include <stdbool.h>

bool verifica(int L[], int N, int x) {
    for (int i = 0; i < N; i++) {
        if (L[i] == x) {
            return true;
        }
    }
    return false;
}

// Funcao principal para teste
int main() {
    int L[] = {6, 22, 13, 4, 45};
    int N = 3;
    int x = 22;
    bool ocorre = verifica(L, N, x);
    if (ocorre) {
        printf("%d ocorre entre os %d primeiros elementos de L.\n", x, N);
    } else {
        printf("%d não ocorre entre os %d primeiros elementos de L.\n", x, N);
    }
    return 0;
}
