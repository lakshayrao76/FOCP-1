//WAP to print following Pyramid:
//0 0
//01 01
//010 010
//0101 0101
//0101001010
#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 5; i++) {
        
        for (j = 1; j <= i; j++) {
            if (j % 2 == 1) { 
                printf("0");
            } else {            
                printf("1");
            }
        }

        printf(" ");

        for (j = 1; j <= i; j++) {
            if (j % 2 == 1) {  
                printf("0");
            } else {            
                printf("1");
            }
        }
        printf("\n");
    }

    return 0;
}
