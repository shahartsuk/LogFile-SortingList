#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)


int main_1_1()
{
    char str[1000];
    FILE* f = fopen("myLogFile.log", "w");

    fputs("line1\n", f);
    fputs("line2\n", f);
    fputs("line3\n", f);
    fputs("line4\n", f);   

    fclose(f);

    f = fopen("myLogFile.log", "r");
    while (fgets(str, 1000, f))
    {
        printf("%s", str);
    }

    fclose(f);
}

