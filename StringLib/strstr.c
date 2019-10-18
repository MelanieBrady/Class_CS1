#include <stdio.h>
#include <string.h>

int main() {
    char *cptr;
    char str[] = "hello";
    char *substr[] = {"he", "hi", "hello"}; 

    printf("%s", strstr(str, substr[0]));
    printf("\n%d", strcmp(str, substr[0]));
}