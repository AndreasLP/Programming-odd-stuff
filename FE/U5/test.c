#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define byte uint8_t
void print_binary(uint8_t number)
{
    if (number) {
        print_binary(number >> 1);
        printf("%s", ((number & 1) ? "1" : "0"));
    } 
}

int main(int argc, char** argv) {
    byte val1 = 0x9d, val2 = 0xe1;
    print_binary(val1); printf("\n");
    print_binary(val2); printf("\n");
    print_binary(val1 | val2); printf("\n");
    print_binary(val1 & val2); printf("\n");
    print_binary(~(val1 | val2)); printf("\n");
    char ch[20] = { 0 };
    for( int i = 0; i < 20; i++) printf("%d, ", ch[i]);
    printf("\n");
    for( int i = 0; i < 20; i++) printf("%c, ", ch[i]);
    printf("\n");
    scanf("%s", ch);
    for( int i = 0; i < 20; i++) printf("%d, ", ch[i]);
    printf("\n");
    for( int i = 0; i < 20; i++) printf("%c, ", ch[i]);
    printf("\n");
    printf("%s\n", ch);


  return 0;
};
