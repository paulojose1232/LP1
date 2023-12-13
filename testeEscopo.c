// programa para teste de escopo. Este programa é escrito em C, e C possui escopo estático. Para saber o valor de x
// considerando escopo estático, deve-se olhar o bloco em que o valor está declarado. Neste programa, a função getx()
// imprime o valor de x, mas não faz nenhum tipo de declaração de x, então qual será o valor de x? olha-se o bloco
// "anterior" de getx(), que no caso é global pois a declaração de getx() está fora da função main. Como no bloco
// global o valor declarado de x é 5, o valor a ser impresso será 5. 
// Considerando escopo dinâmico, deve-se olhar as chamadas na pilha. Primeiro x vale 5, depois quando entra em main
// x passa a valer 10, então o valor de 5 que está na pilha será substituido pelo 10. Agora, rodando a função run()
// x passa a valer 20, e então finalmente imprimimos x, e então o valor impresso por x será 20 pois 20 foi o último
// valor de x a ser passado pela pilha.
// Deve-se prestar atenção que o valor que é passado na pilha só vale durante a execução da função, caso a função
// seja finalizada este valor é removido da pilha.

#include <stdio.h>

int x = 5;

void getx() {
    printf("%d", x);
}

void run() {
    int x = 20;
    getx();
}

int main(void) {
    int x = 10;
    // se declararmos a função getx() aqui e trocar abaixo run() por getx() o valor impresso de x seria 10.
    run();

    return 0;
}
