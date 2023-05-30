//datas.c
#include <stdio.h>
#include <string.h>

int main(void) 
{

int month, day, year;
char monthname[16], line[256];

while (strlen(fgets(line, sizeof(line), stdin)) > 1)
{
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
        printf("valid: %s\n", line); /* 25 Dec 1988 form */
    else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
        printf("valid: %s\n", line); /* mm/dd/yy form */
    else
        printf("invalid: %s\n", line); /* invalid form */
}
    return 0;
}