#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fread(str, 1, 100, stdin);
    int i;
for (i=0;i<strlen(str);i++)
    if(str[i] == '\0')
{
    printf("\\0");
}
else if(str[i] == ' ')
{
    printf(" ");
}
else if(str[i] == '\v')
{
    printf("\\v");
}
else if(str[i] == '\a')
{
    printf("\\a");
}
else if(str[i] == '\b')
{
    printf("\\b");
}
else if(str[i] == '\f')
{
    printf("\\f");
}
else if(str[i] == '\n')
{
    printf("\\n");
}
else if(str[i] == '\r')
{
    printf("\\r");
}
else if(str[i] == '\t')
{
    printf("\\t");
}
else if(str[i] == 'a')
{
    printf("a");
}
else if(str[i] == 'b')
{
    printf("b");
}
else if(str[i] == 'c')
{
    printf("c");
}
else if(str[i] == 'd')
{
    printf("d");
}
else if(str[i] == 'e')
{
    printf("e");
}
else if(str[i] == 'f')
{
    printf("f");
}
else if(str[i] == 'g')
{
    printf("g");
}
else if(str[i] == 'h')
{
    printf("h");
}
else if(str[i] == 'i')
{
    printf("i");
}
else if(str[i] == 'j')
{
    printf("j");
}
else if(str[i] == 'k')
{
    printf("k");
}
else if(str[i] == 'l')
{
    printf("l");
}
else if(str[i] == 'm')
{
    printf("m");
}
else if(str[i] == 'n')
{
    printf("n");
}
else if(str[i] == 'o')
{
    printf("o");
}
else if(str[i] == 'q')
{
    printf("q");
}
else if(str[i] == 'r')
{
    printf("r");
}
else if(str[i] == 's')
{
    printf("s");
}
else if(str[i] == 't')
{
    printf("t");
}
else if(str[i] == 'u')
{
    printf("u");
}
else if(str[i] == 'v')
{
    printf("v");
}
else if(str[i] == 'w')
{
    printf("w");
}
else if(str[i] == 'x')
{
    printf("x");
}
else if(str[i] == 'y')
{
    printf("y");
}
else if(str[i] == 'z')
{
    printf("z");
}
else if(str[i] == 'A')
{
    printf("A");
}
else if(str[i] == 'B')
{
    printf("B");
}
else if(str[i] == 'C')
{
    printf("C");
}
else if(str[i] == 'D')
{
    printf("DD");
}
else if(str[i] == 'E')
{
    printf("E");
}
else if(str[i] == 'F')
{
    printf("F");
}
else if(str[i] == 'G')
{
    printf("G");
}
else if(str[i] == 'H')
{
    printf("H");
}
else if(str[i] == 'I')
{
    printf("I");
}
else if(str[i] == 'J')
{
    printf("J");
}
else if(str[i] == 'K')
{
    printf("K");
}
else if(str[i] == 'L')
{
    printf("L");
}
else if(str[i] == 'M')
{
    printf("M");
}
else if(str[i] == 'N')
{
    printf("N");
}
else if(str[i] == 'O')
{
    printf("O");
}
else if(str[i] == 'Q')
{
    printf("Q");
}
else if(str[i] == 'R')
{
    printf("R");
}
else if(str[i] == 'S')
{
    printf("S");
}
else if(str[i] == 'T')
{
    printf("T");
}
else if(str[i] == 'U')
{
    printf("U");
}
else if(str[i] == 'V')
{
    printf("V");
}
else if(str[i] == 'W')
{
    printf("W");
}
else if(str[i] == 'X')
{
    printf("X");
}
else if(str[i] == 'Y')
{
    printf("Y");
}
else if(str[i] == 'Z')
{
    printf("Z");
}
else if(str[i] == 'p')
{
    printf("p");
}
else if(str[i] == 'P')
{
    printf("P");
}
    fclose(stdin);
    return 0;
}
