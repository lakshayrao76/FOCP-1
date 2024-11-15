#include <stdio.h>
#include <math.h>
int binaryToDecimal(int binary) {
    int decimal = 0, i = 0, remainder;
    while (binary != 0) {
        remainder = binary % 10;
        decimal += remainder * pow(2, i);
        i++;
        binary /= 10;
    }
    return decimal;
}
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }
    
    int binary[32]; 
    int i = 0;
    
   
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    
    
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int choice, num;

    
    printf("Choose the conversion type:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter a binary number: ");
        scanf("%d", &num);
        int decimal = binaryToDecimal(num);
        printf("The decimal equivalent of binary %d is: %d\n", num, decimal);
    } else if (choice == 2) {
        
        printf("Enter a decimal number: ");
        scanf("%d", &num);
        decimalToBinary(num);
    } else {
        printf("Invalid choice! Please enter 1 or 2.\n");
    }

    return 0;
}
