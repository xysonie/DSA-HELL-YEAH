#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hashNum(int num){
    return num % 100;
}

int hashName(char lastName[]){
    return isalpha(lastName[0]) ? toupper(lastName[0]) - 'A' : -1;
}

int hashRGB(int r, int g, int b){
    return ((r + g + b) % 64);

}

int main(){

printf("=== Hash Number ===\n");
printf("%d\n", hashNum(600));
printf("%d\n", hashNum(20));

printf("=== Hash Name ===\n");
printf("%d\n", hashName("Mutia"));
printf("%d\n", hashName("Manlangit"));

printf("=== Hash RGB ===\n");
printf("%d\n", hashRGB(4, 5, 6));
printf("%d\n", hashRGB(7, 8, 9));

return 0;

}