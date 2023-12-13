#include <stdio.h>
int main()
{
int a = 0, b = 3, c = 10;
void alpha() {
int a = 5, c = 11;
c = b + 3;
void beta() {
printf("a: %d b: %d c: %d\n", a, b, c);
}
beta();
}
alpha();
beta(); // se eu remover este beta(); o codigo conseguirá ser compilado e funcionará sem problemas
}