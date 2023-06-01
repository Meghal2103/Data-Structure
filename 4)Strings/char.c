#include <stdio.h>

int main()
{
    char temp='A';//only way to store a single character with single quatation
    char a[5] = "ABCDE"; // we have to give \0
    char d[5] = "AB"; // remaing character will be /0
    char b[] = "ABCDE"; // \0 is already given by compiler
    char c[] = {65,66,67,68,69}; // we have to give \0
    printf("%c\n", temp);
    printf("%s\n", a);
    printf("%s\n", d);
    printf("%s\n", b);
    printf("%s\n", c);
}